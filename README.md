# Data Structures and Algorithms Daily Practice
> This is just my archive repository where I practice coding custom vector classes and other more data structure using this [study plan](https://github.com/jwasham/coding-interview-university).

## Timeline
- ### [Day 1 - Arrays](Day%201%20-%20Arrays/)
 - [x] Implement an automatically resizing vector in :
 	- [x] C++
 	- [x] Java
 	- [x] Python
 - ### [Day 2 - Linked Lists](Day%202%20-%20Linked%20Lists/)
  - [x] Implement the linked lists with given requirements in:
    - [x] C++
    - [ ] Java
    - [ ] Python

## Data Structures

- ### Arrays
    - Implement an automatically resizing vector.
    - [x] Implement a vector (mutable array with automatic resizing):
        - [x] size() - number of items
        - [x] capacity() - number of items it can hold
        - [x] is_empty()
        - [x] at(index) - returns item at given index, blows up if index out of bounds
        - [x] push(item)
        - [x] insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
        - [x] prepend(item) - can use insert above at index 0
        - [x] pop() - remove from end, return value
        - [x] delete(index) - delete item at index, shifting all trailing elements left
        - [x] remove(item) - looks for value and removes index holding it (even if in multiple places)
        - [x] find(item) - looks for value and returns first index with that value, -1 if not found
        - [x] resize(new_capacity) // private function
            - when you reach capacity, resize to double the size
            - when popping an item, if size is 1/4 of capacity, resize to half
    - [x] Time
        - O(1) to add/remove at end (amortized for allocations for more space), index, or update
        - O(n) to insert/remove elsewhere
    - [x] Space
        - contiguous in memory, so proximity helps performance
        - space needed = (array capacity, which is >= n) * size of item, but even if 2n, still O(n)
- ### Linked Lists
    - [x] Implement (I did with tail pointer & without):
        - [x] size() - returns number of data elements in list
        - [x] empty() - bool returns true if empty
        - [x] value_at(index) - returns the value of the nth item (starting at 0 for first)
        - [x] push_front(value) - adds an item to the front of the list
        - [x] pop_front() - remove front item and return its value
        - [x] push_back(value) - adds an item at the end
        - [x] pop_back() - removes end item and returns its value
        - [x] front() - get value of front item
        - [x] back() - get value of end item
        - [x] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
        - [x] erase(index) - removes node at given index
        - [x] value_n_from_end(n) - returns the value of the node at nth position from the end of the list
        - [x] reverse() - reverses the list
        - [x] remove_value(value) - removes the first item in the list with this value