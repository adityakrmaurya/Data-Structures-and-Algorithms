#include <iostream>
using namespace std;
typedef unsigned long long ull;
int function_pisano_period(ull m)
{
    int pisano_period = 2;
    int temp, previous = 0, current = 1;
    for(int i = 2; ; i++){
        pisano_period++;
        temp = current;
        current = (previous + current) % m;
        previous = temp;
        if(previous == 0 && current == 1){
            pisano_period -= 2; // subtraction of current and previous count
            break;
        }
    }
    return pisano_period;
}
int main(void)
{
    ull n;
    ull m;
    cin >> n >> m;
    if(n <= m){
        start:
        int temp, previous = 0, current = 1;
        if(n == 0){ cout << 0; return 0;}
        else if(n == 1){ cout << 1; return 0;}
        for(ull i = 2; i < n+1; i++){
            temp = current;
            current = ((previous) + (current)) % m;
            previous = temp;
        }
        cout << current;
    }
    else{
        int pisano_period = function_pisano_period(m);
        // cout << pisano_period << endl;
        n = n % pisano_period;
        goto start;
    }
    return 0;
}
