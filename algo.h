//
// Created by NY on 11/29/22.
//

#ifndef ICP_PROJECT2_ALGO_H
#define ICP_PROJECT2_ALGO_H

#include "Path.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class algo {
public:
    static void breadthFirstSearch(string sourceAirportID, string destinationAirportID, vector<vector<string>> map);
};


#endif //ICP_PROJECT2_ALGO_H
