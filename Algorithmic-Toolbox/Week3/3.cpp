#include <iostream>
#include <vector>
using namespace std;

int MinRefills(vector<int> &x, int n, int m) {
  int min_refils = 0;
  int current_refil = 0;
  while (current_refil < n - 1) {
    int last_refil = current_refil;
    while (current_refil < n - 1 &&
           (x[current_refil + 1] - x[last_refil] <= m)) {
      current_refil++;
      // cout << current_refil << "\n";
    }
    // cout << "Filling Tank at : " << x[current_refil];
    if (current_refil < n - 1)
      min_refils++;
    if (current_refil == last_refil)
      return -1;
  }
  return min_refils;
}

int main(void) {
  int d; // Total distance
  int m; // max distance traveled on full tank
  int n; // No of gas station
  cin >> d >> m >> n;
  vector<int> x;
  x.push_back(0);
  for (int i = 0, a; i < n; i++) {
    cin >> a;
    x.push_back(a);
  }
  x.push_back(d);
  n = x.size();
  cout << MinRefills(x, n, m);
  return 0;
}
/*
 * Lemma: The Running time of MinRefills(x, n, m) is O(n)
 *
 * Proof:
 *       > current_refil changes from index 0 to n-1, one-by-one
 *       > min_refils can change from index 0 to at most n-2(no. of gas
 *         stations), one-by-one
 *
 *      Thus, O(n) iterations
 */