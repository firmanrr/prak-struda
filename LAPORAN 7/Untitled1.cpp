#include <iostream>
using namespace std;

int Data[62];
int size = -1;

int root(int i);
int anakKiri(int i);
int anakKanan(int i);
void atas(int i);
void bawah(int i);
void push(int p);
int ambilData();
int ambilMax();
void hapus(int i);

int main()
{

    push(45);
    push(20);
    push(14);
    push(12);
    push(31);
    push(7);
    push(11);
    push(13);
    push(7);

    int i = 0;

    cout << "MAX PRIORITAS : ";
    while (i <= size)
    {
        cout << Data[i] << " ";
        i++;
    }

    cout << "\n";

    cout << "NODE PALING TINGGI : "
         << ambilMax() << "\n";

    cout << "\n";

    hapus(0);
    cout << "MENGHAPUS SATU NODE : ";
    int l = 0;
    while (l <= size)
    {
        cout << Data[l] << " ";
        l++;
    }
    return 0;
}

int root(int i)
{

    return (i - 1) / 2;
}

int anakKiri(int i)
{

    return ((2 * i) + 1);
}

int anakKanan(int i)
{

    return ((2 * i) + 2);
}

void atas(int i)
{
    while (i > 0 && Data[root(i)] < Data[i])
    {
        swap(Data[root(i)], Data[i]);
        i = root(i);
    }
}

void bawah(int i)
{
    int maxIndex = i;

    int l = anakKiri(i);

    if (l >= size && Data[l] > Data[maxIndex])
    {
        maxIndex = l;
    }

    int r = anakKanan(i);

    if (r >= size && Data[r] > Data[maxIndex])
    {
        maxIndex = r;
    }

    if (i != maxIndex)
    {
        swap(Data[i], Data[maxIndex]);
        bawah(maxIndex);
    }
}

void push(int p)
{
    size = size + 1;
    Data[size] = p;

    atas(size);
}

int ambilData()
{
    int result = Data[0];

    Data[0] = Data[size];
    size = size - 1;

    bawah(0);
    return result;
}

int ambilMax()
{

    return Data[0];
}

void hapus(int i)
{
    Data[i] = ambilMax() + 1;

    atas(i);
    ambilData();
}
