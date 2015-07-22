#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int counts = 0;

void swaps(int arr[],int target_a,int target_b)
{
    int tmp = arr[target_a];
    arr[target_a] = arr[target_b];
    arr[target_b] = tmp;
}


int partitioning(int _temp_ar[],int s,int e)
{
    int pivot = _temp_ar[e];
    int j = s - 1;
    for(int i = s; i < e; i++)
    {
        if(_temp_ar[i] <= pivot)
        {
            counts++;
            j = j + 1;
            swaps(_temp_ar,i,j);
        }
    }
    swaps(_temp_ar,j+1,e);
    return j + 1;
}


void quicksort(int _ar[],int start,int ends)
{

    if(start < ends)
    {
        int q = partitioning(_ar,start,ends);
        quicksort(_ar,start,q - 1);
        quicksort(_ar,q+1,ends);
    }
}

int main()
{
    int T,k,counter = 0;
    cin>>T>>k;
    int ar[T];
    for(int i = 0; i < T; i ++)
    {
        cin>>ar[i];
    }
    quicksort(ar,0,T - 1);
     for(int i = 0; i < T;  i++)
    {
        cout <<ar[i]<<" ";
    }
    int i = 0; int j = T - 1;
    while (i < T) {
        while( j > 0)
        {
            if(ar[j] - ar[i] == k)
            {
                cout<<ar[j]<<" "<<ar[i]<<endl;
                break;
            }
            j--;
        }

        if (ar[j] - ar[i] == k)
        {
            counter++;
           // cout<<i<<" "<<j;
        }
        j = T - 1;
        i++;
    }
    cout << counter;
    return 0;
}
