#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int lefts[1000000];
int rights[1000000];
int ar[1000000];
int rola = 0;

int main()
{
    memset(lefts,0,sizeof(lefts));
    memset(rights,0,sizeof(rights));
    int T,N = 0;
    cin>>N;
    for(int a = 0; a < N; a ++)
    {
        cin>> T;
        for(int i = 0; i < T; i ++)
        {
            cin>>rola;
            ar[i] = rola;
        }
        int i = 1;
        int j = T - 2;
        lefts[0] = 0;
        rights[T - 1] = 0;
        while(i < T && j >=0)
        {
            lefts[i] += ar[i - 1] + lefts[i - 1] ;
            rights[j] += ar[j + 1] + rights[j + 1];
            i++;j--;
        }
        /*for(int i = 0; i< T;i++)
        {
            cout<<lefts[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i< T;i++)
        {
            cout<<rights[i]<<" ";
        }*/
        i = 1; j = 1;
        bool found = false;
          if(T == 1)
            {

        found = true;

            }
        while(i <= T - 1)
        {
            if(lefts[i] == rights[j])
            {
                found = true;
                break;
            }
            else
            {
                i++;
                j++;
            }
        }
        if(found)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        memset(lefts,0,sizeof(lefts));
        memset(rights,0,sizeof(rights));
        memset(ar,0,sizeof(rights));
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
