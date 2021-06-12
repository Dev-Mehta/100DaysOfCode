/** 
Task: To implement an automatically resizing vector
Functions:
	size() - number of items
	capacity() - number of items it can hold
	is_empty()
	at(index) - returns item at given index, blows up if index out of bounds
	push(item)
	insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
	prepend(item) - can use insert above at index 0
	pop() - remove from end, return value
	delete(index) - delete item at index, shifting all trailing elements left
	remove(item) - looks for value and removes index holding it (even if in multiple places)
	find(item) - looks for value and returns first index with that value, -1 if not found
*/

#include <iostream>
using namespace std;

template<typename T> class Array{
	// arr is the integer pointer which stores the address of our vector
	T* arr;
	// capacity is the total storage available for the vector
	int _capacity;
	// current is the number of elements present in the vector
	int current;
	public: 
		Array(){
			arr = new T[1];
			_capacity = 1;
			current = 0;	
		}
		/**
		 * @return the number of items present in array 
		*/
		int size(){
			return current;
		} 
		/**
		 * @return the number of items array can hold 
		*/
		int capacity(){
			return _capacity;
		}
		/**
		 * @return whether the array is empty or not
		*/
		bool is_empty(){
			if(current==0)
				return true;
			return false;	
		}
		/**
		 * @param item - Adds item to the array
		*/
		void push(T item){
			if(current==_capacity){
				T* temp = new T[2 * _capacity];
				for(int i = 0; i < _capacity; i++){
					temp[i] = arr[i];
				}
				delete[] arr;
				_capacity *= 2;
				arr = temp;
			}
			arr[current] = item;
			current++;
		}
		/**
		 * @param index - index of item
		 * @return return the item at given index
		*/
		T at(int index){
			if(index < current){
				return arr[index];
			}
		} 
		/**
		 * @param index - index of item to be inserted
		 * @param item - item to be inserted
		*/
		void insert(int item, int index){
			// if index is equal to capacity
			// then this function is same as
			// push function defined earlier
			if(index == _capacity){
				push(item);
			}
			else{
				arr[index] = item;
			}
		}
		/**
		 * @param item - item to be added
		*/
		void prepend(int item){
			insert(item, 0);
		}
		/**
		 * @return pops the last element and returns it
		*/
		T pop(){
			current--;
			return arr[current+1];
		}
		void print(){
			for(int i = 0; i < _capacity; i++){
				cout << arr[i] << endl;
			}
		}
};

int main(){
	Array<int> arr;
	arr.push(1);
	arr.push(3);
	arr.insert(2,1);
	arr.prepend(2);
	arr.print();
	cout<< arr.at(0);
	return 0;
}
