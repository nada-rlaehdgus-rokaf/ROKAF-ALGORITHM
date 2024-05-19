#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n ;
    vector<pair<int,int>> work (n+1,{0,0});
    vector<int> arr (n+2,0);
    
    
    for(int i=1 ; i<n+1; i++){
        int a,b;
        cin >> a >> b;
        work[i].first = a; 
        work[i].second = b;
    }
    
    
    
    int result = 0;
    
    for(int i=1 ; i<n+1;  i++){
        if (i + work[i].first >= n+2){
            arr[i+1] = result;
            //arr[i] = arr[i-1];
            //arr[i] = max;
            continue;
        }
        
        if (arr[i] + work[i].second >= arr[i+work[i].first]){
            arr[i+work[i].first] = max(arr[i+work[i].first] ,
            arr[i] + work[i].second ) ;  
            result = arr[i+work[i].first] ;
            // if(arr[i] != 0)
            // {for(int j = i ; j<n + 2; j++){
            //     arr[j] = result;
            // }
            // }
             if(arr[i] != 0)
            {
              for(int j = i+work[i].first+1; j<n+2; j++){
                    if(arr[j] == 0)
                    {
                        arr[j] = arr[i+work[i].first];
                    } 
                    else{
                             break;
                    }
              }
            }
            
        }
        
    
        // if(arr[i] + work[i].second>=arr[i+work[i].first]){
        //   arr[i+work[i].first] = arr[i] + work[i].second;  
        // }
        // // else{
        // //     arr[i+work[i].first] = arr[i] + work[i].second;
        // // }
    }
    for (int i=1; i<n+2; i++){
        cout << i << " "<< arr[i] << '\n';
    }
    
    cout << arr[n+1] << '\n';


    return 0;
}

