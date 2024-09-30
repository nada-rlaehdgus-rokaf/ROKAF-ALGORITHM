#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#define INF 987654321
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n , m ; 
int map[51][51];
vector<pair<int,int>> virus_pos;
vector<int> select_active_virus;
int visited[51][51];

int result = INF;

// 역대급 헛 짓거리 
// 로직도 다 맞았지만 빈칸에다 바이러스를 놓는 것으로 이해해버려 역대급 삽질을 해버렸다는것 ㅜㅜ 
// 바이러스중에 m개를 active 하게 만들어 주는 것이였다 . 


int virus_spread()
{
    int spread_virus[51][51];
    for(int i = 0 ; i < n; i ++)
    {
        for(int j = 0 ; j<n; j++)
        {
            spread_virus[i][j] = INF;
        }
    }
    
    queue<pair<int,int>> acitve_virus;


    for(int i = 0 ; i < select_active_virus.size(); i++)
    {
        int y = virus_pos [select_active_virus[i]].first;
        int x= virus_pos[select_active_virus[i]].second;
        acitve_virus.push({y,x});
        spread_virus[y][x] = 0 ; 
    }

    while(!acitve_virus.empty())
    {
        int y  = acitve_virus.front().first;
        int x = acitve_virus.front().second;
        int cur = spread_virus[y][x];
        acitve_virus.pop();

        for(int i = 0 ; i < 4;  i++)
        {
            int ny = y +dy[i] ;
            int nx = x + dx[i];
            if(ny < 0 || ny >=n || nx <0 || nx >=n )
                continue;
            if(map[ny][nx] == 1)
                continue;
            
            if(spread_virus[ny][nx] == INF)
            {
                acitve_virus.push({ny,nx}) ;
                spread_virus[ny][nx] = cur+1;
            }
            else if(spread_virus[ny][nx] > cur + 1 )
            {
                acitve_virus.push({ny,nx}) ;
                spread_virus[ny][nx] = cur+1;
            }
        }

    }

    int ans = 0 ; 
    for(int i = 0 ; i < n;  i ++ )
    {
        for(int j = 0 ; j < n; j ++)
        {
            if(map[i][j] == 1 )
                continue;
            if(map[i][j] == 2)
                continue;
            ans = max(spread_virus[i][j],ans);
        }
    }
    // bool flag= false;

    // if(ans == 5)
    // {
    //     for(int i = 0 ; i < n; i++)
    //     {
    //         for(int j = 0 ; j < n; j++)
    //         {
    //             cout<< spread_virus[i][j] << " ";
    //         }
    //         cout <<"\n";
    //     }
    //     //flag = false;
    //       cout <<"======================" <<"\n";

    // }
  
    return ans; 
}

void select_virus_pos(int cnt, int idx)
{
    if(cnt == m)
    {
        result = min(result,virus_spread());
        return;
    }
    for(int i = idx ; i <virus_pos.size(); i++)
    {
        int y = virus_pos[i].first;
        int x =  virus_pos[i].second;
        if(visited[y][x] == 1)
            continue;
        visited[y][x] = 1;
        select_active_virus.push_back(i);
        select_virus_pos(cnt+1,i);
        visited[y][x] = 0 ;
        select_active_virus.pop_back();

    }

}



int main()
{
    cin >> n >> m ; 
    for(int i = 0  ; i < n;  i ++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 2)
            {
                virus_pos.push_back({i,j});
            }
        }
    }

    select_virus_pos(0,0);

    if(result == INF)
    {
        cout << -1 <<"\n";
    }
    else{
        cout << result <<"\n";
    }

    return 0;
}