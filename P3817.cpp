// Problem: P3817 小A的糖果
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3817
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

int main() {
  int n, x;
  rd(n); rd(x);
  vector<int> a(n);
  rep(i, n) rd(a[i]);
  LL ans = 0;
  rep(i, n - 1) {
    if (a[i] + a[i + 1] > x) {
      if (a[i] > x) {
        ans += a[i + 1];
        ans += a[i] - x;
        a[i + 1] = 0;
        a[i] = x;
      } else {
        ans += a[i + 1] + a[i] - x;
        a[i + 1] = x - a[i];
      }
    }
  }
  printf("%lld\n", ans);
}
