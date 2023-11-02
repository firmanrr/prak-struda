#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct dataBarang
{
    string nama;
    string jenis;
    int stok;
} 

array[99];

int a = 0;

void tambahBarang()
{
	cout <<"============================="<<endl;
	cout <<"=       DAFTAR BARANG       ="<<endl;
	cout <<"============================="<<endl;
    cout <<" Nama Barang   : " ;cin >> array[a].nama;
    cout <<" Jenis Barang  : " ;cin >> array[a].jenis;
    cout <<" Stok Barang   : " ;cin >> array[a].stok;
    cout <<endl;

    a++;
}
void sortBarang()
{

    string dataNama, dataJenis;
    int dataStok;

    for (int i = 0; i < a; i++)
    {
        for (int b = i + 1; b < a; b++)
        {
            if (array[i].stok < array[b].stok)
            {

                dataNama  = array[i].nama;
                dataJenis = array[i].jenis;
                dataStok  = array[i].stok;

                array[i].nama  = array[b].nama;
                array[i].jenis = array[b].jenis;
                array[i].stok  = array[b].stok;

                array[b].nama  = dataNama;
                array[b].jenis = dataJenis;
                array[b].stok  = dataStok;
            }
        }
    }
}

void lihatBarang()
{

    sortBarang();

    for (int c = 0; c < a; c++)
    {
		cout << "Daftar Barang"<<endl;
        cout << "Nama Barang    : " << array[c].nama << endl;
        cout << "Jenis Barang   : " << array[c].jenis << endl;
        cout << "Stok Barang    : " << array[c].stok << endl;
        cout <<endl;
    }
}
int main()
{

		array[0].nama  = "Mie";
        array[0].jenis = "Makanan";
    	array[0].stok  = 2;

		array[1].nama  = "kopi";
        array[1].jenis = "Minuman";
    	array[1].stok  = 2;

    int pilih;

    do
    {
        system("cls");
        cout << "===================" << endl;
        cout << "=       MENU      =" << endl;
        cout << "=  1.INPUT DATA   =" << endl;
        cout << "=  2.LIHAT DATA   =" << endl;
        cout << "=  3.EXIT         =" << endl;
        cout << "===================" << endl;
        cout << "=  PILIH : ";cin >> pilih;
        cout <<endl;

        switch (pilih)
        {
        case 1:
            tambahBarang();
            cout << "Enter untuk melanjutkan ";
            break;
        case 2:
            lihatBarang();
            cout << "Enter untuk melanjutkan ";
            break;
        default:
            cout << "Selesai... " << endl;
            cout << "Enter untuk melanjutkan ";
            break;
        }
        getch();
    }while (pilih !=3); 

//	dataNama[5]={"MIE", "KOPI","ROKOK","TEPUNG", "TELUR"};
//	dataJenis[5]={"MAKANAN", "MINUMAN", "MAKANAN","MAKANAN","MAKANAN"};
//	dataStock[5]={10, 20,5,17,1};
}
