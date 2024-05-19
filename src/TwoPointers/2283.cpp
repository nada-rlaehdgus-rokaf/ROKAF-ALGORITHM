#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,k;
vector<pair<int,int>> arr;
//int result_st = 0;
//int result_en = 0;
int max_en = 0;
int min_st = 1003;

void solution()
{
    
    int en = min_st+1;
    int tot = 0;
    // st와 en 에 대해서 
    // queue
    // 원래의 것에 대해서 st 와 en 에 a 와 b 가 포함 되지 않을 경우에 
    // 그냥 넣지 않고 계산 함으로써 시간 단축? 
    queue<pair<int,int>> q; 
   
    for(int st = min_st ; st <= max_en; st++)
    {
         for(int i = 0 ; i< arr.size(); i++)
        {
            int a = arr[i].first ;
            int b = arr[i].second ; 
            if(b <= st )
                continue;
            if(a >= en)
                continue;
            q.push({a, b});     
                
        }
        while(st <= en && en <= max_en)
        {
            //cout << "st : " << st <<" " <<"en : " << en <<"\n";
            
            while(!q.empty())
            {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                
                if(a < st)
                {
                    if(b <= en)
                    {
                        tot += (b-st);
                    }
                    else{
                        tot += (en-st);
                    }
                }
                else{
                    if(b <= en)
                    {
                        tot += (b-a);
                    }
                    else{
                        tot += (en-a);
                    }
                }
            }
            //cout << "tot : " << tot <<"\n";
            
           
            if(tot == k)
            {
                cout << st <<" " << en <<"\n";
                return;
            }
            en ++ ; 
            
            tot =  0;
            
            
            if(tot > k)
            {
                tot =  0;
                break;
            }
            
             for(int i = 0 ; i< arr.size(); i++)
            {
                int a = arr[i].first ;
                int b = arr[i].second ; 
                if(b <= st )
                    continue;
                if(a >= en)
                    continue;
                q.push({a, b});     
                    
            }
            
            
            
        }
        
        en = st+1;
        
    }
    
    
    
    
    
}




int main()
{
    cin >> n >> k;
    
    
    for(int i=0; i<n; i++)
    {
        int st,en;
        cin >> st >> en;
        arr.push_back({st,en});
        min_st = min(min_st,st);
        max_en = max(max_en,en);
    }
    
    //cout << min_st << " " << max_en<<"\n";
    
    solution();
    
    //'cout << result_st <<" "<<result_en <<"\n";
    
    

    return 0;
}
