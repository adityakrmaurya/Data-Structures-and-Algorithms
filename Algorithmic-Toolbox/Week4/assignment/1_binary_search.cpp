#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int binary_search(vector<int>& an, int low, int high,int value)
{
    while(low <= high){
        int mid = floor(low + ((high - low) / 2));
        if(an[mid] == value){
            return mid;
        }
        else if(an[mid] < value){
            low = mid+1;
        }
        else 
            high = mid - 1;        
    }
    return -1;
}

int main (void)
{   
    int n, k;
    cin >> n;
    vector<int> an;
    
    for(int i = 0, a; i < n; i++){
        cin >> a;
        an.push_back(a);
    }
    
    sort(an.begin(), an.end());
    
    cin >> k;
    
    for(int i = 0, b; i < k; i++){
        cin >> b;
        cout << binary_search(an, 0, n-1, b) << " ";
    }
    return 0;
}
