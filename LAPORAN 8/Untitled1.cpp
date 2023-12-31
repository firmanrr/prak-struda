/*
 * Program Hash Tables Chaining with
 * Doubly Linked Lists
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
const int TABLE_SIZE = 25;
using namespace std;
/*
 * Node Declaration
 */
struct HashNode
{
    int nim, key;
    string nama, alamat, angkatan;
    HashNode *next;
    HashNode *prev;
};
/*
 * Class Declaration
 */
class HashMap
{
public:
	//top nilai pertama
	//htable nilai selanjutnya
	
    HashNode **htable, **top;
    HashMap()
    {
        htable = new HashNode *[TABLE_SIZE];
        top = new HashNode *[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            htable[i] = NULL;
            top[i] = NULL;
        }
    }
    /*
     * Hash Function
     */
    int HashFunc(int key)
    {
        return key % TABLE_SIZE;
    }
    /*
     * Insert Element at a key
     */
    void insert(int key, int nim, string nama, string alamat, string angkatan)
    {
        int hash_val = HashFunc(key);
        HashNode *entry = htable[hash_val];
        if (entry == NULL)
        {
            entry = new HashNode;
            entry->nim = nim;
            entry->key = key;
            entry->nama = nama;
            entry->alamat = alamat;
            entry->angkatan = angkatan;
            entry->next = NULL;
            entry->prev = NULL;
            htable[hash_val] = entry;
            top[hash_val] = entry;
        }
        else
        {
            while (entry != NULL)
            entry = entry->next;
            entry = new HashNode;
            entry->nim = nim;
            entry->nama = nama;
            entry->alamat = alamat;
            entry->angkatan = angkatan;
            entry->key = key;
            entry->next = NULL;
            entry->prev = top[hash_val];
            top[hash_val]->next = entry;
            top[hash_val] = entry;
        }
    }
    /*
     * Remove Element at a key
     */
    void remove(int key)
    {
        int hash_val = HashFunc(key);
        HashNode *entry = htable[hash_val];
        if (entry->key != key || entry == NULL)
        {
            cout << "No Element found at key:" << key << endl;
            return;
        }
        while (entry != NULL)
        {
            if (entry->next == NULL)
            {
                if (entry->prev == NULL)
                {
                    htable[hash_val] = NULL;
                    top[hash_val] = NULL;
                    delete entry;
                    break;
                }
                else
                {
                    top[hash_val] = entry->prev;
                    top[hash_val]->next = NULL;
                    delete entry;
                    entry = top[hash_val];
                }
            }
            entry = entry->next;
        }
    }
    /*
     * Search Element at a key
     */
    void get(int key)
    {
        int hash_val = HashFunc(key);
        bool flag = false;
        HashNode *entry = htable[hash_val];
        if (entry != NULL)
        {
            while (entry != NULL)
            {
                if (entry->key == key)
                {
                    flag = true;
                }
                if (flag)
                {
                    cout << "DATA MAHASISWA DITEMUKAN DENGAN KATA KUNCI" << key << ": " << endl;
                    cout << "NAMA     :" << entry->nama << endl;
                    cout << "NIM      :" << entry->nim << endl;
                    cout << "ALAMAT   :" << entry->alamat << endl;
                    cout << "ANGKATAN :" << entry->angkatan << endl;
                }
                entry = entry->next;
            }
        }
        
        if (!flag)
            cout << "No Element found at key " << key << endl;
    }
};
/*
 * Main Contains Menu
 */
int main()
{
    HashMap hash;
    int key, value;
    string nama, alamat, angkatan;
    int choice;
    while (1)
    {
        cout << "\n----------------------" << endl;
        cout << "Operations on Hash Table" << endl;
        cout << "\n----------------------" << endl;
        cout << "1.Insert" << endl;
        cout << "2.Search" << endl;
        cout << "3.Delete" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "MASUKKAN NAMA : ";
            cin >> nama;
            cout << "MASUKKAN NIM : ";
            cin >> value;
            cout << "MASUKKAN ALAMAT: ";
            cin >> alamat;
            cout << "MASUKKAN ANGKATAN: ";
            cin >> angkatan;
            cout << "MASUKKAN KATA KUNCI: ";
            cin >> key;
            hash.insert(key, value, nama, alamat, angkatan);
            break;
        case 2:
            cout << "Enter key of the element to be searched: ";
            cin >> key;
            hash.get(key);
            break;
        case 3:
            cout << "Enter key of the element to be deleted: ";
            cin >> key;
            hash.remove(key);
            break;
        case 4:
            exit(1);
        default:
            cout << "\nEnter correct option\n";
        }
    }
    cout << endl;
    system("pause");
	return 0;
}
