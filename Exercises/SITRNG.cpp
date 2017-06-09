#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){

  int groups = 2;
  string staff[15] = {"Jacky",	"Brian", "Henry",	"Max", "Bill", "Jeffrey", "Alan", "Marrian",	"Violet", "Annie",	"Vivian", "Grace", "Kelly", "Fiona", "Joyce"};
  string fellow[9] = {"Morgan", "Hannah", "Gloria", "Michael", "Nicholas", "Yadi", "Zhenwei", "Daniele",	"Nasrettin"};

  srand (time(NULL));

  cout << "========================" << endl;
  cout << "         STAFF" << endl;
  cout << "========================" << endl;
  int staffused[15] = {0};
  int staffremain = 15%groups;
  for(int j = 0; j < groups; j++){
    cout << "-----------" << endl;
    cout << "  GROUP " << j+1 << endl;
    cout << "-----------" << endl;
    int staffnum = 15/groups;
    if(j<staffremain)staffnum++;
    for(int i = 0; i<staffnum; i++){
      rand();rand();rand();
      int staffrand = rand() % 15;
      if(staffused[staffrand] == 0){
        staffused[staffrand] = 1;
        cout << staff[staffrand] << endl;
      }
      else i--;
    }
  }

  cout << "========================" << endl;
  cout << "         FELLOW" << endl;
  cout << "========================" << endl;
  int fellowused[9] = {0};
  int fellowremain = 9%groups;
  for(int j = 0; j < groups; j++){
    cout << "-----------" << endl;
    cout << "  GROUP " << j+1 << endl;
    cout << "-----------" << endl;
    int fellownum = 9/groups;
    if(j<fellowremain)fellownum++;
    for(int i = 0; i<fellownum; i++){
      rand();rand();rand();
      int fellowrand = rand() % 9;
      if(fellowused[fellowrand] == 0){
        fellowused[fellowrand] = 1;
        cout << fellow[fellowrand] << endl;
      }
      else i--;
    }
  }

  return 0;
}
