#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>

typedef unsigned long long ull;
using namespace std;

// sort in decending order
bool sort_by_division(pair<int, int> &a, pair<int, int> &b)
{
    return (((double)a.first/a.second) > ((double)b.first/b.second));
}

double value(vector<pair<int, int>>& v, int w)
{
    double val = 0;
    size_t i = 0;
    while(i < v.size()){
        if(w == 0)
            return val;
        int weight_to_put = min(v[i].second, w);
        val += (double)weight_to_put * ((double)v[i].first/(double)v[i].second);
        w -= weight_to_put;
        i += 1;
    }
    return val;
}
int main(void)
{
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> v;
    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), sort_by_division);
    cout << fixed << setprecision(4) << value(v, w);
    return 0;
}
