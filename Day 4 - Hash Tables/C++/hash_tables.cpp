#include <iostream>
#include "arrays.h"

using namespace std;
template<typename K, typename V> class HashTable{
	private:
		Array<K> keys;
		Array<V> values;
	public:
		void add(K key, V value){
			if(keys.exists(key)){
				int index = keys.find(key);
				values.overwrite(index, value);
				return;
			}
			keys.push(key);
			values.push(value);	
		}
		bool exists(K key){
			return keys.exists(key);
		}
		V get(K key){
			if(keys.exists(key)){
				int index = keys.find(key);
				return values.at(index);
			}
			return '\0';
		}
		void remove(K key){
			if(keys.exists(key)){
				int index = keys.find(key);
				keys.deleteElement(index);
				values.deleteElement(index);
			}
		}
		void print(){
			cout << "{" << endl;
			for(int i = 0; i < keys.size(); i++){
				bool append_comma = keys.size() - 1 != i;
				if(append_comma)
					cout << "  {" << keys.at(i) << ":" << values.at(i) << "}," << endl;
				else
					cout << "  {" << keys.at(i) << ":" << values.at(i) << "}" << endl;
			}
			cout << "}" << endl;
		}
};

int main(){
	HashTable<string, string> hash_table;
	hash_table.add("username", "Dev-Mehta");
	hash_table.add("password", "mehta@007");
	hash_table.print();
	return 0;
}