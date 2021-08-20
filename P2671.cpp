// Problem: P2671 [NOIP2015 普及组] 求和
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2671
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
const int N = 100010, mod = 10007;
LL n, m, a[N], c[N];
vector<int> odd[N], even[N];

int main() {
  rd(n);
  rd(m);
  repn(i, n) rd(a[i]);
  repn(i, n) {
    rd(c[i]);
    if (i % 2 == 1)
      odd[c[i]].push_back(i);
    else
      even[c[i]].push_back(i);
  }
  LL ans = 0;
  repn(i, m) {
    if (odd[i].size() < 2) continue;
    LL x1 = 0, x2 = 0;
    rep(j, odd[i].size()) {
      x1 = (x1 + a[odd[i][j]]) % mod;
      x2 = (x2 + odd[i][j]) % mod;
 //     cerr << a[odd[i][j]] << ' ' << odd[i][j] << endl;
    }
 //   cerr << x1 << ' ' << x2 << endl;
    ans = (ans + x1 * x2 % mod) % mod;
    rep(j, odd[i].size()) {
      ans = (ans + ((odd[i].size() - 2) % mod * a[odd[i][j]] % mod * odd[i][j] %
                    mod)) %
            mod;
    }
  }
  repn(i, m) {
    if (even[i].size() < 2) continue;
    LL x1 = 0, x2 = 0;
    rep(j, even[i].size()) {
      x1 = (x1 + a[even[i][j]]) % mod;
      x2 = (x2 + even[i][j]) % mod;
    }
    ans = (ans + x1 * x2 % mod) % mod;
    rep(j, even[i].size()) {
      ans = (ans + ((even[i].size() - 2) % mod * a[even[i][j]] % mod *
                    even[i][j] % mod)) %
            mod;
    }
  }
  printf("%lld\n", ans);
}
