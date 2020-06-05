#include <iostream>
#include <vector>
using namespace std;
int edit_distance(string a, string b)
{
    int dp[a.length()+1][b.length()+1];
    for(size_t i = 0; i <= a.length(); i++){
        for(size_t j = 0; j <= b.length(); j++){
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
        }
    }
    return dp[a.length()][b.length()];
}
int main (void)
{
    string a, b;
    cin >> a >> b;
    cout << edit_distance(a, b);
    return 0;
}
