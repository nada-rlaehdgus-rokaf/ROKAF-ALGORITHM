#include <iostream>

using namespace std;
int n,k;
int coin[11];
int main()
{
    cin >> n >> k;
    for(int i=1; i<n+1; i++)
    {
        int a;
        cin >> a;
        coin[i] = a;
    }
    int count = 0;
    for(int i=n; i>0; i--)
    {
        if(k>coin[i])
        {
            count += k/coin[i];
            k = k%coin[i];
        }
        else if(k==coin[i])
        {
            count +=1;
            break;
        }
    }
    
    cout << count <<"\n";
    //cout<<"Hello World";

    return 0;
}
