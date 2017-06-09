#include <iostream>
using namespace std;

int main(){
  long long int denum = 1;
  for(int i = 1; i < 21; i++){
    denum *= (1+i)*i/2;
  }
  long long int num = 0;
  for(int i = 1; i < 21; i++){
    num += denum / ((1+i)*i/2);
  }
  cout << num << "/" << denum << endl;
  return 0;
}
