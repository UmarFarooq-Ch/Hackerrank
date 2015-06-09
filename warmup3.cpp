#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int make_palindromo(string temp)
{
    int i = 0;
    int j = temp.length() - 1;
    int cont = 0;
    while(i < j)
    {
        if(temp[i] < temp[j])
        {
            cont+= temp[j] - temp[i];
        }
        else if(temp[j] < temp[i])
        {
            cont+= temp[i] - temp[j];
        }
        i++;
        j--;
    }
    return cont;
}


int main()
{
    int T = 0;
    string temp = "";
    cin >> T;
    int result[T];
    for(int i = 0 ; i < T; i ++)
    {
        cin>> temp;
        result[i] = make_palindromo(temp);
    }
    for(int i = 0 ; i < T; i++)
    {
        if(i == T - 1)
            cout<<result[i];
        else
            cout<< result[i]<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
