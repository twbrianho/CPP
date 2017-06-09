//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================

#include <iostream>
#include <fstream>
#include "../MyBinaryTreeOps.h"

void tryTestCase(MyBinaryTreeOps &mbtops, std::string testfile)
{
    std::ifstream ifs(testfile);
    if( !ifs.good() )
        throw "[Missing Test File]";
    
    // parse each case
    std::string treeSExp;
    int treeHeight, treeWeight, leafNum, minPathWeight;
    while( ifs >> treeSExp )
    {
        ifs >> treeHeight >> treeWeight >> leafNum >> minPathWeight;
        
        // the pointer to the tree root
        Node *root;
        
        // construct the tree
        root = mbtops.constructTree( root, treeSExp );
        
        int myTreeHeight    = mbtops.treeHeight( root );
        int myTreeWeight    = mbtops.treeWeight( root );
        int myLeafNum       = mbtops.leafNum( root );
        int myMinPathWeight = mbtops.minPathWeight( root );
        
        // release the tree
        root = mbtops.deleteTree( root );
        
        // check the answer
        if( myTreeHeight != treeHeight )
            throw "[Wrong Height]";
        
        if( myTreeWeight != treeWeight )
            throw "[Wrong Weight]";
        
        if( myLeafNum != leafNum )
            throw "[Wrong LeafNum]";
        
        if( myMinPathWeight != minPathWeight )
            throw "[Wrong PathWeight]";
    }
    
    ifs.close();
}


int main(int argc, char* argv[])
{
    std::string testfile = argc==1 ? "1.in" : argv[1];
    
    try
    {
        MyBinaryTreeOps mbtops;
        tryTestCase( mbtops, testfile );
        std::cout << "[Accepted]" << std::endl;
    }
    catch(const char *e)
    {
        std::cout << e << std::endl;
    }
    
    return 0;
}

//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
