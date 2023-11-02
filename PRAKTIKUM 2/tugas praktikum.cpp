#include <iostream>
#include <string>
using namespace std;

struct mahasiswa{
	
    string namaMahasiwa;
    string nim;
    string matakuliah;
    int kehadiran;
    int tugas;
    int uts;
    int uas;
    int ratarata;
};

mahasiswa data[3];

void tambahData()
{

    for (int i = 0; i < 1; i++)
    {
    	cout << "===============================" <<endl;
    	cout << " INPUT NILAI MAHASISWA KE " << i + 1 << endl;
    	cout << "===============================" <<endl;
        cout << "Masukan Nama            : "; cin  >> data[i].namaMahasiwa;
        cout << "Masukan Nim             : "; cin  >> data[i].nim;
        cout << "Masukan Mata Kuliah     : "; cin  >> data[i].matakuliah;
        cout << "Masukan Nilai Kehadiran : "; cin  >> data[i].kehadiran;
        cout << "Masukan Nilai Tugas     : "; cin  >> data[i].tugas;
        cout << "Masukan Nilai UTS       : "; cin  >> data[i].uts;
        cout << "Masukan Nilai UAS       : "; cin  >> data[i].uas;
        
    }system("cls");
} 
void hasil()
{

    for (int s = 0; s < 1; s++)
    {
    	cout << "MAHASISWA " << s + 1 << endl;
        data[s].ratarata = (data[s].kehadiran * 0.1) + (data[s].tugas * 0.25) + (data[s].uts * 0.25) + (data[s].uas * 0.4);
		cout <<endl;
        cout << "Nama            : " << data[s].namaMahasiwa << endl;
        cout << "NIM             : " << data[s].nim << endl;
        cout << "Mata Kuliah     : " << data[s].matakuliah << endl;
        cout << "Nilai Kehadiran : " << data[s].kehadiran << endl;
        cout << "Nilai Tugas     : " << data[s].tugas << endl;
        cout << "Nilai UTS       : " << data[s].uts << endl;
        cout << "Nilai UAS       : " << data[s].uas << endl;
        cout << "Rata-Rata Nilai : " << data[s].ratarata << endl;
        cout <<endl;
    }
}
int main()
{
    char opsi = '2';
    do
    {
        tambahData();
        hasil();

        cout << "Pilihan: " << endl
             << "1. Ulang" << endl
             << "2. Exit" << endl
             << "Pilihan anda:";
        cin >> opsi;
    } while (opsi == '1');
    cout << endl
         << "Program selesai!" << endl;
    system("pause");
}
