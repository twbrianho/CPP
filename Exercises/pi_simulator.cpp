#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int
gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main(){

  int coprime=0;

  srand (time(NULL));

  for(int i=0; i<1000; i++){
    if(gcd(rand(),rand())==1)coprime++;
  }

  float x=coprime/1000;
  float sim_pi=sqrt(6/x);
  cout<<sim_pi<<endl;

  return 0;
}
