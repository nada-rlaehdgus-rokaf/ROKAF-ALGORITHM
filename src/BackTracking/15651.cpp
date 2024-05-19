#include <iostream>
#include <vector>

using namespace std;

int visited[8];
int arr[8];
int first[8];
int n,m;
void print(int k ){
    if(k==m){
        for(int i=0; i<m; i++){
            cout << arr[i] <<" ";
        }
        cout <<"\n";
        return;
    }
    
    for(int i=1; i<n+1; i++){
        arr[k] = i;  
        print(k+1);
    }
    
}


int main()
{
    cin >> n>> m;
    
    print(0);

    return 0;
}
