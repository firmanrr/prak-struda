#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

struct Node
{
    string nama, namaDokter, rekamMedis;
    Node *nextNode;
    Node *prevNode;
};

void isFull();
void enqueue(string nm, string nDokter, string rMedis);
void dequeue();
void cetakQueue();

int k = 1;
bool otomatis = true;

Node *head, *tail;

int main()
{
int pilih;
    do
    {
        system("cls");
        cout << "======= MENU =======" << endl;
        cout << "= 1.AMBIL ANTRIAN  =" << endl;
        cout << "= 2.PANGGIL PASIEN =" << endl;
        cout << "= 3.LIHAT ANTRIAN  =" << endl;
        cout << "= 4.EXIT           =" << endl;
        cout << "====================" << endl;
        cout << "PILIH : ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            isFull();
            cout << "KLIK UNTUK MELANJUTKAN ";
            break;
        case 2:
            dequeue();
            k--;
            cout << "KLIK UNTUK MELANJUTKAN ";
            break;
        case 3:
            cetakQueue();
            cout << "KLIK UNTUK MELANJUTKAN ";
            break;
 default:
            cout << "PILIHAN TIDAK ADA " << endl;
            cout << "KLIK UNTUK MELANJUTKAN ";
            break;
        }
        getch();
    } while (pilih != 4);
    system("pause");
    return 0;
}

void isFull()
{

    string nama, rMedis, nDokter;
    if (k == 3)
    {
        cout << "ANTRIAN FULL" << endl;
    }
    else
    {
        cout << "MASUKKAN NAMA        : ";
        cin >> nama;
        cout << "MASUKKAN REKAM MEDIS : ";
        cin >> rMedis;
        if (otomatis)
        {
 nDokter = "Yuan Lisna ";
            otomatis = false;
        }
        else
        {
            nDokter = "Alex Jane";
            otomatis = true;
        }

        enqueue(nama, nDokter, rMedis);
        k++;
    }
}


void enqueue(string nm, string nDokter, string rMedis)
{
    Node *newQueueNode = new Node;
    newQueueNode->nama = nm;
    newQueueNode->namaDokter = nDokter;
    newQueueNode->rekamMedis = rMedis;
    newQueueNode->nextNode = NULL;
    newQueueNode->prevNode = NULL;
    if (head == NULL)
    {
        head = newQueueNode;
        tail = NULL;
    }
else if (tail == NULL)
    {
        tail = newQueueNode;
        head->nextNode = tail;
        tail->prevNode = head;
    }
    else
    {
        Node *prevTailNode = tail;
        tail = newQueueNode;
        prevTailNode->nextNode = tail;
        tail->prevNode = prevTailNode;
    }
}
void dequeue()
{
    if (head == NULL)
    {
        cout << "ANTRIAN KOSONG, SILAHKAN AMBIL ANTRIAN!\n\n";
    }
    else
    {
        Node *delQueueNode = head;
        head = delQueueNode->nextNode;
        cout << "MEMANGGIL ANTRIAN :"
             << delQueueNode->nama << endl;
        delete delQueueNode;
    }
}
void cetakQueue()
{
    int i = 0;
    cout << "ANTRIAN PASIEN : \n";
    if (head == NULL)
    {
        cout << "ANTRIAN KOSONG!\n\n";
    }
    else
    {
        cout << "NO. ANTRIAN  |\tNAMA PASIEN  |\tREKAM MEDIS  |\tNAMA DOKTER" << endl;
        Node *p = head;
        while (p != NULL)
        {
            i++;
            cout << "    " << i << "\t\t" << p->nama << "\t\t" << p->rekamMedis << "\t\t" << p->namaDokter << endl;
            p = p->nextNode;
        }
        cout << endl
             <<endl;
	}
}
