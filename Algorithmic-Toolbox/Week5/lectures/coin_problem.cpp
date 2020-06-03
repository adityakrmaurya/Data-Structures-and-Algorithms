/*
 * Change Problem
 * Input:
 *  An integer money and positive integers coin1, coin2,...., coinN
 * 
 * Output:
 *  The minimum number of coins with denominations coin1,...coinN that 
 *  changes the money
 *
 */


#include <iostream>
#include <vector>

using namespace std;

int f(int x, vector<int>& c, vector<int>& coins_required)
{
    
    if(x < 0) return 1e9;
    if(x == 0) return 0;
    if(coins_required[x] != 0) return coins_required[x];
    int u = 1e9, k = c.size();
    for (int i = 0; i < k; i++){
        u = min(u, f(x-c[i], c, coins_required)+1);
    }
    coins_required[x] = u;
    return coins_required[x];
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
    cout << f(sum, coins, coins_required);
    return 0;
}
