#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct MataKuliah{
	string mataKuliah;
	double nilai;
	
};

struct Mahasiswa{
	string nama,kelas;
	int nim;
	MataKuliah mk[2];
	
};

void TambahkanMataKuliah(Mahasiswa &mhs,MataKuliah mk1, MataKuliah mk2){
	mhs.mk[0] = mk1;
	mhs.mk[1] = mk2;
}

int main(){
	
	char opsi = '2';
	
	do{
		Mahasiswa mhs;
		cout <<endl
				<<"Masukan identitas mahasiswa: "<<endl
				<<"Nama [string]: "; cin >> mhs.nama;
				cout <<"NIM [integer]: "; cin >> mhs.nim;
				MataKuliah mk1, mk2;
				cout <<"Matakuliah 1 [string]: ";cin >> mk1.mataKuliah;
				cout <<"Nilai [Double]: "; cin >> mk1.nilai;
				cout <<"Matakuliah 2 [string]: ";cin >> mk2.mataKuliah;
				cout <<"Nilai [Double]: "; cin >> mk2.nilai;
				cout <<endl;
				
				TambahkanMataKuliah(mhs,mk1,mk2);
				cout <<"Berikut data mahasiswa dan nilai MKnya: \n"
						<<setw(16) << left <<" Nama [string]"<<": "
						<<mhs.nama <<endl
						<<setw(16) << left <<" Nim [integer]"<<": "
						<<mhs.nim <<endl
						<<setw(16) << left <<"\tMata Kuliah 1 "
						<< ": "
						<<mhs.mk[0].mataKuliah << endl
						<<setw(16) << left <<"\tNilai "<<": "
						<<mhs.mk[0].nilai << endl
						<<setw(16) << left << "\tMata Kuliah 2 "
						<< ": "
						<<mhs.mk[1].mataKuliah << endl
						<<setw(16) << left <<"\tNilai "<<": "
						<<mhs.mk[1].nilai << endl;
						
						cout << endl << endl;
						
						cout << endl
								<<"Pilihan: " <<endl
								<<"1. Ulang" <<endl
								<<"2. Exit" <<endl
								<<"Pilihan anda:";
								cin >> opsi;
				
					
					}while(opsi == '1');
					cout <<endl
							<<"Program selesai" << endl;
						
					system("pause");
					return 0;
					
				
}
