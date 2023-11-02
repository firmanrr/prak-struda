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
	
	Mahasiswa mhs[5][2];
	
	mhs[0][0].nama = "Firman";
	mhs[0][0].nim = "60900121062";
	mhs[0][0].jenisKelamin = 'L';
	mhs[0][0].umur = 19;
	mhs[0][0].angkatan = 2021;
	
	mhs[3][2].nama = "Reski";
	mhs[3][2].nim = "60900121063";
	mhs[3][2].jenisKelamin = 'L';
	mhs[3][2].umur = 20;
	mhs[3][2].angkatan = 2021;
	
	cout << "Berikut identitas mahasiswa 2 : \n"
			<< setw(16) << left << "Nama " << ": "
			<< mhs[0][0].nama <<endl
			<< setw(16) << left << "Nim " << ": "
			<< mhs[0][0].nim <<endl
			<< setw(16) << left << "Jenis kelamin " << ": "
			<< mhs[0][0].jenisKelamin <<endl
			<< setw(16) << left << "Umur " << ": "
			<< mhs[0][0].umur <<endl
			<< setw(16) << left << "Angkatan " << ": "
			<< mhs[0][0].angkatan <<endl;
			
		system("pause");
		return 0;

}
