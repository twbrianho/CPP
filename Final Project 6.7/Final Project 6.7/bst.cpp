#include <iostream>
#include <vector>
#include "bst.h"

using namespace std;

//Recursive function for NewBike to call.
BNode* Insert(LicenseType License, BNode* t, BikePtr bikeptr)
{
    if(t == NULL)
    {
        t = new BNode;
        for( int i = 0 ; i < 6 ; i++ ){
            t->license[i] = License[i];
        }
        t->left = t->right = NULL;
        t->bikeptr = bikeptr;
    }
    else if(License < t->license)
        t->left = Insert(License, t->left, bikeptr);
    else if(License > t->license)
        t->right = Insert(License, t->right, bikeptr);
    return t;
}

//Recursive function for Remove to call.
BNode* FindMax(BNode* t)
{
    if(t == NULL)
        return NULL;
    else if(t->right == NULL)
        return t;
    else
        return FindMax(t->right);
}

//Recursive function for JunkIt to call.
BNode* Remove(LicenseType License, BNode* t, BNode* junk)
{
    if(junk->left == NULL && junk->right == NULL){
        goto del;
    }
    else if(junk->left == NULL && junk->right != NULL){
        junk->left = junk->right->left;
        junk->right = junk->right->right;
        for( int i = 0 ; i < 6 ; i++ ){
            junk->license[i] = junk->right->license[i];
        }
        Remove(junk->right->license, t, junk->right);
    }
    else{
        BNode* max;
        max = FindMax(junk);
        junk->left = max->left;
        junk->right = max->right;
        for( int i = 0 ; i < 6 ; i++ ){
            junk->license[i] = max->license[i];
        }
        Remove(max->license, t, max);
    }
    del:
        delete junk->bikeptr;
        delete junk;
        return NULL;
}

//Locate Bnode with corresponding License.
BNode* Find(LicenseType License, BNode* t)
{
    if(t == NULL)
        return NULL;
    else if(License < t->license)
        return Find(License, t->left);
    else if(License > t->license)
        return Find(License, t->right);
    else if(License == t->license)
        return t;
}

//Print BST in preorder traversal.
void PreorderPrint(BNode* t, vector<LicenseType>& preorder)
{
    if(t == NULL)
        return;
    if(t->right != NULL) preorder.push_back(t->license);
    PreorderPrint(t->left, preorder);
    PreorderPrint(t->right, preorder);
}

//Print BST in inorder traversal.
void InorderPrint(BNode* t, vector<LicenseType>& inorder)
{
    if(t == NULL)
        return;
    InorderPrint(t->left, inorder);
    if(t->right != NULL)inorder.push_back(t->license);
    InorderPrint(t->right, inorder);
}


