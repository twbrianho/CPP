#ifndef _DATATYPE_H_
#define _DATATYPE_H_

enum StatusType{
    Free, Rented
};

enum ClassType{
    Electric, Lady, Road, Hybrid
};

enum StationType{
    Danshui, Hongshulin, Beitou, Shilin, Zhongshan, Xinpu,
    Ximen, Liuzhangli, Muzha, Guting, Gongguan, Jingmei
};

typedef char LicenseType[5];

struct BikeType{
    LicenseType License;
    StatusType Status;
    int Mileage; /* most recently rented age. */
    int Cursor; /* cursor to the entry in heap where there is a pointer to this node */
    StationType Station;
    ClassType Class;
};

typedef struct BikeType* BikePtr;

class BNode{
public:
    LicenseType license;
    BNode* left;
    BNode* right;
    BikeType* bikeptr;
};

struct HeapType{
    BikePtr Elem[256]; /* use array to implement heap, and each node in the heap is a pointer. */
    int Number; /* Maximum = 255. */
};

struct StationType{
    int Net; /* total income of station. */
    int NetElectric;
    int NetLady;
    int NetRoad;
    int NetHybrid;
    int NumElectric; /* number of electric bikes. */
    int NumLady; /* number of lady bikes. */
    int NumRoad; /* number of road bikes. */
    int NumHybrid; /* number of hybrid bikes. */
    HeapType HRent;
    HeapType HElectric;
    HeapType HLady;
    HeapType HRoad;
    HeapType HHybrid;
};

#endif // _DATATYPE_H_
