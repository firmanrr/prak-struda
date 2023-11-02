#include <iostream>
using namespace std;

typedef struct
{
	int pilih;
	double jumlah;
	double total;
	double bayar;
	double kembalian;

}transaksi;

transaksi kasir;

string nama[3] = {"ROKOK", "KOPI", "MIE"};
string kode[3] = {"R13", "K14", "M15"};
int harga[3] = {25000, 15000, 10000};

double getTotal()
{

	return kasir.total = kasir.jumlah * harga[kasir.pilih - 1];
}

double getKembalian()
{

	kasir.kembalian = kasir.bayar - getTotal();
	return kasir.kembalian;

}

void getBarang()
{

	cout << "1.\t" << nama[0] << "\t" << kode[0] << "\t" << harga[0] << endl;
	cout << "2.\t" << nama[1] << "\t" << kode[1] << "\t" << harga[1] << endl;
	cout << "3.\t" << nama[2] << "\t" << kode[2] << "\t" << harga[2] << endl;
}

void getData(){

	int select = kasir.pilih - 1;

	cout << "Anda Membeli " << nama[select] << " Kode Barang " << kode[select] << " Harga Barang " << harga[select] << endl;
}

void getTransaksion()
{

	cout << "=======================================" << endl;
	cout << "=                KASIR                =" << endl;
	cout << "=======================================" << endl;
	cout << "|\tNAMA\tKODE\tHARGA         |" << endl;
	cout << "---------------------------------------" << endl;

	getBarang();
	cout << "=======================================" << endl;
	cout << "BELI NOMER : ";
	cin >> kasir.pilih;
	getData();
cout << "JUMLAH     : ";
	cin >> kasir.jumlah;
	cout << "TOTAL      : " << getTotal() << endl;
	cout << "BAYAR      : ";
	cin >> kasir.bayar;
	if(kasir.bayar < getTotal())
		cout << "UANG ANDA TIDAK CUKUP" << endl;
	else
		cout << "KEMBALIAN  : " << getKembalian() << endl;
}

int main()
{

	bool ulang = true;
	char y;

	while (ulang)
	{
		system("cls");
		getTransaksion();
		cout << "ULANG? [Y/N] : "; cin >> y;
		if(y == 'N')
			ulang = false;

	}
	
	return 0;
}

