#ifndef MyBinaryTreeOps_h
#define MyBinaryTreeOps_h

#include "readonly/BinearyTreeOps.h"
#include <sstream>

class MyBinaryTreeOps : public BinearyTreeOps
{
public:
    // add your code here
    //------------------------------------------------------
    Node* constructTree(Node *root, std::string treeStr)const;
    Node* deleteTree(Node *root)const;
    int treeHeight(const Node *root)const;
    int treeWeight(const Node *root)const;
    int leafNum(const Node *root)const;
    int minPathWeight(const Node *root)const;
    //------------------------------------------------------
};

#endif
