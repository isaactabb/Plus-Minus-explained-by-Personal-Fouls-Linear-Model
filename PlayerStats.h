//
// Created by Isaac Tabb on 10/20/22.
//

#ifndef M3OEP_ITABB_PLAYERSTATS_H
#define M3OEP_ITABB_PLAYERSTATS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/* PLAYERSTATS class
 * This class is meant to hold the PlayerStats needed to compute the model
 * in main. This class is used to store PlayerStats from the gameLogs csv file.
 * This class has three fields: player name, plusMinusObs, and personalFouls.
 */

class PlayerStats {
private:
    // holds the name of the player
    string name;
    // holds the player's plus minus score
    int plusMinusObs;
    // holds the player's personalFouls total
    int personalFouls;

public:
    // constructor
    PlayerStats(string name, int plusMinusObs, int personalFouls);

    // getters
    string getName() const;
    int getPlusMinusObs() const;
    int getPersonalFouls() const;

    // setters
    void setName(string name);
    void setPlusMinusObs(int plusMinusObs);
    void setPersonalFouls(int personalFouls);

    // overloaded op
    friend ostream& operator << (ostream& outs, const PlayerStats& player);
};

void readStatsFromFile(string filename, vector<PlayerStats>& players);

#endif //M3OEP_ITABB_PLAYERSTATS_H
