#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> v;
    
    int sum = 0, i = 1;
    while(sum < n){
        if(sum + i > n){
            *(v.end() - 1) += n - sum;
            break; 
        }
        sum += i;
        v.push_back(i);
        i++;
    }
    cout << v.size() << endl;
    for(size_t j = 0; j < v.size(); j++){
        cout << v[j] << " ";
    }
    
    
    return 0;
}
