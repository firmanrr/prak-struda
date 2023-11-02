#include "stdio.h"
#include "math.h"
#include "iostream"
#include "ctime"
using namespace std;
// asumsikan kita menggunakan array dengan batas 1024
int storage[1024];
int i = 0;
int hdt_boundary;
void tambah_linear_probing(int n)
{
bool inserted = false;
int hash;
i = 0;
while( (!inserted) && (i < hdt_boundary) )
{
hash = (n % hdt_boundary) + i;
if(storage[hash] == 0)
{
storage[hash] = n;
inserted = true;
}
else
{
++i;
cout << "Terjadi tabrakan di " << hash << endl;
}
}
if(i == 0)
{
cout << "Langsung" << endl;
}
cout << "[" << hash << "] dengan " << n << endl;cout <<
"=================================================================="
<< endl;
cout << "Data Mahasiswa" << endl;
cout << "NAma : Muflih Ramadhan" << endl;
cout << "Nim : 60900121057" << endl;
cout << "Jurusan : Sistem Informasi" << endl;
cout << "Fakultas : Sains Dan Teknologi" << endl;
}
void tambah_quadric_probing(int n)
{
bool inserted = false;
int hash;
i = 0;
while( (!inserted) && (i < hdt_boundary) )
{
hash = (n % hdt_boundary) + (i*i);
if(storage[hash] == 0)
{
storage[hash] = n;
inserted = true;
}
else
{
++i;
cout << "Terjadi tabrakan di " << hash << endl;
}
}
if(i == 0)
{
cout << "Langsung" << endl;
}
cout << "Isi hash[" << hash << "] dengan " << n << endl;
cout <<
"=================================================================="
<< endl;
cout << "Data Mahasiswa" << endl;
cout << "NAma : Muflih Ramadhan" << endl;
cout << "Nim : 60900121057" << endl;
cout << "Jurusan : Sistem Informasi" << endl;
cout << "Fakultas : Sains Dan Teknologi" << endl;
}
// fungsi pembantu double_hashing
int prima_atas(int n)
{
if (n % 2 == 0)
n = n + 1;
else
n = n + 2;
bool ketemu = false;
while (!ketemu){
bool prima = true;
if (n % 2 == 0)
prima = false;
else {
int i = 3;
while (prima == true && i <=sqrt(n))
{
if(n % i == 0)
prima = false;
i = i + 2;}
}
if (prima)
ketemu = true;
else
n = n + 2;
}
return n;
}
int prima_bawah()
{
int n = hdt_boundary;
if (n % 2 == 0)
n = n - 1;
else
n = n - 2;
bool ketemu = false;
while (!ketemu){
bool prima = true;
if (n % 2 == 0)
prima=false;
else {
int i=3;
while (prima == true && i <= sqrt(n)){
if(n % i == 0)
prima = false;
i = i + 2;
}
}
if (prima)
ketemu = true;
else
n = n-2;
}
return n;
}
void tambah_double_hashing(int n)
{
//cout <<
"=================================================================="
<< endl;
//cout << "doube hashing..." << endl;
int hash;
int hash2 = prima_bawah();
bool inserted = false;
i = 0;
while( (!inserted) && (i < hdt_boundary) )
{
hash = ( (n%hdt_boundary) + i*((n) % hash2 + 1) ) % hdt_boundary;
if(storage[hash] == 0)
{
storage[hash] = n;
inserted = true;
}
else
{
++i;
cout << "Nama : Muflih Ramadhan " << hash << endl;
cout<< "Nim : 60900121057 " << hash << endl;
}
}
if(i == 0)
{
cout << "Langsung" << endl;
}cout << "Isi hash[" << hash << "] dengan " << n << endl;
cout <<
"=================================================================="
<< endl;
cout << "Data Mahasiswa" << endl;
cout << "NAma : Muflih Ramadhan" << endl;
cout << "Nim : 60900121057" << endl;
cout << "Jurusan : Sistem Informasi" << endl;
cout << "Fakultas : Sains Dan Teknologi" << endl;
}
void cetak(int n)
{
cout << endl;
cout << "Output program : " << endl;
for (int a = 0; a < n; ++a)
{
cout << "hash[" << a << "] = " << storage[a] << endl;
}
}
int getRandomNumberFromRange(int min, int max)
{
return min + (rand() % (max - min ) );
}
int main()
{
int n,random_number;
char pilihan;
string cara;
// harus panggil fungsi ini agar generate random datanya tidak sama terus.
srand((unsigned)time(0));
cout << "Masukan jumlah data : ";
cin >> n;
cout << "Kami menggunakan metode open addressing ada 3 cara, pilih salah satu dengan
memilih a,b, atau c : " << endl;
cout << "a. linear probing" << endl;
cout << "b. quadric probing" << endl;
cout << "c. double hashing" << endl;
cout << "Pilih a,b, atau c ? " << endl;
cin >> pilihan;
cout << endl << endl << "Proses pemasukan data ke hashtable " << endl;
// tentukan batas |T|
hdt_boundary = prima_atas(n);
for (int a = 0; a < n; ++a)
{
random_number = getRandomNumberFromRange(0,n);
// switch mau pakai cara open addressing apa?
switch(pilihan)
{
case 'a':
tambah_linear_probing(random_number);
cara = "Linear Probing" ;
break;
case 'b':
tambah_quadric_probing(random_number);
cara = "Quadric Probing";
break;
case 'c':
tambah_double_hashing(random_number);
cara = "Double hashing";break;
}
}
/**
* Dibawah adalah operasi untuk cetak
*/
cetak(n);
cout << "Diatas adalah hasil output Hashtable dengan cara \"" << cara << "\""<< endl;
switch(pilihan)
{
case 'a':
cout << "Nama : Muflih"<< hdt_boundary <<") + i" << endl;
break;
case 'b':
cout << "h(k) = (k mod "<< hdt_boundary <<") + i*i" << endl;
break;
case 'c':
cout << "h1(k) = k mod "<< hdt_boundary << endl;
cout << "h2(k) = ( h1(k) + i*(k mod " << prima_bawah() << " + 1) ) mod " <<
hdt_boundary << endl;
break;
}
}
