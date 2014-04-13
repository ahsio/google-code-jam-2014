//
//  magic-trick.cpp
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

int fillGrid(ifstream& inputFile, int grid[4][4])
{
    string line;
    
    for (int a = 0; a < 4; a++) {
        
        line = readFile(inputFile);
        auto v = explode(line, ' ');
        
        for (int b = 0; b < 4; b++) {
            string position =  v.at(b);
            grid[a][b] = atoi(position.c_str());
        }
    }
    
    return 0;
}

int main(int argc, const char * argv[])
{
    ifstream inputFile ("input.txt");
    ofstream outputFile ("output.txt");
    
    string line;
    
    int numberOfCases;
    int choices[2], grid1[4][4], grid2[4][4];
    
    line = readFile(inputFile);
    numberOfCases = atoi(line.c_str());
    
    for (int i = 0; i < numberOfCases; i++) {
        line = readFile(inputFile);
        choices[0] = atoi(line.c_str());
        
        fillGrid(inputFile, grid1);
        
        line = readFile(inputFile);
        choices[1] = atoi(line.c_str());
        
        fillGrid(inputFile, grid2);
        
        int firstMatch[4], secondMatch[4];
        for (int k = 0; k < 4; k++) {
            firstMatch[k]  = grid1[choices[0] - 1][k];
            secondMatch[k] = grid2[choices[1] - 1][k];
        }
        
        string message;
        int selectedCard;
        bool alreadyMatch = false;
        
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                if (firstMatch[x] == secondMatch[y]) {
                    selectedCard = firstMatch[x];
                    if (alreadyMatch) {
                        message = "Bad magician!";
                    }
                    alreadyMatch = true;
                }
                
            }
        }
        
        if (!alreadyMatch) {
            message = "Volunteer cheated!";
        }
        
        if (outputFile.is_open()) {
            if (!message.empty())
                outputFile << "Case #" << i+1 << ": " << message << '\n';
            else
                outputFile << "Case #" << i+1 << ": " << selectedCard << '\n';
        }
    }
    inputFile.close();
    outputFile.close();
    
    return 0;
}