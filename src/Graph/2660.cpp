#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n;
vector<int> graph[51];
int visited[51];
int depth[51];
vector<int> result[51];

void solution(int now)
{
    queue<int> q;
    q.push(now);
    visited[now] = 1;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        //vector<int> v;
        for(int i=0; i < graph[cur].size(); i++)
        {
            int curd = graph[cur][i];
            if(visited[curd] == -1 )
            {
                visited[curd] = visited[cur]+1;
                q.push(curd);
            }
            else if(visited[cur] + 1 <= visited[curd] )
            {
                visited[curd] = visited[cur]+1;
                q.push(curd);
            }
        }



    }


}


int main()
{   
    cin >> n ;
    for( ; ; )
    {
        int a,b ;
        cin >> a >> b ;
        if(a == -1 && b==-1)
            break;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }    

    for(int i= 1; i<=n ; i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }
    
    // for(int i=1; i<=n; i++)
    // {
    //     for(int j=0; j<graph[i].size(); j++)
    //     {
    //         cout << graph[i][j] <<" ";
    //     }
    //     cout <<"\n";
    // }
    for(int i =1 ; i<=n ; i++)
    {
        visited[i] = -1 ;
    }
    // depth 가 얼마나 깊나 
    for(int i= 1; i <=n; i++)
    {
        solution(i);
        for(int j= 1; j<=n; j++)
        {
            depth[i] = max(depth[i],visited[j]-1);
        }
        for(int j= 1 ; j<=n; j++)
        {
            visited[j] = -1;
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        result[depth[i]].push_back(i);
    }

    for(int i=1; i<=n; i++)
    {
        if(result[i].size() !=0)
        {
            cout << i << " "<<result[i].size() <<"\n";
            sort(result[i].begin(),result[i].end());
            for(int j=0; j<result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout <<"\n";
            break;
        }
    }


    return 0;
}