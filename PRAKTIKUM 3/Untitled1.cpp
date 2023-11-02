#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Node{
	string nama;
	Node * nextNode;
};


void addNode(string nama);
void cetakList();

//deklarasi head
Node *head;

int main(){
	
	string nama1 = "Firman";
	string nama2 = "Reski";
	string nama3 = "Ramadhan";
	
	cetakList();
	addNode(nama1);
	cetakList();
	addNode(nama2);
	cetakList();
	addNode(nama3);
	cetakList();
	
	cout<<endl;
	system("pause");
	return 0;
	
}

void addNode(string nama){
	Node * newNodePtr = new Node;
	newNodePtr->nama = nama;
	newNodePtr->nextNode = NULL;
	if(head == NULL){
		head = newNodePtr;
	}else{
		Node *prevHeadPtr = head;
		head = newNodePtr;
		newNodePtr->nextNode = prevHeadPtr;
	}
}

void cetakList(){
	int i = 0;
	cout <<"Berikut daftar mahasiswa dalam list: \n";
	if(head == NULL){
		cout <<"List kosong\n\n";
	}else{
		Node *p = head;
		while(p != NULL){
			i++;
			cout << i << ". "
					<<p->nama << "."<<endl;
			p = p->nextNode;
		}
		cout <<endl<<endl;
	}

}
