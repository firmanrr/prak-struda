#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct dataMahasiswa
{
    string nama;
    string nim;

    dataMahasiswa *next;
    dataMahasiswa *prev;
};

dataMahasiswa *head, *tail, *cur, *newNode, *del;

void createNewdata(string name, string nomerIndukmahasiswa)
{

    head = new dataMahasiswa();
    head->nama = name;
    head->nim = nomerIndukmahasiswa;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}
void addFirstdata(string name, string nomerIndukmahasiswa)
{
    if (head == NULL)
        createNewdata(name, nomerIndukmahasiswa);
    else
    {
        newNode = new dataMahasiswa();
        newNode->nama = name;
        newNode->nim = nomerIndukmahasiswa;
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void addLast(string name, string nomerIndukmahasiswa)
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat!!!";
    }
    else
    {
        newNode = new dataMahasiswa();
        newNode->nama = name;
        newNode->nim = nomerIndukmahasiswa;
        newNode->prev = tail;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
}
void removeFirst()
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat!!!";
    }
    else
    {
        del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
    }
}

void removeAwal(){

    if(head == NULL){

        cout << "Masukan Data Dahulu" << endl;

    }else{

        del = head;
        head = head -> next;
        head -> prev = NULL;
        delete del;

    }

}
void printData()
{

    if (head == NULL)
    {
        cout << "Tambahkan Data Dahulu" << endl;
    }
    else
    {
        cur = head;
        cout << "=============================" << endl;
        while (cur != NULL)
        {
            cout << "= Nama  : " << cur->nama << endl;
            cout << "= Nim   : " << cur->nim << endl;
            cout << "=============================" << endl;

            cur = cur->next;
        }
    }
}
void removeAkhir(){

    if (head == NULL)
    {
        cout << "Masukan Data Dahulu" << endl;
    }
    else
    {
        del = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete del;
    }

}
int main()
{

    int pilih;
    string nama, nim;
    do
    {
        system("cls");
        cout << "=====================" <<endl;
        cout << "=       MENU        =" << endl;
        cout << "= 1.INPUT DEPAN     =" << endl;
        cout << "= 2.HAPUS DEPAN     =" << endl;
        cout << "= 3.INPUT BELAKANG  =" << endl;
        cout << "= 4.HAPUS BELAKANG  =" << endl;
        cout << "= 5.LIHAT DATA      =" << endl;
        cout << "= 6.EXIT            =" << endl;
        cout << "===================== " << endl;
        cout << "PILIH : ";
        cin >> pilih;
        switch (pilih)
        {
		case 1:
            cout << "Masukan Nama : "; cin >> nama;
            cout << "Masukan NIM  : "; cin >> nim;
            cout <<endl;
            addFirstdata(nama, nim);
            cout << "Data Ditambahkan" << endl;
            cout << "Klik Untuk Lanjut";
            break;
        case 2:
            removeAwal();
            cout << "Data Berhasil Dihapus" << endl;
            cout << "Klik Untuk Lanjut ";
            break;
        case 3:
        	cout << "Masukan Nama : "; cin >> nama;
            cout << "Masukan NIM  : "; cin >> nim;
            cout <<endl;
            addLast(nama, nim);
             cout << "Klik Untuk Lanjut";
            break;
        case 4:
            removeAkhir();
            cout << "Data Berhasil Dihapus" << endl;
            cout << "Klik Untuk Lanjut ";
            break;
        case 5:
            printData();
            cout << "Klik Untuk Lanjut";
            break;
        default:
            cout << "Selesai..... " << endl;
            break;
        }
        getch();
        
    } while (pilih !=6);
}
