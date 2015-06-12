#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;



int calculate_min(int vetor[],int t)
{
    bool zero = false;
    int menor = vetor[0];
    if(menor == 0)
        zero = true;
    for(int i = 0 ; i < t;i++)
    {
        if(zero && vetor[i] != 0)
        {
            menor = vetor[i];
            zero = false;
        }
        else if(menor > vetor[i] && vetor[i] > 0)
            menor = vetor[i];
    }
    return menor;
}

int main() {
    int n = 0;
    cin>> n;
    int sticks[n];
    //Searches for the min element in the array
     for(int i = 0 ; i < n;i++)
    {
        cin>> sticks[i];
    }
    int menor = calculate_min(sticks,n);
    vector <int> resultado;
    bool op = true;
    int num_cuts = 0;
    while(op)
    {
        op = false;
        for ( int i = 0; i < n;i++)
        {
            if(sticks[i] > 0)
            {
                sticks[i] -= menor;
                op = true;
                num_cuts++;
            }
        }
        if(num_cuts != 0)
            resultado.push_back(num_cuts);
        num_cuts = 0;
        menor = calculate_min(sticks,n);
    }
    for (vector<int>::iterator it = resultado.begin(); it != resultado.end(); ++it)
        if(*it ==resultado.at(resultado.size() - 1))
            cout << *it;
        else
            cout << *it<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
