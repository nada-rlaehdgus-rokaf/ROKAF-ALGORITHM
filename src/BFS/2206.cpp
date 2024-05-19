#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int map[1001][1001];
int v[1001][1001][2];

int n,m;

void solution(){
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{1,1},{0,1}});
    v[1][1][0] = 1;
    
    while(!q.empty())
    {
        int cury = q.front().first.first;
        int curx=  q.front().first.second;
        int curk = q.front().second.first;
        int move = q.front().second.second;
        q.pop();
        
        if(cury == n && curx == m)
        {
            cout << move << "\n";
            return;
        }
        
        
        
        for(int i = 0 ; i<4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            
            if(ny >= 1 && ny <=n && nx >=1 && nx <=m && 
            v[ny][nx][curk] == 0 )
            {
                if(curk < 1 && map[ny][nx] == 1)
                {
                    v[ny][nx][curk+1] = 1;
                    q.push({{ny,nx},{curk+1,move+1}});
                    
                }
                if( map[ny][nx] == 0)
                {
                    v[ny][nx][curk] = 1;
                    q.push({{ny,nx},{curk,move+1}});
                    
                }
                
                
                
            }
            
            
            
        }
        
        
        
        
        
        
        
    }
    
    cout << -1  <<"\n";
    
    
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        string s;
        cin >> s;
        for(int j=0 ; j<s.size(); j++)
        {
            map[i][j+1] = s[j] -'0';
        }
        
        
    }
    /*  for(int i=1; i<=n; i++)
    {
        
        for(int j=1 ; j<=m; j++)
        {
            cout <<  map[i][j] <<" "; 
        }
        cout << "\n";
    }*/
    //cout<<"Hello World";
    solution();

    return 0;
}
