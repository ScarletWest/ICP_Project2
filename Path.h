//
// Created by NY on 11/29/22.
//

#ifndef ICP_PROJECT2_PATH_H
#define ICP_PROJECT2_PATH_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Path {
private:
    vector<string> actionSequence;
    double pathCost;

public:
    Path();
    Path(vector<string> actionSequence, double pathCost);
    vector<string> getActionSequence();
    double getPathCost() const;
    string createString();
};


#endif //ICP_PROJECT2_PATH_H
