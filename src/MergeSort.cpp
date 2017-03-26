#include <fstream>
#include <string>
#include <vector>
#include "MergeSort.h"

MergeSort::MergeSort(){
}

void MergeSort::merge(std::vector<int> &a, int firstIndex , int lastIndex){
	int size = (lastIndex-firstIndex);
	std::vector<int> temp;
	int i = firstIndex;
	int middleIndex = (firstIndex+lastIndex)/2;
	int k = 0;
	int j = middleIndex+1;

	while ((i <= middleIndex) && (j <= lastIndex)){
		if(a[i] > a[j]){
			int z = a[j++];
			temp.insert(temp.begin() + k++, z);
		}
		else{
			int z = a[i++];
			temp.insert(temp.begin() + k++, z);
		}
	}
	while (j <= lastIndex) {
		int z = a[j++];
		temp.insert(temp.begin() + k++, z);
	}
	while(i <= middleIndex){
		int z = a[i++];
		temp.insert(temp.begin() + k++, z);
	}

	for(k = 0; k <= size; k++){
		int z = temp[k];
		a.erase(a.begin() +k +firstIndex);
		a.insert(a.begin() +k +firstIndex, z);
	}
}

void MergeSort::sort(std::vector<int> &a, int firstIndex, int lastIndex){

	if(firstIndex >= lastIndex) return; //base case

	int middleIndex = (firstIndex+lastIndex)/2;
	sort(a,firstIndex,middleIndex);
	sort(a,middleIndex+1,lastIndex);
	merge(a,firstIndex,lastIndex);
  }

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
