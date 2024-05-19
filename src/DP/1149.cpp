#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int N;
int house[1001][4];
int RGB[1001][4];
int main()
{
    cin >> N;
    for (int i = 1; i < N + 1; i++)
    {
        int R, G, B;
        cin >> R >> G >> B;
        RGB[i][1] = R;
        RGB[i][2] = G;
        RGB[i][3] = B;
    }
    house[1][1] = RGB[1][1];
    house[1][2] = RGB[1][2];
    house[1][3] = RGB[1][3];

    for (int i = 2; i < N + 1; i++)
    {
        house[i][1] = min(house[i - 1][2], house[i - 1][3]) + RGB[i][1];
        house[i][2] = min(house[i - 1][1], house[i - 1][3]) + RGB[i][2];
        house[i][3] = min(house[i - 1][2], house[i - 1][1]) + RGB[i][3];
    }

    cout << min(house[N][1], min(house[N][2], house[N][3])) << " \n";

    return 0;
}
