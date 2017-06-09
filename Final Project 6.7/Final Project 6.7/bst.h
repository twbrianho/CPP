#ifndef _BST_H_
#define _BST_H_

#include <vector>
#include "datatype.h"

//Recursive function for NewBike to call.
BNode* Insert(LicenseType License, BNode* t, BikePtr bikeptr);

//Recursive function for Remove to call.
BNode* FindMax(BNode* t);

//Recursive function for JunkIt to call.
BNode* Remove(LicenseType License, BNode* t, BNode* junk);

//Locate Bnode with corresponding License.
BNode* Find(LicenseType License, BNode* t);

//Print BST in preorder traversal.
void PreorderPrint(BNode* t, std::vector<LicenseType>& preorder);

//Print BST in inorder traversal.
void InorderPrint(BNode* t, std::vector<LicenseType>& inorder);

#endif
