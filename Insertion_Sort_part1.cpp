#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int counts = 0;
void swaps(int pos_a,int pos_b, int arr[])
{
    int tmp = arr[pos_a];
    arr[pos_a] = arr[pos_b];
    arr[pos_b] = tmp;
}

void print_array(int tgt[],int sz)
{
    for(int i = 0 ; i < sz;i++)
    {
        cout<<tgt[i]<<" ";
    }
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
            counts++;
           // print_array(ar,sizis);
          //  cout<<"\n";
        }
        ar[j + 1] = key;
    }

}


int main(void) {
   int _ar_size;
   cin >> _ar_size;
   int _ar[_ar_size];
   for(int _ar_i=0; _ar_i<_ar_size; _ar_i++)
   {
      int _ar_tmp;
      cin >> _ar_tmp;
      _ar[_ar_i] = _ar_tmp;
   }

   insertionSort(_ar,_ar_size);
    print_array(_ar,_ar_size);
    cout << counts;


   return 0;
}
