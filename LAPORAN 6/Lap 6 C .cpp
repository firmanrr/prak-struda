#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// deklarasi struktur double linked node
struct Node
{
	int angka;
	string posisi;
	Node *induk;
	Node *kiri;
	Node *kanan;
	Node(int ang)
	{
		angka = ang;
	}
};
// method cetak tree
void preorder(Node *node, string space);
void postorder(Node *node, string space);
void inorder(Node *node, string space);
void deleteTree(Node *node);

// deklarasi root
Node *root;
int i = 0;

int main()
{
	Node *root = new Node(77);

	//

	Node *level_11 = new Node(11);

	Node *level_111 = new Node(10);
	Node *level_1111 = new Node(7);
	Node *level_1112 = new Node(8);

	Node *level_112 = new Node(4);
	Node *level_1121 = new Node(1);
	Node *level_1122 = new Node(2);

	// 

	Node *level_12 = new Node(62);

	Node *level_121 = new Node(48);
	Node *level_1211 = new Node(3);
	Node *level_1212 = new Node(33);

	Node *level_122 = new Node(2);
	Node *level_1221 = new Node(-5);
	Node *level_1222 = new Node(1);

	root->induk = nullptr;
	root->kiri = level_11;
	root->kanan = level_12;

	//

	level_11->induk = root;
	level_11->kiri = level_111;
	level_11->kanan = level_112;
	level_12->induk = root;
	level_12->kiri = level_121;
	level_12->kanan = level_122;

	//

	level_111->induk = level_11;
	level_111->kiri = level_1111;
	level_111->kanan = level_1112;
	level_112->induk = level_11;
	level_112->kiri = level_1121;
	level_112->kanan = level_1122;

	level_1111->induk = level_111;
	level_1111->kiri = nullptr;
	level_1111->kanan = nullptr;

	level_1112->induk = level_111;
	level_1112->kiri = nullptr;
	level_1112->kanan = nullptr;

	level_1121->induk = level_112;
	level_1121->kiri = nullptr;
	level_1121->kanan = nullptr;

	level_1122->induk = level_112;
	level_1122->kiri = nullptr;
	level_1122->kanan = nullptr;


	//

	level_121->induk = level_12;
	level_121->kiri = level_1211;
	level_121->kanan = level_1212;
	level_122->induk = level_12;
	level_122->kiri = level_1221;
	level_122->kanan = level_1222;

	level_1211->induk = level_121;
	level_1211->kiri = nullptr;
	level_1211->kanan = nullptr;

	level_1212->induk = level_121;
	level_1212->kiri = nullptr;
	level_1212->kanan = nullptr;

	level_1221->induk = level_122;
	level_1221->kiri = nullptr;
	level_1221->kanan = nullptr;

	level_1222->induk = level_122;
	level_1222->kiri = nullptr;
	level_1222->kanan = nullptr;

	
	deleteTree(level_12);

	cout << "Berikut ini data dalam struktur PREORDER:\n";
	cout << "===========================================" << endl;
	preorder(root, "");
	
	cout << "Berikut ini data dalam struktur INORDER:\n";
	cout << "===========================================" << endl;
	i = 0;
	inorder(root, "");
	
	cout << "Berikut ini data dalam struktur POSTORDER:\n";
	cout << "===========================================" << endl;
	i = 1;
	postorder(root, "");
	
	cout << endl;
	system("pause");
	return 0;
}

void preorder(Node *node, string space)
{
	if (node != NULL)
	{
		i++;
		cout << space << i << ". Node: \n"
			 << space << "ANGKA: " << node->angka << endl
			 << endl;
		preorder(node->kiri, space + " ");
		preorder(node->kanan, space + " ");
	}
}

void inorder(Node *node, string space)
{
	if (node != NULL)
	{

		inorder(node->kiri, space + " ");
		i++;
		cout << space << i << ". Node: \n"
			 << space << "ANGKA: " << node->angka << endl
			 << endl;

		inorder(node->kanan, space + " ");
	}
}

void postorder(Node *node, string space)
{
	if (node != NULL)
	{

		postorder(node->kiri, space + " ");
		postorder(node->kanan, space + " ");
		cout << space << i << ". Node: \n"
			 << space << "ANGKA: " << node->angka << endl
			 << endl;

		i++;
	}
}

void deleteTree(Node *node)
{

    if (root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {

        if (node != NULL)
        {
            if (node == node->induk->kanan)
            {
                node->induk->kanan = NULL;
            }else{

				node->induk->kiri = NULL;

			}
            deleteTree(node->kiri);
            deleteTree(node->kanan);

            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
		}
	}
}
