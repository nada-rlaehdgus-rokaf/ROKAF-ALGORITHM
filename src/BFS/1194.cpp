#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,m;
char map[51][51];
pair<int,int> player;
queue<pair<pair<int,int>,pair<int,vector<int>>>> q;

void solution()
{
    
    while(!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int d = q.front().second.first;
        vector<int> keys = q.front().second.second;
        q.pop();

        //cout << " y : " << y <<" x : " << x << " d : " << d << "\n";
        //vector<int> copy = keys;

        
        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            //vector<int> copy = keys;

            if(ny < 0 || ny >= n || nx <0 || nx >=m)
                continue;
            if(map[ny][nx] == '#')
                continue;
            if(map[ny][nx] == '1')
            {
                cout << d + 1 <<"\n";
                return;
            }
            if(map[ny][nx] >= 'a' && map[ny][nx] <='f' )
            {
                //cout << map[ny][nx] -97 <<"\n";
                if(keys[map[ny][nx] - 97] == 0)
                {
                    keys[map[ny][nx] - 97] = 1;
                    q.push({{ny,nx},{d+1,keys}});
                    keys[map[ny][nx] - 97] = 0;
                }
                else{
                    q.push({{ny,nx},{d+1,keys}}); 
                }
            }
            if(map[ny][nx] >= 'A' && map[ny][nx] <='F')
            {
                if(keys[map[ny][nx]- 65] ==  1)
                {
                    q.push({{ny,nx},{d+1,keys}});
                }
            }
            if(map[ny][nx] == '.')
            {
                q.push({{ny,nx},{d+1,keys}});
            }
            else if(map[ny][nx] == '0')
            {
                q.push({{ny,nx},{d+1,keys}});
            }
            
        }
        
    }
    
    
    cout << "-1"<<"\n";

    
}




int main()
{
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char c;
            cin >> c;
            if(c == '0')
            {
                player.first = i ;
                player.second = j ; 
                
            }
            map[i][j] = c;
            
        }
    }
    vector<int> keys(6,0);
    q.push({{player.first,player.second},{0,keys}});
    solution();


    return 0;
}