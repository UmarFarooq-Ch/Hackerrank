#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;


int main() {
    int  T = 0;
    cin >> T;
    int  number = 0;
    float qt_positives =0.000f;
    float qt_negatives = 0.000f;
    float qt_zeroes = 0.000f;
    for (int i = 0 ; i < (int)T; i ++)
    {
        cin >> number;
        if(number > 0)
            qt_positives += (float)1.000;
        else if(number == 0)
            qt_zeroes ++;
        else
            qt_negatives += (float)1.000;
    }
    qt_positives = (float)qt_positives / (float)T ;
    qt_negatives = qt_negatives / (float)T;
    qt_zeroes = qt_zeroes / (float)T;
    cout.precision(3);
    cout << fixed<< qt_positives<<endl;
    cout <<qt_negatives<<endl;
    cout <<qt_zeroes<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
