#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,m,v; 
vector<int> graph[1001];
int dfsvisited[1001];
int bfsvisited[1001];


void dfs(int now ){

    cout << now << " ";
    dfsvisited[now] = 1;
    for(int i= 0; i<graph[now].size(); i++)
    {
        if(dfsvisited[graph[now][i]] == 1)
        {
            continue;
        }
        dfsvisited[graph[now][i]] = 1;
        dfs(graph[now][i]);
    }

}
void bfs(int now){
    queue<int> q;
    q.push(now);
    bfsvisited[now] = 1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int i = 0 ;  i< graph[cur].size(); i++)
        {
            if(bfsvisited[graph[cur][i]] == 1)
                continue;
            int curd  = graph[cur][i];
            bfsvisited[curd] = 1;
            q.push(curd);

        }

    }


}

int main()
{
    cin >> n >> m >> v;
    for(int i= 0 ; i < m ; i++)
    {
        int a , b ;
         cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(v);
    cout << "\n";
    bfs(v);   

    return 0;
}