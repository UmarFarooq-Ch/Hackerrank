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
    string number = "";
    int num_divisors = 0;
    cin>> T;
    for(int i = 0; i < T; i ++)
    {
        cin>>number;
        int value = atoi(number.c_str());
        for(int j = 0; j < number.size();j++)
        {
            if(number[j] - '0' != 0 && value % (number[j] - '0') == 0 )
            {
                if(numbers[j])
                {
                    num_divisors++;
                }
                else
                {
                    numbers[number[j]] = true;
                    num_divisors++;
                }
            }
        }
        cout<< num_divisors<<endl;
        num_divisors = 0;
        reset(numbers);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
