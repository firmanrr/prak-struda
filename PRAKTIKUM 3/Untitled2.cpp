#include <iostream>
#include <conio.h>

using namespace std;

struct dataMahasiswa {
    char nama[99];
    char nim[99];
    char alamat[99];
    char ipk[99];
    dataMahasiswa* next, * prev;
};

//mendeklarasikan variabel struct yang akan digunakan dalam program
dataMahasiswa* awal = NULL, * akhir = NULL, * var, * baru, * hapus;

//prosedur untuk menginput data
void inputData() {
    baru = new dataMahasiswa;
    baru->next = NULL;
    baru->prev = NULL;

    cout << "Nama   : "; cin >> baru->nama;
    cout << "NIM    : "; cin >> baru->nim;
    cout << "IPK    : "; cin >> baru->ipk;
    cout << "Alamat : "; cin >> baru->alamat;
    
//mengubah kepala simpul sebelumnya ke simpul baru
    if (awal == NULL) {
        awal = akhir = baru;
    }
    else {
    	

// baru next kita isi data awal 
// awal sebelumnya kita isi data baru
// awal diisi baru
        baru->next = awal;
        awal->prev = baru;
        awal = baru;
    }
    system("cls");
}

//prosedur untuk menghapus data yang ada didepan
void hapusDatadepan() {
	
// sebelum menghapus kita cek apakah awal / head nya tidak kosong
    if (awal->next == NULL) {
    	
// Menghapus node awal dengan menimpa datanya mengguanakn null
        awal = akhir = NULL;
        cout << "Data sudah kosong";
    }
    else {
        hapus = awal;
        awal = awal->next;
        awal->prev = NULL;
        delete hapus;
    }
}


//prosedur untuk mencetak data 
void outputData() {
	
//var kita isi data alamat awal
    var = awal;
    while (var != NULL) {
        cout << "Nama    : " << var->nama << endl;
        cout << "NIM     : " << var->nim << endl;
        cout << "IPK     : " << var->ipk << endl;
        cout << "Alamat  : " << var->alamat << endl;
        cout << endl;
        
//var diisi var selanjutnya
        var = var->next;
    }
}


//fungsi utama
int main()
{
    int pilihan;
    do {
        cout << "====================" << endl;
        cout << "=       Menu       = \n";
        cout << "====================" << endl;
        cout << "1. INPUT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. LIHAT DATA\n";
        cout << "4. KELUAR\n";
        cout << "Pilihan : "; cin >> pilihan;
        cout << endl;

        switch (pilihan) {
        case 1:
            inputData();
            break;
        case 2:
            hapusDatadepan();
            break;
        case 3:
            if (baru == NULL) {
                cout << "Data masih kosong" << endl;
            }
            else {
                outputData();
            }
            break;
        default:
            cout << "Selesai.....";
            break;
        }
    } while (pilihan <= 3);
    getch();
}
