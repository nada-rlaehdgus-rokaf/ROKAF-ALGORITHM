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

int n,m;
int map[51][51];
vector<pair<int,int>> VirusPos; // y, x 
vector<int> choose;
int visited[51][51];

int Answer = INF;



void SpreadVirus()
{
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            visited[i][j] = INF; 
        }
    }
    queue<pair<int,int>> q;
    for(int i = 0 ; i < choose.size(); i++)
    {
        int y = VirusPos[choose[i]].first;
        int x = VirusPos[choose[i]].second;
        q.push({y,x});
        visited[y][x] = 0; 
    }

    while(!q.empty())
    {
        int y = q.front().first;
        int x=  q.front().second;
        int cur = visited[y][x];
        q.pop();

        for(int i = 0  ;  i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >=n || nx < 0 || nx >=n)
                continue;
            if(map[ny][nx] == 1)
                continue;
            if(visited[ny][nx] == INF)
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            }
            else if(visited[ny][nx] > visited[y][x] +1)
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            }

        }

    }
    
    // for(int i = 0 ; i < n; i++)
    // {
    //     for(int j = 0 ; j < n; j++)
    //     {   
    //         cout << visited[i][j] << " ";
    //     }
    //     cout <<"\n";
    // }
    //  cout <<"===================" <<"\n";
    
    int result = -1;

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {   
            if(map[i][j] == 1)
                continue;
            if(visited[i][j] == INF)
            {
                return;
            }
            else{
                result = max(result,visited[i][j]);
            }
        }
    }

  
    
    Answer = min(Answer,result);

}





void combination(int cur, int idx)
{
    if(cur == m )
    {
        // for(int i = 0;  i < choose.size(); i++)
        // {
        //     cout << choose[i] <<" ";
        // }
        // cout <<"\n";
        SpreadVirus();

        return;
    }
    for(int i = idx ; i < VirusPos.size() ;   i++)
    {
        choose.push_back(i);
        combination(cur+1,i+1);
        choose.pop_back();
    }
}


void solution()
{

    combination(0,0);

}

int main()
{
    cin >> n >> m ; 
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ;  j < n;  j++)
        {
            int a;
            cin >> a;
            map[i][j] = a;
            if(a==2 )
            {
                VirusPos.push_back({i,j});
            }
        }
    }    

    solution();

    if(Answer == INF)
    {
        cout << -1 <<"\n";
    }
    else
        cout << Answer <<"\n";

    return 0;
}