#include<iostream>
#include<string>
#include<cstdio>
#include<fstream>
#include"bike_type.h"
#include"bike_type.cpp"
//Used for testing input.
#include <string>
#include <sstream>
#include <iostream>
/////////////////////////
using namespace std;

ofstream fileOut;
ifstream testCaseIn;
ifstream mapIn;
int main(int argc, char * argv[]) {
    
    
    //Hidden for testing input.
    /*
     if(argc!=4)
    {
        cout << "arguments are incorrect" << endl;
        return 0;
    }
    //argv[1] is the name of the transaction file
    //argv[2] is the name of the map file
    //argv[3] is the name of the output file
    fileOut.open(argv[3],ifstream::out);
    mapIn.open(argv[2],ifstream::in);
    testCaseIn.open(argv[1],ifstream::in);
    //read map
    string s, t, dist;
    while(mapIn >> s >> t >> dist){
    }
    string cmd;
    */
    /////////////////////////
    
    
    //....
    //your parser about testCase
    
    BNode *root = NULL;
    bool first_bnode = true;
    string cmd;
    while(getline(cin, cmd))
    {
        while(testCaseIn>>cmd)
        {
            if(cmd=="NewBike")
            {
                string ClassStr;
                LicenseType License;
                int Mile;
                string StationStr;
                
                testCaseIn >> ClassStr;
                testCaseIn >> License;
                testCaseIn >> Mile;
                testCaseIn >> StationStr;
                
                ClassType Class = ReadClass(ClassStr);
                StationType Station = ReadStation(StationStr);
                
                BNode *newbike = NewBike(License, Mile, Class, Station, root);
                if(first_bnode == true){
                    root = newbike;
                    first_bnode = false;
                }
                cout << "New bike is received by " << Station << " station." << endl;
            }
            else if(cmd == "JunkIt")
            {
                
            }
            fileOut << "your output" << endl;
            
            return 0;
        }
    }
}
