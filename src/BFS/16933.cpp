#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,m,k;
int visited[1001][1001][11];
int map[1001][1001];
queue<pair<pair<int,int>,pair<int,int>>> q;
// y,x , 날 수  , 뚫은 수 

// 멈춰도 + 1 시작은 낮  낮에만 벽을 부숨 

void solution()
{
    while(!q.empty())
    {
        int cury = q.front().first.first;
        int curx =q.front().first.second;
        int curd = q.front().second.first;
        int curk =  q.front().second.second;
        q.pop();
        
        //cout << cury <<" "<< curx <<"\n";
        if(cury == n && curx == m)
        {
            cout << curd <<"\n";
            return;
        }
        
        
        for(int i=0; i<4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            
            if(ny <=0 || ny > n || nx <=0 || nx > m)
                continue;
            if(visited[ny][nx][curk] == 1)
                continue;
            if(curd %2 == 1) //  낮
            {
                if(map[ny][nx] == 1)
                {
                    if(curk+1 <= k && visited[ny][nx][curk+1] == 0)
                    { 
                        visited[ny][nx][curk+1] = 1;
                        q.push({{ny,nx},{curd+1,curk+1}});
                    }
                    
                }
                else{
                    
                    visited[ny][nx][curk] = 1;
                    q.push({{ny,nx},{curd+1,curk}});
                    
                }
                
            }
            else{
                if(map[ny][nx] == 1)
                {
                    q.push({{cury,curx},{curd+1,curk}});
                }
                else{
                    visited[ny][nx][curk] = 1;
                    q.push({{ny,nx},{curd+1,curk}});
                }
            }
            
        }

    }
    
    cout << -1 <<"\n";

}

int main()
{
    
    cin >> n >> m >> k;
    
    
    for(int i=0; i<n ; i++)
    {
        string str;
        cin >> str;
        for(int j=0; j<m; j++)
        {
            map[i+1][j+1] = str[j]-'0';
        }
    }
    
    
 /*   for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout << map[i][j] <<" ";
        }
        cout <<"\n";
    }
    */
    
    q.push({{1,1},{1,0}});  
    visited[1][1][0] = 1;
    
    solution();
    


    return 0;
}