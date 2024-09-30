#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

vector<int> ascgraph[100];
vector<int> dcsgraph[100];

int n,m;
int ascvisited[100];
int asc_sum[100];
int dcsvisited[100];
int dcs_sum[100];

int result[100];

void solution(int now)
{
    queue<int> ascq;
    ascq.push(now);
    ascvisited[now] = 1;

    while(!ascq.empty())
    {
        int x = ascq.front();
        ascq.pop();

        for(int i=0; i<ascgraph[x].size(); i++)
        {
            int nx = ascgraph[x][i];
            if(ascvisited[nx] == 0)
            {
                ascvisited[nx] = 1;
                ascq.push(nx);
            }
            else if(ascvisited[nx] > ascvisited[x]+1)
            {
                ascvisited[nx] = ascvisited[x]+1;
                ascq.push(nx);
            }
        }
    }
    
    for(int i =1 ; i<=n; i++)
    {
       asc_sum[i] += ascvisited[i];
    }

    queue<int> dcq;
    dcq.push(now);
    dcsvisited[now] = 1;

    while(!dcq.empty())
    {
        int x = dcq.front();
        dcq.pop();

        for(int i=0; i<dcsgraph[x].size(); i++)
        {
            int nx = dcsgraph[x][i];
            if(dcsvisited[nx] == 0)
            {
                dcsvisited[nx] = 1;
                dcq.push(nx);
            }
            else if(dcsvisited[nx] > dcsvisited[x]+1)
            {
                dcsvisited[nx] = dcsvisited[x]+1;
                dcq.push(nx);
            }
        }
    }

    for(int i =1 ; i<=n; i++)
    {
        dcs_sum[i] += dcsvisited[i];
    }



}

int main()
{   
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin >> a >> b;
        ascgraph[b].push_back(a);
        dcsgraph[a].push_back(b);
    }
    
    for(int i =  1; i<=n ; i++)
    {
        solution(i);

        for(int j = 1; j<=n; j++)
        {
            ascvisited[j] = 0;
            dcsvisited[j] = 0;
        }   
    }

    
    for(int i=1; i<=n; i++)
    {
        if(asc_sum[i] >= (n+1)/2 )
        {
            result[i] = 1;
        }
    }
    for(int i=1; i<=n ; i++)
    {
        if(dcs_sum[i] >= (n+1)/2 )
        {
            if(result[i] == 1)
            {
                continue;
            }
            result[i] = 1;
        }
    }

    int answer = 0;
    for(int i = 1; i<=n;  i++)
    {
        answer += result[i];
    }   

    cout << answer <<"\n";

    return 0;
}