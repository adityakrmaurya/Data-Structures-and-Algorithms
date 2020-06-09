#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool partitioning_souvenirs(int a)
{
    
    
    
    
    
    return 1;
}

int main(void)
{
    int t;
    cin >> t;
    vector<int> v;
    int sum = 0;
    for(int i = 0, a; i < t; i++){
        cin >> a;
        v.push_back(a);
        sum += a;
    }
    sort(v.begin(), v.end());
    for(auto a : v){
        cout << a << " ";
    }
    return 0;
}
    
