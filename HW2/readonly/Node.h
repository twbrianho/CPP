//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
#ifndef Node_h
#define Node_h
#include <string>

//The data structure that present a node.
class Node
{
friend class Chain;
public:
    //the pointer to left and right node in the chain
	Node *left, *right;

    //stores the data
    int data;
	
	//constructor and destructor
	Node();
	Node(const int e, Node* left=NULL, Node* right=NULL);
	~Node();
};

#endif
//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
