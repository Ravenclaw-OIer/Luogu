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
int a[505], b[505], t[1505];
void f() {
  memset(t, 0, sizeof(t));
  repn(i, 500) repn(j, 500) t[i + j - 1] += a[i] * b[j];
  repn(i, 500) { 
    t[i + 1] += t[i] / 10;
    t[i] %= 10;
  }
  memcpy(a, t, sizeof(a));
}
void g() {
  memset(t, 0, sizeof(t));
  repn(i, 500) repn(j, 500) t[i + j - 1] += b[i] * b[j];
  repn(i, 500) { 
    t[i + 1] += t[i] / 10;
    t[i] %= 10;
  }
  memcpy(b, t, sizeof(b));
}
int main() {
  int p;
  rd(p);
  printf("%d\n", (int)(p * log10(2) + 1));
  a[1] = 1; b[1] = 2;
  for (; p; p >>= 1) {
    if (p & 1) f(); 
    g();
  }
  a[1]--;
  for (int i = 500; i; i--) {
    if (i != 500 && i % 50 == 0) puts("");
    printf("%d", a[i]);
  }
}
