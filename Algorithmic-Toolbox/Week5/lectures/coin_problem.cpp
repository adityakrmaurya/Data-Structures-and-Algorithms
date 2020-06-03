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

int f(int x, vector<int>& c)
{
    
    if(x < 0) return 1e9;
    if(x == 0) return 0;
    int u = 1e9, k = c.size();
    for (int i = 0; i < k; i++){
        u = min(u, f(x-c[i], c)+1);
    }
    return u;
}
int main(void)
{
    vector<int> coins = {1, 3, 4};
    int sum = 6;
    cout << f(sum, coins);
    
    return 0;
}
