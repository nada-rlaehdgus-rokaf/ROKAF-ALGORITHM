#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int dicx[5] =  {0,1,-1,0,0};
int dicy[5] =  {0,0,0,-1,1};
int n , m  , y , x, k;
int map[21][21] ;
vector<int> order;
int dice[7] ; 

void solution()
{
    pair<int,int> dice_pos = {y,x};  // y,x 
    int ny = dice_pos.first;
    int nx = dice_pos.second;
    for(int i =  0 ;  i < order.size(); i ++)
    {
        ny += dicy[order[i]];
        nx += dicx[order[i]];
           
        //cout << ny <<" " <<nx <<"\n";
        if(ny< 0 || ny >= n || nx < 0  || nx >= m)
        {
            ny -= dicy[order[i]];
            nx -= dicx[order[i]];
            continue;
        }
        
        // 동서남북을 order 대로 따져준다음 밑바닥 을 갱신 시켜준다.
        // 주사위 값 갱신 해줘야함 
        if(order[i] == 1)
        {
            int temp = dice[1]; 
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;

        }
        else if(order[i] == 2)
        {
            int temp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;

        }
        else if(order[i] == 3)
        {
            int temp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;

        }
        else if(order[i] == 4)
        {
            int temp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
        }

        if(map[ny][nx] == 0 )
        {
            map[ny][nx] = dice[6];
        }
        else{
            dice[6] = map[ny][nx] ;
            map[ny][nx] = 0;
        }
        cout << dice[1] << "\n";
    }

}




int main()
{
    cin >> n >> m >> y >> x >>  k  ;
    for(int  i = 0 ; i < n; i ++)
    {
        for(int j = 0;  j < m;  j ++)
        {
            cin >> map[i][j] ;
        }
    }
    for(int i = 0 ;  i < k ;  i++)
    {   
        int a;
        cin >> a;
        order.push_back(a);
    }
    // for(int i = 0 ; i < order.size(); i ++)
    // {
    //     cout<< order[i] <<" ";
    // }
    // cout << "\n";
    //cout << order.size() <<"\n";
    solution();

    return 0;
}