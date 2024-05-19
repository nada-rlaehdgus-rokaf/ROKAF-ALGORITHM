#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int n,m,k;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int map[1002][1002];
int bt[1002][1002];
int visited[1002][1002][11];
int result = 123456789;


void solution(int x,int y)
{
 
   // cout << x <<" "<<y <<"\n";
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{y,x},{0,1}}); // y, x, k ,1 ;
    visited[1][1][0] = 1;
    
    
    while(!q.empty())
    {
        int cury = q.front().first.first;
        int curx = q.front().first.second;
        int curk = q.front().second.first;
        int move = q.front().second.second;
        q.pop();
        
        if(cury == n &&  curx == m){
            cout << move <<"\n";
            return;
        }
        
        for(int i=0; i<4; i++)
        {
            int ny = dy[i] + cury;
            int nx = dx[i] + curx;
           
           
            if(ny >=1 && ny <= n && nx >=1 && nx <= m && visited[ny][nx][curk] == 0 )
            {
                if(curk < k && map[ny][nx]==1){
                    visited[ny][nx][curk+1]=1;
                    q.push({{ny,nx},{curk+1, move+1}});
                }
                if(map[ny][nx]==0){
                    visited[ny][nx][curk]=1;
                    q.push({{ny,nx},{curk, move+1}});
                }
            }
   
            
            
        }
        
        
    }
    cout << -1 <<"\n";
}


int main()
{
    cin >> n >> m >>k;
    
    for(int i=1; i<=n; i++)
    {
        string input;
        cin >> input;
        for(int j=0; j<input.size(); j++)
        {
            int in = input[j] - '0';
            map[i][j+1] = in;
        }
    }

    
  
    solution(1,1);
    
    


    return 0;
}





