
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,m;
int map[301][301];
int v[301][301];
//int temp[301][301];
int ice_count = 0;
queue<pair<int,pair<int,int>>> q;
//vector<pair<int,pair<int,int>>> pv;

bool check(pair<int,pair<int,int>> p)
{
    
    queue<pair<int,pair<int,int>>> check_q;
    check_q.push(p);

    v[p.second.first][p.second.second] = 1;
  
    int check_count = 1;
    
    while(!check_q.empty())
    {
        int y = check_q.front().second.first;
        int x = check_q.front().second.second;
        int h = check_q.front().first;
        check_q.pop();
        
        
      
        int ice = 0;
        for(int j=0; j<4; j++)
        {
            int ny = y + dy[j];
            int nx = x + dx[j];
            if( nx < 0  || nx >= m || ny <0 || ny >=n)
                continue;
            if(v[ny][nx] == 1)
                continue;
            if(map[ny][nx] != 0 )
            {
                check_q.push({h,{ny,nx}});
                v[ny][nx] = 1;
                check_count++;
            }
            
        }
        
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            v[i][j] = 0;
        }
    }
     /* cout << "ice_count : "<< ice_count << 
      "check_count : "<< check_count <<"\n";*/
    if(check_count == ice_count)
    {
        return true;
    }
    else{
        return false;
    }
    
}


void solution(){
    
   
    
    int now = 0;
    while(!q.empty())
    {
    
        
        int size = q.size();
        //cout << "size : " <<size <<"\n";
        vector<pair<int,pair<int,int>>> save_ice;
         vector<pair<int,pair<int,int>>> save_zero;
        for(int i = 0; i<size; i++)
        {
            int y = q.front().second.first;
            int x = q.front().second.second;
            int h = q.front().first;
            //cout << y <<" "<< x <<" "<< h <<"\n";
            q.pop();
            
            int ice = 0;
            for(int j=0; j<4; j++)
            {
                int ny = y + dy[j];
                int nx = x + dx[j];
                if( nx < 0  || nx >= m || ny <0 || ny >=n)
                    continue;
                
                if(map[ny][nx] == 0)
                    ice ++ ;
                
            }
            
            if( h - ice > 0  )
            {
                //map[y][x] = h-ice;
                //v.push_back({x{i,j}});
                save_ice.push_back({(h-ice),{y,x}});
            }
            else{
                ice_count--;
               save_zero.push_back({0,{y,x}});
            }
        }
        for(int i = 0 ; i<save_ice.size(); i++)
        {
            q.push(save_ice[i]);
        }
        //cout << "size :" << q.size() <<"\n";
        for(int i=0; i<save_ice.size(); i++)
        {
            int y = save_ice[i].second.first;
            int x = save_ice[i].second.second;
            int h = save_ice[i].first;
            map[y][x] = h;
        }
        for(int i=0; i<save_zero.size(); i++)
        {
            int y = save_zero[i].second.first;
            int x = save_zero[i].second.second;
            int h = save_zero[i].first;
            map[y][x] = h;
        }
        
        now ++ ; 
       // cout << "now : " << now <<"\n";
        if(q.size()  == 0)
        {
            cout << 0 <<"\n";
            
            return;
        }
          // 떨어져 있는지 검사
        if(check(q.front()) == false)
        {
            cout << now <<"\n";
            
            return;
        }
        
        

    }
    
    cout << 0 <<"\n";
    
    
    
}



int main()
{
    cin >> n >>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int x;
            cin >> x;
            if(x >0)
            {
                //cout <<x <<"\n";
                q.push({x,{i,j}});
                //v.push_back({x{i,j}});
                ice_count++;
            }
            map[i][j] = x;
            
        }
    }
   
    
    solution();    

    return 0;
}



