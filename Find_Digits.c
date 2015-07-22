#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void reset(bool number[])
{
    for(int i = 0; i < 10; i ++)
    {
        number[i] = false;
    }
}

int main() {
    int T = 0;
    bool numbers[10];
    reset(numbers);
    cout<< numbers[0];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
