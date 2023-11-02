#include <iostream>
#include <iterator> 
#include <list>
using namespace std;
int main(){

	list<int> angka;
	for (int i = 1; i <= 9; ++i){
	angka.push_back(i);
	}

	list<int>::iterator it;

	for (it = angka.begin(); 
	it != angka.end(); ++it){ 
	cout << *it << " ";
	} 
	cout << endl;

	for (auto it = rbegin(angka); it != rend(angka); it++);
	{
	cout << *it << " ";
	} cout << endl;
	system("pause");
	return 0;
}

