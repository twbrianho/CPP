#include <iostream>
using namespace std;

int main()
{
  int values[3];

  values[0] = 88;
  values[1] = 123;
  values[2] = 7;

  cout << values[0] << endl;
  cout << values[1] << endl;
  cout << values[2] << endl;

  double numbers[4] = {4.5, 2.3, 7.2, 8.1};

  for(int i=0; i <4; i++)
  {
    cout << numbers[i] << endl;
  }
  return 0;
}
