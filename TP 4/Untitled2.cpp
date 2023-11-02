#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
char data;
struct node *next;
struct node *prev;
};
typedef struct node node;
node *head, *tail;
int choice;
char item;int count = 0;
int keluar = 0;
void initial()
{
head = tail = NULL;
}
int isEmpty()
{
if (tail == NULL)
return 1;
else
return 0;
}
void enqueue(char item)
{
node *baru = new node;
baru->data = item;
baru->next = baru;
baru->prev = baru;
if (isEmpty() == 1)
{
head = tail = baru;
head->next = head;
head->prev = head;
tail->next = tail;
tail->prev = tail;
}
else{
baru->next = head;
head->prev = baru;
head = baru;
head->prev = tail;
head->next = head;
}
cout << "\n# Queue : No urut/index : " << count << ", Value :"
<< item;
count++;
}
void dequeue()
{
if (isEmpty() == 0)
{
if (head->next != tail)
{
node *hapus = tail;
tail = tail->prev;
tail->next = head;
head->prev = tail;
delete hapus;
cout << "\n##Dequeue result:" << item;
cout << "\n##jumlah item dalam queue : " << count;
--count;
}
else
{
head = tail = NULL;}
}
else
{
cout << "\n## Queue kosong";
}
}
void printAll()
{
cout << "\n## Queue Size : " << count;
node *temp = head;
int i = 0;
if (isEmpty() == 0)
{
do
{
cout << "\n## No Urut/index : " << i << ", Value :" << temp-
>data;
temp = temp->next;
i++;
} while (temp != head);
}
else
{
cout << "List Kosong.";
}
}
void menu(){
cout << "\nMasukkan operasi yang akan dilakukan (1:enqueue,
2:dequeue, 3:print) : ";
cin >> choice;
switch (choice)
{
case 1:
{
cout << "\nMasukkan huruf yang akan dimasukkan dalam
queue : ";
cin >> item;
enqueue(item);
break;
}
case 2:
dequeue();
break;
case 3:
printAll();
break;
default:
cout << "\n1:enqueue, 2:dequeue, 3:print\n";
keluar = 1;
break;
}
}
int main()
{
initial();do
{
menu();
} while (keluar == 0);
}

