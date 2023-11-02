#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
int data;
struct Node *prev;
struct Node *next;
};
Node *start = NULL;
Node *top = NULL;
// Check if stack is empty
bool isEmpty()
{
if (start == NULL)
return true;
return false;}
// pushes element onto stack
void push(int d)
{
struct Node *n;
n = new Node();
n->data = d;
if (isEmpty())
{
n->prev = NULL;
n->next = NULL;
// As it is first node if stack
// is empty
start = n;
top = n;
}
else
{
top->next = n;
n->next = NULL;
n->prev = top;
top = n;
} }
// Pops top element from stack
void pop()
{struct Node *n;
n = top;
if (isEmpty())
printf("Stack is empty");
else if (top == start)
{
top = NULL;
start = NULL;
free(n);
}
else
{
top->prev->next = NULL;
top = n->prev;
free(n);
} }
// Prints top element of the stack
void topelement()
{
if (isEmpty())
printf("Stack is empty");
else
printf(
"The element at top of the stack is : %d \n",
top->data);
}
// Determines the size of the stackvoid stacksize()
{
int c = 0;
if (isEmpty())
printf("Stack is empty");
else
{
struct Node *ptr = start;
while (ptr != NULL)
{
c++;
ptr = ptr->next;
}
}
printf("Size of the stack is : %d \n ", c);
}
// Determines the size of the stack
void printstack()
{
if (isEmpty())
printf("Stack is empty");
else
{
struct Node *ptr = start;
printf("ISI STACK : ");
while (ptr != NULL)
{
printf("%d ", ptr->data);
ptr = ptr->next;}
printf("\n");
} }
// Driver code
int main()
{
int pilih, data;
do
{
system("cls");
cout << "==== MENU ======" << endl;
cout << "[1].PUSH " << endl;
cout << "[2].POP " << endl;
cout << "[3].VIEW " << endl;
cout << "[4].EXIT " << endl;
cout << "================ " << endl;
cout << "PILIH : ";
cin >> pilih;
switch (pilih)
{
case 1:
cout << "MASUKKAN DATA : "; cin >> data;
push(data);
cout << "KLIK UNTUK MELANJUTKAN ";
break;
case 2:
pop();
cout << "KLIK UNTUK MELANJUTKAN ";break;
case 3:
printstack();
cout << "KLIK UNTUK MELANJUTKAN ";
break;
default:
cout << "PILIHAN TIDAK ADA " << endl;
cout << "KLIK UNTUK MELANJUTKAN ";
break;
}
getch();
} while (pilih != 4);
return 0;
}

