#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct kabGowa
{

    string namaDesa;
    string makanankhas;
    string minumankhas;

};

int main()
{

    kabGowa cek;
    char opsi = '2';

    do
    {
        system("cls");
        cout << "Nama Desa    : "; cin >> cek.namaDesa;
        cout << "Makanan Khas : "; cin >> cek.makanankhas;
        cout << "Minuman Khas : "; cin >> cek.minumankhas;
		cout <<endl;
        system("cls");

        cout << "Nama Desa    : " << cek.namaDesa << endl;
        cout << "Makanan Khas : " << cek.makanankhas << endl;
        cout << "Minuman Khas : " << cek.minumankhas << endl;
        cout << endl
             << "Pilihan: " << endl
             << "1. Ulang" << endl
             << "2. Keluar" << endl
             << "Pilihan anda:";
        cin >> opsi;

    } while (opsi='1');
}
