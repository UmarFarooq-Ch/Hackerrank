#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int contador = 0;
char matrix[101][101];
char visitado[101][101];
int entry_x,entry_y = 0;
bool cu;
//                        2
//                    1       3
//                        4
void depth_first(char matriz[][101],int i,int j, int lim_x,int lim_y,int k)
{
    if(matriz[i][j] == '*')
    {
       // cout<<"lol";
        cu = true;
    }
    else
    {
        //Direita
         if(j  + 1< lim_y && (visitado[i][j + 1] == '.' || visitado[i][j+1] == '*') && !cu )
        {
           //cout<<"Capiroto a DIREITA "<<i<<" "<<j<<endl;
            visitado[i][j] = 'X';
            k = 3;
            depth_first(matriz,i,j+1,lim_x,lim_y,k);
        }
        //Esquerda
        if(j - 1 >= 0 && (visitado[i][j - 1] == '.' || visitado[i][j - 1] == '*')&& !cu)
        {
           // cout<<"Capiroto a esquerda "<<i<<" "<<j<<endl;
            visitado[i][j] = 'X';
            k = 1;
            depth_first(matriz,i,j-1,lim_x,lim_y,k);
        }

        //Para baixo
        if(i +1 < lim_x && (visitado[i+1][j] == '.' || visitado[i+1][j] == '*')&& !cu)
        {
            visitado[i][j] = 'X';
            depth_first(matriz,i+1,j,lim_x,lim_y,k);
        }
        //Para cimna
        if(i - 1 >=0 && (visitado[i-1][j] == '.' || visitado[i-1][j] == '*')&& !cu)
        {
            visitado[i][j] = 'X';
            depth_first(matriz,i-1,j,lim_x,lim_y,k);
        }
        if(cu)
        {
            //cout<<"cu "<< i<<" "<<j<<"  ";
            int temp = 0;

            if(i == entry_x && j == entry_y)
            {
                if(i+1 < lim_x && (matriz[i+1][j] == '.' || matriz[i+1][j] =='*'))
                    temp++;
                if(j +1 < lim_y && (matriz[i][j+1] == '.'|| matriz[i][j+1] == '*'))
                    temp++;
                if(j - 1 >=0 && (matriz[i][j-1] == '.' || matriz[i][j-1] == '*'))
                    temp++;
                if(i-1 >= 0 && (matriz[i-1][j] == '.' || matriz[i-1][j] =='*'))
                    temp++;
                if(temp >= 2)
                    contador++;
            }else
            {

                if(i+1 < lim_x && (matriz[i+1][j] == '.' || matriz[i+1][j] =='*' || matriz[i+1][j] =='M'))
                {
                    //cout<<"cima";
                    temp++;
                }if(j +1 < lim_y && (matriz[i][j+1] == '.'|| matriz[i][j+1] == '*' || matriz[i][j+1] =='M'))
                    temp++;
                if(j - 1 >=0 && (matriz[i][j-1] == '.' || matriz[i][j-1] == '*' || matriz[i][j-1]=='M'))
                    temp++;
                if(i-1 >= 0 && (matriz[i-1][j] == '.' || matriz[i-1][j] =='*' || matriz[i-1][j]=='M'))
                    temp++;
                if(temp > 2)
                    contador++;
            }
            //cout<<contador<<endl;
        }
    }
}

int main()
{
    int a = 0;
    cin>>a;
    for(int i = 0; i < a;i++)
    {
        int N,M = 0;
        cin>>N;
        cin>>M;
        for(int i = 0; i < N;i++)
        {
            for(int j = 0; j < M;j++)
            {
                cin>>matrix[i][j];
                visitado[i][j] = matrix[i][j];
                if(matrix[i][j] == 'M')
                {
                    entry_x = i;entry_y = j;
                }
            }
        }
        int k = 0;
        int num_turns = 0;
        cin>>num_turns;
        depth_first(matrix,entry_x, entry_y,N,M,k);
        if(contador == num_turns && cu)
            cout<<"Impressed"<<endl;
        else
            cout<<"Oops!"<<endl;
        contador = 0;
        cu = false;
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
