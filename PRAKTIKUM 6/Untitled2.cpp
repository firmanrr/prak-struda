#include <stdio.h>
#include <iostream>

class Node
{
public:
	Node( int v )
	{
		data = v;
		left = 0;
		right = 0;
	}

	int data;
	Node* left;
	Node* right;
};

void Add( Node** root, Node* n )
{
	if ( !*root )
	{
		*root = n;
		return;
	}

	if ( (*root)->data < n->data )
	{
		Add( &(*root)->right, n );
	}
		else
	{
		Add( &(*root)->left, n );
	}
}

void Print( Node* node )
{
	if ( !node ) return;
	Print( node->left );
	printf( "value = %i\n", node->data );
	Print( node->right );
}

int main()
{
	Node* root = 0;

	Add( &root, new Node( 1 ) );
	Add( &root, new Node( 2 ) );
	Add( &root, new Node( -1 ) );
	Add( &root, new Node( 12 ) );

	Print( root );
	system("pause");
	return 0;
}
