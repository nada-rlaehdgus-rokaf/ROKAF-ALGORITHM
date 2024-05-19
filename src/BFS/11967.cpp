#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,m;

vector<pair<int,int>> light[101][101];

queue<pair<int,int>> q;

int map[101][101];

int visit[101][101];

int result = 0;


void solution()
{
    while(!q.empty())
    {
        
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        //cout << "Y : " << y<< " X : " << x <<"\n";
        for(int i=0 ; i< light[y][x].size();  i++)
        {
            int ly = light[y][x][i].first;
            int lx = light[y][x][i].second;
            bool flag = false;
            //cout << " lY : " << ly<< " lX : " << lx <<"\n";
            if(visit[ly][lx] == 1)  // 여러곳에서 visit 했을 경우도 있음으로 
                continue;
            for(int j = 0 ; j < 4; j++)
            {
                int ny = ly + dy[j];
                int nx = lx + dx[j];
                
                if(ny <= 0 || ny > n || nx <=0 || nx > n) 
                    continue;
                
                if(visit[ny][nx] == 1)
                {
                    flag = true;
                    break;
                }
            }
            if(flag == true)
            {
                if(map[ly][lx] == 0)
                {
                    map[ly][lx] = 1; 
                    visit[ly][lx] = 1;
                    q.push({ly,lx});
                    result ++ ; 
                }
            }
            else{
                if(map[ly][lx] == 0)
                {
                    map[ly][lx] = 1; 
                    result ++ ; 
                }
            }
        }
        
        
        for(int i=0 ; i< 4; i++)
        {
            int ny  = y + dy[i];
            int nx  = x + dx[i];
            
            if(ny <= 0 || ny > n || nx <=0 || nx > n) 
                continue;
            
            if(visit[ny][nx] == 1)
                continue;
            
            if(map[ny][nx] ==  0)
                continue;
                
            visit[ny][nx] = 1;
            q.push({ny,nx});
            
        }
        
        
    }
    
    cout << result <<"\n";
}

int main()
{
    cin >> n >> m ; 
    
    for(int i=0; i<m ; i++)
    {
        int x,y,a,b;
        cin >> x >> y >> a>> b;
        light[y][x].push_back({b,a});
  
    }
    
    q.push({1,1});
    visit[1][1] = 1;
    result ++ ;
    
    solution();
    
    
    
    return 0;
}