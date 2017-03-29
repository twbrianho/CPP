#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  string lineStr;
  while(getline(cin,lineStr)) {
    istringstream iss(lineStr);
    string word;
    while(iss>>word){
      cout<<word<<endl;
    }
  }
  return 0;
}
