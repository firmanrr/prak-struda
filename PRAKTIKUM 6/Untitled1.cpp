#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//deklarasi struktur double linked node
struct Node{
	string nama;
	string posisi;
	Node * induk;
	Node * kiri;
	Node * kanan;

	Node(string nam, string pos){
		nama = nam;
		posisi = pos;
	}
};

//method cetak tree
void cetakTree(Node * node, string space);
void cetakTreePreOrder(Node * node, string space);
void cetakTreeInOrder(Node * node, string space);
void cetakTreePostOrder(Node * node, string space);

//deklarasi root
Node *root;

int i = 1;

int main(){

	Node * root = new Node("Abdullah","CEO");
	Node * level_11 = new Node("Hendra","Marketing Devision");
	Node * level_12 = new Node("Sulaeman",\
								"Research & Development");
	Node * level_111 = new Node("Wawan","Sales");
	Node * level_112 = new Node("Winda","Sales");
	Node * level_121 = new Node("Rachmah","Analyst System");
	Node * level_122 = new Node("Faqih","Programmer");

	root->induk = nullptr;
	root->kiri = level_11;
	root->kanan = level_12;

	level_11->induk = root;
	level_11->kiri = level_111;
	level_11->kanan = level_112;

	level_12->induk = root;
	level_12->kiri = level_121;
	level_12->kanan = level_122;

	level_111->induk = level_11;
	level_111->kiri = nullptr;
	level_111->kanan = nullptr;
	
	level_112->induk = level_11;
	level_112->kiri = nullptr;
	level_112->kanan = nullptr;
	
	level_121->induk = level_12;
	level_121->kiri = nullptr;
	level_121->kanan = nullptr;

	level_122->induk = level_12;
	level_122->kiri = nullptr;
	level_122->kanan = nullptr;
	cout << "Berikut ini data dalam struktur tree:\n";
	cetakTree(root, "");
	cout << endl;
	i = 1;
	cout << "Berikut ini data dalam struktur tree Pre Order:\n";
	cetakTreePreOrder(root, "");
	cout << endl;
	i = 1;
	cout << "Berikut ini data dalam struktur tree In Order:\n";
	cetakTreeInOrder(root, "");
	cout << endl;
	i = 1;
	cout << "Berikut ini data dalam struktur tree Post Order:\n";
	cetakTreePostOrder(root, "");
	cout << endl;

	system("pause");
	return 0;
}

void cetakTree(Node * node, string space){
	if(node != NULL){
		cout << space << i << ". Node: \n"
				<< space << "Nama: " << node->nama << endl
				<< space << "Posisi: " << node->posisi
				<< endl << endl;
				i++;
		cetakTree(node->kiri, space+" ");
		cetakTree(node->kanan, space+" ");
	}
}

void cetakTreePreOrder(Node * node, string space){
if(node != NULL){
	
		cout << space << i << ". Node: \n"	
		<< space << "Nama: " << node->nama << endl
		<< space << "Posisi: " << node->posisi<< endl << endl;
		i++;
		cetakTree(node->kiri, space+" ");
		cetakTree(node->kanan, space+" ");
	
	}
}

void cetakTreeInOrder(Node * node, string space){
if(node != NULL){
		cetakTreeInOrder(node->kiri, space+" ");
		cout << space << i << ". Node: \n"
		<< space << "Nama: " << node->nama << endl
		<< space << "Posisi: " << node->posisi
		<< endl << endl;
		i++;
		cetakTree(node->kanan, space+" ");
	}
}

void cetakTreePostOrder(Node * node, string space){
	if(node != NULL){
		cetakTreePostOrder(node->kiri, space+" ");
		cetakTreePostOrder(node->kanan, space+" ");
		cout << space << i << ". Node: \n"
		<< space << "Nama: " << node->nama << endl
		<< space << "Posisi: " << node->posisi
		<< endl << endl;
		i++;
	}
}
