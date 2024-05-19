#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n;
vector<int> arr;
long long result = 0;
int mcount = 0;
int pcount = 0;
priority_queue<int> ppq;
priority_queue<int> mpq;
// bool comp(int a,int b)
// {
//     return a < b ;
// }

int main()
{
    
    cin >> n;
          bool zero = false;
         bool mone = false;
        bool pone = false; 
   for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        if(a < -1)
        {
            mcount++;
        }
        if (a > 1)
        {
            pcount++;
        }
        if (a== 0)
        {    
            zero = true;
            continue;
        }
        if (a== 1)
        {    
            pone = true;
            continue;
        }
         if (a== -1)
        {    
            mone = true;
            continue;
        }
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    int index = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] >= 0)
            index = i;
    }

  
    int msum = 0;
    if(mcount % 2 == 0)
    {
        for(int i=0 ; i <index; i+=2)
        {
            msum += (arr[i] * arr[i+1]);
        }
        
        if(mone == true)
            msum -= 1;
        
    }
    else{
        for(int i=0 ; i <index-1; i+=2)
        {
            msum += (arr[i] * arr[i+1]);
        }
        // -1이 비어잇음
        if(mone == true)
            msum += (arr[index-1] * -1);
        else
        {
            if(zero == true)
            {
                index ++;
            }
            else{
                msum += arr[index-1];
            }
            
        }
        
       /* if(zero== true)
        {
            index ++; // 0임으로 그다음 것 부터 
        }
        else{
            if()
            msum += arr[index-1];
        }*/
    }
    //cout << index <<"\n";
    int psum = 0;
    if(pone == true)
    {
        psum +=1;
        index ++; 
    }
    if(pcount %2 == 0)
    {
        for(int i= arr.size()-1; i>=index ; i-=2)
        {
            psum += (arr[i] * arr[i+1]);
        }
    }
    else{
        for(int i=arr.size()-1; i>=index+1 ; i-=2)
        {
            psum += (arr[i] * arr[i+1]);
        }
        psum+=arr[index];
    }
    
    result = psum + msum ;
    cout << result <<"\n";
    
    
/*    bool zero = false;
    bool mone = false;
    bool pone = false; 
    
    for(int i=0 ;i<n ; i++)
    {
        int a ;
        cin >> a;
        if(a> 1) 
        {
            ppq.push(a);
        }
         if(a<-1 )
        {
            mpq.push(a);
        }
        if(a== 0)
        {
            zero = true;
        }
        if (a == -1)
        {
            mone = true;
        }
        if (a == 1)
        {
            pone = true;
        }
    }
    
    
    while(!ppq.empty())
    {
        int first = ppq.top();
        ppq.pop();
        
    }*/
    

    return 0;
}