#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> arr;
int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        long long ll;
        cin >> ll;
        arr.push_back(ll);
    }
    
    sort(arr.begin(),arr.end());
    
    long long max_val = -(1ll << 62) - 1;
    int count = 0;
    int max_count = 0;
    for(int i=0; i<n; i++){
        if(i == 0 || arr[i] == arr[i-1] )
            count ++ ;
        else{
            if(count > max_count)
            {
                max_count = count;
                max_val = arr[i-1];
            }
            // else if(count == max_count)
            // {
            //     if(arr[i-1] < max_val)
            //         max_val = arr[i-1];
            // }
            count = 1;
        }   
    }
    if(count > max_count)
    {
        max_val = arr[n-1];
    }

    
    cout << max_val <<"\n";



    return 0;
}
