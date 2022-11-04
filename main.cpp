//
// Created by Isaac Tabb on 10/20/22.
//

/* MAIN
 * The main.cpp of this program prompts the user to choose either to
 * run the model (plus minus explained by personal fouls) or to obtain a prediction
 * from the model. The main.cpp calls an R program which computes the linear model.
 * The main.cpp also calls a Python program which creates a side-by-side bar chart
 * to depict how accurate (or inaccurate...) the model is.
 *
 * Note: The model ends up not being super accurate. This is okay though. The point of this
 *      program was to test the accuracy of a model where plus minus is explained by
 *      personal fouls. The outcome is that the model is just alright.
 *
 */

#include "PlayerStats.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/* DisplayMenu function
 * This function displays the menu for the user to choose from.
 * They can either run the model or use the model to predict.
 */
string displayMenu();

/* RunModel function
 * This function runs the model. It calls R and Python to compute
 * the linear model and create a bar graph (respectively). This function
 * outputs everything the user needs to know about the model, including
 * how accurate (or inaccurate...) the model is.
 */
void runModel();

/* Predict function
 * This function allows the user to obtain a prediction for plus minus
 * using the model. The user is prompted for a number of personal fouls
 * and the model predicts plus minus using that value.
 */
void predict();

/* GetCoefs function
 * This function is used to retrieve the coefficients from the R model.
 */
vector<double> getCoefs();

int main() {
    // create vector of PlayerStats called players
    vector<PlayerStats> players;
    // read in player stats from gameLogs.csv
    // this will read in name, observed plus minus, and personal fouls
    readStatsFromFile("gameLogs.csv", players);

    // create an outfile
    ofstream outFile;
    // open outfile as gameLogsClean.csv
    outFile.open("../gameLogsClean.csv");
    // read in the data cleaned from readStatsFromFile function
    // data now only includes name plusminus and pf
    outFile << "Name,PM,PF" << endl;
    for (int i = 0; i < players.size(); i++) {
        outFile << players[i].getName() << "," << players[i].getPlusMinusObs() << "," << players[i].getPersonalFouls() << endl;
    }
    outFile.close();

    // calls the R program to create model and create necessary files in repo
    /* NOTE: This calls linearModel.R which does not print any model information, it solely
     * creates the model.
     */
    string r_command = "/usr/local/bin/RScript --vanilla ../linearModel.R \"../gameLogsClean.csv\" ";
    system(r_command.c_str());

    // print output heade
    cout << "Plus Minus explained by Personal Fouls Model" << endl;
    // call displayMenu function to prompt for user choice
    string userChoice = displayMenu();

    // if user choice is 1, run the model
    if (userChoice == "1") {
        cout << "Running the model... " << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        runModel();
    // else if user choice is 2, enter prediction mode
    } else if (userChoice == "2") {
        cout << "Entering predict mode... " << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        predict();
    }

    return 0;
}

string displayMenu() {
    // user choice holds the users choice from meny
    string userChoice;
    // print the menu
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "Choose from menu:" << endl;
    cout << "(1) Run the model (create graph, display model equation)" << endl;
    cout << "(2) Predict using the model (enter PF, returns prediction for Plus Minus)" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "Enter your choice (1 or 2): ";
    // retrieve user input for choice
    getline(cin, userChoice);

    // input validation, choice must be 1 or 2
    while (userChoice != "1" && userChoice != "2") {
        cout << "Invalid input. Enter your choice (1 or 2): ";
        getline(cin, userChoice);
    }

    return userChoice;
}

void runModel() {
    // pass the gameLogsClean.csv file to R
    // R will compute the linear model and print information from the model
    // source: https://stackoverflow.com/questions/2669598/calling-r-script-from-within-c-code
    string r_command = "/usr/local/bin/RScript --vanilla ../linearModelPrint.R \"../gameLogsClean.csv\" ";
    system(r_command.c_str());

    // call getCoefs to retrieve the model LSEs
    vector<double> coefs = getCoefs();

    // print the model equation using coef vector
    cout << endl;
    cout << "Plus Minus explained by Personal Fouls Equation:" << endl;
    cout << endl;
    cout << "PlusMinus = " << coefs[0] << " + (" << coefs[1] << ") * PersonalFouls" << endl;
    cout << endl;

    // print a note about the correlation coefficient
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "Note: The correlation coefficient is .2166 which is considered a weak to slightly moderate correlation." << endl;
    cout << "      The purpose of this program is not to display a perfect model. It is to show how accurate the " << endl;
    cout << "      Plus Minus explained by Personal Fouls model is. The correlation coefficient suggests that the " << endl;
    cout << "      model is weak/not very accurate." << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "Creating graph..." << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "See pop-up window for graph." << endl;

    // pass the gameLogsObsPredic.csv to python to graph using matplotlib
    // the new csv is retrieved from R
    string py_command = "python3 ../plotGraphs.py ../gameLogsObsPredic.csv";
    system(py_command.c_str());

    cout << "-----------------------------------------------------------------------" << endl;
    cout << "Closing program..." << endl;
    cout << "-----------------------------------------------------------------------" << endl;
}

void predict() {
    // holds the observed personal fouls value, to be entered by use
    string pfObs;
    int pf;
    // prompt user for personal foul value, take input
    cout << "Enter number of Personal Fouls: ";
    getline(cin, pfObs);

    // input validation, personal fouls must be between 0 and 6 (because you cant have negative, nor have more than 6)
    while (pfObs != "0" && pfObs != "1" && pfObs != "2" && pfObs != "3" && pfObs != "4" && pfObs != "5" && pfObs != "6") {
        cout << "Invalid input. Enter number of Personal Fouls (0-6): ";
        getline(cin, pfObs);
    }
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "Calculating prediction..." << endl;

    // convert observed value for personal fouls from string to int
    stringstream ss;
    ss << pfObs;
    ss >> pf;

    // get the coefficients using getCoefs()
    vector<double> coefs = getCoefs();
    // compute the predicted plus minus using pf and coefs
    double predPlusMinus = (pf * coefs[1]) + coefs[0];

    // output the model equation, personal fouls input, and predicted plus minus
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "PlusMinus = " << coefs[0] << " + (" << coefs[1] << ") * PersonalFouls" << endl;
    cout << endl;
    cout << "Personal Fouls: " << pf << endl;
    cout << "Predicted Plus Minus: " << predPlusMinus << endl;
    cout << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "Closing program..." << endl;
    cout << "-----------------------------------------------------------------------" << endl;
}

vector<double> getCoefs() {
    // take in the returned file from R, modCoefs.csv
    ifstream inFile;
    inFile.open("../modCoefs.csv");

    // looking for intercept and slope
    double intercept, slope;
    string junk;
    char endline;

    // get rid of header
    getline(inFile, junk, ',');
    getline(inFile, junk, '\n');
    getline(inFile, junk, ',');
    // read in intercept
    inFile >> intercept >> endline;
    // get rid of junk
    getline(inFile, junk, ',');
    // read in slope
    inFile >> slope >> endline;

    inFile.close();

    // return the coefs as a vector
    vector<double> coefs;
    coefs.push_back(intercept);
    coefs.push_back(slope);
    return coefs;
}

