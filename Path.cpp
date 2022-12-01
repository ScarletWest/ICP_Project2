//
// Created by NY on 11/29/22.
//

#include "Path.h"
#include "readFiles.h"

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

//string solutionString = optimalPath.createSolutionSring();
//string filename = "cmake-build-debug/" + sourceCity.lower() + destinationCity.lower() + "-output";
//readWriteFile::write(filename, solutionString);
//}

string Path::createString() {
    string solutionString = "";
    int count = 0;
    int totalStops = 0;
    vector<string> actions = this->getActionSequence();
    for (string airportId: actions) {
        for (vector<string> routeVector: readFiles::routeInfo) {
            vector<vector<string>> possibleRoutes;
            if (routeVector[3] == airportId) {
                possibleRoutes.push_back(routeVector);
            }
            for (vector<string> possibleRoute: possibleRoutes) {
                if (count < (actions.size() - 1)) {
                    if (possibleRoute[5] == actions[count + 1]) {
                        solutionString += to_string(count + 1) + ". " +
                                possibleRoute[0] + " from ";

                        vector<string> sourceAirportObject;
                        vector<string> destinationAirportObject;
                        for (vector<string> airportVector: readFiles::airportInfo) {
                            if (airportVector[0] == possibleRoute[3]) {
                                sourceAirportObject = airportVector;
                            } else if (airportVector[0] == possibleRoute[5]) {
                                destinationAirportObject = airportVector;
                            }
                        }

                        solutionString += sourceAirportObject[4] + " to " +
                                destinationAirportObject[4] +" " +
                                possibleRoute[7] + " stops.\n";
                        count++;
                        totalStops += stoi(possibleRoute[7]);
                    }
                }
            }
        }
    }

    solutionString += "\nTotal flights: " + to_string(actions.size() -1);
    solutionString += "\nTotal additional stops: " + to_string(totalStops);
    solutionString += "\nTotal distance: " + to_string(this->getPathCost()) + " km";
    solutionString += "\nOptimality criteria: number of flights";

    return solutionString;
}