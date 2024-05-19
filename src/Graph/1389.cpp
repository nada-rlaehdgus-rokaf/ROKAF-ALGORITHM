#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
vector<int> graph[101];
int visited[101];
int n,m;
int kevin[101];

void solution(int now)
{
    queue<int> q;
    q.push(now);
    visited[now] = 1;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i=0; i<graph[cur].size(); i++)
        {
            int curd = graph[cur][i];
            if(visited[curd] == -1)
            {
                visited[curd] = visited[cur]+1;
                q.push(curd);
            }
            else if(visited[cur]+1 < visited[curd])
            {
                visited[curd] = visited[cur]+1;
                q.push(curd);
            }
        }
    }



}

int main()
{
    cin >> n >> m;  
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=n ; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    for(int i=1; i<=n; i++)
    {
        visited[i] = -1;
    }

    for(int i= 1 ; i<=n;  i++)
    {
        solution(i);
        for(int j=1; j<=n; j++)
        {
            kevin[i] +=visited[j];
        }
        for(int j=1; j<=n; j++)
        {
            visited[j] = -1;
        }
    }
    int index = kevin[1];
    int who = 1;
    for(int i = 2 ; i <=n ; i++)
    {
        if(index > kevin[i])
        {
            index = kevin[i];
            who = i; 
        }
        else if(index == kevin[i])
        {
            if(who > i)
            {
                who = i;
            }
        }
    } 

    cout << who << "\n";

    return 0;
}