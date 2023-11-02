#include <iostream>
using namespace std;

struct barang{
    string nama;
    string jenis;
    int stok;
};
int batas = 4;

void catatbarang();
void daftar();
void descending();

barang gudang_a[99]; 
void setatis(){
    gudang_a[0].nama = "Teh Kotak";
    gudang_a[0].jenis = "Minuman";
    gudang_a[0].stok = 12;

    gudang_a[1].nama = "Teh Sisri";
    gudang_a[1].jenis = "Minuman";
    gudang_a[1].stok = 44;

    gudang_a[2].nama = "Teh Sari Murni";
    gudang_a[2].jenis = "Minuman";
    gudang_a[2].stok = 1;
    
	gudang_a[3].nama = "Teh Kotak";
    gudang_a[3].jenis = "Minuman";
    gudang_a[3].stok = 112;

    gudang_a[4].nama = "Teh Kotak";
    gudang_a[4].jenis = "Minuman";
    gudang_a[4].stok = 32;
}

void menu();
int main(){
    setatis();
    while(true){
        menu();
        system("pause");
        system("cls");
        cout << endl;
    }
}

void menu(){
    setatis();
    int pilihan;
    cout << "1. Masukan barang" << endl;
    cout << "2. Lihat barang" << endl;
    cout << "[1-2]: ";
    cin >> pilihan;
    if(pilihan == 1 )catatbarang();
    else if(pilihan == 2 ){descending(); daftar();}
}
void descending(){
    
    //sorting
    int temp_1;
    string temp_2;
    string temp_3;
    int n = 99;

    for(int i = 0;i <= 99;i++){
        for(int j = i + 1;j < n - 1;j++){
            if(gudang_a[j].stok > gudang_a[i].stok){
                temp_1 = gudang_a[i].stok;
                gudang_a[i].stok = gudang_a[j].stok;
                gudang_a[j].stok = temp_1;

                temp_2 = gudang_a[i].nama;
                gudang_a[i].nama = gudang_a[j].nama;
                gudang_a[j].nama = temp_2;

                temp_3 = gudang_a[i].jenis;
                gudang_a[i].jenis = gudang_a[j].jenis;
                gudang_a[j].jenis = temp_3;

  			} 
        }
    }
}

void daftar(){
    cout << "=== Daftar Barang(Dari Stok Terbanyak) ==== " << endl;
    for(int i = 0;i <= batas;i++){
        cout << "Nama\t\t: "<< gudang_a[i].nama << endl;
        cout << "Jenis\t\t: "<< gudang_a[i].jenis<< endl;
        cout << "Stok\t\t: "<< gudang_a[i].stok << " Stok"<< endl;
        cout << endl;
    }
}

void catatbarang(){
    batas = batas + 1;
    cout << "Nama  : ";
    cin >> gudang_a[batas].nama;
    cout << "Jenis : ";
    cin >> gudang_a[batas].jenis;
    cout << "Stock : ";
    cin >> gudang_a[batas].stok;

}

