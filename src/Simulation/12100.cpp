#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};


vector<vector<int>> map(21,vector<int>(21,0));
int n ;

int result = 0;
// 중복 순열 5번 




void MoveLeft(vector<vector<int>> &curmap)
{
    vector<vector<int>> copymap(21,vector<int>(21,0));

    for(int i = 0 ; i < n; i++)
    {
        vector<pair<int,bool>> v; 
        for(int j = 0 ; j < n; j++)
        {
            if(curmap[i][j] != 0 )
            {
                v.push_back({curmap[i][j],false});
            }
        }

          if(v.size() == 0)
        {
            continue;
        }
        else if(v.size() == 1)
        {
            copymap[i][0] = v[0].first;
            continue;
        }

        vector<int> merge;
        for(int j = 0 ; j < v.size()-1; j++)
        {
            if(j != v.size()-2)
           {
                if(v[j].first == v[j+1].first)
                {
                    if(v[j].second == true)
                        continue;
                    merge.push_back(v[j].first*2);
                    v[j].second = true;
                    v[j+1].second = true;
                }
                else{
                    if(v[j].second == true)
                        continue;
                    merge.push_back(v[j].first);
                }
           }
           else if( j == v.size() -2 )
           {
                if(v[j].first == v[j+1].first)
                {
                    if(v[j].second == true)
                     {
                        merge.push_back(v[j+1].first);
                        continue;
                     }   
                    merge.push_back(v[j].first*2);
                    v[j].second = true;
                    v[j+1].second = true;
                }
                else{
                    if(v[j].second == true)
                    {
                        merge.push_back(v[j+1].first);
                    }
                    else{
                        merge.push_back(v[j].first);
                        merge.push_back(v[j+1].first);
                    }
                }
           }
            
        }
        for(int j = 0 ; j < merge.size(); j++)
        {
            copymap[i][j] = merge[j] ; 
        }
        
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <n; j++)
        {
            curmap[i][j] = copymap[i][j];
        }
    }


}

void MoveRight(vector<vector<int>> &curmap)
{
    vector<vector<int>> copymap(21,vector<int>(21,0));

    for(int i = 0 ; i < n; i++)
    {
        vector<pair<int,bool>> v; 
        for(int j = n-1 ; j >= 0; j--)
        {
            if(curmap[i][j] != 0 )
            {
                v.push_back({curmap[i][j],false});
            }
        }

        if(v.size() == 0)
        {
            continue;
        }
         else if(v.size() == 1)
        {
            copymap[i][n-1] = v[0].first;
            continue;
        }

        vector<int> merge;
        for(int j = 0 ; j < v.size()-1; j++)
        {
            if(j != v.size()-2)
            {    
                if(v[j].first == v[j+1].first)
                {
                    if(v[j].second == true)
                        continue;
                    merge.push_back(v[j].first*2);
                    v[j].second = true;
                    v[j+1].second = true;
                }
                else{
                    if(v[j].second == true)
                        continue;
                    merge.push_back(v[j].first);
                }
            }
            else if(j == v.size() -2 )
            {
                if(v[j].first == v[j+1].first)
                {
                    if(v[j].second == true)
                     {
                        merge.push_back(v[j+1].first);
                        continue;
                     }   
                    merge.push_back(v[j].first*2);
                    v[j].second = true;
                    v[j+1].second = true;
                }
                else{
                    if(v[j].second == true)
                    {
                        merge.push_back(v[j+1].first);
                    }
                    else{
                        merge.push_back(v[j].first);
                        merge.push_back(v[j+1].first);
                    }
                }
            }
        }
        for(int j = 0 ; j < merge.size(); j++)
        {
            copymap[i][n-(j+1)] = merge[j] ; 
        }
        
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <n; j++)
        {
            curmap[i][j] = copymap[i][j];
        }
    }
}

void MoveUp(vector<vector<int>> &curmap)
{
    vector<vector<int>> copymap(21,vector<int>(21,0));

    for(int i = 0 ; i < n; i++)
    {
        vector<pair<int,bool>> v; 
        for(int j = 0 ; j < n; j++)
        {
            if(curmap[j][i] != 0 )
            {
                v.push_back({curmap[j][i],false});
            }
        }
        
        if(v.size() == 0)
        {
            continue;
        }
        else if(v.size() == 1)
        {
            copymap[0][i] = v[0].first;
            continue;
        }

        vector<int> merge;
        for(int j = 0 ; j < v.size()-1; j++)
        {
            
            if(j != v.size()-2)
            {    
                if(v[j].first == v[j+1].first)
                {
                    if(v[j].second == true)
                        continue;
                    merge.push_back(v[j].first*2);
                    v[j].second = true;
                    v[j+1].second = true;
                }
                else{
                    if(v[j].second == true)
                        continue;
                    merge.push_back(v[j].first);
                }
            }
            else if( j == v.size() -2 )
            {
                if(v[j].first == v[j+1].first)
                {
                    if(v[j].second == true)
                     {
                        merge.push_back(v[j+1].first);
                        continue;
                     }   
                    merge.push_back(v[j].first*2);
                    v[j].second = true;
                    v[j+1].second = true;
                }
                else{
                    if(v[j].second == true)
                    {
                        merge.push_back(v[j+1].first);
                    }
                    else{
                        merge.push_back(v[j].first);
                        merge.push_back(v[j+1].first);
                    }
                }
            }
        }
        
        for(int j = 0 ; j < merge.size(); j++)
        {
            copymap[j][i] = merge[j] ; 
        }
        
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <n; j++)
        {
            curmap[i][j] = copymap[i][j];
        }
    }
}

void MoveDown(vector<vector<int>> &curmap)
{
    vector<vector<int>> copymap(21,vector<int>(21,0));

    for(int i = 0 ; i < n; i++)
    {
        vector<pair<int,bool>> v; 
        for(int j = n-1 ; j >= 0; j--)
        {
            if(curmap[j][i] != 0 )
            {
                v.push_back({curmap[j][i],false});
            }
        }

          if(v.size() == 0)
        {
            continue;
        }
         else if(v.size() == 1)
        {
            copymap[n-1][i] = v[0].first;
            continue;
        }

        vector<int> merge;
        for(int j = 0 ; j < v.size()-1; j++)
        {
            if(j!= v.size()-2)
            {    
                if(v[j].first == v[j+1].first)
                {
                    if(v[j].second == true)
                        continue;
                    merge.push_back(v[j].first*2);
                    v[j].second = true;
                    v[j+1].second = true;
                }
                else{
                    if(v[j].second == true)
                        continue;
                    merge.push_back(v[j].first);
                }
            }
            else if( j == v.size() -2 )
            {
                if(v[j].first == v[j+1].first)
                {
                    if(v[j].second == true)
                     {
                        merge.push_back(v[j+1].first);
                        continue;
                     }   
                    merge.push_back(v[j].first*2);
                    v[j].second = true;
                    v[j+1].second = true;
                }
                else{
                    if(v[j].second == true)
                    {
                        merge.push_back(v[j+1].first);
                    }
                    else{
                        merge.push_back(v[j].first);
                        merge.push_back(v[j+1].first);
                    }
                }
            }
        }
        for(int j = 0 ; j < merge.size(); j++)
        {
            copymap[n-(j+1)][i] = merge[j] ; 
        }
        
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <n; j++)
        {
            curmap[i][j] = copymap[i][j];
        }
    }

    

}

void Answer(vector<int> order)
{
    vector<vector<int>> copymap(21,vector<int>(21,0));
    for(int i = 0 ; i < n; i ++ )
    {
        for(int j = 0 ; j < n; j++)
        {
            copymap[i][j] = map[i][j];
        }
    }

    for(int i = 0 ; i < order.size(); i++)
    {
        if(order[i] == 0)
        {
            MoveLeft(copymap);
        }
        else if(order[i] == 1)
        {
            MoveRight(copymap);
        }
        else if(order[i] == 2)
        {
            MoveUp(copymap);
        }
        else if(order[i] == 3)
        {
            MoveDown(copymap);
        }
        
        // for(int a = 0 ; a < n; a ++)
        // {
        //     for(int b = 0 ;b < n; b++)
        //     {
        //         cout << copymap[a][b] <<" ";
        //     }
        //     cout <<"\n";
        // }


    }

    for(int i = 0 ; i < n; i ++)
    {
        for(int j = 0 ;j < n; j++)
        {
            result = max(result,copymap[i][j]);
        }
    }

}

void RepeatPermutiaon(int cur,vector<int> order)
{
    if(cur == 5)
    {
        // for(int i = 0 ; i < order.size(); i++)
        // {
        //     cout << order[i] <<" ";
        // }
        // cout <<"\n";
        Answer(order);
        return; 
    }
    
    for(int i = 0; i < 4; i++)
    {
        order[cur] = i ;
        RepeatPermutiaon(cur+1,order);
    }

}




void solution()
{
    // 4 가지 위 아래 오른쪽 왼쪽으로 정렬 
    vector<int> order(5,0);
    RepeatPermutiaon(0,order);





}






int main()
{
    cin >> n;
    for(int i = 0 ; i< n; i++)
    {
        for(int j = 0 ; j<n; j++)
        {
            cin >> map[i][j];
        }
    }
    
    solution();

    cout << result <<"\n";

    return 0;
}