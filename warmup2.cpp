#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int length = 0;
    int T = 0;
    cin>>length>>T;
    int width[T];
    string temp;
    getline(cin,temp);
    for(int i = 0; i < T; i ++)
    {
       width[i] = (int)temp[i];
    }

     for(int i = 0; i < T; i ++)
    {
       cout << width[i]<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}\
