#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;
int main(void) {
  priority_queue<pair<ll, ll>> pq;
  queue<ll> q;
  ll n, m;
  cin >> n >> m;
  for(int i = 0, a; i < m; i++) {
    cin >> a;
    q.push(a);
  }
  pair<ll, ll> p;
  for (int i = 0; i < n; i++) {
    p.first = 0; // time
    p.second = -i; // thread
    pq.push(p);
  }
  while (!q.empty()) {
    p = pq.top();
    cout << -p.second << " " << -p.first << endl; 
    pq.pop();
    ll value = q.front();
    q.pop();
    pq.push(make_pair(-value + p.first, p.second));
  }
}
  
