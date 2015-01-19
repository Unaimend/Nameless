//
//  Parser.h
//  Nameless
//
//  Created by Thomas Dost on 10.01.15.
//  Copyright (c) 2015 Thomas Dost. All rights reserved.
//

#ifndef __Nameless__Parser__
#define __Nameless__Parser__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Parser
{
public:
    Parser()
    {
        pIfStream = new std::ifstream("Save.txt");

        readData();

        pIfStream->close();
        
        pOfStream = new std::ofstream("Save.txt");
    };
    ~Parser()
    {
         pOfStream->close();
    };

    void saveData(std::string name, std::string value)
    {

        *pOfStream << name + value + "\n";

        std::cout << "DATA SAVED" << std::endl;
    };
    void readData()
    {
        
        while (std::getline(*pIfStream,mData))
        {
            for(unsigned int i = 0; i < strlen(chars); ++i)
            {
                // you need include <algorithm> to use general algorithms like std::remove()
                mData.erase (std::remove(mData.begin(), mData.end(), chars[i]), mData.end());
                //Kommatas löschen um casten von string zu einem anderen Typ zu ermöglichen.
            }

            mDataToLoad.push_back(mData);

        }


    };
    std::vector<std::string> mDataToLoad;
    std::string mData;
private:
    std::ofstream *pOfStream;
    std::ifstream *pIfStream;


    int test = 12;
    char chars[3] {","};
};
#endif /* defined(__Nameless__Parser__) */
