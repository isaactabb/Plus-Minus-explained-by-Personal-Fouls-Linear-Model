//
// Created by Isaac Tabb on 10/20/22.
//

#include "PlayerStats.h"

/* PLAYERSTATS.cpp
 * This file implements the PlayerStats.h class.
 */

// constructor
PlayerStats::PlayerStats(string name, int plusMinusObs, int personalFouls) {
    setName(name);
    setPlusMinusObs(plusMinusObs);
    setPersonalFouls(personalFouls);
}

// getters
string PlayerStats::getName() const {
    return name;
}

int PlayerStats::getPlusMinusObs() const {
    return plusMinusObs;
}
int PlayerStats::getPersonalFouls() const {
    return personalFouls;
}

// setters
void PlayerStats::setName(string name) {
    this->name = name;
}

void PlayerStats::setPlusMinusObs(int plusMinusObs) {
    this->plusMinusObs = plusMinusObs;
}

void PlayerStats::setPersonalFouls(int personalFouls) {
    this->personalFouls = personalFouls;
}

// overloaded operator to print name plus minus and pf
ostream& operator << (ostream& outs, const PlayerStats& player) {
    cout << player.getName() << " " << player.getPlusMinusObs() << "pm " << player.getPersonalFouls() << "asts " << endl;
    return outs;
}

/* This is a helper function to read PlayerStats data from a file */
void readStatsFromFile(string filename, vector<PlayerStats>& players) {
    // clear players vector
    players.clear();

    // Open the file
    ifstream inFile;
    inFile.open("../" + filename);

    // Create needed fields to read in PlayerStats information
    string name, junk;
    int plusMinusObs, personalFouls;
    char comma;

    // While the file is in good condition and next line is not end of file
    while (inFile && inFile.peek() != EOF) {
        // read in name
        getline(inFile, name, ',');

        // skip unnecessary lines
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');
        getline(inFile, junk, ',');

        // read in personalFouls
        inFile >> personalFouls >> comma;

        // skip unnecessary lines
        getline(inFile, junk, ',');

        // read in plusMinusObs
        inFile >> plusMinusObs >> comma;

        // All other lines are unnecessary
        getline(inFile, junk, '\n');

        // Add the read in Team Member to the teamMembers vector
        players.push_back(PlayerStats(name, plusMinusObs, personalFouls));
    }
    // close file
    inFile.close();
}
