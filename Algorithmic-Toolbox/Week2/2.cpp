#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

int last_digit(ull n)
{
    if(n == 0){return 0;}
    if(n == 1){return 1;}
    else{
        int a, b, c;
        a = 0;
        b = 1;
        for(ull i = 2; i < n + 1; i++){
            c = b;
            b = (a + b) % 10; 
            a = c;
        }
        return b;
    }
}
int main(void)
{
    ull n;
    cin >> n;
    cout << last_digit(n);
    return 0;
}
