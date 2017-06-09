#ifndef UBIKE_H
#define UBIKE_H

enum StatusType { Free, Rented };

enum ClassType { Electric, Lady, Road, Hybrid };

enum StationType { Danshui, Hongshulin, Beitou, Shilin, Zhongshan, Xinpu, Ximen, Liuzhangli, Muzha, Guting, Gongguan, Jingmei };

typedef char LicenseType[6];

struct BikeType{
    LicenseType License;
    StatusType Status;
    int Mileage; /* most recently rented mileage */
    int Cursor; /* cursor to the entry in heap where there is a pointer to this node */
    StationType Station;
    ClassType Class;
};

typedef struct BikeType *BikePtr;

class BNode{
public:
    LicenseType license;
    BNode* left;
    BNode* right;
    BikeType* bikeptr;
};

#endif
