//============================================================================
// Name        : 279Group2.cpp
// Author      : Matt Borkowski
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MergeSort.h"
using namespace std;
#define OUTFILE = "SortedFile.txt"

int main() {
	MergeSort q;
	int i = 0;
	int j;
	std::vector<int> a;
	std::vector<int> b;
	while(i<10){
		cin >> j;
		a.push_back(j);
		i++;
	}
	for (std::vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
	    std::cout << *i << ' ';
	q.sort(a,0,9);
	cout<<endl;
	for (std::vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
		    std::cout << *i << ' ';

	return 0;
}

