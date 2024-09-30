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

int map[51][51];
int n,m;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;

int result = INF ;
int visited[14];
vector<int> v;

int CalDist()
{
    int sum = 0 ; 
    for(int i = 0 ;  i < house.size(); i++)
    {
        auto h =  house[i];
        int dd = INF;
        for(int j  = 0 ;  j < v.size();  j++)
        {

            auto select_chicken = chicken[v[j]];
            int d =  abs(h.first - select_chicken.first) 
            + abs(h.second-select_chicken.second);
            dd = min(dd,d);
        }
        sum += dd;
    }

    return sum;
}



void solution(int cnt , int idx)
{
   if(cnt == m)
   {    
        result =  min(result , CalDist());

        return;
   }
   for(int i = idx ; i < chicken.size(); i++)
   {
        if(visited[i] == 1)
            continue;
        visited[i] = 1 ; 
        v.push_back(i);
        solution(cnt+1,i);
        v.pop_back();
        visited[i] = 0 ; 

   }

}


int main()
{
    cin >> n >> m ;

    for(int i = 0 ; i< n; i++)
    {
        for(int j = 0 ; j<n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 1)
            {
                house.push_back({i,j});
            }
            else if(map[i][j] == 2)
            {
                chicken.push_back({i,j});
            }
        }
    }    

    solution(0,0);

    cout << result << "\n";

    return 0;
}