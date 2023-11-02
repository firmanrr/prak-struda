#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
struct HashTable
{
	string alamat[62];
};

HashTable hashTable;

int hashFunction(string key)
{
	return key.length();
}

void insert(string key, string value)
{
	int index = hashFunction(key);
	hashTable.alamat[index] = value;
}

string getData(string key)
{
	int index = hashFunction(key);
	return hashTable.alamat[index];
}

int main()
{
	int pilih;
	string key, alamat;

	do
	{
		system("cls");
		cout << "[1].MASUKKAN DATA " << endl;
		cout << "[2].TAMPILKAN DATA " << endl;
		cout << "[3].EXIT " << endl;
		cout << "PILIH : ";
		cin >> pilih;
		switch (pilih)
		{
		case 1:
			cout << "NAMA   : ";
			cin >> key;
			cout << "ALAMAT : ";
			cin >> alamat;
			insert(key, alamat);
			cout << "KLIK UNTUK MELANJUTKAN ";
			break;
		case 2:
			cout << "MASUKKAN KEY/NAMA : ";
			cin >> key;
			cout << "\nNAMA " << key << " ALAMAT " << getData(key) << endl;
			cout << "KLIK UNTUK MELANJUTKAN ";
			break;
		default:
			cout << "PILIHAN TIDAK ADA " << endl;
			cout << "KLIK UNTUK MELANJUTKAN ";
			break;
		}
		getch();
	} while (pilih != 3);

	cout << endl;
	system("pause");
	return 0;
}
