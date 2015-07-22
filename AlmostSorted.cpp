#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void shift(int vetor[],int aux[],int sizis, int num_shifts)
{
    int temp = vetor[0];
    int temp2 = vetor[1];
    for(int i = 0; i  < sizis; i ++)
    {
        aux[(num_shifts+i)%sizis] =  vetor[i];
    }
}

void swaps(int arr[],int target_a,int target_b)
{
    int tmp = arr[target_a];
    arr[target_a] = arr[target_b];
    arr[target_b] = tmp;
}


void reverses(int _ar[],int a, int b)
{
    int i = a;
    int j = b;
    while(i < j)
    {
        int temp = _ar[j];
        _ar[j] = _ar[i];
        _ar[i] = temp;
        i++;j--;
    }
}

bool reverse_spots[1000000]; // holds the positions where the i - 1 position value is greater than i position value
int ar[1000000];
int main()
{

    bool swap_done,reverse_done = 1;
    int T = 0;
    cin >> T;
    int temp,temp_ant = 0; // Temp variables used when traversing the array
    int pos_a,pos_b = 0; // Holds the positions for swap.
    for(int i = 0; i < T; i ++)
    {
        cin>>ar[i];
    }

    int counter = 0;
    pos_a = 0;
    pos_b = T - 1;
    while(pos_a < pos_b)
    {
        if(ar[pos_a] > ar[pos_a+ 1])
        {
            reverse_spots[pos_a] = true;
            counter++;
        }if(ar[pos_b] < ar[pos_b -1])
        {
            counter++;
            reverse_spots[pos_b] = true;
        }
        pos_a++;
        pos_b--;
    }
    pos_a = 0;
    pos_b = 0;
    if(counter == 2)
    {
        for(int i = 0 ; i < T; i ++)
        {
            if(reverse_spots[i])
            {
                if(pos_a == 0 && pos_b == 0)
                    pos_a = i;
                else
                    pos_b = i;
            }


        }
        swaps(ar,pos_a,pos_b);
        for(int i = 1 ; i < T; i ++)
        {
            if(ar[i] < ar[i - 1])
                swap_done = false;
        }
        if(swap_done)
            cout<<"yes\n"<<"swap "<<pos_a<<" "<<pos_b;
        else
            cout<<"no";
    }
    else
    {
        swap_done = false;
        int b = 0;
        int c = 0;

        for(int i = 0; i < T; i ++)
        {
            if(reverse_spots[i])
            {
                if(c == 0 && b == 0)
                    c = i;
                else if ( b == 0 || b!=0)
                {
                    if(i - b > 1 && b !=0)
                    {
                       // If the points that are in the wrong order arent continuous, you cant reverse 2 sub-arraays, so you cant order it.
                        reverse_done = false;
                        break;
                    }
                    b = i;
                }
            }
        }
        if(reverse_done)
        {
            reverses(ar,c,b);
            for(int i = 1 ; i < T; i ++)
            {
                if(ar[i] < ar[i - 1])
                    reverse_done = false;
            }
            if(reverse_done)
                cout<<"yes\n"<<"reverse "<<c + 1<<" "<<b + 1<<endl;
            else
                cout<<"no";
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
