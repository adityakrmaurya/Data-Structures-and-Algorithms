#include <iostream>
#include <vector>
using namespace std;
int lcs(vector<int>& u, vector<int>& v)
{
    int dp[u.size()+1][v.size()+1]  {};
    for(size_t i = 0; i <= u.size(); i++){
        for(size_t j = 0; j <= v.size(); j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(u[i-1] == v[j - 1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[u.size()][v.size()];
}
int main (void)
{
    int a, b;
    vector<int> u, v;
    cin >> a;
    for(int i = 0, t; i < a; i++){
        cin >> t;
        u.push_back(t);
    }
    cin >> b;
    for(int i = 0, t; i < b; i++){
        cin >> t;
        v.push_back(t);
    }
    cout << lcs(u, v);
    return 0;
}
