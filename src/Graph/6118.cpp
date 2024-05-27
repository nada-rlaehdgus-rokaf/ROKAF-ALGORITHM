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
vector<int> graph[20001];
int visited[20001];
vector<int> result[20001];


void solution()
{
    queue<int> q;
    q.push(1);
    visited[1] = 0;

    while(!q.empty())
    {
        int cur  = q.front();
        q.pop();

        for(int i = 0 ; i<graph[cur].size(); i++)
        {
            int curd = graph[cur][i];
            if(visited[curd] == - 1)
            {
                visited[curd] = visited[cur]+1;
                q.push(curd);
            }
            else if(visited[cur] + 1 < visited[curd] ){
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

    for(int i = 1; i<=n ; i++)
    {
        visited[i] = -1;
    }

    solution();

    for(int i = 1 ; i<=n; i++)
    {
        result[visited[i]].push_back(i);
    }

    for(int i = n;  i>=0; i--)
    {
        if(result[i].size() !=0)
        {
            cout << result[i][0]<< " "<<  i << " " << result[i].size() << "\n";
            break;
        }
    }

    return 0;
}