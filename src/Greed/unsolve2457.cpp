#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
vector<pair<pair<int,int>,pair<int,int>>> v;
int n;
bool comp(pair<pair<int,int>,pair<int,int>> p1,
pair<pair<int,int>,pair<int,int>> p2 )
{
    if(p1.first.first ==p2.first.first)
    {
        return p1.first.second < p2.first.second;
    }
    else{
        return p1.first.first < p2.first.first ? true : false;
    }
}


int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int fm,fd,lm,ld;
        cin >> fm >> fd>> lm>> ld;
        v.push_back({{fm,fd},{lm,ld}});
    }
    //  4 , 6, 9, 11 -> 30
    // 1,3,5,7,8,10,12 -> 31
    // 2 -> 28
    
    // 3-1 -> 11-30 은 매일 무조건 피어 있어함 && 최소값을 가짐 
    sort(v.begin(),v.end(),comp);
/*    for(int i=0; i<n; i++)
    {
        cout << v[i].first.first << " "<<v[i].first.second 
        <<" "<< v[i].second.first <<" "<< v[i].second.second <<"\n";
    }
*/
    int result = 0;
    int ifm =v[0].first.first;
    int ifd = v[0].first.second;
    int ilm = v[0].second.first;
    int ild =v[0].second.second;
/*    for(int i=0; i<n; i++)
    {
        int fm =v[i].first.first;
        int fd = v[i].first.second;
        int lm = v[i].second.first;
        int ld =v[i].second.second;
        if( (fm >= 3 && fd >1) && (ifm == 0 && ifd == 0) )
        {
            continue;
        }
        
        if(ifm == 0 && ifd == 0)
        {
            ifm = fm;
            ifd = fd;
            ilm = lm;
            ild = ld;
            result++;
        }
        if(ifm > fm){
            if(ilm > lm)
            {
            continue;
            }
            else if(ilm ==  lm){
                if(ild > ld)
                {
                    continue;
                 }
                else{
                    ifm = fm;
                    ifd = fd;
                    ilm = lm;
                    ild = ld;
                    result++;
                }
            }
            else{
                   ifm = fm;
                    ifd = fd;
                    ilm = lm;
                    ild = ld;
                    result++;
            }
        }
        else if(ifm == fm){
            if(ifd >= fd)
            {
                if(ild > ld)
                {
                    continue;
                }
                else{
                    ifm = fm;
                    ifd = fd;
                    ilm = lm;
                    ild = ld;
                    result++;
                }
            }
        }
        else{
               ifm = fm;
                ifd = fd;
                ilm = lm;
                ild = ld;
                result++;
        }
            
        
    }*/
    bool flag = true;
    for(int i=1; i<n; i++)
    {
        if(ifm >= 3 && ifd >1)
            break;
        int fm =v[i].first.first;
        int fd = v[i].first.second;
        int lm = v[i].second.first;
        int ld =v[i].second.second;
        if(ilm < fm)
         {
            // result = 0;
            // cout << reuslt <<"\n";
            // return 0;   
            int ifm =v[i-1].first.first;
            int ifd = v[i-1].first.second;
            int ilm = v[i-1].second.first;
            int ild =v[i-1].second.second;
            result++;
            continue;
         }
        if(ilm == fm)
        {
            if(ild < fd)
            {
                //   result = 0;
                // cout << reuslt <<"\n";
                // return 0;  
                int ifm =v[i-1].first.first;
                int ifd = v[i-1].first.second;
                int ilm = v[i-1].second.first;
                int ild =v[i-1].second.second;
                result++;
                continue;
            }
        }
        if(ilm > lm)
            continue;
        if(ilm == lm )
        {
            if(ild > ld)
                continue;
        }
        
        
    }
    if(ilm <11)
        result = 0;
    else if(ilm == 11){
        if(ild < 30)
        result = 0;
    }
    
    cout << result <<"\n";



    return 0;
}