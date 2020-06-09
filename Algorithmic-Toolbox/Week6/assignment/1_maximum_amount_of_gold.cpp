#include <iostream>
#include <vector>

using namespace std;
int max_gold(int W, vector<int>& w)
{
    
    return int {};
}
int main(void)
{
    int w, n;
    cin >> w >> n;
    vector<int> v;
    for(int i = 0, a; i < n; i++){
        cin >> a;
        v.push_back(a);
    }
    cout << max_gold(w, v);
    return 0;
}
