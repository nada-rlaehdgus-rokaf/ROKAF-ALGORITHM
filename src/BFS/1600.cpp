#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int hdx[8] = {-2,-1,1,2 , -2, -1 ,1 ,2 };
int hdy[8] = {-1,-2,-2, -1,1  ,2 ,2 ,1};

int k,w, h;
int map[201][201];
int v[201][201][31];


void solution(){
    
    queue<pair<pair<int,int>,pair<int,int>>> q; // y , x , k ,move
    q.push({{1,1},{0,0}});
    v[1][1][0] = 1;
    
    while(!q.empty())
    {
        int cury = q.front().first.first;
        int curx = q.front().first.second;
        int curk = q.front().second.first;
        int move = q.front().second.second;
        q.pop();
        
        if(cury == h && curx == w)
        {
            cout << move <<"\n";
            return;
        }
        
        for(int i=0; i<  4 ;  i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            
            if(ny < 1 || ny > h || nx < 1 ||  nx>w )
                continue;
            if(map[ny][nx] == 1) 
            {
                continue;
            }
            
            if(v[ny][nx][curk] == 1)
                continue;
            
            v[ny][nx][curk] = 1;
            q.push({{ny,nx},{curk,move+1}});
            
        }
        
        if(curk < k )
        {
             for(int i=0; i<  8 ;  i++)
            {
                int ny = cury + hdy[i];
                int nx = curx + hdx[i];
                
                if(ny < 1 || ny > h || nx < 1 ||  nx>w )
                    continue;
                    
                 if(map[ny][nx] == 1) 
                {
                    continue;
                }
                if(v[ny][nx][curk+1] == 1)
                    continue;
                
                v[ny][nx][curk+1] = 1;
                q.push({{ny,nx},{curk+1,move+1}});
                
            }
            
        }
        
        
        
        
        
        
        
    }
    
    cout << - 1 <<"\n";
    
    return;
}



int main()
{
    cin >> k ;
    cin >> w>> h;
    
    for(int i=1; i<= h ; i++){
        for(int j=1; j<=w; j++) 
       {
           int a;
           cin >> a;
           map[i][j] = a;
       }
    }
    
    
    
    solution();
    

    return 0;
}
