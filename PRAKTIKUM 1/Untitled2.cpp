#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Mahasiswa{
	public:
		string nama;
		string nim;
		char jenisKelamin;
		int umur;
		int angkatan;
};

int main(){
	
	char opsi = '2';
	
	do{
		Mahasiswa mhs;
		cout <<"Masukan Identitas Mahasiswa"<<endl;
		cout <<"Nama                : ";cin >>mhs.nama;
		cout <<"Nim                 : ";cin >>mhs.nim;
		cout <<"Jenis Kelamin [L/P] : ";cin >>mhs.jenisKelamin;
		cout <<"Umur                : ";cin >>mhs.umur;
		cout <<"Angkatan            : ";cin >>mhs.angkatan;
		cout <<endl;
		
		cout <<"Berikut Identitas Mahasiswa \n"
		<< setw(16) << left << "Nama " << ": "
		<< mhs.nama <<endl
		<< setw(16) << left << "Nim " << ": "
		<< mhs.nim <<endl
		<< setw(16) << left << "Jenis Kelamin " << ": "
		<< mhs.jenisKelamin <<endl
		<< setw(16) << left << "Umur " << ": "
		<< mhs.umur <<endl
		<< setw(16) << left << "Ungkatan " << ": "
		<< mhs.angkatan <<endl;
		cout <<endl;
		
		cout <<"Pilihan: "<<endl;
		cout <<"1. Ulang"<<endl;
		cout <<"2. Exit" <<endl;
		cout <<"Pilihan anda: ";
		cin  >>opsi; 
		
	}while(opsi=='1');
	cout <<endl;
		cout<<"Program selesai"<<endl;
		system("pause");
		return 0;
}
