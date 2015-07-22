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
#include <string>
#include <string.h>

using namespace std;

int A[1000000];
string text[1000000 ],bla[1000000];

void counting_sort(int entry[],string C[],string D[],int sizis)
{
    int histogram[100];
    for(int i = 0; i < 100; i ++)
    {
        histogram[i] = 0;
    }
    for(int i = 0; i < sizis; i ++)
    {
        histogram[entry[i]] = histogram[entry[i]] + 1;
    }
    for(int i = 1; i < 100; i ++)
    {
        histogram[i] = histogram[i] + histogram[i - 1];
    }
    for(int i = sizis - 1; i >= 0; i --)
    {
        //out[histogram[entry[i]]]  = entry[i];
        if(i < sizis / 2)
            D[histogram[entry[i]]] = "-";
        else
            D[histogram[entry[i]]] = C[i];
        histogram[entry[i]] = histogram[entry[i]] - 1;
    }

}


int main(void)
{
    int T = 0;
    cin >> T;
    for(int i = 0; i < T; i ++)
    {
        cin>>A[i]>>text[i];
    }
    counting_sort(A,text,bla,T);
    for(int i = 1; i <= T; i ++)
    {
        cout<<bla[i]<<" ";
    }
}
