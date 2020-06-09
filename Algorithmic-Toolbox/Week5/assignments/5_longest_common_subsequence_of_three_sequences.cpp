#include <iostream>
#include <vector>

using namespace std;

int lcs(vector<int>& u, vector<int>& v, vector<int>& w)
{
    int dp[u.size()+1][v.size()+1][w.size()+1] = {};
    
    for(size_t i = 0; i <= u.size(); i++){
        for(size_t j = 0 ; j <= v.size(); j++){
            for(size_t k = 0; k <= w.size(); k++){
                
                if(i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else if((u[i-1] == v[j - 1]) && v[j-1] == w[k-1] && w[k-1] == u[i-1]){
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                }
                else
                    dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
            }
        }
    }
    return dp[u.size()][v.size()][w.size()];
}

int main(void)
{
    int a, b, c;
    cin >> a;
    vector<int> u, v, w;
    for(int i = 0, t; i < a; i++){
        cin >> t;
        u.push_back(t);
    }
    cin >> b;
    for(int i = 0, t; i < b; i++){
        cin >> t;
        v.push_back(t);
    }
    cin >> c;
    for(int i = 0, t; i < c; i++){
        cin >> t;
        w.push_back(t);
    } 
    cout << lcs(u, v, w);
    return 0;
}
