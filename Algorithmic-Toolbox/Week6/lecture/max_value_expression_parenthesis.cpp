#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_oper(char op) {
  return (op == '+' || op == '-' || op == '/' || op == '*');
}

int evaluate(int val1, char oper, int val2) {
  if (oper == '+')
    return (val1 + val2);
  else if (oper == '-')
    return (val1 - val2);
  else if (oper == '/')
    return (val1 / val2);
  else if (oper == '*')
    return (val1 * val2);

  return -1e9;
}

pair<int, int> min_and_max(int i, int j, string &s, vector<vector<int>> &M,
                           vector<vector<int>> &m) {
  int minimum = 1e9, maximum = -1e9;
  for (int k = i; k < j; k++) {
    if (is_oper(s[2 * k + 1])) {
      int a = evaluate((M[i][k]), s[2 * k + 1], M[k + 1][j]);
      int b = evaluate((M[i][k]), s[2 * k + 1], m[k + 1][j]);
      int c = evaluate((m[i][k]), s[2 * k + 1], m[k + 1][j]);
      int d = evaluate((m[i][k]), s[2 * k + 1], M[k + 1][j]);
      minimum = min(minimum, min(d, min(c, min(a, b))));
      maximum = max(maximum, max(d, max(c, max(a, b))));
    }
  }
  pair<int, int> Pair(minimum, maximum);
  return Pair;
}

int parenthesis(string &str) {
  int n = (str.length() + 1) / 2;

  vector<vector<int>> M(n, vector<int>(n, 0));
  vector<vector<int>> m(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    m[i][i] = stoi(str.substr(2 * i, 1));
    M[i][i] = stoi(str.substr(2 * i, 1));
  }

  for (int s = 0; s < n - 1; s++) {
    for (int i = 0; i < n - s - 1; i++) {
      int j = i + s + 1;
      pair<int, int> p = min_and_max(i, j, str, M, m);
      m[i][j] = p.first;
      M[i][j] = p.second;
    }
  }
  return M[0][n - 1];
}

int main(void) {
  string s;
  cin >> s;
  cout << parenthesis(s);
  return 0;
}
