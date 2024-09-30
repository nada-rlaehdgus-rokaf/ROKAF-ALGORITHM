#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int n ; 
vector<pair<pair<int,int>,pair<int,int>>> dragoncurve; // y , x , d, g
int map[101][101]; // y , x ; 
int result = 0 ;

void solution()
{
    // 
    for(int i = 0 ; i < dragoncurve.size(); i++)
    {
        int y = dragoncurve[i].first.first;
        int x = dragoncurve[i].first.second;
        int d = dragoncurve[i].second.first;
        int g = dragoncurve[i].second.second;
        vector<pair<pair<int,int>,int>> v;
        map[y][x] = 1;
        map[y+dy[d]][x+dx[d]] = 1;
        v.push_back({{y,x},d});
        v.push_back({{y+dy[d],x+dx[d]},d}) ; 
        for(int j = 1 ; j <= g; j++)
        {
            int size = v.size();
            int ly = v[size-1].first.first;
            int lx = v[size-1].first.second;
            for(int k = size-1 ; k>=1; k--)
            {
                int ldd = (v[k].second + 1) % 4 ; 
                ly += dy[ldd];
                lx += dx[ldd];
                v.push_back({{ly,lx},ldd});
            }
        }
        
        for(int i = 0 ; i< v.size(); i++)
        {
            int y  = v[i].first.first;
            int x = v[i].first.second;
            map[y][x] = 1; 
        }
      

    }

}
void Answer()
{
    for(int i = 0 ; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            if(map[i][j] == 0 || map[i+1][j] == 0  
            || map[i][j+1] == 0 || map[i+1][j+1] == 0){
                continue;
            }
            result ++ ;
        }
    }



}




int main()
{
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        dragoncurve.push_back({{y,x},{d,g}});
    }

    solution();

    Answer();
    
    cout << result <<"\n";
    // for(int i = 0; i< 10; i++)
    // {
    //     for(int j = 0 ; j<10; j++)
    //     {
    //         cout << map[i][j] <<" ";
    //     }
    //     cout <<"\n";
    // }

    

    return 0;
}