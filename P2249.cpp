// Problem: P2249 【深基13.例1】查找
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2249
// Written by RavenclawOIer on 08-15-2021

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
int a[N];
int main() {
  int n, q;
  rd(n); rd(q);
  repn(i, n) rd(a[i]);
  rep(i, q) {
    int x;
    rd(x);
    int L = 1, R = n, ans = -1;
    while (L <= R) {
      int mid = (L + R) >> 1;
      if (a[mid] >= x) {
        ans = mid;
        R = mid - 1;
      } else L = mid + 1;
    }
    if (a[ans] != x) ans = -1;
    printf("%d ", ans);
  }
  
}
