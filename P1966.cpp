/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ttt template <typename T>
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
const int mod = 1e8 - 3;
const int INF = 0x3f3f3f3f;
ttt inline T rd(T &x) {
  x = 0;
  T neg = 1;
  char c = 0;
  while (c < '0' || c > '9') {
    if (c == '-')
      neg = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - 48;
    c = getchar();
  }
  x *= neg;
  return x;
}
// -------- Item Get Border Line! -----------
// Don't forget to use long long if needed!
const int N = 500010;
int a[N], b[N], c[N], d[N], t[N];
int n;
LL ans;
void merge(int L, int R) {
 // eprintf("merge(%d, %d)\n", L, R);
  if (R - L <= 1)
    return;
  int mid = (L + R) >> 1;
  merge(L, mid);
  merge(mid, R);
  int p = L, q = mid;
  for (int i = L; i < R; i++) {
    if (p >= mid || (q < R && c[q] < c[p]) ) {
      t[i] = c[q++];
      ans += mid - p;
      ans %= mod;
    } else {
      t[i] = c[p++];
    }
  }
//  for (int i = L; i < R; i++) cerr << t[i] << ' ';
// cerr << endl;
  for (int i = L; i < R; i++) c[i] = t[i];
}
int id[N], id2[N];
int main() {
  freopen("/home/shushang/Downloads/P1966_2.in", "r", stdin);
  rd(n);
  repn(i, n) rd(a[i]);
  repn(i, n) rd(b[i]);
  repn(i, n) id[i] = id2[i] = i;
  // discrete c
  sort(id + 1, id + n + 1, [](int x, int y) { return a[x] < a[y]; });
  sort(id2 + 1, id2 + n + 1, [](int x, int y) { return b[x] < b[y]; });
  repn(i, n) c[id[i]] = id2[i];
  merge(1, n + 1);
//  repn(i, n) cerr << c[i] << ' '; 
//  cerr << endl;
  cout << ans << endl;
 // repn(i, n) cerr << c[i] << ' ';
 // cerr << endl;
}
