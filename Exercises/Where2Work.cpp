#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
  srand (time(NULL));
  rand();rand();rand();
  int choice = rand() % 7 + 1;
  cout << endl << endl << endl;
  cout << "YOUR IDEAL STUDY LOCATION FOR TODAY IS:" << endl;
  cout << "---------------------------------------" << endl;
  switch (choice){
    case 1:
    cout << "Waffles" << endl; break;
    case 2:
    cout << "Starbucks" << endl; break;
    case 3:
    cout << "Smile Cafe" << endl; break;
    case 4:
    cout << "Water Work Bird" << endl; break;
    case 5:
    cout << "Library" << endl; break;
    case 6:
    cout << "That really nice tiny coffee shop" << endl; break;
    case 7:
    cout << "Look for a new place!" << endl; break;
    default:
    cout << "An error has occurred..." << endl; break;
  }
  cout << "---------------------------------------" << endl;
  cout << endl << endl;

  return 0;
}
