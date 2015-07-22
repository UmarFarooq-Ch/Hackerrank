#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

bool numeros[1000001];
long long histogram[1000001];

int main()
{
    memset(histogram,0,sizeof(histogram));
    memset(numeros,false,1000000);
    int T,N,temp = 0;
    long long repetitions = 0;
    cin>> T;
    for(int i = 0; i < T; i ++)
    {
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            cin >> temp;
            if(numeros[temp])
            {
                histogram[temp]++;
            }
            else
                numeros[temp] = true;
        }
        for(long long i = 0; i <= 1000000;i++)
        {
            if(histogram[i] > 0)
                repetitions+= (histogram[i] + 1) * (histogram[i]);
        }
        cout<<repetitions<<endl;
        repetitions = 0;
        memset(numeros,false,sizeof(numeros));
        memset(histogram,0,sizeof(histogram));
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
