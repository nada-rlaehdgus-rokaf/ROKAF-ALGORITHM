#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n;
int result =  0; 
struct InitDay
{
    int sm = 3 ;
    int sd = 1;
    int em = 11;
    int ed = 30;
};

struct flower
{
    int sm ;
    int sd ;
    int em ;
    int ed ;
};

vector<flower> v;
vector<flower> save;
// 4 , 6 , 9 ,11 -> 30
// 1 3 5 7 8 10 12 -> 31
// 2 -> 28
bool comp(flower f1, flower f2)
{

    if(f1.em == f2.em)
    {
        return f1.ed < f2.ed;
    }
    else{
        if(f1.em < f2.em)
        {
            return true;
        }
        else{
            return false;
        }
    }

}


void solution()
{
    InitDay initday;
    flower store;
    store.sm = 3;
    store.sd = 1;
    store.em = 3;
    store.ed = 1;


    for(int i= 0 ; i<n; i++)
    {
        // if(v[i].em < store.sm)
        //     continue;
        // else if(v[i].em == store.sm){
        //     if(v[i].ed < store.sd)
        //         continue;
        // }
        if(v[i].sm > store.sm)
            continue;
        else if(v[i].sm == store.sm)
        {
            if(v[i].sd < store.sd)
                continue;
        }

        if(store.em < v[i].sm)
        {
            // 저장되어 있는 것보다 더 커졌음으로 
            // 가장 큰 것으로 바꿔야한다 
            if(i == 0)
            {
                store.ed = v[i].ed;
                store.em = v[i].em;
                store.sd = v[i].sd;
                store.sm = v[i].sm;
            }
            else{
                store.ed = v[i-1].ed;
                store.em = v[i-1].em;
                store.sd = v[i-1].sd;
                store.sm = v[i-1].sm;
            }
          
        }
        else if(store.em == v[i].sm){
          if(store.ed < v[i].sd)
          {
             if(i == 0)
            {
                store.ed = v[i].ed;
                store.em = v[i].em;
                store.sd = v[i].sd;
                store.sm = v[i].sm;
            }
            else{
                store.ed = v[i-1].ed;
                store.em = v[i-1].em;
                store.sd = v[i-1].sd;
                store.sm = v[i-1].sm;
            }
            
          }
        }

        cout << store.sm << " " << store.sd << " " 
        <<store.em << " " << store.ed << "\n";





    }





}



int main()
{
    cin >> n ;
    for(int i= 0; i<n ;i ++)
    {
        int  sm,sd,em,ed;
        flower f;
        cin >> sm >> sd >> em >> ed;
        f.sm = sm ;
        f.sd = sd ;
        f.em = em;
        f.ed = ed ;
        v.push_back(f);
    }

    sort(v.begin(),v.end(),comp);

    for(int i=0; i<n ;i++)
    {
        cout << v[i].sm <<" " << v[i].sd <<" "<<v[i].em
         <<" "<< v[i].ed << "\n";
    }

    solution();




    return 0;
}