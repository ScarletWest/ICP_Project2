//
// Created by NY on 11/29/22.
//

#include "algo.h"
#include "node.h"
#include "Path.h"
#include <list>
#include <algorithm>
#include <stdexcept>
#include <cstring>
#include <unordered_set>


Path algo::breadthFirstSearch(string sourceAirportID, string destinationAirportID, vector<vector<string>> map) {
    Path path;

    vector<Node> openList;
    unordered_set<string> closedList;

    // using nodes to search through Airport IDs until desired outputs are produced
    cout << "About to do the search on the problem: " << endl;
    Node *initialNode = new Node(sourceAirportID);
    openList.push_back(*initialNode);

    while (!openList.empty()) {
        // remove and store the first item on the openList
        Node node = openList[0];
        openList.erase(openList.begin());
        closedList.insert(node.getState());

        cout << "Expanding: " << node.getState() << endl;

//        if (destinationAirportID == node.getState()) {
//            cout << "Yay, found a solution!";
//            return node.path();
//        } else {
//            closedList.insert(node.getState());

        try {
            vector<string> neighbouringAirports;

            for (vector<string> routeVector: map) {
//                    cout << routeVector[3] << endl;
                if (!((routeVector[3] == "\\N") && !(routeVector[5] == "\\N"))) {
                    if (node.getState() == routeVector[3]) {
                        neighbouringAirports.push_back(routeVector[5]);
                    }
                }
            }

            for (const string& airportId: neighbouringAirports) {
                Node* child = new Node(airportId, &node, node.getPathCost() + 1);

//                auto iter = find(openList.begin(), openList.end(), *child);
//                if ((closedList.find(airportId) == closedList.end()) && (iter == openList.end()))

                auto iter = find(openList.begin(), openList.end(), *child);
                if (find(openList.begin(), openList.end(), *child) != openList.end() &&
                        !(closedList.count(child->getState()))) {
                    if (destinationAirportID == child->getState()) {
                        cout << "Yay, found a solution!";
                        return node.path();
                    } else {
                        openList.push_back(*child);
                    }
                }
            }

        } catch (exception& e) {
            cout << e.what();
        }
    }
    // If desired outputs are non-existent, this message is printed
    cout<<"After the rather frustrating search, I couldn't find any valid route.";
    return path;
}