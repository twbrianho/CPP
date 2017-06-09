#include <iostream>
using namespace std;

int main(){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      int x[8] = {i+1, i+2, i+2, i+1, i-1, i-2, i-2, i-1};
      int y[8] = {j-2, j-1, j+1, j+2, j+2, j+1, j-1, j+2};
      for(int k = 0; k < 8; k++){
        if(x[k] >= 0 && y[k] >= 0 && x[k] < 8 && y[k] < 8)cout << "g.addEdge(" << i + j * 8 << ", " << x[k] + y[k] * 8 << ");" << endl;
      }
    }
  }
  return 0;
}
