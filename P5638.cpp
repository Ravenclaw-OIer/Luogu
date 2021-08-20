// Problem: P5638 【CSGRound2】光骓者的荣耀
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5638
// Written by RavenclawOIer on 08-20-2021

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
const int N = 1000100;
LL a[N], n, k, pre[N], suf[N];
int main() {
  rd(n);
  rd(k);
  repn(i, n - 1) rd(a[i]);
  repn(i, n - 1) pre[i] = pre[i - 1] + a[i];
  for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];
  //repn(i, n) eprintf("%lld ", suf[i]); eprintf("\n");
  LL ans = 1e18;
  repn(i, n) {
 //   cerr << i - 1 << ' ' << i + k << endl;
    chmin(ans, pre[i - 1] + suf[min(n, i + k)]);
  //  cerr << ans << endl;
  }
  printf("%lld\n", ans);
}
