#include <iostream>
typedef unsigned long long ull;
using namespace std;

int pisano_period_10_array[60];
int pisano_period_10_array_sum = 280;

void create_pisano_period_10_array()
{
    pisano_period_10_array[0] = 0;
    pisano_period_10_array[1] = 1;
    for(int i = 2; i < 60; i++){
        pisano_period_10_array[i] = (pisano_period_10_array[i-1] + pisano_period_10_array[i-2]) % 10;
    }
}
int main(void)
{
    ull n; cin >> n;
    int pisano_period_10 = 60;
    create_pisano_period_10_array();
    int left = n % pisano_period_10;
    // cout << "left " << left;
    ull sum = (pisano_period_10_array_sum * (n / pisano_period_10)) % 10;
    // cout << "sum " << sum;
    for(int i = 0; i < left+1; i++){
        sum += pisano_period_10_array[i];
        sum = sum % 10;
    }
    cout << sum;
    return 0;
}
