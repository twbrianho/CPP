//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
#include "Node.h"

Node::Node()
{
	this->left = NULL;
	this->right = NULL;
}

Node::Node(const int e, Node* left, Node* right) 
{
	this->data = e;
	this->left = left;
	this->right = right;
}

Node::~Node()
{
	this->left = NULL;
	this->right = NULL;
}
//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
