#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::cin;
using std::cout;
using std::ios_base;
using std::vector;

class TreeOrders {
  int n;
  vector<int> key;
  vector<int> left;
  vector<int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  void in_order(int ind) {
    if (ind == -1) {
      return;
    }
    in_order(left[ind]);
    cout << key[ind] << " ";
    in_order(right[ind]);
  }
  void pre_order(int ind) {
    if (ind == -1) {
      return;
    }
    cout << key[ind] << " ";
    pre_order(left[ind]);
    pre_order(right[ind]);
  }
  void post_order(int ind) {
    if (ind == -1) {
      return;
    }
    post_order(left[ind]);
    post_order(right[ind]);
    cout << key[ind] << " ";
  }
};

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  t.in_order(0);

  cout << std::endl;
  t.pre_order(0);

  cout << std::endl;
  t.post_order(0);
  cout << std::endl;
  return 0;
}

int main(int argc, char **argv) {
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024; // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0) {
    if (rl.rlim_cur < kStackSize) {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0) {
        std::cerr << "setrlimit returned result = " << result << std::endl;
      }
    }
  }
#endif

  return main_with_large_stack_space();
}
