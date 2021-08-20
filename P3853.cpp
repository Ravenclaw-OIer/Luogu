// Problem: P3853 [TJOI2007]路标设置
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3853
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
const int N = 100010;
int a[N], l, n, k;
bool check(int x) {
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] - a[i - 1] >= x) {
      cnt += (a[i] - a[i - 1]) / x;
      if ((a[i] - a[i - 1]) % x == 0) cnt--;
    }
  }
  return cnt <= k;
}
int main() {
  rd(l); rd(n); rd(k);
  repn(i, n) rd(a[i]);
  int L = 1, R = l, ans = -1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(mid)) {
      ans = mid;
      R = mid - 1;
    } else L = mid + 1;
  }
  printf("%d\n", ans);
}
