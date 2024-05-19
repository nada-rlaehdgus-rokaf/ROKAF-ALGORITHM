#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int t,w,h;
vector<string> result; 
 
// 불과 사람이 같이 있을 때 역시 배제해야 한다는 것 

void solution(int w, int h)
{
    vector<vector<char>> map(h,vector<char>(w,' '));
    vector<vector<int>> pvisited(h,vector<int>(w,-1));
    vector<vector<int>> fvisited(h,vector<int>(w,-1));
    queue<pair<int,int>> fq; // y , x 
    queue<pair<int,int>> pq; 
    for(int i=0; i<h; i++)
    {
        for(int j=0; j< w; j++)
        {
            char c;
            cin >> c;
            map[i][j] = c;
            if(c=='*')
            {
                fq.push({i,j});
                fvisited[i][j] = 0;
            }
            if(c=='@')
            {
                pq.push({i,j});
                pvisited[i][j] = 0;
            }
        }
    }
    while(!fq.empty())
    {
        int y = fq.front().first;
        int x = fq.front().second;
        fq.pop();
        for(int i = 0 ; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x  + dx[i];
            
            if(ny  < 0 || ny >= h || nx < 0 || nx >=w)
                continue;
            if(map[ny][nx] == '#')
                continue;
            if(map[ny][nx] == '*')
                continue;
            if(fvisited[ny][nx] > -1)
                continue;
            /*if(fvisited[ny][nx] < fvisited[y][x] + 1 )
                continue;*/
            fq.push({ny,nx});
            fvisited[ny][nx] = fvisited[y][x] + 1;
        
        }
        
    }
/*    for(int i= 0 ; i < h; i++)
    {
        for(int j=0; j<w; j++)
        {
            cout << fvisited[i][j] <<" ";
        }
        cout <<"\n";
    }*/
    
    while(!pq.empty())
    {
        int y = pq.front().first;
        int x = pq.front().second;
        pq.pop();
        //cout << "y :" << y << " " <<"x : "<<x  <<"\n";
        //cout << pvisited[y][x] <<" "<<fvisited[y][x] <<"\n";
        if( y== 0 || y==h-1 || x== 0 || x ==w-1)
        {
            result.push_back(to_string(pvisited[y][x]+1));
            //cout << pvisited[y][x] + 1 << "\n";
            return;
        }
        
        for(int i = 0 ; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x  + dx[i];
            
            if(ny  < 0 || ny >= h || nx < 0 || nx >=w)
                continue;
            if(map[ny][nx] == '#')
                continue;
            if(map[ny][nx] == '*')
                continue;
            if(pvisited[ny][nx] > -1)
                continue;
            if( pvisited[y][x] +1 >=fvisited[ny][nx] && fvisited[ny][nx] != -1 )
                continue;
            pq.push({ny,nx});
            pvisited[ny][nx] = pvisited[y][x] + 1;
        
        }
        
        
    }
    
    result.push_back("IMPOSSIBLE");
    //cout << "IMPOSSIBLE" <<"\n";
    
    
}

int main()
{
    cin >> t ;
    for(int i = 0; i< t; i++)
    {
        cin >> w >> h ;
        solution(w,h);
    }
    
    for(int i= 0; i< result.size(); i++)
    {
        cout << result[i] <<"\n";
    }
    
    

    return 0;
}