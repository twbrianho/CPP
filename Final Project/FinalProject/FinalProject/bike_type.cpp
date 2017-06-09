#include <iostream>
#include "bike_type.h"

using namespace std;

//StationType reader.
StationType ReadStation(string Station){
    if(Station == "Danshui")return Danshui;
    else if(Station == "Hongshulin")return Hongshulin;
    else if(Station == "Beitou")return Beitou;
    else if(Station == "Shilin")return Shilin;
    else if(Station == "Zhongshan")return Zhongshan;
    else if(Station == "Xinpu")return Xinpu;
    else if(Station == "Ximen")return Ximen;
    else if(Station == "Liuzhangli")return Liuzhangli;
    else if(Station == "Muzha")return Muzha;
    else if(Station == "Guting")return Guting;
    else if(Station == "Gongguan")return Gongguan;
    else if(Station == "Jingmei")return Jingmei;
    else throw;
}

//ClassType reader.
ClassType ReadClass(string Class){
    if(Class == "Electric")return Electric;
    else if(Class == "Lady")return Lady;
    else if(Class == "Road")return Lady;
    else if(Class == "Hybrid")return Lady;
    else throw;
}

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

//
BNode* NewBike(LicenseType License, int Mile, ClassType Class, StationType Station, BNode* root)
{
    BikeType temp;
    temp = *new BikeType;
    for( int i = 0 ; i < 6 ; i++ ){
        temp.License[i] = License[i];
    }
    temp.Mileage = Mile;
    temp.Class = Class;
    temp.Station = Station;
    temp.Status = Free;
    BikePtr bikeptr = &temp;
    
    BNode* bnode = Insert(License, root, bikeptr);
    
    //Insert code to add node in Heap
    //...
    
    return bnode;
}

//Recursive function for SearchBike to call.
BNode* PreorderSearch(LicenseType License, BNode* t)
{
    if(t == NULL)return NULL;
    if(t->license == License)return t;;
    PreorderSearch(License, t->left);
    PreorderSearch(License, t->right);
    return NULL;
}

BNode* SearchBike(LicenseType License, BNode* root)
{
    BNode* bikeptr = PreorderSearch(License, root);
    return bikeptr;
}

//Recursive function for Remove to call.
BNode* FindMin(BNode* t)
{
    if(t == NULL)
        return NULL;
    else if(t->left == NULL)
        return t;
    else
        return FindMin(t->left);
}

//Recursive function for JunkIt to call.
BNode* Remove(LicenseType License, BNode* t)
{
    BNode* temp;
    if(t == NULL)return NULL;
    else if(License < t->license)t->left = Remove(License, t->left);
    else if(License > t->license)t->right = Remove(License, t->right);
    else if(t->left && t->right)
    {
        temp = FindMin(t->right);
        for( int i = 0 ; i < 6 ; i++ ){
            t->license[i] = temp->license[i];
        }
        t->right = Remove(t->license, t->right);
    }
    else
    {
        temp = t;
        if(t->left == NULL)
            t = t->right;
        else if(t->right == NULL)
            t = t->left;
        delete temp;
    }
    return NULL;
}

int JunkIt(LicenseType License, BNode* t)
{
    int i = 1;
    Remove(License, t);
    return i;
}

BNode* Find(LicenseType License, BNode* t)
{
    if(t == NULL)
        return NULL;
    else if(License < t->license)
        return Find(License, t->left);
    else if(License > t->license)
        return Find(License, t->right);
    else
        return t;
}

BNode* Inquire(LicenseType License, BNode* t){
    BNode* target = Find(License, t);
    return target;
}

void BReport(){
    //Inorder and preorder.
}

void inorder(BNode* t)
{
    if(t == NULL)
        return;
    inorder(t->left);
    cout << t->license << " ";
    inorder(t->right);
}



