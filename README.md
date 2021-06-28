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
    - [x] Java
    - [x] Python
- ###  [Day 3 - Queues](Day%203%20-%20Queues/)
  - [x] Implement the queue with given requirements in:
    - [x] C++
- ### [Day 4 - Hash Tables](Day%204%20-%20Hash%20Tables/)
  - [x] Implement the hash table with given requirements in:
    - [x] C++
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

- ### Queue
    - [x] [Queue (video)](https://www.coursera.org/lecture/data-structures/queues-EShpq)
    - [x] [Circular buffer/FIFO](https://en.wikipedia.org/wiki/Circular_buffer)
    - [x] Implement using linked-list, with tail pointer:
        - enqueue(value) - adds value at position at tail
        - dequeue() - returns value and removes least recently added element (front)
        - empty()
    - [x] Implement using fixed-sized array:
        - enqueue(value) - adds item at end of available storage
        - dequeue() - returns value and removes least recently added element
        - empty()
        - full()
    - [x] Cost:
        - a bad implementation using linked list where you enqueue at head and dequeue at tail would be O(n)
            because you'd need the next to last element, causing a full traversal each dequeue
        - enqueue: O(1) (amortized, linked list and array [probing])
        - dequeue: O(1) (linked list and array)
        - empty: O(1) (linked list and array)
- ### Hash table
    - [x] Videos:
        - [x] [Hashing with Chaining (video)](https://www.youtube.com/watch?v=0M_kIqhwbFo&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=8)
        - [x] [Table Doubling, Karp-Rabin (video)](https://www.youtube.com/watch?v=BRO7mVIFt08&index=9&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
        - [x] [Open Addressing, Cryptographic Hashing (video)](https://www.youtube.com/watch?v=rvdJDijO2Ro&index=10&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
        - [x] [PyCon 2010: The Mighty Dictionary (video)](https://www.youtube.com/watch?v=C4Kc8xzcA68)
        - [x] [(Advanced) Randomization: Universal & Perfect Hashing (video)](https://www.youtube.com/watch?v=z0lJ2k0sl1g&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=11)
        - [x] [(Advanced) Perfect hashing (video)](https://www.youtube.com/watch?v=N0COwN14gt0&list=PL2B4EEwhKD-NbwZ4ezj7gyc_3yNrojKM9&index=4)

    - [x] Online Courses:
        - [x] [Core Hash Tables (video)](https://www.coursera.org/lecture/data-structures-optimizing-performance/core-hash-tables-m7UuP)
        - [x] [Data Structures (video)](https://www.coursera.org/learn/data-structures/home/week/4)
        - [x] [Phone Book Problem (video)](https://www.coursera.org/lecture/data-structures/phone-book-problem-NYZZP)
        - [x] distributed hash tables:
            - [Instant Uploads And Storage Optimization In Dropbox (video)](https://www.coursera.org/lecture/data-structures/instant-uploads-and-storage-optimization-in-dropbox-DvaIb)
            - [Distributed Hash Tables (video)](https://www.coursera.org/lecture/data-structures/distributed-hash-tables-tvH8H)

    - [x] Implement with array using linear probing
        - hash(k, m) - m is size of hash table
        - add(key, value) - if key already exists, update value
        - exists(key)
        - get(key)
        - remove(key)