#include <vector>
#include <iostream>

class MergeSort{
	void merge(std::vector<int> &a,int firstIndex , int lastIndex);
public:
	MergeSort();
	void sort(std::vector<int> &a, int firstIndex, int lastIndex);
};
