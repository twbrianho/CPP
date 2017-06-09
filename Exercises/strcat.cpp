#include <iostream>
#include <string>

using namespace std;

int main(){
  char teststring[50] = "Here is the string: ";
  cout << teststring << endl;
  strcat (teststring, "Hello ");
  cout << teststring << endl;
  strcat (teststring, "Fiona.");
  cout << teststring << endl;

  return 0;
}
