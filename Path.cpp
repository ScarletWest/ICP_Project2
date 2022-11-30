//
// Created by NY on 11/29/22.
//

#include "Path.h"

Path::Path(){};

Path::Path(vector<string> actionSequence, double pathCost) {
    this->actionSequence = actionSequence;
    this->pathCost = pathCost;
}

vector<string> Path::getActionSequence() {
    return actionSequence;
}

double Path::getPathCost() const {
    return pathCost;
}