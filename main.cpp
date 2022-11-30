//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <string>
//#include <cstring>
//#include <stdlib.h>
//#include <list>
//#include <algorithm>
//#include <map>
//#include <stdexcept>
//#include <cstring>
//#include <queue>
//#include <unordered_set>
//using namespace std;
//
//class readFiles::
//{
//public:
//    int id;
//    string destinationICAOCode,sourceICAOCode, destinationIATACode, sourceIATACode, sourceAirportID, destinationAirportID;
//    string destination_country,destination_city, source_country,source_city;
//    static vector<vector<string>> airportinfo;
//    vector<string> row;
//    string line, word, line2,word2;
//    vector<vector<string>>destination_airport_details;
//    vector<vector<string>>source_airport_details;
//
//    vector<vector<string>> routeinfo;
//    vector<vector<string>> routeFromSourceToDestination;
//    vector<string> row2;
//
//    static vector<string> getAirportByCityCountry(string city, string country) {
//        vector<string> airportIds;
//        for (vector<string> vector: airportinfo) {
//            if (vector[2] == city && vector[3] == country) {
//                airportIds.push_back(vector[0]);
//            }
//        }
//        return airportIds;
//    }
//
//
//    void setCurrentRoute(){
//        cout<<"Enter the start country: ";
//        getline(cin, source_country);
//
//        cout<<"\nEnter the start city: ";
//        getline(cin,source_city);
//
//        cout<<"\nEnter the Destination country: ";
//        getline(cin,destination_country);
//
//        cout<<"\nEnter the Destination city: ";
//        getline(cin,destination_city);
//
//    }
//
//    void readfile(){
//        setCurrentRoute();
//        fstream file ("/Users/user/Downloads/C++ Project/airports.csv");
//        if(file.is_open()){
//            while(getline(file, line)){
//                row.clear();
//
//                stringstream str(line);
//
//                while(getline(str, word, ','))
//                    row.push_back(word);
//                airportinfo.push_back(row);
//            }
//        }else
//            cout<<"Could not open the file\n";
//
//
//        cout<<"Printing the source Airport\n";
//
//
//        for (int i = 0; i < airportinfo.size(); i++) {
//            if (source_country.compare(airportinfo[i][3]) ==0 && source_city.compare(airportinfo[i][2]) == 0) {
//                source_airport_details.push_back(airportinfo[i]);
//            }
//
//        }
//
////        vector<vector<string>>::iterator row;
////        vector<string>::iterator col;
////        for (row = source_airport_details.begin(); row != source_airport_details.end(); row++) {
////            for (col = row->begin(); col != row->end(); col ++) {
////                cout << source_airport_details[row][col];
////            }
////        }
//        for (int a = 0; a < source_airport_details.size(); a++)
//        {
//            for (int j = 0; j <source_airport_details[a].size(); j++)
//            {
//                cout << source_airport_details[a][j] << " ";
//            }
//            cout << "\n";
//        }
//
//
//
//        for (int i = 0; i < airportinfo.size(); i++)
//        {
//            if (destination_country.compare(airportinfo[i][3]) ==0 && destination_city.compare(airportinfo[i][2]) == 0)
//            {
//                destination_airport_details.push_back(airportinfo[i]);
//
//            }
//
//        }
//        cout<<"Printing the destination Airport\n";
//        for (int a = 0; a < destination_airport_details.size(); a++)
//        {
//            for (int j = 0; j <destination_airport_details[a].size(); j++)
//            {
//
//                cout << destination_airport_details[a][j] << " ";
//            }
//            cout << "\n";
//        }
//
//    }
//
//    void airlines()
//    {
//        readfile();
//        fstream file2("/Users/user/Downloads/C++ Project/routes.csv");
//        if (file2.is_open())
//        {
//            while (getline(file2, line2))
//            {
//                row2.clear();
//
//                stringstream str(line2);
//
//                while (getline(str, word2, ','))
//                    row2.push_back(word2);
//                routeinfo.push_back(row2);
//            }
//        }
//        else{
//            cout << "Could not open the file\n";
//        }
//
//
//
//        for (int i = 0; i < destination_airport_details.size(); i++)
//        {
//            for (int k = 0; k < source_airport_details.size() ; k++)
//            {
//                for (int j = 0; j < routeinfo[i].size(); j++)
//                {
//                    if (source_airport_details[k][0].compare(routeinfo[j][3]) == 0 && destination_airport_details[i][0].compare(routeinfo[j][5]) == 0)
//                    {
//                        routeFromSourceToDestination.push_back(routeinfo[j]);
//                    }
//
//                }
//            }
//        }
//
//        int count = 1;
//        int total_flight,total_stops =0;
//        for (int i = 0; i < routeFromSourceToDestination.size(); i++)
//        {
//            total_stops = total_flight + stoi(routeFromSourceToDestination[i][7]);
//            total_flight = routeFromSourceToDestination.size();
//            cout <<count<<" "<< routeFromSourceToDestination[i][0] << " from " << routeFromSourceToDestination[i][2]<<" to " <<routeFromSourceToDestination[i][4]<<" "<<routeFromSourceToDestination[i][7]<<" "<<"stops";
//            cout << "\n";
//            cout<<"Total flights: "<<total_flight;
//            cout << "\n";
//            cout << "Total additional stops: "<<total_stops;
//            count++;
//
//        }
//
//
//         if (destination_airport_details.size() > source_airport_details.size())
//         {
//         	for (int c = 0; c < destination_airport_details.size(); c++)
//         	{
//         		for (int d = 0; d < routeinfo.size(); d++)
//         		{
//         			if (source_airport_details[c][0].compare(routeinfo[d][3]) == 0 && destination_airport_details[c][0].compare(routeinfo[d][5]) == 0)
//         			{
//         				routeFromSourceToDestination.push_back(routeinfo[d]);
//         				cout<<routeFromSourceToDestination[0][0];
//         			}
//         		}
//         	}
//         }
//         else
//         {
//         	for (int c = 0; c < source_airport_details.size(); c++)
//         	{
//         		for (int d = 0; d < routeinfo.size(); d++)
//         		{
//         			if (source_airport_details[c][0].compare(routeinfo[d][3]) == 0 && destination_airport_details[c][0].compare(routeinfo[d][5]) == 0)
//         			{
//         				routeFromSourceToDestination.push_back(routeinfo[d]);
//         				cout<<routeFromSourceToDestination[0][0];
//         			}
//         		}
//         	}
//         }
//
//
//
//    }
//
//};
//int main() {
//
//    readFiles:: obj1;
//    obj1.readfile();
//    obj1.airlines();
//    return 0;
//}

#include "algo.h"
#include "readFiles.h"

int main() {
    readFiles::readAirportFile();
    readFiles::readRouteAirline();

    string destination_country, destination_city, source_country, source_city;

    cout<<"Enter the start country: ";
    getline(cin, source_country);

    cout<<"\nEnter the start city: ";
    getline(cin,source_city);

    cout<<"\nEnter the Destination country: ";
    getline(cin,destination_country);

    cout<<"\nEnter the Destination city: ";
    getline(cin,destination_city);

    vector<string> sourceAirportIds = readFiles::getAirportByCityCountry(
            source_city, source_country);
    vector<string> destinationAirportIds = readFiles::getAirportByCityCountry(
            destination_city, destination_country);

    for (string id : sourceAirportIds) {
        cout << "Source: " << id << endl;
    }

    for (string id: destinationAirportIds) {
        cout << "Destination: " << id << endl;
    }

//    for (vector<string> vect : readFiles::routeInfo) {
//        cout << vect[2] << endl;
//    }

    for (string sourceAirportId: sourceAirportIds) {
        for (string destinationAirportId: destinationAirportIds) {
            Path path = algo::breadthFirstSearch(sourceAirportId, destinationAirportId,
                                                 readFiles::routeInfo);
        }
    }

//
//    vector<string> actionSequence = path.getActionSequence();
//
//    for (string action: actionSequence) {
//        cout << action << endl;
//    }

    return 0;
}