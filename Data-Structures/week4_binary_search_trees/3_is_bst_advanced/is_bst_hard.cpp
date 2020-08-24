#include <algorithm>
#include <iostream>
#include <vector>
typedef long long int ll;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

ll prev = -1e18;
bool flag = true;
int nodes;
vector<ll> key;
vector<int> left;
vector<int> right;


void in_order(int ind) {
  if (ind == -1 || !flag) {
    return;
  }
  in_order(left[ind]);
  if (prev > key[ind]) {
    flag = false;
    return;
  }
  /**
   * The node right to inorder pedecessor but left to its parent
   * https://www.coursera.org/learn/data-structures/discussions/weeks/6/
   * threads/QyTVc_BhEeamuwo9wEiniA/replies/AwZ3sbZ-EeiTjBLDL4RcNA
   **/
  else if(prev == key[ind]) {
    if (left[ind] != -1 && key[left[ind]] == prev) {
      flag = false;
      return;
    }
  }
  prev = key[ind];
  in_order(right[ind]);
}

int main() {
  cin >> nodes;
  for (int i = 0, l, r; i < nodes; ++i) {
    ll k;
    cin >> k >> l >> r;
    key.push_back(k);
    left.push_back(l);
    right.push_back(r);
  }
  if(nodes)
    in_order(0);
  if (flag)
    cout << "CORRECT";
  else
    cout << "INCORRECT";

  return 0;
}
