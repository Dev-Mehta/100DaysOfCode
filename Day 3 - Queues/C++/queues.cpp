#include <iostream>
#include "linked_list.h"

using namespace List;
using namespace std;

template<typename T> class Queue{
	private:
		LinkedList<T> queue;
	public:
		/**
		 * @return Size of queue
		*/
		int size(){
			return queue.size();
		}
		/**
		 * @return Boolean whether queue is empty or not
		*/
		bool empty(){
			return queue.empty();
		}
		/**
		 * @param value Enqueue the value to the end of the list
		*/
		void enqueue(T value){
			queue.push_back(value);
		}	
		/**
		 * @return Pop the latest value and return to it
		*/
		T dequeue(){
			return queue.pop_back();
		}
		/**
		 * Print the queue
		*/
		void print(){
			queue.print();
		}
};

// Driver Code
int main(){
	Queue<int> queue;
	cout << "Size: " << queue.size() << endl;
	cout << "Empty: " << queue.empty() << endl;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);
	cout << "Size: " << queue.size() << endl;
	cout << "Empty: " << queue.empty() << endl;
	queue.print();
	cout << endl;
	cout << "Dequeued: " << queue.dequeue() << endl;
	cout << "Dequeued: " << queue.dequeue() << endl;
	queue.print();
	return 0;
}