#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void)
{
  string lineStr;
  while(getline(cin,lineStr)) {
    istringstream iss(lineStr);
    string word;
    int count = 0;
    while(iss >> word){
      count++;
    }
    cout << count << endl;
  }
  return 0;
}
