// Problem: P3406 海底高铁
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3406
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
int n, m;
const int N = 100010;
LL p[N], d[N], t[N];
int main() {
  rd(n); rd(m);
  repn(i, m) rd(p[i]);
  repn(i, m - 1) {
    int x = p[i], y = p[i + 1];
    if (x > y) swap(x, y);
    d[x]++;
    d[y]--;
  }
  repn(i, n - 1) t[i] = t[i - 1] + d[i];
 // repn(i, n - 1) cerr << t[i] << ' '; cerr << endl;
  LL ans = 0;
  repn(i, n - 1) {
    int a, b, c;
    rd(a); rd(b); rd(c);
    ans += min(a * t[i], b * t[i] +  c);
  }
  printf("%lld\n", ans);
}
