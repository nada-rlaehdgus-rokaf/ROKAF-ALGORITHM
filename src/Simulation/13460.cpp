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

int n,m ;
vector<vector<char>> map (11,vector<char>(' ',11));
int result = INF;


void titlRight(vector<vector<char>> curmap ,
pair<int,int> &red, pair<int,int>&blue, pair<int,int> hole)
{
    if(red.first == blue.first)
    {
        if(red.second > blue.second)
        {
            int rx = red.second;
            for(int i = red.second; i < m; i++)
            {
                rx += dx[2] ; 
                if(rx < 0 || rx > m)
                {
                    red.second = (rx - dx[2]);
                    break;
                }
                if(curmap[red.first][rx] == '#')
                {
                   red.second = (rx-dx[2]);
                    break;
                }
                if(curmap[red.first][rx] == 'o')
                {
                    red.second = rx ;
                    break;
                }

            }
            int bx = blue.second;
            for(int i = blue.second; i < m ; i++)
            {
                 bx += dx[2] ; 
                if(rx < 0 || rx > m)
                {
                    red.second = (bx - dx[2]);
                    break;
                }
                if(curmap[blue.first][bx] == '#')
                {
                   red.second = (bx-dx[2]);
                    break;
                }
                if(curmap[blue.first][bx] == 'o')
                {
                    red.second = bx ;
                    break;
                }
                if(curmap[blue.first][bx] ==  )
            }
        }
        else{

        }
    }
    else{


    }

}
void tiltLeft(vector<vector<char>> curmap ,
pair<int,int> &red, pair<int,int>&blue, pair<int,int> hole)
{

}

void tiltUp(vector<vector<char>> curmap ,
pair<int,int> &red, pair<int,int>&blue, pair<int,int> hole)
{

}
void tiltDown(vector<vector<char>> curmap ,
pair<int,int> &red, pair<int,int>&blue, pair<int,int> hole)
{


}

void Answer(vector<int> order)
{
    vector<vector<char>> copymap (11,vector<char>(' ',11));
    pair<int,int> blue;
    pair<int,int> red;
    pair<int,int> hole;

    for(int i = 0 ; i < n; i ++)
    {
        for(int j = 0 ; j < n; j++)
        {
            if(map[i][j] == 'R')
            {
                red.first = i;
                red.second = j ;
            }
            else if(map[i][j] == 'B')
            {
                blue.first = i;
                blue.second = j ;
            }
            else if(map[i][j] == 'o')
            {
                hole.first = i;
                hole.second = j ; 
            }
            copymap[i][j] = map[i][j];
        }
    }


    for(int i = 0 ; i < order.size(); i++)
    {
        if(order[i] == 0)
        {

        }
        else if(order[i] == 1)
        {

        }
        else if(order[i] == 2)
        {

        }
        else if(order[i]== 3)
        {

        }

    }












}





void RepeatPermutiaon(int cnt , vector<int> order)
{
    if(cnt == 10)
    {
        Answer(order);
        return;
    }
    for(int i = 0 ; i < 4;  i++)
    {
        order[cnt] = i ;
        RepeatPermutiaon(cnt+1, order);
    }

}

void solution()
{
    vector<int> order(10,0);
    RepeatPermutiaon(0,order);

}


int main()
{
    cin >> n >> m ; 
    for(int i = 0 ; i < n;  i++)
    {
        for(int j = 0 ; j <  m; j++)
        {
            cin >> map[i][j] ;
        }
    }
    



    return 0;
}