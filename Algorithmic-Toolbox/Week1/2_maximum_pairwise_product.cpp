#include <iostream>
#include <vector>
#include <algorithm>
typedef unsigned long long ull;
using namespace std;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    sort(begin(numbers), end(numbers), greater<int>());
    cout << (((ull)numbers[0])*numbers[1]);
    return 0;
}
