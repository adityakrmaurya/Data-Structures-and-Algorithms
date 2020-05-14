#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned long long ull;

using namespace std;

bool sort_by_second(pair<ull, ull>& a, pair<ull, ull>& b)
{
    return a.second < b.second;
}


int main (void)
{
    int t;
    cin >> t;
    vector<pair<ull, ull>> v;
    while(t--){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), sort_by_second);
    vector<int> ans;
    size_t i = 0, count = 0;
    while(i < v.size()){
        size_t j = i + 1;
        ans.push_back(v[i].second);
        count++;
        while(j < v.size() && (v[i].second <= v[j].second && v[i].second >= v[j].first)){
            j++;
        }
        i = j;
    }
    cout << count << "\n";
    for(i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}
