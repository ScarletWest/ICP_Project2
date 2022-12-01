//
// Created by NY on 11/30/22.
//

#include "readFiles.h"

vector<vector<string>> readFiles::airportInfo;
vector<vector<string>> readFiles::routeInfo;
vector<Path> readFiles::validPaths;

vector<string> readFiles::getAirportByCityCountry(const string& city, const string& country) {
    vector<string> airportIds;
    for (vector<string> vector: readFiles::airportInfo) {
        if (vector[2] == city && vector[3] == country) {
            airportIds.push_back(vector[0]);
        }
    }
    return airportIds;
}

void readFiles::readAirportFile(){
    vector<string> row;
    string line, word;

    fstream file ("/Users/user/Downloads/C++ Project/airports.csv");
    if(file.is_open()) {
        while(getline(file, line)){
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            readFiles::airportInfo.push_back(row);
        }
    } else
        cout<<"Could not open the file\n";
}

void readFiles::readRouteFile() {
    vector <string> row;
    string line, word;

    fstream file2("/Users/user/Downloads/C++ Project/routes.csv");
    if (file2.is_open()) {
        while (getline(file2, line)) {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            routeInfo.push_back(row);
        }
    } else {
        cout << "Could not open the file\n";
    }
}


vector<vector<string>> readFiles::readInputFile() {
    vector<vector<string>> rows;
    vector <string> row;
    string line, word;

    fstream file("accra-winnipeg.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            rows.push_back(row);
        }
    } else {
        cout << "Could not open the file\n";
    }

    return rows;
}

void readFiles::addPath(Path path) {
    validPaths.push_back(path);
}

void readFiles::writeOutputFile(const string& filename, const string& data) {

        ofstream outputFile(filename);
        if (outputFile.fail()) {
            cout << "Could not open " << filename << " for writing!" << endl;
        }

        outputFile << data;
        outputFile.close();
}