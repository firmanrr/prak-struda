#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
    int data, p;
    Node *next;

    struct Node *f = NULL;
    struct Node *r = NULL;

    void enqueue(int d, int pr)
    {
        Node *tmp, *q;
        tmp = new Node;
        tmp->data = d;
        tmp->p = pr;
        if (r == NULL || pr > r->p)
        {
            tmp->next = r;
            r = tmp;
        }
        else
        {
            q = r;
            while (q->next != NULL && q->next->p >= pr)
            q = q->next;
            tmp->next = q->next;
            q->next = tmp;
        }
    }

    void display()
    {
        Node *temp = r;
        while (temp != NULL)
        {
            cout << "\tNO PASIAN : " << temp->data << " TINGKATAN PENYAKIT : " << temp->p << endl;
            temp = temp->next;
        }
    }

    void dequeue()
    {
        Node *temp = new Node;
        if (r == NULL)
        {
            cout << "ANTRIAN KOSONG\n";
            return;
        }

        else
        {
            temp = r;
            r = r->next;
            cout << "\n\t----------------------------------------";
            cout << "\n\tMEMANGGIL PASIEN: " << temp->data << " \nDIPRIORITASKAN KARENA PENYAKIT " << temp->p;
            cout << "\n\t----------------------------------------\n";
            free(temp);
        }
    }
};

int main()
{

    Node x;
    int  qprior, choice, number;
    do
    {
        system("cls");
        cout << "==== MENU ======" << endl;
        cout << "[1].ENQUEUE " << endl;
        cout << "[2].DISPLAY " << endl;
        cout << "[3].DEQUEU " << endl;
        cout << "[4].EXIT " << endl;
        cout << "================ " << endl;
        cout << "PILIH : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "MASUKKAN NOMER PASIEN : ";
            cin >> number;
            cout << "TINGKAT PENYAKIT: ";
            cin >> qprior;
            x.enqueue(number, qprior);
            cout << "KLIK UNTUK MELANJUTKAN ";
            break;
        case 2:
            x.display();
            cout << "KLIK UNTUK MELANJUTKAN ";
            break;
        case 3:
            x.dequeue();
            cout << "KLIK UNTUK MELANJUTKAN ";
            break;
        default:
            cout << "PILIHAN TIDAK ADA " << endl;
            cout << "KLIK UNTUK MELANJUTKAN ";
            break;
        }
        getch();
    } while (choice != 4);

    return 0;
}


