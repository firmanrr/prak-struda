#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//deklarasi struktur node
struct Node{
	string nama;
	Node * nextNode;
};

//method push tambah tumpukan
void push(string nama);

//method pop keluarkan tumpukan
void pop();
void cetakList();

//deklarasi stack sebagai head
Node *stack;

int main(){
	
	string nama1 = "Arifudding";
	string nama2 = "Salma";
	string nama3 = "Joko";
	
	cetakList();
	push(nama1);
	cetakList();
	push(nama2);
	cetakList();
	push(nama3);
	cetakList();
	
	pop();
	cetakList();
	pop();
	cetakList();
	
	cout <<endl;
	
	system("pause");
	return 0;
}

void push(string nama){
	Node * newNodePtr = new Node;
	newNodePtr -> nama = nama;
	newNodePtr -> nextNode = NULL;
	if(stack == NULL){
		stack = newNodePtr;
	}else{
		Node *prevHeadPtr = stack;
		stack = newNodePtr;
		newNodePtr -> nextNode = prevHeadPtr;
	}
}


void pop(){
	if(stack == NULL){
		cout << "Stack kosong \n\n";
	}else{
		Node * delNodePtr = stack;
		stack = delNodePtr -> nextNode;
		cout <<"Mengeluarkan data:"
				<< delNodePtr -> nama <<endl;
				delete delNodePtr;
	}
}

void cetakList(){
	int i = 0;
	cout << "Berikut daftar mahasiswa dalam Stack: \n";
	if(stack == NULL){
		cout << "Stack kosong!\n\n";
	}else{
		Node *p = stack;
		while(p != NULL){
		i++;
		cout << i << ". "
			<< p->nama << "." << endl;
		p = p->nextNode;
		}	
	cout << endl << endl;
	}
}
