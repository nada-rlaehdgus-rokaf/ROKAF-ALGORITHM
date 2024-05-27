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
vector<int> graph[100001];
int visited[100001];
vector<int> question[100001];

void solution(int cur)
{
    queue<int> q;
    q.push(cur);
    visited[cur] = 1;

    int result =  0;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        result++;

        for(int i =  0 ; i< graph[now].size(); i++)
        {
            int dnow = graph[now][i];
            if(visited[dnow] == 1)
                continue;
            q.push(dnow);
            visited[dnow] = 1;

        }

    }

    question[result].push_back(cur);

}




int main()
{
    cin >> n >> m;
    for(int i=0 ; i< m; i++)
    {
        int a,b;
        cin >> a >> b;
        //graph[a].push_back(b);
        graph[b].push_back(a);

    }


    for(int i= 1 ; i<=n ; i++)
    {
        solution(i);

        for(int j = 1; j<=n; j++)
        {
            visited[j] = 0;
        }
    }

    for(int i = n  ; i >=0; i--)
    {
        if(question[i].size() !=0)
        {
            for(int j =0 ; j<question[i].size(); j++)
            {
                cout << question[i][j] << " ";
            }
            cout<<"\n";
            break;
        }
    }



    return 0;
}