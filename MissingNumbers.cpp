#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int A[1000000];
int B[1000000];
int aux1[101];
bool check[1000000];
int aux2[101];

void swaps(int pos_a,int pos_b, int arr[])
{
    int tmp = arr[pos_a];
    arr[pos_a] = arr[pos_b];
    arr[pos_b] = tmp;
}

void insertionSort(int  ar[],int sizis)
{
    for(int i = 1; i < sizis;i++ )
    {
        int key = ar[i];
        int j = i - 1;
        while (j >= 0 && ar[j]> key)
        {
            ar[j+1] = ar[j];
            j--;

        }
        ar[j + 1] = key;
    }

}

int main()
{
    int N,T = 0;
    cin>> T;

    int temp = 0;
    for(int i = 0 ; i < T;i++)
    {
        cin>>temp;
       // aux1[i] = temp;
        A[temp]++;
    }
   // aux2[N];
    cin>>N;
    int smallest = 0;
    for(int i = 0 ; i < N;i++)
    {
        cin>>temp;
        if(smallest == 0 || smallest > temp)
            smallest = temp;
       // aux2[i] = temp;
        B[temp]++;
    }
   // insertionSort(aux1,T);
   // insertionSort(aux2,N);

  /*  for(int i =0; i<=N;i++)
    {
       // cout<<A[i]<< "  "<<B[i]<<endl;

            if(A[aux2[i]] != B[aux2[i]] && !check[aux2[i]])
            {
                cout<<aux2[i]<<" ";
                check[aux2[i]] = true;
            }
            if(A[aux1[i]] != B[aux1[i]] && !check[aux1[i]])
            {
                cout<<aux1[i]<<" ";
                check[aux1[i]] = true;
            }
    }
    */

    for(int i =smallest; i<=smallest+100;i++)
    {
       // cout<<A[i]<< "  "<<B[i]<<endl;

            if(A[i] != B[i] && !check[i % 100])
            {
                cout<<i<<" ";
                check[i% 100] = true;
            }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
