#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,c,m;
// vector<pair<int,int>> graph[2001];
vector<pair<int,pair<int,int>>> graph;

bool comp(pair<int,pair<int,int>> p1, 
pair<int,pair<int,int>> p2)
{
    if(p1.first == p2.first)
    {
        return p1.second.first > p2.second.first;
    }
    else{
        return p1. first > p2.first;
    }
    
}


int main()
{
   cin >> n >> c;
   cin >> m;
   
   
   for(int i=0; i<m; i++)
   {
       int s,e,w;
       cin >> s >> e>>w;
        graph.push_back({s,{e,w}});
   }
   
   sort(graph.begin(),graph.end(),comp);
   
   for(int i=0; i<m; i++)
   {
       cout << graph[i].first <<" "<<
       graph[i].second.first <<"\n";
   }
   

    return 0;
}
