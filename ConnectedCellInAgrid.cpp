#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool matrix[10][10];
bool entry_points[100];
int resultados[100];
int contador = 0;

void depth_first(bool matriz[10][10],int i,int j, int lim_x,int lim_y)
{
    //Direita
    if(j < lim_y && matriz[i][j + 1] )
    {
      //  cout<<"Xablau para direita "<<i<<" "<<j<<endl;
        contador++;
        matriz[i][j] = false;
        matriz[i][j+1] = false;
        depth_first(matriz,i,j+1,lim_x,lim_y);
    }
    //Diagonal direita para cima
    if(j < lim_y && i >=0 &&  matriz[i - 1][j + 1] )
    {
      //  cout<<"Xablau para direita "<<i<<" "<<j<<endl;
        contador++;
        matriz[i][j] = false;
        matriz[i - 1][j+1] = false;
        depth_first(matriz,i-1,j+1,lim_x,lim_y);
    }
    //Diagonal direita para baixo
    if(j < lim_y && i < lim_x &&  matriz[i + 1][j + 1] )
    {
      //  cout<<"Xablau para direita "<<i<<" "<<j<<endl;
        contador++;
        matriz[i][j] = false;
        matriz[i+1][j+1] = false;
        depth_first(matriz,i+1,j+1,lim_x,lim_y);
    }
    //Esquerda
    if(j >= 0 && matriz[i][j - 1])
    {
      //  cout<<"Xablau para esquerda "<<i<<" "<<j<<endl;
        contador++;
        matriz[i][j] = false;
        matriz[i][j - 1] = false;
        depth_first(matriz,i,j-1,lim_x,lim_y);
    }
    //Diagonal esquerda para cima
    if(j >= 0 &&  i>= 0 && matriz[i - 1][j - 1])
    {
      //  cout<<"Xablau para esquerda "<<i<<" "<<j<<endl;
        contador++;
        matriz[i][j] = false;
        matriz[i - 1][j - 1] = false;
        depth_first(matriz,i-1,j-1,lim_x,lim_y);
    }

    //Diagonal esquerda para baixo
    if(j >= 0 &&  i < lim_x && matriz[i + 1][j - 1])
    {
      //  cout<<"Xablau para esquerda "<<i<<" "<<j<<endl;
        contador++;
        matriz[i][j] = false;
        matriz[i+1][j - 1] = false;
        depth_first(matriz,i+1,j-1,lim_x,lim_y);
    }

    //Para baixo
    if(i < lim_x && matriz[i+1][j])
    {
      //  cout<<"Xablau para baixo "<<i<<" "<<j<<endl;
        contador++;
        matriz[i][j] = false;
        matriz[i+1][j] = false;
        depth_first(matriz,i+1,j,lim_x,lim_y);
    }
    //Para cimna
    if(i >=0 && matriz[i-1][j])
    {
      //  cout<<"Xablau para cima "<<i<<" "<<j<<endl;
        contador++;
        matriz[i][j] = false;
        matriz[i-1][j] = false;
        depth_first(matriz,i-1,j,lim_x,lim_y);
    }



}

int main()
{
    int N,M,entry ,ant_contador = 0;
    bool found = false;
    cin>>N;
    cin>>M;
    for(int i = 0; i < N;i++)
    {
        for(int j = 0; j < M;j++)
        {
            cin>>matrix[i][j];
            if(matrix[i][j])
            {
                if(i == 0)
                {
                    entry_points[i + j] = true;
                    entry = i + j;
                }else
                    entry_points[i* 10 + j] = true;
            }
        }
    }

    for(int i = 0; i < 100;i++)
    {
        if(entry_points[i])
        {
            contador++;
            depth_first(matrix,i / 10, i % 10,N,M);
            resultados[i] = contador;
            contador = 0;
        }
    }

    int maior = 0;
    for(int i = 0; i < 100; i ++)
    {
        if(resultados[i] > maior)
            maior = resultados[i];
    }

    cout<<maior;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
