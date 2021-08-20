// Problem: P1102 A-B 数对
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1102
// Written by RavenclawOIer on 08-15-2021

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */


#include <bits/stdc++.h>
#define int long long
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
int n, c;
const int N = 200020;
int a[N];
signed main() {
  rd(n); rd(c);
  rep(i, n) rd(a[i]);
  sort(a, a + n);
  int ans = 0;
  rep(i, n) {
    ans += upper_bound(a, a + n, a[i] + c) - lower_bound(a, a + n, a[i] + c);
  }
  cout << ans << endl;
}
