#include <iostream>
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
        return gcd(b, a%b);
    }
}
int main(void)
{
    ull a, b;
    cin >> a >> b;
    cout << (a * b) / gcd(a , b);
    return 0;
}
