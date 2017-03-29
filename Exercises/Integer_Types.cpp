#include <iostream>
#include <limits>

using namespace std;

int main() {

  int value = 54656;
  cout << value << endl;

  cout << "Max int value = " << INT_MAX << endl;
  cout << "Min int value = " << INT_MIN << endl;

  long int lValue = 1232314025123;
  cout << lValue << endl;

  short int sValue = 12344;
  cout << sValue << endl;

  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of short: " << sizeof(short) << endl;

  unsigned int uValue = 1234141;
  cout << uValue << endl;

  return 0;
}
