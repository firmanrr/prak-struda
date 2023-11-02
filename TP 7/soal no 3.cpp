#include <iostream>
using namespace std;

struct Node
{
    int data, p;
    Node *next;
};

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
        cout << "\tNO PASIAN : " << temp->data << " STADIUM : " << temp->p << endl;
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
        cout << "\n\tMEMANGGIL PASIEN: " << temp->data << " \nDIPRIORITASKAN KARENA STADIUM " << temp->p;
        cout << "\n\t----------------------------------------\n";
        free(temp);
    }
}

int main()
{

    int qdata, qprior, choice, numberOfElements;

    cout << "\n\t\t_________OPERATE PRIORITY DEQUEU_________\n\n";
    cout << "\t1. QUEUE.\n\t2. Display.\n\t3. DEQUEU ELEMEN TERBESAR\n\t0. Exit\n\n";
    do
    {
        cout << "\n\tPILIH[0-3] : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n\tMASUKKAN NOMER PASIEN : ";
            cin >> numberOfElements;
            cout << "\n\tPRIOTAS: ";
            cin >> qprior;
            enqueue(numberOfElements, qprior);
            break;

        case 2:
            cout << "\t_____________________\n\n";
            display();
            cout << "\t_____________________\n";
            cout << "\n\n";
            break;

        case 3:
            dequeue();
            break;

        default:
            cout << "\nEXIT \n\n";
            break;
        }

    } while (choice != 0);

    return 0;
}

