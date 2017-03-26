//============================================================================
// Name        : 279Group2.cpp
// Author      : Matt Borkowski
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <string>
#include <vector>
#include "MergeSort.h"

int main ( int argc, char *argv[] ) {
    using namespace std;
    MergeSort Mergesort;

    if(argc !=3) {
        cout << "Invalid Input";
        exit(1);
    }
    //argsv[1] = input input_file, argsv[2] = output output_file (argsv[0] is the name of the program)
    vector<int> input;
    string number;
    ifstream input_file(argv[1]);
    if(!input_file.is_open()) {
        cout << "Invalid File";
        exit(1);
    }
        while (getline(input_file, number)) {
            input.push_back(stoi(number));
        }
        input_file.close();
        Mergesort.sort(input,0,input.size());
        ofstream output_file;
        output_file.open(argv[2],ios::out);
        if(!output_file.is_open()) {
            cout << "invalid output file";
            exit(1);
        }
        for(int i=0; i < input.size(); i++) {
            output_file << input[i];
            output_file << "\n";
        }
    output_file.close();


}

