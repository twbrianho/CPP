 //========================DO-NOT-MODIFY-THE-FILE========================

#include <iostream>
#include <string>
#include <fstream>
#include "../Implement.h"

void tryTestCase(Chain &inst, std::string testfile)
{
    std::ifstream ifs(testfile);

    if( !ifs.good() )
        throw "[Missing Test File]";

    std::string op, result;
	int value1, value2;
    while( ifs >> op )
    {
		if( op == "InsertBack" )
        {
            ifs >> value1;
			inst.InsertBack(value1);
		}
		else if( op == "InsertAfter" )
        {
			ifs >> value1 >> value2;
            inst.InsertAfter(value1, value2);
		}
		else if( op == "Delete" )
        {
			ifs >> value1;
            inst.Delete(value1);
		}
		else if( op == "DeleteAll" )
        {
			ifs >> value1;
            inst.DeleteAll(value1);
		}
		else if( op == "EndR" )
        {
            ifs >> result;
			if( result != inst.toString() )
                throw "[Wrong Answer]";
                //cout << result;

		}
		else if( op == "EndL" )
        {
            ifs >> result;
			if( result != inst.toStringL() )
                throw "[Wrong Answer]";
                //cout << result;

		}
    }

    ifs.close();
}

int main(int argc, char *argv[])
{
	std::string testfile = argc==1 ? "1.in" : argv[1];
    try
    {
        Implement inst;
        tryTestCase( inst, testfile );
        std::cout << "[Accepted]" << std::endl;
    }
    catch(const char *e)
    {
        std::cout << e << std::endl;
    }
    return 0;
}

//========================DO-NOT-MODIFY-THE-FILE========================
