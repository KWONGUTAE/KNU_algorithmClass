#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 15  // N <= 14 정도로 제한, 더 크면 동적 할당 필요

int col[MAX + 1];
long long max = 0;
int count = 0;

void solve(int row, int N) {
  if (row == N + 1) {
    count++;
    long long num = 0;
    for (int i = 1; i <= N; i++) {
      if (col[i] >= 10) {
        num = num * 100 + col[i];
      } else {
        num = num * 10 + col[i];
      }
    }
    if (num > max) max = num;
    return;
  }

  for (int i = 1; i <= N; i++) {
    int ok = 1;
    for (int j = 1; j < row; j++) {
      if (col[j] == i || abs(col[j] - i) == abs(j - row)) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      col[row] = i;
      solve(row + 1, N);
    }
  }
}

int main() {
  int N;
  scanf("%d", &N);
  solve(1, N);
  printf("%d\n", count);
  printf("%lld\n", max);
  return 0;
}

