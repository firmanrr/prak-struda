#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int MAX_LEVEL = 16; // maksimum level dari skip-list

struct Node
{
	string nama;
	string nim;
	string asal;
	string jurusan;
	string fakultas;
	Node *next[MAX_LEVEL]; // pointer ke node selanjutnya pada setiap level
	Node(string nama, string nim, string asal, string jurusan, string fakultas) : nama(nama), nim(nim), asal(asal), jurusan(jurusan), fakultas(fakultas)
	{
		for (int i = 0; i < MAX_LEVEL; i++)
		{
			next[i] = NULL;
		}
	}
};

class SkipList
{
public:
	Node *head; // pointer ke node pertama dari skip-list
	int level;	// level teratas dari skip-list
	int size;	// jumlah node dalam skip-list

public:
	// konstruktor
	SkipList()
	{
		head = new Node("", "", "", "", "");
		level = 0;
		size = 0;
	}

	// mengembalikan jumlah node dalam skip-list
	int getSize()
	{
		return size;
	}

	// mengembalikan level teratas dari skip-list
	int getLevel()
	{
		return level;
	}

	// menambahkan node baru ke skip-list
	void add(string nama, string nim, string asal, string jurusan, string fakultas)
	{
		// menentukan level untuk node baru dengan menggunakan fungsi rand()
		int newLevel = 0;
		while (rand() < RAND_MAX / 2 && newLevel < MAX_LEVEL - 1)
		{
			newLevel++;
		}

		// mengalokasikan memori untuk node baru
		Node *newNode = new Node(nama, nim, asal, jurusan, fakultas);

		// menentukan pointer ke node sebelumnya pada setiap level
		Node *current = head;
		Node *update[MAX_LEVEL];
		for (int i = level; i >= 0; i--)
		{
			while (current->next[i] != NULL && current->next[i]->nim < nim)
			{
				current = current->next[i];
			}
			update[i] = current;
		}
		current = current->next[0];

		// mengupdate pointer dari node sebelumnya ke node baru
		if (current == nullptr || current->nim != nim)
		{
			// mengupdate level teratas jika perlu
			if (newLevel > level)
			{
				for (int i = level + 1; i <= newLevel; i++)
				{
					update[i] = head;
				}
				level = newLevel;
			}
			for (int i = 0; i <= newLevel; i++)
			{
				newNode->next[i] = update[i]->next[i];
				update[i]->next[i] = newNode;
			}

			size++; // menambahkan jumlah node dalam skip-list
		}
	}

	// menghapus node dari skip-list
	void remove(string nim)
	{
		// menentukan pointer ke node sebelumnya pada setiap level
		Node *current = head;
		Node *update[MAX_LEVEL];
		for (int i = level; i >= 0; i--)
		{
			while (current->next[i] != NULL && current->next[i]->nim < nim)
			{
				current = current->next[i];
			}
			update[i] = current;
		}
		current = current->next[0];

		if (current != nullptr && current->nim == nim)
		{
			// mengupdate pointer ke node selanjutnya pada setiap level
			for (int i = 0; i <= level; i++)
			{
				if (update[i]->next[i] != current)
				{
					break;
				}
				update[i]->next[i] = current->next[i];
			}

			// mengurangi level teratas jika perlu
			while (level > 0 && head->next[level] == nullptr)
			{
				level--;
			}

			delete current; // menghapus node dari memori
			size--;			// mengurangi jumlah node dalam skip-list
		}
	}

	// mencari node dengan NIM yang diberikan
	Node *find(string nim)
	{
		// menentukan pointer ke node sebelumnya pada setiap level
		Node *current = head;
		for (int i = level; i >= 0; i--)
		{
			while (current->next[i] != NULL && current->next[i]->nim < nim)
			{
				current = current->next[i];
			}
		}
		current = current->next[0];
			// mengembalikan node jika ditemukan, atau NULL jika tidak ditemukan
		if (current != nullptr && current->nim == nim)
		{
			return current;
		}else
		{
			return nullptr;
		}
	}
};

int main()
{
	srand((unsigned)time(0)); // menentukan seed untuk fungsi rand()

	SkipList skipList; // membuat objek skip-list

	// menambahkan beberberapa node ke skip-list
	skipList.add("Joko", "1234567890", "Jakarta", "Informatika", "Ilmu Komputer");
	skipList.add("Budi", "2345678901", "Bandung", "Sistem Informasi", "Ilmu Komputer");
	skipList.add("Anton", "3456789012", "Surabaya", "Teknik Elektro", "Teknik");
	skipList.add("Doni", "4567890123", "Semarang", "Teknik Industri", "Teknik");
	skipList.add("Eka", "5678901234", "Yogyakarta", "Teknik Informatika", "Ilmu Komputer");

	// menampilkan data mahasiswa
	cout << "Jumlah node dalam skip-list: " << skipList.getSize() << endl;
	cout << "Level teratas dari skip-list: " << skipList.getLevel() << endl;
	cout << "Data mahasiswa:" << endl;
	for (int i = 0; i <= skipList.getLevel(); i++)
	{
		Node *node = skipList.head->next[i];
		while (node != nullptr)
		{
			cout << " Level " << i << ": " << node->nama << " (" << node->nim << ") " << node->asal << " " << node->jurusan << " " << node->fakultas << endl;
			node = node->next[i];
		}
	}

	// mencari data mahasiswa dengan NIM yang diberikan
	cout << endl;
	cout << "Mencari data mahasiswa dengan NIM 1234567890:" << endl;
	Node *node = skipList.find("1234567890");
	if (node != nullptr)
	{
		cout << " Ditemukan: " << node->nama << " (" << node->nim << ") " << node->asal << " " << node->jurusan << " " << node->fakultas << endl;
	}
	else
	{
		cout << " Tidak ditemukan" << endl;
	}

	// menghapus data mahasiswa dengan NIM yang diberikan
	cout << endl;
	cout << "Menghapus data mahasiswa dengan NIM 1234567890:" << endl;
	skipList.remove("1234567890");
	node = skipList.find("1234567890");
	if (node != nullptr)
	{
		cout << " Ditemukan: " << node->nama << " (" << node->nim << ") " << node->asal << " " << node->jurusan << " " << node->fakultas << endl;
	}
	else
	{
		cout << " Tidak ditemukan" << endl;
	}

	return 0;
}
