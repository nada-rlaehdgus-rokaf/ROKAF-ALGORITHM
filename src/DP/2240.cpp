#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[31][3][1001];

int main ()
{
  int t, w;
  cin >> t >> w;

  vector < int >arr (1001, 0);

  for (int i = 1; i < t + 1; i++)
    {
      int a;
      cin >> a;
      arr[i] = a;
    }

  for (int i = 0; i < w + 1; i++)
    {
//       for (int j = 1; j < 3; j++)
// 	{
// 	  for (int k = 1; k < t + 1; k++)
// 	    {
// 	      if (i != 0)
// 		{
// 		  if (arr[k] == 1)
// 		    {
// 		      dp[i][1][k] =
// 			max (dp[i - 1][2][k - 1], dp[i - 1][1][k - 1]) + 1;
// 		      dp[i][2][k] = dp[i][2][k - 1];
// 		    }
// 		  else
// 		    {
// 		      dp[i][2][k] =
// 			max (dp[i - 1][2][k - 1], dp[i - 1][1][k - 1]) + 1;
// 		      dp[i][1][k] = dp[i][1][k - 1];
// 		    }
// 		}
// 		else{
// 		      if (arr[k] == 1)
// 		    {
// 		      dp[i][1][k] = dp[i][1][k - 1]+ 1;
// 		      dp[i][2][k] = dp[i][2][k - 1];
// 		    }
// 		  else
// 		    {
// 		      dp[i][2][k] = dp[i][2][k - 1]+ 1;
// 		      dp[i][1][k] = dp[i][1][k - 1];
// 		    }
// 		}
// 	    }
// 	}

        for(int j = 1; j<t+1; j++){
            if( i == 0){
                dp[i][1][j] = dp[i][1][j-1] + (arr[j] == 1);
            }
            else{
                dp[i][1][j] = max(dp[i][1][j-1] + (arr[j] == 1) ,
                dp[i-1][2][j-1] +(arr[j] == 1)  );
                dp[i][2][j] = max(dp[i][2][j-1] + (arr[j] == 2) ,
                dp[i-1][1][j-1] +(arr[j] == 2)  );
            }
        }

    }

    int result = 0;

    for(int i = 0; i< w+1 ; i++){
        for(int j=1; j< 3; j++)
        {result = max (result, dp[i][j][t]);
        }
    }

    cout << result <<"\n";


  return 0;
}

