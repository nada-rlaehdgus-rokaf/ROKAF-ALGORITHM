#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
 

int t,n;

vector<vector<int>> graph;

int team[100001];

int solution(int gnow,int cur, int team_n,int index){
    
   /* int team[100001];
    for(int i=0; i<graph[now].size()+1; i++)
    {
        team[i] = 0;
    }
    int lose = graph[now].size()-1;
    
    while(!q.empty())
    {
        
    }
    
/*    for(int i = 1; i<graph[now].size(); i++)
    {
        if(team[graph[now][i]] == 1)
            continue;
        queue<int> q;
        q.push(i);
        int index = i;
        int team_n = 0;
        vector<int> save;
        save.push_back(i);
        while(!q.empty())
        {
            int p = q.front();
           // cout << " p : " <<p <<"\n";
            q.pop();
            if(team[p] == 1)
                break;
            if(graph[now][p] == p )
            {
                lose--;
                team[p] = 1;
                //cout << "lose : " << lose << "\n";
                break;
            }
            if(graph[now][p] == index)
            {
                //cout << index << " "<< save.size()<<"\n";
                lose -= save.size();
                //cout << "lose : " << lose << "\n";
                for(int i=0; i<save.size(); i++)
                {
                    team[save[i]] = 1;
                }
                break;
            }
            team_n ++;
            q.push(graph[now][p]);
            save.push_back(p);
            
            
        }
    }*/
    
    // 이미 팀일 경우
    if(team[cur] == 1)
        return 0;
    
    // 자기 자신
    if(graph[gnow][cur] == cur)
    {
        team[cur] =1 ;
        return 1;
    }
    // 처음 것과 마지막이 같을 경우 
    if(graph[gnow][cur] == index)
    {
        
        return team_n
    }
    
    if(team_n == 0)
        solution(gnow,cur,team_n+1,cur)
    else
        solution(gnow,cur,team_n+1,index)
    //cout <<lose <<"\n";*/

}



int main()
{
    cin >> t;
    for(int i=0; i<t; i++)
    {

        int a;
        cin >> a;
        vector<int> arr(a+1,0);
        for(int j=0; j< a; j++)
        {
            int x;
            cin >> x;
            arr[j+1] = x;
        }
        graph.push_back(arr);
    }
    

    for(int i=0; i<t; i++)
    {
        int lose = graph[i].size()-1;
        for(int j=1; j<graph[i].size(); j++)
        {
            lose -= solution(i,j,0,graph[i][j])
        }
        cout << lose <<"\n";
    }
    
    
    

    return 0;
}

