#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct homestay
{

    string namaPenyewa;
    string noHp;
    string status;
    string lamaSewa;
    int nokamar;

} pakMaman[20];

void cek()
{

    for (int i = 0; i < 20; i++)
    {
        pakMaman[i].status = "KOSONG";
        pakMaman[i].nokamar = i + 1;
    }
}

void isiKamar()
{

    int pilih;

    cout << "PILIH KAMAR : ";
    cin >> pilih;
    if (pakMaman[pilih - 1].status == "KOSONG")
    {

        cout << "NAMA PENYEWA : ";
        cin >> pakMaman[pilih - 1].namaPenyewa;
        cout << "NOMER HP     : ";
        cin >> pakMaman[pilih - 1].noHp;
        cout << "LAMA SEWA    : ";
        cin >> pakMaman[pilih - 1].lamaSewa;
        pakMaman[pilih - 1].status = "TERISI";

        cout << "BERHASIL DIISI " << endl;
    }
    else
        cout << "KAMAR TERISI" << endl;
}

void daftarPenyewa()
{
    cout << "================" << endl;
    for (int i = 0; i < 20; i++)
    {
        if (i < 9)
        {
            cout << "[" << i + 1 << "] .KAMAR " << pakMaman[i].nokamar << "   |  " << pakMaman[i].status << endl;
        }
        else
        {
            cout << "[" << i + 1 << "].KAMAR " << pakMaman[i].nokamar << "  |  " << pakMaman[i].status << endl;
        }
    }
    cout << "================" << endl;
}

void lihatData()
{

    int pilih;

    cout << "PILIH KAMAR : ";
    cin >> pilih;
    if (pakMaman[pilih - 1].status == "TERISI")
    {

        cout << "NAMA  PENYEWA  : " << pakMaman[pilih - 1].namaPenyewa << endl;
        cout << "NOMER HP       : " << pakMaman[pilih - 1].noHp << endl;
        cout << "LAMA SEWA      : " << pakMaman[pilih - 1].lamaSewa << endl;
        pakMaman[pilih - 1].status = "TERISI";
    }
    else
        cout << "KAMAR KOSONG" << endl;
    cout <<endl;
    cout << "Klik Untuk Melanjutkan " << endl;
}

void kosongkanKamar()
{

    int pilih;

    cout << "PILIH KAMAR : ";
    cin >> pilih;
    if (pakMaman[pilih - 1].status == "TERISI")
    {
        pakMaman[pilih - 1].status = "KOSONG";
        cout << "BERHASIL DIHAPUS " << endl;
    }
    else
        cout << "KAMAR KOSONG" << endl;
}

void menu()
{

    int pilih;

    do
    {
        system("cls");
        cout << "=====================" << endl;
        cout << "=   INFO HOMESTAY   =" << endl;
        cout << "=====================" << endl;
        cout << "=  1.CHECKOUT       =" << endl;
        cout << "=  2.CHECKIN        =" << endl;
        cout << "=  3.CEK KAMAR      =" << endl;
        cout << "=  4.CEK DATA       =" << endl;
        cout << "=  5.KELUAR         =" << endl;
        cout << "=====================" << endl;
        cout << "PILIH : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            daftarPenyewa();
            kosongkanKamar();
            cout << "Klik Untuk Melanjutkan " << endl;
            break;
        case 2:
            daftarPenyewa();
            isiKamar();
            cout << "Klik Untuk Melanjutkan " << endl;
            break;
        case 3:
            daftarPenyewa();
            cout << "Klik Untuk Melanjutkan " << endl;
            break;
        case 4:
            daftarPenyewa();
            lihatData();
        }
        getch();
    } while (pilih != 5);
}

int main()
{
    cek();
    menu();
}
