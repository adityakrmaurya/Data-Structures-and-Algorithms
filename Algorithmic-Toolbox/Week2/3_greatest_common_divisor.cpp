#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
ull gcd(ull a, ull b)
{
    if(a < b){
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    if(b == 0){
        return a;
    }
    else{
        ull temp;
        temp = b;
        b = a % b;
        a = temp;
        return gcd(a, b);
    }
}

int main(void)
{
    ull a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}
