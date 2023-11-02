#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Mahasiswa{
	string nama;
	string nim;
	char jenisKelamin;
	int umur;
	int angkatan;
}; 

int main(){
	
	Mahasiswa mhs[2];
	
	mhs[0].nama = "Firman";
	mhs[0].nim = "60900121062";
	mhs[0].jenisKelamin = 'L';
	mhs[0].umur = 19;
	mhs[0].angkatan = 2021;
	
	mhs[1].nama = "Reski";
	mhs[1].nim = "60900121063";
	mhs[1].jenisKelamin = 'L';
	mhs[1].umur = 20;
	mhs[1].angkatan = 2021;
	
	cout << "Berikut identitas mahasiswa 2 : \n"
			<< setw(16) << left << "Nama " << ": "
			<< mhs[1].nama <<endl
			<< setw(16) << left << "Nim " << ": "
			<< mhs[1].nim <<endl
			<< setw(16) << left << "Jenis kelamin " << ": "
			<< mhs[1].jenisKelamin <<endl
			<< setw(16) << left << "Umur " << ": "
			<< mhs[1].umur <<endl
			<< setw(16) << left << "Angkatan " << ": "
			<< mhs[1].angkatan <<endl;
			
		system("pause");
		return 0;

}
