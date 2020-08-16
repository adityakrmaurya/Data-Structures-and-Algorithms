#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::make_pair;
using std::pair;
using std::swap;
using std::vector;

template <typename T> void exch(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

class HeapBuilder {
private:
  int data[1000000];
  int n;
  vector<pair<int, int>> swaps_;

  void fixdown(int pq[], int k, int size) {
    while (2 * k <= size) {
      int j = 2 * k;
      if (j < size && pq[j] > pq[j + 1]) {
        j++;
      }
      if (pq[j] >= pq[k]) {
        break;
      }
      swaps_.push_back(make_pair(k - 1, j - 1));
      exch(pq[j], pq[k]);
      k = j;
    }
  }

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (unsigned long long i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> data[i];
  }

  void GenerateSwaps() {
    swaps_.clear();
    int *pq = data - 1;
    for (int i = n / 2; i >= 1; i--) {
      fixdown(pq, i, n);
    }
  }

public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
