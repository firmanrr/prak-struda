#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct node
{
    string namaM;
    int nim;
    struct node *link;
};

class Priority_Queue
{
private:
    node *front;

public:
    Priority_Queue()
    {
        front = NULL;
    }

    void insert(string nama, int nimm)
    {
        node *tmp, *q;
        tmp = new node;
        tmp->namaM = nama;
        tmp->nim = nimm;
        if (front == NULL || nimm > front->nim)
        {
            tmp->link = front;
            front = tmp;
        }
        else
        {
            q = front;
            while (q->link != NULL && q->link->nim >= nimm)
                q = q->link;
            tmp->link = q->link;
            q->link = tmp;
        }
    }

    void del()
    {
        node *tmp;
        if (front == NULL)
            cout << "ANTRIAN KOSONG\n";
        else
        {
            tmp = front;
            cout << "MENGELUARKAN : " << tmp->namaM << endl;
            front = front->link;
            free(tmp);
        }
    }

    void display()
    {
        node *ptr;
        ptr = front;
        if (front == NULL)
            cout << "ANTRIAN KOSONG\n";
        else
        {
            cout << "ANTRIAN :\n";
            cout << "=====================" << endl;
            cout << "NIM            NAMA\n";
            cout << "=====================" << endl;
            while (ptr != NULL)
            {
                cout << ptr->nim << "                 " << ptr->namaM << endl;
                ptr = ptr->link;
            }
        }
    }
};

int main()
{
    int choice, nim;
    string nama;
    Priority_Queue pq;
    do
    {
        cout << "=====================" << endl;
        cout << "1.QUEUE\n";
        cout << "2.DEQUE\n";
        cout << "3.DISPLAY\n";
        cout << "4.Quit\n";
        cout << "=====================" << endl;
        cout << "PILIH[1-4] : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "MASUKKAN NAMA : ";
            cin >> nama;
            cout << "MASUKKAN NIM  : ";
            cin >> nim;
            pq.insert(nama, nim);
            break;
        case 2:
            pq.del();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            break;
        default:
            cout << "PILIHAN TIDAK ADA\n";
        }
    } while (choice != 4);
    return 0;
}

