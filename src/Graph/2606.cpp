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
int result = 0;

int visited[1001];

vector<int> graph[1001];

void solution(int now)
{
    queue<int> q;
    q.push(now);
    visited[now] = 1;

    while(!q.empty())
    {   
        int cur = q.front();
        //cout << cur <<" ";
        q.pop();
        if(cur != 1)
            result++;
        for(int i = 0 ; i< graph[cur].size(); i++)
        {
            if(visited[graph[cur][i]] == 1)
                continue;
            int curd = graph[cur][i];
            visited[curd] = 1;
            q.push(curd);
        }
    }



}


int main()
{
    cin >> n ;
    cin >> m; 

    for(int i=0; i< m ; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<n;  i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }
    solution(1);
    //cout << "\n";

    cout << result <<"\n";

    return 0;
}