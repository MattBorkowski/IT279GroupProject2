#include "MergeSort.h"

MergeSort::MergeSort(){
	//constructor does nothing for now
}

void MergeSort::merge(std::vector<int> &a, int firstIndex , int lastIndex){
	int size = (lastIndex-firstIndex);
	std::vector<int> temp; //holds the sorted vector
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
//		std::cout<<z;
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
