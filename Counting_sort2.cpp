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


void counting_sort(int entry[],int out[],int sizis)
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
        out[histogram[entry[i]]]  = entry[i];
        histogram[entry[i]] = histogram[entry[i]] - 1;
    }

}


int main(void)
{
    int T = 0;
    cin >> T;
    int A[T],B[T];
    for(int i = 0; i < T; i ++)
    {
        cin>>A[i];
    }
    counting_sort(A,B,T);
    for(int i = 1; i <= T; i ++)
    {
        cout<<B[i]<<" ";
    }
}
