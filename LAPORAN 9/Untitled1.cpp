#include <iostream>
#include <iterator>
#include <map>
using namespace std;
int main()
{
	// deklarasi map container
	map<string, string> map1, map2, map3;
	string judul, penerbit, pengarang, tahun, genre, ringkasana;
	map<string, string>::iterator itr1, itr2, itr3;

	cout << "MASUKKAN JUDUL        : ";
	cin >> judul;
	cout << "MASUKKAN PENERBIT     : ";
	cin >> penerbit;
	map1.insert(pair<string, string>(judul, penerbit));
	cout << "MASUKKAN TAHUN        : ";
	cin >> tahun;
	cout << "MASUKKAN GENRE        : ";
	cin >> genre;
	map2.insert(pair<string, string>(tahun, genre));
	cout << "MASUKKAN PENGARANG    : ";
	cin >> pengarang;
	cout << "MASUKKAN RINGKASANA   : ";
	cin >> ringkasana;
	map3.insert(pair<string, string>(pengarang, ringkasana));
	
	
	for (itr1 = map1.begin(); itr1 != map1.end(); ++itr1)
	{
		cout << "\tJUDUL     : " << itr1->first << '\n'
			 << "\tPENERBIT  : "<< itr1->second << '\n';

	}
	for (itr1 = map2.begin(); itr1 != map2.end(); ++itr2)
	{
		cout << "\tTAHUN     : " << itr1->first << '\n'
			 << "\tPENERBIT  : " << itr1->second << '\n';

	}
	for (itr1 = map3.begin(); itr1 != map3.end(); ++itr3)
	{
		cout << "\tPENGARANG : " << itr1->first << '\n'
			 << "\tRINGKASAN : " << itr1->second << '\n';

	}
	cout << endl;

	return 0;
}
