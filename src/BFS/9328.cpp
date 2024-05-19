#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int w,h;
char map[104][104];
int visit[104][104];
int t;
vector<int> result;
void solution(int a,int b,vector<int> keyV)
{
    queue<pair<int,int>> q;
    q.push({a,b});
    visit[a][b] = 1;
    int document = 0;
    queue<pair<int,int>> door[27];
    while(!q.empty())
    {
        int y = q.front().first; 
        int x = q.front().second;
        q.pop();
        //cout << "y : " <<y  <<" x : "<< x <<"\n";

        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || ny >= h+2|| nx <0 || nx >=w+2)
                continue;
            if(map[ny][nx] == '*')
                continue;
            if(visit[ny][nx] == 1)
                continue;
                
                
            if(map[ny][nx] == '$')
            { 
                q.push({ny,nx});    
                visit[ny][nx] = 1;
                document++;
                //cout << document << "\n";
            }
            
            if(map[ny][nx] >=  'A' && map[ny][nx] <= 'Z' )
            {
                
                if( keyV[map[ny][nx] - 64] == 1) // 이상
                {
                    q.push({ny,nx});    
                    // cout <<map[ny][nx] - 64 <<" " << keyV[map[ny][nx] - 64] <<"\n";
                    visit[ny][nx] = 1;
                }
                else{
                    if(visit[ny][nx] ==0 )
                    {
                        door[map[ny][nx] - 64].push({ny,nx});
                        visit[ny][nx] = 2;
                        //q.push({y,x});
                    }
                  
                }
                
            }    
            
            if(map[ny][nx] >=  'a' && map[ny][nx] <= 'z' )
            {
                q.push({ny,nx});
                visit[ny][nx] = 1;
                keyV[map[ny][nx]-96]=1;
                while(!door[map[ny][nx] - 96].empty())
                {
                    q.push(door[map[ny][nx] -96].front());
                    door[map[ny][nx]-96].pop();
                }
            }   
            
            if(map[ny][nx] == '.' || map[ny][nx] == ' ')
            {   q.push({ny,nx});
                visit[ny][nx] = 1;
            }
            
        }
    }
     result.push_back(document);
}

int main()
{
    cin >> t;
    for(int i = 0; i<t; i++)
    {
        //vector<vector<char>> arr(100,vector<char>(100,0));
        
        cin >> h >> w ;
        for(int j=0; j<h+2; j++)
        {
            for(int k=0; k<w+2; k++)
            {
                map[j][k] = ' ';
            }
        }
         for(int j=0; j<h+2; j++)
        {
            for(int k=0; k<w+2; k++)
            {
                visit[j][k] = 0;
            }
        }
        for(int j=1; j<h+1; j++)
        {
           string str;
           cin >> str;
           for(int k=0; k<str.size(); k++)
           {
               map[j][k+1] = str[k];
           }
        }
        
        string keys;
        cin >> keys;
        vector<int> keyV(27,0);
        if(keys != "0")
        {
            for(int j=0; j<keys.size(); j++)
            {
                keyV[keys[j]-96]= 1;
            }
        }
        
        
        
        
        solution(0,0,keyV);
        
    }
    for(int i=0; i<result.size(); i++)
    {
        cout << result[i] <<"\n";
    }

    return 0;
}


