//
// Created by NY on 11/29/22.
//

#include "readFiles.h"
#include "algo.h"
#include "node.h"
#include "Path.h"
#include <algorithm>
#include <stdexcept>
#include <deque>
#include <unordered_set>


void algo::breadthFirstSearch(string sourceAirportID, string destinationAirportID, vector<vector<string>> map) {
    deque<Node> openList;
    unordered_set<string> closedList;

    // using nodes to search through Airport IDs until desired outputs are produced
    cout << "\nAbout to do the search on the problem: " << endl;
    Node initialNode = Node(sourceAirportID);

    if (stoi(initialNode.getState()) == stoi(destinationAirportID)) {
        cout << "Yay, found a solution!" << endl;
        cout << "about to call path";
        Path path = initialNode.path();
//        readFiles::addPath(path);
        cout << "done";
        return;
    }

    openList.push_back(initialNode);

    while (!openList.empty()) {
        // remove and store the first item on the openList
        Node node = openList.front();
        openList.pop_front();
        closedList.insert(node.getState());

        cout << "Expanding: " << node.getState() << endl;

        try {
            vector<string> neighbouringAirports;

            for (vector<string> routeVector: map) {
                if (node.getState() == (routeVector[3])) {
//                    cout << "routeVector[3]: " << routeVector[3] << endl;
                    neighbouringAirports.push_back(routeVector[5]);
                }
            }

//            cout << "neighbouringAirports.size: " << neighbouringAirports.size() << endl;
            for (const string& airportId: neighbouringAirports) {
                Node child = Node(airportId, &node, node.getPathCost() + 1);

                auto it = find(openList.begin(), openList.end(), child);
                if ((closedList.find(airportId)) == closedList.end() && it == openList.end()) {
                    if (destinationAirportID == child.getState()) {
                        cout << "Yay, found a solution!" << endl;
                        cout << "about to call path";
                        Path path = child.path();
//                        readFiles::addPath(path);
                        cout << "done";
                        return;
                    } else {
                        openList.push_back(child);
                    }
                }
            }

        } catch (exception& e) {
            cout << e.what();
        }
    }
    // If desired outputs are non-existent, this message is printed
    cout<<"After the rather frustrating search, I couldn't find any valid route.";
    return;
}