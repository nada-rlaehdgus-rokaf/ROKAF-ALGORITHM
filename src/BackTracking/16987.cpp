#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<pair<int,int>> eggs;
int visited[9];
int result = 0;

void solution(int cur)
{
    
    
    if(cur >= n)
    {
        int count = 0;
        for(int i=0; i< eggs.size() ; i++)
        {
            if(visited[i] <= 0 )
                count++;
        }
        result = max(result,count);
        return;
    }
  
 
    
    if(visited[cur] <= 0 )
    {
        solution(cur+1);
    }
    else{
        int curs = eggs[cur].first;
        int curw = eggs[cur].second;
        bool check = false;
        for(int i=0; i<eggs.size(); i++)
        {
            if(i == cur)
                continue;
            if(visited[i] <=0 )
                continue;
    
            visited[i] -= curw;
            visited[cur] -= eggs[i].second;
            check = true;
            solution(cur+1);
            visited[i] += curw;
            visited[cur] += eggs[i].second;
            
        }
        if(!check)
        {
            solution(n);
        }
    }
    
 
    
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int s ,w;
        cin >> s >> w; // 내구도 무게 
        eggs.push_back({s,w});
    }
    //cout<<"Hello World";
    for(int i=0; i<n; i++)
    {
        visited[i] = eggs[i].first;
    }
    
    
    solution(0);
    
    cout << result <<"\n";

    return 0;
}

