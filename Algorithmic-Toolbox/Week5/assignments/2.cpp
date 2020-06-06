#include <iostream>
#include <vector>
#include <list>

using namespace std;
void primitive_cal(int x)
{
    vector<int> dp (x+1, 0);
    vector<int> previous (x+1);

    for(int i = 2; i <= x; i++){
        dp[i] = 1e9;
        for(int j = 1; j <= 3; j++){
            if(j == 1){
                int u = dp[i-1]+1;
                if(u < dp[i]){
                    dp[i] = u;
                    previous[i] = i-1;
                }
            }
            else{
                if(i % j)
                    continue;
                int u = dp[i / j]+1;
                if(u < dp[i]){
                    dp[i] = u;
                    previous[i] = i / j;
                }
            }
        }
    }
    cout << dp[x] << "\n";
    list<int> ans;
    for(int i = x; i > 0; i = previous[i]){
        ans.push_front(i);
    }
    for(auto a : ans)
        cout << a << " ";
}

int main (void)
{
    int x;
    cin >> x;
    primitive_cal(x);
    return 0;
}
