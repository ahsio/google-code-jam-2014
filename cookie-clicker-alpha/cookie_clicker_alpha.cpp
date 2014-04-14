//
//  cookie_clicker_alpha.cpp
//  google_code_jam
//
//  Created by ahmed on 4/12/14.
//  Copyright (c) 2014 ahmed. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>

using namespace std;

vector<string> explode(string const & s, char delim)
{
    vector<string> result;
    istringstream iss(s);
    
    for (string token; getline(iss, token, delim); )
    {
        result.push_back(move(token));
    }
    
    return result;
}

string readFile(ifstream& inputFile)
{
    string newLine;
    
    if (inputFile.is_open()) {
        getline (inputFile,newLine);
    }
    
    return newLine;
}

int main(int argc, const char * argv[])
{
    ifstream inputFile ("input.txt");
    ofstream outputFile ("output.txt");
    
    string line;
    int numberOfCases;
    
    line = readFile(inputFile);
    numberOfCases = atoi(line.c_str());
    
    for (int i = 0; i < numberOfCases; i++) {
       line = readFile(inputFile);
        auto v = explode(line, ' ');

        float c = stof(v.at(0).c_str());
        float f = stof(v.at(1).c_str());
        float x = stof(v.at(2).c_str());

        int perSecond = 2;
        double time = 0;
        bool checkIfINeedAFarm = true;
        
        while (checkIfINeedAFarm) {
            if (x/(perSecond + f) + (c/perSecond) < (x/perSecond)) {
                time = time + c/perSecond;
                perSecond = perSecond + f;
            } else {
                checkIfINeedAFarm = false;
                time = time + x/perSecond;
            }
        }

        if (outputFile.is_open()) {
           outputFile.precision(7);
            outputFile << "Case #" << i+1 << ": " << fixed << time << '\n';
        }
    }
    inputFile.close();
    outputFile.close();
    
    return 0;
}