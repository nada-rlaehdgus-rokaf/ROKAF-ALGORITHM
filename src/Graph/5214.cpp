#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,k,m;
vector<int> graph[101001];
int visited[101001];

// 그래프의 저장 방법에 대해서 

void solution()
{
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty())
    {
       int cur = q.front();
       q.pop();
       //cout << cur <<"\n";
    //    if(cur == n)
    //    {
    //     cout << visited[cur] <<"\n";
    //     break;
    //    }
        for(int i = 0;  i< graph[cur].size(); i++)
        {
            int curd = graph[cur][i];
            if(visited[curd] == -1)
            {
                if(cur > n )
                {
                    visited[curd] = visited[cur];
                    q.push(curd);

                }
                else{
                    visited[curd] = visited[cur] + 1;
                    q.push(curd);
                }
                
            }
            else if(visited[cur] + 1 < visited[curd])
            {
                if(cur > n )
                {
                    visited[curd] = visited[cur];
                    q.push(curd);

                }
                else{
                    visited[curd] = visited[cur] + 1;
                    q.push(curd);
                }
            }
        }


    }
    

}




int main()
{
    cin >> n >> k >> m;

    for(int i= 0 ; i< m; i++)
    {
        //vector<int> arr;
        for(int j= 0 ; j< k; j++)
        {
            int a;
            cin >> a;
            //arr.push_back(a);
            graph[a].push_back(n+i+1);
            graph[n+i+1].push_back(a);
        }
        // for(int j = 0; j < k ; j++)
        // {

        //     for(int h = j+1; h < k; h++)
        //     {
        //         graph[arr[h]].push_back(arr[j]);
        //         graph[arr[j]].push_back(arr[h]);
        //         // 전부 간선을 연결 할 경우 메모리 초과된다.



        //     }
        // }


    }




    // for(int i = 1;  i <=n; i++)
    // {
    //     cout << i << "\n";
    //     for(int j = 1; j<graph[i].size(); j++)
    //     {
    //         cout <<graph[i][j] <<" ";
    //     }
    //     cout << "\n";
    // }
    // for(int i = 1;  i <=n; i++)
    // {
    //     sort(graph[i].begin(),graph[i].end());
    // }

    for(int i = 1; i<=n+m; i++)
    {
        visited[i] = -1;
    }

    solution();

    if(visited[n] == -1)
    {
        cout << -1 << "\n";
    }
    else
    {
            cout << visited[n] << "\n";
    }

    return 0;
}