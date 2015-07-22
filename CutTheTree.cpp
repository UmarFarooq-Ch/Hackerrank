#include <iostream>
#include <string>

using namespace std;

int edges[100][2];
bool visited[100][100];

int main()
{
    int T = 0;
    cin>>T;
    int vertices[T];
    for(int i = 0; i < T; i ++)
    {
        cin>>vertices[i];
    }
    int a, b = 0;
    for(int i = 0; i < T - 1;i++)
    {
        cin>>a>>b;
        for(int j = 0; j < 3; j++)
        {
            if(edges[a-1][j] == 0)
            {
                edges[a - 1][j] = b -1;
                if(edges[b-1][2] != 0)
                    edges[b-1][1] = a - 1;
                else
                    edges[b -1][2] = a - 1;
                break;
            }
        }
    }

    for(int i = 0; i < T ;i++)
    {

        for(int j = 0; j < 3; j++)
        {
            cout<<edges[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
