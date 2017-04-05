#include <iostream>
#include <string>
using namespace std;

int main(){
  string cmd = "012345";
  if(cmd.substr(0,9)=="012345678") cout << "Okay.";
  return 0;
}
