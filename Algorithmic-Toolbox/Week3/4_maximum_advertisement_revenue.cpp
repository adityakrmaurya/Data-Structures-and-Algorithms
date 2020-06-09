#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long sum(vector<long long>& a, vector<long long>& b)
{
    long long sum = 0;
    for(size_t i = 0; i < a.size(); i++){
        sum += a[i] * b[i];
    }
    return sum;
}
int main(void)
{
    int n;
    cin >> n;
    vector<long long> a, b;
    for(int i = 0; i < n; i++){
        long long c;
        cin >> c;
        a.push_back(c);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        long long c;
        cin >> c;
        b.push_back(c);
    }
    sort(b.begin(), b.end());
    cout << sum(a, b);
    return 0;
}
    
