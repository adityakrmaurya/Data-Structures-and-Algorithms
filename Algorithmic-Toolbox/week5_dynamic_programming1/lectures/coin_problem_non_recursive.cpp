#include <iostream>
#include <vector>

using namespace std;
int coin_change(int x, vector<int>& dp, vector<int>& coins)
{
    dp[0] = 0;
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
int main(void)
{
    int no_denominations, sum;
    vector<int> coins;
    cin >> no_denominations >> sum;
    vector<int> coins_required(sum+1, 0);
    for(int i = 0, a; i < no_denominations; i++){
        cin >> a;
        coins.push_back(a);
    }
    cout << coin_change(sum, coins_required, coins);
    return 0;
}
