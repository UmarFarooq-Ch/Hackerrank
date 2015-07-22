#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void shift(int vetor[],int aux[],int sizis, int num_shifts)
{
    int temp = vetor[0];
    int temp2 = vetor[1];
    for(int i = 0; i  < sizis; i ++)
    {
        aux[(num_shifts+i)%sizis] =  vetor[i];
    }
}

int main()
{
    int N,Q,K = 0;
    cin >> N >> K >> Q;
    int ar[N],aux[N];
    for(int i = 0; i < N; i ++)
    {
        cin>>ar[i];
    }
    int temp = 0;
    shift(ar,aux,N,K);
    for(int i = 0 ; i < Q; i ++)
    {
        cin>> temp;
        cout<<aux[temp]<<endl;
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
