#include <iostream>

using namespace std;
int min_coins(int m)
{
    int one = 0, five = 0, ten = 0;
    
    if(m >= 10){
        ten = m / 10;
        m = m % 10;
    }
    if(m >= 5){
        five = m / 5;
        m = m % 5;
    }
    one = m / 1;
    
    return ten+five+one;
}
int main(void)
{
    int m;
    cin >> m;
    cout << min_coins(m);
    return 0;
}
