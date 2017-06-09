#include <iostream>
#include <vector>
#include <iomanip>
#include "function.h"

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

//Create new BNode and BikeType.
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
    
    cout << "New bike is received by Station " << Station << endl;
    
    return bnode;
}

//Destroy BNode and BikeType.
void JunkIt(LicenseType License, BNode* t)
{
    BNode* junk = Find(License, t);
    if(junk == NULL){
        cout << "Bike " << License << " does not belong to our company." << endl;
    }
    else{
        if(junk->bikeptr->Status == Rented){
            cout << "Bike " << License << " is now being rented." << endl;
        }
        else{
            cout << "Bike " << License << " is deleted from " << junk->bikeptr->Station << "." << endl;
            Remove(License, t, junk);
        }
    }
    return;
}

//Print summary of BikeType, specified by License.
BNode* Inquire(LicenseType License, BNode* t){
    BNode* target = Find(License, t);
    if(target == NULL){
        cout << "Bike " << License << " does not belong to our company." << endl;
    }
    else{
        cout << setw(15) << "License" << setw(15) << "Mileage"<< setw(15) << "Class" << setw(15) << "Station"<< endl;
        cout << "============================================================" << endl;
        cout << setw(15) << target->bikeptr->License << setw(15) << target->bikeptr->Mileage << setw(15) << target->bikeptr->Class << setw(15) << target->bikeptr->Station << endl;
    }
    return target;
}

//Print the Binary Search Tree in preorder, then inorder.
void BReport(BNode* t){
    cout << "Binary Search Tree" << endl;
    vector<LicenseType> preorder;
    PreorderPrint(t, preorder);
    for(int i=0; i<preorder.size(); i++){
        cout << preorder[i];
        if(i!=preorder.size()-1)cout << "->";
    }
    vector<LicenseType> inorder;
    InorderPrint(t, inorder);
    for(int i=0; i<inorder.size(); i++){
        cout << inorder[i];
        if(i!=inorder.size()-1)cout << "->";
    }
    return;
}
