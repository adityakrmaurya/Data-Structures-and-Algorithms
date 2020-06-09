#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;
ll max_gold(int W, vector<int>& weights, vector<int> values)
{
    // n : no. of weights
    int n = weights.size();
    vector<vector<ll>> dp (n+1, vector<ll>(W+1, 0));
    for(int i = 1; i < n+1; i++){
        for(int w = 1; w < W+1; w++){
            dp[i][w] = dp[i-1][w]; // if ith weight is not in optimal solution
            if(weights[i-1] <= w){
                ll value = dp[i-1][w-weights[i-1]] + values[i-1]; // if ith weight is in optimal solution
                if(value > dp[i][w]){
                    dp[i][w] = value;
                }
            }
        }
    }
    return dp[n][W];
}
int main(void)
{
    int W, n;
    cin >> W >> n;
    vector<int> weights, values;
    for(int i = 0, a; i < n; i++){
        cin >> a;
        values.push_back(a);
        weights.push_back(a);
    }
    cout << max_gold(W, weights, values);
    return 0;
}
