#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include "station_graph.h"
#include "bst.h"
#include "heap.h"
#include "datatype.h"

using namespace std;

StationType ReadStation(string Station);
//StationType reader.


ClassType ReadClass(string Class);
//ClassType reader.


BNode* NewBike(LicenseType License, int Mile, ClassType Class, StationType Station, BNode* root);
//Create new BNode and BikeType.
/////////////////////////////////////////
//Input : NewBike Lady 00000 0 Hongshulin
//Output : New bike is received by Station Hongshulin.
/////////////////////////////////////////


void JunkIt(LicenseType License, BNode* t);
//Destroy BNode and BikeType.
/////////////////////////////////////////
//1. General case.
//Input : JunkIt TPI01
//Output : Bike TPI01 is deleted from Danshui.
//
//2. If the bike is now being rented.
//Input : JunkIt TPI03
//Output : Bike TPI03 is now being rented.
//
//3. If the bike doesn't exist.
//Input : JunkIt KKK23
//Output : Bike KKK23 does not belong to our company.
/////////////////////////////////////////


BNode* Inquire(LicenseType License, BNode* t);
//Print summary of BikeType, specified by License.
/////////////////////////////////////////
//1. If the bike does not exist.
//Input : Inquire 00BC4
//Output : Bike 00BC4 does not belong to our company.
//
//2. General case.
//Input : Inquire 00BC4
//Output : #include<iomanip>
//         cout << setw(15) << "License" << setw(15) << "Mileage"<< setw(15)
//         << "Class" << setw(15) << "Station"<< endl;
//         cout << "============================================================" << endl;
//         cout << setw(15) << ...->License; << setw(15) << ...->Mileage << setw(15)
//         << ...->Class << setw(15) << ...->Station << endl;
/////////////////////////////////////////


void BReport();
//Print the Binary Search Tree in preorder, then inorder.
/////////////////////////////////////////
//Input : BReport
//Output : The first line is “Binary Search Tree”.
//         The second line is the preorder of the BST.
//         The third line is the inorder of the BST.
/////////////////////////////////////////


#endif // _FUNCTION_H_
