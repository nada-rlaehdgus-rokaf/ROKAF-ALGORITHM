#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int pdy[3] ={0,1,1};
int pdx[3] = {1,0,1};

int n;
int house[17][17];
int visited[17][17][3];
int result = 0 ;

void solution()
{
    queue<pair<pair<int,int>,int>> q; // y , x ,dir  (0,1,2) 가로 세로 대각선
    //visited[1][1][0] = 1;
    //visited[1][2][0] = 1;
    q.push({{1,2},0});

    while(!q.empty())
    {
        int y = q.front().first.first;
        int x=  q.front().first.second;
        int dir = q.front().second;
        q.pop();

        if(y==n && x==n)
        {
            result++;
            continue;
        }

        for(int i = 0 ; i < 3; i ++)
        {
            if(dir == 0)
            {
                if(i==1)
                {
                    continue;
                }
            }
            else if(dir == 1)
            {
                if(i==0)
                {
                    continue;
                }
            }

            if(i!=2)
            {
                int ny = y+pdy[i];
                int nx = x+pdx[i];
                if(ny  <= 0 || ny > n || nx <=0 || nx>n )
                    continue;
                // if(visited[ny][nx][i] == 1)
                //     continue;
                if(house[ny][nx] == 1)
                    continue;
                q.push({{ny,nx},i});
                //visited[ny][nx][i] = 1;
            }
            else{
                int ny = y+pdy[i];
                int nx = x+pdx[i];
                if(ny  <= 0 || ny > n || nx <=0 || nx>n )
                    continue;
                // if(visited[y+1][x+1][i] == 1|| visited[y+1][x][i] == 1 
                // || visited[y][x+1][i] == 1)
                //     continue;
                if(house[ny][nx] == 1 || house[y+1][x] == 1 || house[y][x+1] ==1)
                    continue;
                q.push({{ny,nx},i});
                //visited[ny][nx][i] = 1;
            }

        }


    }




}



int main()
{
    cin >> n; 
    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1 ; j <= n; j++)
        {
            cin >> house[i][j];
        }
    }


    solution();

    cout << result <<"\n";

    return 0;
}