#include<iostream>
#include "arrays.h"
using namespace std;
int main(){
	Array<int> array;
	array.push(1);
	array.push(2);
	array.push(5);
	array.push(4);
	array.push(3);
	array.sort();
	cout << "Binary Search of 2: " << array.binary_search(2) << endl;
	cout << "Binary Search of 3: " << array.binary_search(3, 0, 4);
	return 0;
}