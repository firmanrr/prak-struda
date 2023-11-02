#include <iostream>
#include <list>

using namespace std;
int main()
{

//deklarasi list
list<int> myList;
//list<int>::iterator it;

//menambah data dalam list
	for(int i=1; i<6; i++){
	myList.push_front(i);
	}
	cout <<"Size = "<<myList.size() <<endl;
	list<int>::iterator it = myList.begin();
	it = myList.begin();
	
	cout <<endl;
	while (it != myList.end()){
		cout << "it"<<" ";
		it++;
	}
}
