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
Node *tail, * cur;


int hitungdata(){
    if(head == NULL){
        return 0;
    }else{
        int banyak =0;
        cur = head;
        while(cur != NULL){
            cur = cur ->nextNode;
            banyak++;
        }
        return banyak;

    }
}

int maksimal = 4;
bool isFull(){ 
    if(hitungdata()== maksimal){
        return true;
    }else{
        return false;
    }
}
int main(){
    int pil;
    while (true){
        cout << "================" << endl;
        cout << "= 1. Enqueue   =" << endl;
        cout << "= 2. Dequeue   =" << endl;
        cout << "= 3. Cetak     =" << endl;
        cout << "================" << endl;
        cout << "Pilih : ";
        cin >> pil;

        string input;
        if(pil == 1){
            cout << "Masukan nama :";
            cin >> input;
            enqueue(input);
        }else if(pil == 2){
            // cout << "Menghapus : " << head->nama;
            dequeue();
        }
        else if(pil == 3){
            cetakQueue();
        }


        system("pause");
        system("cls");
    }
    

    system("pause");
    return 0;

}
// add node as new tail
void enqueue(string nama){
    if(isFull()){
        cout << "Data Penuh" << endl;
    }else{
        Node * newQueueNode = new Node;
        newQueueNode->nama = nama;
        newQueueNode->nextNode = NULL;
        newQueueNode->prevNode = NULL;
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
}

//Antrian keluar dari head
void dequeue(){
    if(head == NULL){
        cout << "Data kosong!\n\n";
    }else{
        Node * delQueueNode = head;
        head = delQueueNode->nextNode;
        cout << "Memproses antrian keluar:" << delQueueNode->nama << endl;
        delete delQueueNode;
    }
}

void cetakQueue(){
    int i = 0;
    cout << "Berikut daftar mahasiswa yang masuk: \n";
    if(head == NULL){
        cout << "Data tidak ada!\n\n";
    }else{
        Node *p = head;
        while(p != NULL){
            i++;
            cout << i << ". "<< p->nama << "." << endl;
            p = p->nextNode;
        }
        cout << endl <<endl;
	}	
}
