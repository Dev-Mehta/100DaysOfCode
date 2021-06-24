/**
 * Task: To implement linked list with given requirements
 * 
 * Requirements:
 * size() - returns number of data elements in list
 * empty() - bool returns true if empty
 * value_at(index) - returns the value of the nth item (starting at 0 for first)
 * push_front(value) - adds an item to the front of the list
 * pop_front() - remove front item and return its value
 * push_back(value) - adds an item at the end
 * pop_back() - removes end item and returns its value
 * front() - get value of front item
 * back() - get value of end item
 * insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
 * erase(index) - removes node at given index
 * value_n_from_end(n) - returns the value of the node at nth position from the end of the list
 * reverse() - reverses the list
 * remove_value(value) - removes the first item in the list with this value
*/

#include <iostream>

using namespace std;

template <typename T> struct Node {
	T data;
	struct Node<T> *next;
};

template <typename T> class LinkedList {
	private:
		struct Node<T> *head = NULL;
		int element_count;
	public:
		LinkedList(){
			element_count = 0;
		}
		/**
		 * @return Return the size of array
		*/
		int size() {
			return element_count;
		}
		/**
		 * @return Whether the array is empty or not
		*/
		bool empty() {
			return element_count == 0;
		}
		/**
		 * @param value Value to insert at front of linked list
		*/
		void push_front(T value) {
			struct Node<T> *new_node = new Node<T>();
			new_node->data = value;
			new_node->next = head;
			head = new_node;
			element_count++;
		}
		/**
		 * @param value Value to insert at back of linked list
		*/
		void push_back(T value) {
			struct Node<T> *new_node = new Node<T>();
			new_node->data = value;
			new_node->next = NULL;
			if (empty()) {
				head = new_node;
				element_count++;
				return;
			}
			struct Node<T> *temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = new_node;
			element_count++;
		}
		/**
		 * @return Removes the first element of linked list and return it
		*/
		T pop_front() {
			if(empty()) {
				cout << "Underflow" << endl;
				return '\0';
			}
			struct Node<T> *new_node = head;
			T data = new_node->data;
			head = new_node->next;
			delete new_node;
			element_count--;
			return data;
		}
		/**
		 * @return Removes the last element of list and returns it
		*/
		T pop_back() {
			if (empty()) {
				cout << "Underflow" << endl;
				T data = '\0';
				return data;
			}
			else if (head->next == NULL) {
				T data = head->data;
				struct Node<T> *new_node = head;
				head = NULL;
				delete new_node;
				element_count--;
				return data;
			}
			else {
				struct Node<T> *temp = head;
				struct Node<T> *new_node = NULL;
				while (temp->next != NULL) {
					new_node = temp;
					temp = temp->next;
				}
				element_count--;
				new_node->next = NULL;
				T data = temp->data;
				delete temp;
				return data;
			}
		}
		/**
		 * @return Return the first element of list
		*/
		T front() {
			if(empty()) {
				cout << "Underflow" << endl;
				return '\0';
			}
			return head->data;
		}
		/**
		 * @return Return the last element of list
		*/
		T back() {
			if(empty()) {
				cout << "Underflow" << endl;
				return '\0';
			}
			struct Node<T> *temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			return temp->data;
		}
		/**
		 * @param index The position to insert the element
		 * @param value The value to insert at the given index
		*/
		void insert(int index, T value){
			if (head == NULL || index > element_count - 1 || index < 0){
				return;
			}
			else if (index == element_count - 1){
				push_back(value);
				return;
			}
			else if(index == 0){
				push_front(value);
				return;
			}
			struct Node<T> *n = new Node<T>();
			n->data = value;
			struct Node<T> *c=new Node<T>();
			int count=1;
			c=head;
			while(count!=index)
			{
				c=c->next;
				count++;
			}
			n->next=c->next;
			c->next=n;
			element_count++;
		}
		/**
		 * @param index The position of element to erase
		*/
		void erase(int index) {
			if (head == NULL || index > element_count - 1 || index < 0) {
				return;
			}
			else if (index == element_count - 1) {
				pop_back();
			}
			else if(index == 0){
				pop_front();
			}
			else {
				struct Node<T> *temp = head;
				struct Node<T> *temp2;
				for (int i = 0; i < index; i++) {
					temp2 = temp;
					temp = temp->next;
				}
				temp2->next = temp->next;
				delete temp;
				element_count--;
			}
		}
		/**
		 * @param index The position of nth element to fetch from end
		 * @return Returns the nth element from back
		*/
		T value_n_from_end(int index) {
			struct Node<T> *main_ptr = head;
			struct Node<T> *ref_ptr = head;
			int count = 0;
			if(head == NULL ||index > element_count - 1 || index < 0){
				return '\0';
			}
			while( count < index ){
				ref_ptr = ref_ptr->next;
				count++;
			}
			while(ref_ptr != NULL){
				main_ptr = main_ptr->next;
				ref_ptr = ref_ptr->next;
			}
			return main_ptr -> data;
		}
		/**
		 * @param value Value to search and remove
		*/
		void remove_value(T value){
			if(empty()){
				return;
			}
			struct Node<T> *temp = head;
			int i = 0;
			while(temp != NULL){
				if(temp->data == value){
					erase(i);
					break;
				}
				i++;
				temp = temp->next;
			}
		}
		/**
		 * To print the whole linked list
		*/
		void print(){
			if(empty()){
				cout << "Underflow";
				return;
			}
			struct Node<T> *temp = head;
			while(temp != NULL){
				cout << temp -> data << "-->";
				temp = temp->next;
			}
		}
		/**
		 * @param headRev To reverse the linked list from given node
		*/
		Node<T>* reverseFromHead(Node<T> *headRev){
			if(headRev == NULL || headRev->next == NULL){
				return headRev;
			}
			Node<T> *rest = reverseFromHead(headRev->next);
			headRev->next->next = headRev;
			headRev->next = NULL;
			return rest;
		}
		/**
		 * Method to reverse the complete linked list
		*/
		void reverse(){
			head = reverseFromHead(head);
		}
};

// Driver Code
int main(){
	LinkedList<int> linked_list;
	cout << "Empty: " << linked_list.empty() << endl;
	cout << "Size: " << linked_list.size() << endl;
	linked_list.push_back(2);
	linked_list.push_back(3);
	linked_list.push_back(4);
	linked_list.push_back(5);
	linked_list.push_back(6);
	linked_list.push_front(1);
	cout << "ll[0]: " << linked_list.pop_front() << endl;
	cout << "ll[4]: " << linked_list.pop_back() << endl;
	linked_list.insert(0,1);
	linked_list.insert(1,2);
	linked_list.remove_value(2);
	linked_list.erase(1);
	linked_list.insert(1,2);
	linked_list.remove_value(3);
	linked_list.insert(2,3);
	cout << "Front: " << linked_list.front() << endl;
	cout << "Back: " << linked_list.back() << endl;
	linked_list.print();
	linked_list.reverse();
	cout << endl << "Reversed: " << endl;
	linked_list.print();
	return 0;
}