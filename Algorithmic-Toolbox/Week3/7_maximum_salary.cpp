#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool max_sal(string& ans, string& a)
{
    return (ans+a > a+ans);
}
int main(void)
{
    int t;
    cin >> t;
    vector<string> ans;
    while(t--){
        string a;
        cin >> a;
        ans.push_back(a);
    }
    sort(ans.begin(), ans.end(), max_sal);
    for(auto a : ans){
        cout << a;
    }
    return 0;
}
