#include <iostream>
#include <vector>

using namespace std;


int n,m;
int arr[9];

void print(int k){
    if(k == m){
        for(int i=0; i< m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1; i<n+1; i++){
        if(k==0)
        {
            arr[k] = i;
        }
        else{
            if(i >= arr[k-1])
            {
                arr[k] = i;
                print(k+1);
            }
            
        }
    
    }

    
}


int main()
{
    
    cin >> n >> m;
    //cout<<"Hello World";

    print(0);
    return 0;
}

