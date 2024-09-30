#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,l ; 
int map[101][101];
int result = 0 ;
int visited[101][101][2]; // 가로 세로 길 

// 경사로는 낮은 칸에 놓이며 
// 낮은 칸과 높은 칸의 높이 차이가 1 
// 낮은 지점의 칸의 높이가 모두 같고 L개가 연속되어야함
// 경사로가 범위안에 있어야함 

// ===========================//
// 총평 for문에 조건문을 넣어서 풀어야하는데 
// for문에 인자가 돌아갈 때 조건을 타이트하게 쓰고 
// 인자처리를 신중히 해야하는 문제 
// ===========================// 
void solution()
{
    //  가로 ++ 
    for(int i = 0 ; i < n; i ++)
    {
        bool SafeRoad = true;
        for(int j = 0 ; j <n-1; j++)
        {
            if(map[i][j] != map[i][j+1])
            {
                if(abs(map[i][j] - map[i][j+1]) == 1 )
                {
                    if(map[i][j] > map[i][j+1])
                    {
                        for(int k = 1 ; k <= l ; k++)
                        {
                            if(k != l)
                            {
                                if(j+k > n-1 )
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                if(map[i][j+k] != map[i][j+k+1])
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                if(visited[i][j+k][0] ==1 )
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                visited[i][j+k][0] = 1; 
                            }
                            else{
                                if(j+k  > n-1 )
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                if(visited[i][j+k][0] == 1)
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                visited[i][j+k][0] = 1;
                            }
        
                        }
                    }
                    else{
                        for(int k = 1 ; k <= l ; k++)
                        {

                            if(k != l)
                            {
                                if((j+1)-k  < 0 )
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                if(map[i][j+1-k] != map[i][j-k])
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                if(visited[i][j+1-k][0] ==1 )
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                visited[i][j+1-k][0] = 1; 
                            }
                            else{
                                if((j+1)-k  < 0 )
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                if(visited[i][j+1-k][0] == 1)
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                visited[i][j+1-k][0] = 1;
                            }
                        }
                    }

                }
                else{
                    SafeRoad = false;
                    break;
                }

            }
        }
        if(SafeRoad)
        {
            // cout <<"가로" << i <<"\n";
            // for(int j = 0 ; j < n; j++)
            // {
            //     cout << visited[i][j][0] << " ";
            // }
            // cout <<"\n";
            result++;
        }    
    }

    for(int i = 0 ; i < n; i ++)
    {
        bool SafeRoad = true;
        for(int j = 0 ; j <n-1; j++)
        {
            if(map[j][i] != map[j+1][i])
            {
                if(abs(map[j][i] - map[j+1][i]) == 1 )
                {
                    if(map[j][i] > map[j+1][i])
                    {
                        for(int k = 1 ; k <= l ; k++)
                        {
                            if(k!=l)
                            {
                                if(j+k > n-1 )
                                {
                                    SafeRoad = false;
                                    break;
                                }
                            
                                if(map[j+k][i] != map[j+1+k][i])
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                
                                if(visited[j+k][i][1] ==1 )
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                visited[j+k][i][1] =1 ;
                            }
                            else{
                                if(j+k > n-1 )
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                if(visited[j+k][i][1] == 1)
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                visited[j+k][i][1] =1 ;
                                
                            }
                        }
                    }
                    else{

                        for(int k = 1 ; k <= l ; k++)
                        {
                            
                            if(k!=l)
                            {
                                if((j+1)-k  < 0 )
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                if(map[j+1-k][i] != map[j-k][i])
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                if(visited[j+1-k][i][1] == 1)
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                visited[j+1-k][i][1] = 1 ;
                            }
                            else{
                                if( (j+1)-k  < 0 )
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                if(visited[j+1-k][i][1] == 1)
                                {
                                    SafeRoad = false;
                                    break;
                                }
                                 visited[j+1-k][i][1] = 1 ;
                                 
                            }
                        }
                    }

                }
                else{
                    SafeRoad = false;
                    break;
                }

            }
        }
        if(SafeRoad)
        { 
            // cout <<"세로" << i <<"\n";
            // for(int j = 0 ; j < n; j++)
            // {
            //     cout << visited[j][i][1] << " ";
            // }
            // cout << "\n";
            result++;
        }
    }







}




int main()
{
    cin >> n >> l;
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j <n; j++)
        {
            cin >> map[i][j];
        }
    }

    solution();

    cout << result<< "\n";

    return 0;
}