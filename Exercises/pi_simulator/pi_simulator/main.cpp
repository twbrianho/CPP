#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int gcd ( int a, int b )
{
    int c;
    while ( a != 0 ) {
        c = a; a = b%a;  b = c;
    }
    return b;
}

int main(){
/*
    srand(time(NULL));
    float sum_pi=0;
    
    for(int i=0; i<1000000000; i++){
        float coprime=0;
        for(int i=0; i<10000000; i++){
            if(gcd(rand(),rand())==1)coprime++;
        }
        
        float x=coprime/10000000;
        float sim_pi=sqrt(6/x);

        float avg_pi=(sim_pi+sum_pi*i)/(i+1);
        cout<<avg_pi<<endl;
        sum_pi=avg_pi;
    }
    
    cout<<"Pi is around: "<<sum_pi<<endl;
*/
    long double sum=0;
    float i=1;
    long double calc_pi=0;
    while(calc_pi<3.14159){
        sum+=1/(i*i);
        calc_pi=sqrt(sum*6);
        cout<<i<<" "<<calc_pi<<endl;
        i++;
    }
    return 0;
}
