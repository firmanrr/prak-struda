#include <iostream>
#include <iomanip>

using namespace std;

////UDT 
struct dataBarang{
	string barang;
	string kode;
	long harga;
	int jumlah;
};

struct kasir{
	int x, uang;
	dataBarang*barang;
};

////ADT
kasir transaksi;


long hitung(int y){
	long z;
	z=transaksi.barang[y].harga*transaksi.barang[y].jumlah;
	return z;
}

long total(){
	long s;
	s=0;
	for(int i=0;i<transaksi.x;i++){
		s=s+hitung(i);
	}
	return s;
}

long kembalian(){
	long k;
	k=transaksi.uang-total();
	return k;
}

void belanja();

int main(void){
	cout<<"PROGRAM KASIR"<<endl<<endl;
	belanja();
	cout<<"Pembayaran"<<endl<<endl;
	cout<<"Jumlah Barang : "<<transaksi.x<<endl<<endl;
	for(int a = 0; a < transaksi.x; a++){
		cout<<"Barang Ke-"<<a+1<<endl;
		cout<<"Nama Barang : "<<transaksi.barang[a].barang<<endl;
		cout<<"Kode Barang : "<<transaksi.barang[a].kode<<endl;
		cout<<"Harga Satuan Barang : "<<transaksi.barang[a].harga<<endl;
		cout<<"Jumlah Barang : "<<transaksi.barang[a].jumlah<<endl;
		cout<<endl;
	}
	cout<<"Total : "<<total()<<endl<<endl;
	cout<<"Masukkan Jumlah Uang : ";
	cin>>transaksi.uang;
	cout<<"Kembalian : "<<kembalian()<<endl;
}

void belanja(){
	cout<<"Masukkan Jumlah Data Barang : ";
	cin>>transaksi.x;
	cout<<endl;
	
	transaksi.barang=new dataBarang[transaksi.x];
	
	for(int a = 0; a < transaksi.x; a++){
		cin.ignore();
		cout<<"Barang Ke-"<<a+1<<endl;
		cout<<"Masukkan Nama Barang : ";
		getline(cin,transaksi.barang[a].barang);
		cout<<"Masukkan Kode Barang : ";
		getline(cin,transaksi.barang[a].kode);
		cout<<"Masukkan Harga Satuan Barang : ";
		cin>>transaksi.barang[a].harga;
		cout<<"Masukkan Jumlah Barang : ";
		cin>>transaksi.barang[a].jumlah;
		cout<<endl;
	}
	system("pause");
	system("cls");
}
