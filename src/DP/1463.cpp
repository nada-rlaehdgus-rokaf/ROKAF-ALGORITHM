#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr (n+1,987654321);
    
    arr[n] = 0;
    
    for(int i=n; i>=1; i--){
        if(i %3 == 0){
            arr[i/3]=min(arr[i/3],arr[i]+1);
        }
        if(i%2 == 0){
            arr[i/2] = min(arr[i/2],arr[i]+1);
        }
        if(i>=0){
            arr[i-1] =min(arr[i-1],arr[i]+1);
        }
    }
    
    cout << arr[1] <<'\n';

    return 0;
}

