#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//deklarasi struktur node
struct Node{
	string nama;
	Node * nextNode;
	Node * prevNode;
};

//method enqueue tambah antrian
void enqueue(string nama);
//method dequeue keluarkan antrian
void dequeue();
void cetakQueue();

//deklarasi queue dengan head dan tail
Node *head;
Node *tail;


int main(){

	string nama1 = "Arifudding";
	string nama2 = "Salma Roshidin";
	string nama3 = "Joko Subando";
	
	cetakQueue();
	enqueue(nama1);
	cetakQueue();
	enqueue(nama2);
	cetakQueue();
	enqueue(nama3);
	cetakQueue();

	dequeue();
	cetakQueue();
	dequeue();
	cetakQueue();
	enqueue("Sugeng Yellor");
	cetakQueue();
	enqueue("Budi Sumantri");
	cetakQueue();
	dequeue();
	cetakQueue();
	dequeue();
	cetakQueue();
	
	cout << endl;

	system("pause");
	return 0;
}

// add node as new tail
void enqueue(string nama){
	Node * newQueueNode = new Node;
	newQueueNode->nama = nama;
	newQueueNode->nextNode =NULL;
	newQueueNode->prevNode =NULL;
	if(head == NULL){
		head = newQueueNode;
		tail = NULL;
	}else if(tail == NULL){
		tail = newQueueNode;
		head->nextNode = tail;
		tail->prevNode = head;
	}else{
		Node *prevTailNode = tail;
		tail = newQueueNode;
		prevTailNode->nextNode = tail;
		tail->prevNode = prevTailNode;
	}
}

//Antrian keluar dari head
void dequeue(){

	if(head == NULL){
		cout << "Queue kosong!\n\n";
	}else{
		Node * delQueueNode = head;
		head = delQueueNode->nextNode;
		cout << "Memproses antrian keluar:"
			<< delQueueNode->nama << endl;
		delete delQueueNode;
	}
}

void cetakQueue(){
	int i = 0;
	cout << "Berikut daftar mahasiswa dalam Queue: \n";
	if(head == NULL){
		cout << "Queue kosong!\n\n";
	}else{
		Node *p = head;
		while(p != NULL){
			i++;
			cout << i << ". "
				<< p->nama << "." << endl;
			p = p->nextNode;
		}
	cout << endl << endl;
	}
}
