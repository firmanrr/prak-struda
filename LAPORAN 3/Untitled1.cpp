#include <iostream>
#include <conio.h>
using namespace std;

struct mhs
{
    string nama;
    string nim;
    string alamat;
    string ipk;
    mhs *next, *prev;
};

// Mendekslerasikan varianel struct yang akan digunakan dalam program
mhs *awal, *akhir, *bantu, *baru, *hapus, *cur, *del;

void inputDatadepan()
{
    baru = new dataMahasiswa();
    baru->next = NULL;
    baru->prev = NULL;
    cout << "Nama   : ";
    cin >> baru->nama;
    cout << "Alamat : ";
    cin >> baru->alamat;
    cout << "Nim    : ";
    cin >> baru->nim;
    cout << "Ipk    : ";
    cin >> baru->ipk;
    if (awal == NULL)
    {
        // jika awal isinya kosong maka awal / head sama dengan akhir / tail
        awal = akhir = baru;
    }
    else
    {
        // baru next kita isi data awal 
        // awal sebelumnya kita isi data baru
        // awal disi baru
        baru->next = awal;
        awal->prev = baru;
        awal = baru;
    }
    system("cls");
}

void hapusDatadepan()
{
    // sebelum menghapus kita cek apakah awal / head nya tidak kosong
    if (awal->next == NULL)
    {
        // Menghapus node awal dengan menimpa datanya mengguanakn null
        awal = akhir = NULL;
        cout << "Data sudah kosong";
    }
    else
    {
        // isi data hapus menggunakan data alamat awal
        hapus = awal;
        awal = awal->next;
        awal->prev = NULL;
        delete hapus;
    }
}

bool hapusNama()
{

    string nama;
    mhs *temp = awal;
    mhs *prev = NULL;

    cout << "MASUKKAN NAMA : ";
    cin >> nama;

    // Sebelum menghapus node kita cek terlebih dahulu isi link listnya
    if (temp != NULL && temp->nama == nama)
    {
        awal = temp->next; // Menjadikan data selanjutnya menjadi head jika kondisi true
        delete temp;       // Menghapus temp yang berisi alamat node yang ingin dihapus
        return false;
    }
    // Jika data yang dicari tidak ada diawal maka akan lanjut ke
    // cabang selanjutnya
    else
    {
        // melakukan perulangan dengan kondisi nya temp bukan null
        // dan temp -> nama bukan sama dengan nama
        while (temp != NULL && temp->nama != nama)
        {
            // Memasukkan alamat temp ke prev
            prev = temp;
            // mengganti isi data temp dengan menggunakan temp -> next
            temp = temp->next;
        }

        // selanjutnya jika temp sama dengan null maka akan mereturn false
        if (temp == NULL)
            return false;

        // prev next kita isi dengan temp next
        prev->next = temp->next;

        // menghapus temp
        delete temp;
    }
}

void outputData()
{
    // bantu kita isi data alamat awal
    bantu = awal;
    // menggunakan perulangan jika bantu belum null akan mengulang lagi
    while (bantu != NULL)
    {
        cout << "Nama   : " << bantu->nama << endl;
        cout << "Alamat : " << bantu->alamat << endl;
        cout << "Nim    : " << bantu->nim << endl;
        cout << "IPK    : " << bantu->ipk << endl;
        // bantu disi bantu selanjutnya
        bantu = bantu->next;
    }
}

int main()
{
    int pilihan;
    do
    {
        cout << "----------DOUBLE LINKED LIST-----------\n";
        cout << "Pilih menu : \n";
        cout << "[1]. Input data di depan\n";
        cout << "[2]. Hapus data di depan\n";
        cout << "[3]. Output data\n";
        cout << "[4]. Hapus data tertentu\n";
        cout << "[5]. Exit\n";
        cout << "Pilihan : ";

        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            inputDatadepan();
            break;
        case 2:
            hapusDatadepan();
            break;
        case 3:
            if (baru == NULL)
            {
                cout << "Data masih kosong !\n";
            }
            else
            {
                outputData();
            }
            break;
        case 4:
            hapusNama();
            break;
        default:
            cout << "---------EXIT---------";
            break;
        }

    } while (pilihan < 5);
    getch();
}
