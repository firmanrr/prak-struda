#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct mahasiswa
{
  string nama;
  string nim;
  string asal;
  int jarak;

} uin[5];

int i = 0;

void inputData()
{

  cout << "NAMA          : "; cin >> uin[i].nama;
  cout << "NIM           : "; cin >> uin[i].nim;
  cout << "ASAL          : "; cin >> uin[i].asal;
  cout << "JARAK RUMAH   : "; cin >> uin[i].jarak;

  i++;
}

void lihatData()
{

  cout << "=============================" << endl;
  for (int x = 0; x < i; x++)
  {
    cout << "NAMA      : " << uin[x].nama << endl;
    cout << "NIM       : " << uin[x].nim << endl;   
    cout << "ASAL      : " << uin[x].asal << endl;
    cout << "JARAK /KM : " << uin[x].jarak << endl;
    cout << "=============================" << endl;
  }
}

void sorting()
{

  string tempNama, tempNim, tempAsal;
  int tempjarak;

  for (int k = 0; k < i; k++)
  {
    for (int s = k + 1; s < i; s++)
    {
      if (uin[k].jarak < uin[s].jarak)
      {

        tempNama = uin[k].nama;
        tempNim = uin[k].nim;
        tempAsal = uin[k].asal;
        tempjarak = uin[k].jarak;

        uin[k].nama = uin[s].nama;
        uin[k].nim = uin[s].nim;
        uin[k].asal = uin[s].asal;
        uin[k].jarak = uin[s].jarak;

        uin[s].nama = tempNama;
        uin[s].nim = tempNim;
        uin[s].asal = tempAsal;
        uin[s].jarak = tempjarak;
      }
    }
  }
}

int main()
{

  int pilih;

  do
  {
    system("cls");
    cout << "====================" << endl;
    cout << "=       MENU       =" << endl;
    cout << "====================" << endl;
    cout << "=  1.INPUT DATA    =" << endl;
    cout << "=  2.LIHAT DATA    =" << endl;
    cout << "=  3.SORTING DATA  =" << endl;
    cout << "=  4.EXIT          =" << endl;
    cout << "====================" << endl;
    cout << "PILIH : ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
      inputData();
      cout <<endl;
      cout << "Klik Untuk Lanjut ";
      break;
    case 2:
      lihatData();
      cout <<endl;
      cout << "Klik Untuk Lanjut ";
      break;
    case 3:
      sorting();
      cout <<endl;
      cout << "Klik Untuk Lanjut ";
      break;
    default:
      cout <<endl;
      cout << "Pilihan Tidak Ada " << endl;
      cout << "Klik Untuk Lanjut ";
      break;
    }
    getch();
  } while (pilih != 5);
}
