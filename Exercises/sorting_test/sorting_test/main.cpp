#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>

using namespace std;

vector<char> flipSort(vector<char> v){
    int l = v.size();
    char temp;
    for (int i = 0 ; i < ( l - 1 ); i++)
    {
        for (int j = 0 ; j < l - i - 1; j++)
        {
            if (v[j] > v[j+1])
            {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
    return v;
}

int main(){
    string input;
    stringstream ss;
    while (getline(cin, input)) {
        vector<char> v;
        ss << input;
        char c;
        int spaces = 0;
        for(int i = 0; i < input.length(); i++){
            if(input[i] == ' '){
                spaces++;
            }
        }
        while (ss >> c) v.push_back(c);
        ss.str("");
        ss.clear();
        
        v = flipSort(v);
        for(int i = 0; i < spaces; i++)cout << ' ';
        for(int i = 0; i < v.size(); i++){
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}
