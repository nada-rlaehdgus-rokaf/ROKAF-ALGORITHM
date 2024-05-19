#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n;
int graph[501][501];
int visited[501];
int result[501][501];

// graph[now][i]를 조사하고 있으니 당연히 안 나옴 
void solution(int now,int row)
{
    
    //cout << now << "\n";
    for(int i = 1 ; i<=n ; i++)
    {
        if(graph[now][i] == 0)
        {
            continue;
        }
        if(i == row)
        {
            result[row][i] = 1;
            continue;
        }
        if(visited[i] != -1)
        {
            continue;
        }
        //cout << now << " "<< i <<"\n";
        visited[i] = 1;
        result[row][i] = 1;
        solution(i,row);
                
    }



}


int main()
{
    cin >> n;
    for(int i=1 ; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int a;
            cin >> a;
            graph[i][j] = a;
        }
    }
     for(int j=1; j<= n; j++)
    {
        visited[j] = -1;
    }
    for(int i=1; i<=n ; i++)
    {
        solution(i,i);
        for(int j=1; j<= n; j++)
        {
            visited[j] = -1;
        }
    }    

    for(int i= 1; i<=n; i++)
    {
        for(int j= 1; j<=n; j++)
        {
            cout<< result[i][j] <<" ";
        }
        cout << "\n";
    }

    return 0;
}