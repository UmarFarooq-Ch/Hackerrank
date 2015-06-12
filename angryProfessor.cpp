#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T = 0;
    int num_students,students_limit = 0;
    cin>> T;
    for(int i = 0; i < T; i ++)
    {
        cin>> num_students>>students_limit;
        int student_time,cont = 0;
        for(int j = 0 ; j < num_students; j ++)
        {
            cin >> student_time;
            if(student_time <= 0)
                cont++;
        }
        if(cont >= students_limit)
            cout <<"NO";
        else
            cout<<"YES";
        if(i != T - 1)
            cout<<"\n";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
