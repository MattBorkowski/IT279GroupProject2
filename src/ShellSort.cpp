//
// Created by Adam Johnson on 3/21/17.
//

#include <cmath>
#include <fstream>
#include "ShellSort.h"
//hibbard shell sort
//Hibbard starts at 1 then goes up 2^k -1
void ShellSort::shellsort(std::vector<int> &a) {
    int gap,i,j,temp,size;
    size = a.size()+1;
    for (/* ht */gap = 1; gap > 0; gap = pow(2,size)-1 /* hk+1 */) {
        size--;
        for (i = gap; i < size; i++)

            for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap) {

                temp = a[j];

                a[j] = a[j + gap];

                a[j + gap] = temp;

            }
    }
}
int main ( int argc, char *argv[] ) {
    using namespace std;
    ShellSort object; //test on
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
        object.shellsort(input); /* run sorting algorithm */
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
