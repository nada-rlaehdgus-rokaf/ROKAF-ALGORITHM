#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,w ;

pair<int,int> police1;
pair<int,int> police2;
vector<pair<int,int>> vcases;
queue <pair<int,int>> qcases;
vector<pair<int,int>> polices;

struct Event {
    vector<pair<int,int>> polices;
    int result;
    int event_num;
    vector<int> way;
    
    bool operator<(const Event e) const {
        return this->result > e.result;
    }
    
};



priority_queue<Event> pq; 

int answer = 123456789;
vector<int> whosolve;

int caculate(int cx , int cy, int px, int py)
{
    int revalue = abs(cx-px) + abs(cy-py);
    return revalue;
}

// memory out 
/*
// 우선순위 큐를 이용해서 시간단축 할 것 
void new_solution()
{
    //cout << " 111" <<"\n";
    while(!pq.empty())
    {
        Event e = pq.top();
        int p1y = e.polices[0].first;
        int p1x = e.polices[0].second;
        int p2y = e.polices[1].first;
        int p2x = e.polices[1].second;
        int result = e.result;
        int event_num = e.event_num;
        vector<int> way = e.way;
        
        pq.pop();
        
        
        if(event_num == w)
        {
            if(answer > result)
            {
                answer = result;
                whosolve = way;
            }
            
        }
        
        
        int cy = vcases[event_num].first ;
        int cx = vcases[event_num].second ;
    
        
        for(int i = 0 ; i<2 ;i++)
        {
            int py = e.polices[i].first;
            int px = e.polices[i].second;
            
            int value =  caculate(cx,cy, px ,py);
            //cout << "py : " << py << "px : "<< px <<"\n";
            //cout << "v: " <<value <<"\n";
            
            e.polices[i].first = cy ;
            e.polices[i].second = cx; 
            e.way.push_back(i+1);
            e.result = result + value;
            e.event_num = event_num + 1;
            
            if(answer < result+value)
            {
                continue;
            }
            
            pq.push(e);
            
            e.polices[i].first = py;
            e.polices[i].second = px; 
            e.way.pop_back();
            e.result -= value;
            e.event_num -= 1 ;
            // 첫번째 경찰차와 두번째 경찰차 
            
        }
        
        
        
        
        
        
        
        
        
        
    }
    
    

    
}
*/

// time out 
/*
void solution(vector<pair<int,int>> polices, int k , int result, vector<int> way)
{
    if(result > answer)
    {
        return;
    }
    // dfs bfs 
    if(k== w)
    {
        if(answer > result)
        {
            answer = result;
            whosolve = way;
        }
        
        return ; 
    }
    int cy = vcases[k].first ;
    int cx = vcases[k].second ;
    
    for(int i = 0 ; i<2 ;i++)
    {
        int py = polices[i].first;
        int px = polices[i].second;
        
        int value =  caculate(cx,cy, px ,py);
        cout << "py : " << py << "px : "<< px <<"\n";
        cout << "v: " <<value <<"\n";
        
        polices[i].first = cy ;
        polices[i].second = cx; 
        way.push_back(i+1);
        
        solution(polices,k+1,result+value,way);
        
        polices[i].first = py;
        polices[i].second = px; 
        way.pop_back();
        // 첫번째 경찰차와 두번째 경찰차 
        
    }
    
    
    
    
    
}
*/

int main()
{
    cin >> n;
    cin >> w;
    
    for(int i= 0;  i< w; i++)
    {
        int a , b;
        cin >> a >> b; // y, x 
        vcases.push_back({a,b});
        //qcases.push({a,b});
        
    }
    
    police1.first = 1;
    police1.second = 1;
    
    police2.first = n ;
    police2.second = n;
    
    polices.push_back(police1);
    polices.push_back(police2);
    
    vector<int> way;
    Event event;
    
    // event.police1 = police1;
    // event.polices = police2;
    
    event.polices = polices;
    event.result = 0;
    event.event_num = 0;
    event.way = way;
    
    pq.push(event);
   /* for(int i=0; i<polices.size(); i++)
    {
        cout<< polices[i].first <<" " << polices[i].second <<"\n";
    }
    for(int i=0; i<vcases.size(); i++)
    {
        cout << vcases[i].first <<" "<< vcases[i].second <<"\n";
    }*/

    // solution(polices,0,0,whosolve);
    
    //new_solution();
    
    cout << answer << "\n";
    for(int i= 0; i< w; i++)
    {
        cout << whosolve[i] << "\n";
    }

    return 0;
}