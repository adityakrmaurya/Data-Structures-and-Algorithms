#include <iostream>
#include <vector>

using namespace std;

int coin_change(int x, vector<int>& dp, vector<int>& coins)
{
    for(int i = 1; i <= x; i++){
        int u = 1e9;
        for(size_t j = 0; j < coins.size(); j++){
            if(i < coins[j])
                continue;
            u = min(u, dp[i-coins[j]]+1);
        }
        dp[i] = u;
    }
    return dp[x];
}
    

int main (void)
{
    int sum;
    cin >> sum;
    
    vector<int> dp (sum+1, 0);
    vector<int> coins {1, 3, 4};
    
    cout << coin_change(sum, dp, coins);
    return 0;
}
