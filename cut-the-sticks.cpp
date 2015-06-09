#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    int n = 0;
    cin>> n;
    int sticks[n];
    string temp = "";
    cin.ignore(); // The savior of the nation!!!!!
    getline(cin,temp);
    int menor = temp[0];
    //Searches for the min element in the array
    for(int i = 0 ; i < temp.size();i++)
    {
        if(temp[i] < menor)
            menor = temp[i];
    }
    vector <int> resultado;
    cout <<"dsad "<< temp.size();
    bool op = true;
    int num_cuts = 0;
    while(op)
    {
        op = false;
        for ( int i = 0; i < temp.size();i++)
        {
            if(temp[i] > 0)
            {
                temp[i] -= menor;
                op = true;
                num_cuts++;
            }
        }
        resultado.push_back(num_cuts);
        num_cuts = 0;
    }
    for (vector<int>::iterator it = resultado.begin(); it != resultado.end(); ++it)
        cout << ' ' << *it;
    cout << resultado.size();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
