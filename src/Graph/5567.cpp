#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int n,m;
vector<int> graph[501];
int visited[501];
int result = 0;

void solution(int now)
{
    queue<int> q;
    q.push(now);
    visited[now] = 1;

    while(!q.empty())
    {
        int cur = q.front();
        //cout << "cur :" << cur <<"\n";
        q.pop();
        for(int i=0; i< graph[cur].size(); i++)
        {
            int curd = graph[cur][i];
            if(visited[curd] == -1)
            {
                visited[curd] = visited[cur]+1;
                q.push(curd);
            }
            else if(visited[curd] > visited[cur] +1 )
            {
                visited[graph[cur][i]] = min(visited[graph[cur][i]],
                visited[cur] +1);
                q.push(curd);
            }
            
        }
    }
}

int main()
{
    cin >> n;
    cin >> m;
    for(int i=0 ; i< m; i++)
    {
        int a,b ;
        cin >> a>> b ;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }    
    for(int i = 1 ; i<= n; i++)
    {
        visited[i] = -1; 
    }

    solution(1);
    // for(int i= 1; i<=n; i++)
    // {
    //     cout << visited[i]<<" ";
    // }
    // cout << "\n";
    for(int i =2 ; i<=n; i++)
    {
        if(visited[i] <=3 && visited[i]!=-1)
            result++;
    }

    cout << result <<"\n";

    return 0;
}