// Problem: P1208 [USACO1.3]混合牛奶 Mixing Milk
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1208
// Written by RavenclawOIer on 08-27-2021

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
int m, n;
pii a[2100010];
int main() {
  rd(m);
  rd(n);
  rep(i, n) {
    rd(a[i].first);
    rd(a[i].second);
  }
  sort(a, a + n);
  LL ans = 0;
  rep(i, n) {
    //  eprintf("%d %d %d\n", a[i].first, a[i].second, m);
    if (m >= a[i].second) {
      m -= a[i].second;
      ans += 1LL * a[i].first * a[i].second;
    } else {
      ans += 1LL * a[i].first * m;
      break;
    }
  }
  printf("%lld\n", ans);
}
