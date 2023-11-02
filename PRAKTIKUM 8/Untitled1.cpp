#include <iostream>
#include <string>
using namespace std;

struct HashTable{
	string alamat[100];

	void insert(string key, string value){
		int index = hashFunction(key);
		alamat[index] = value;
	}

	string getData(string key){
		int index = hashFunction(key);
		return alamat[index];
	}

	int hashFunction(string key){
		return key.length();
	}
};

int main(){
	HashTable hashTable;
	
	hashTable.insert("Acox","Jl. Toddopuli 4 No 2");
	hashTable.insert("Wawan","Jl. Perintis Kemerdekaan VII No 14");
	hashTable.insert("Takass","Republik kokbang");

	cout << "\nAlamat Acox   : " << hashTable.getData("Acox");
	cout << "\nAlamat Wawan  : " << hashTable.getData("Wawan");
	cout << "\nAlamat Takass : " << hashTable.getData("Takass");
	
	cout << endl;
	system("pause");
	return 0;
}
