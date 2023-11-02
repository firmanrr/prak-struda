#include <iostream>
using namespace std;

class pegawai
{

private:
    string nama;
    string nip;
    string jenisKelamin;
    string golongan;

public:
    void dataMasuk(){

        int pegGolongan;

		cout << "Masukan Data Pegawai"<<endl;
        cout << "Nama                : "; cin >> nama;
        cout << "Nip                 : "; cin >> nip;
        cout << "Jenis Kelamin [L/P] : "; cin >> jenisKelamin;
        cout << "Golongan [1-4]      : "; cin >> pegGolongan;
        cout <<endl;
        
        if(pegGolongan == 1)
            golongan = "2.000.000";
        else if(pegGolongan == 2)
            golongan = "2.500.000";
        else if(pegGolongan == 3) 
            golongan = "3.000.000";
        else if(pegGolongan == 4)
            golongan = "4.000.000";

    }

    void lihatData(){
		cout << "Berikut Identitas Pegawai"<<endl;
        cout << "Nama          : " << nama << endl;
        cout << "Nip           : " << nip << endl;
        cout << "Jenis Kelamin : " << jenisKelamin << endl;
        cout << "Gaji          : " << golongan << endl;
    }

};

int main()
{
    pegawai peg;

    bool ulang = true;
	char x;

	while (ulang)
	{
		system("cls");
		peg.dataMasuk();
        peg.lihatData();
		cout << "Ulang? [Y/N] : "; cin >> x;
		if(x == 'N')
		ulang = false;

	}

	return 0;
}
