#include <iostream>
#include <list>
using namespace std;

int main(){
	list<int> mylist;
	list<int>::iterator it;

	for(int i = 1; i<6; i++){
		mylist.push_front(i);
	};
	mylist.push_front(10);

	mylist.push_back(7);

	it = mylist.end();

    cout << endl;
     
    for( it = mylist.begin(); it != mylist.end(); it++){
    	cout << *it <<" ";
	}


}
