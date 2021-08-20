// Problem: P2678 [NOIP2015 提高组] 跳石头
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2678
// Written by RavenclawOIer on 08-17-2021

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */


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
const int INF = 0x3f3f3f3f;
ttt inline T rd(T& x) {
  x = 0;
  T neg = 1;
  char c = 0;
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
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
int l, n, m;
const int N = 50050;
int a[N];
bool check(int d) {
// cerr << "Checking for " << d << endl;
  int cnt = 0;
  for (int i = 1, pos = 0; i <= n + 1; i++) {
    //cerr << pos << ' ' << i << ' ' << a[i + 1] - pos << endl;
    if (a[i] - pos < d) {
      cnt++;
   //   cerr << i + 1 << " removed" << endl;
    } else pos = a[i];
  }
//  cerr << cnt << endl;
  return cnt <= m;
}
int main() {
  rd(l); rd(n); rd(m);
  repn(i, n) rd(a[i]);
  a[n + 1] = l;
  int L = 0, R = l, ans = -1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(mid)) {
      L = mid + 1;
      ans = mid;
    } else R = mid - 1;
  }

  printf("%d\n", ans);
}
