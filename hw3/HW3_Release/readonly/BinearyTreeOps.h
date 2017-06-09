//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
#ifndef BinearyTree_h
#define BinearyTree_h

#include <string>

class Node
{
public:
    int weight; // weight can be negative!
    Node *left, *right;
    Node():weight(0),left(NULL),right(NULL){}
    Node(int d):weight(d),left(NULL),right(NULL){}
};

class BinearyTreeOps
{
public:
//----------------------------------------------------------------------
// Input a tree string in S-expression, construct the tree and
// return the pointer to its root node.
//----------------------------------------------------------------------
virtual Node* constructTree(Node *root, std::string treeStr)const;

//----------------------------------------------------------------------
// Delete and release the memory allocation of each node, and
// return a nullptr.
//----------------------------------------------------------------------
virtual Node* deleteTree(Node *root)const;

//----------------------------------------------------------------------
// Return the height of the tree.
//----------------------------------------------------------------------
virtual int treeHeight(const Node *root)const;

//----------------------------------------------------------------------
// Return the sum of node weights.
//----------------------------------------------------------------------
virtual int treeWeight(const Node *root)const;

//----------------------------------------------------------------------
// Return the number of leaf nodes.
//----------------------------------------------------------------------
virtual int leafNum(const Node *root)const;

//----------------------------------------------------------------------
// Return the max path weight from root to leaf.
//----------------------------------------------------------------------
virtual int minPathWeight(const Node *root)const;
};

#endif

//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
