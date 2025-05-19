#include <stdio.h>
#include <stdbool.h>

#define MAX 20
#define MAX_CASE 1000000

int w[MAX + 1];
int n, W;
int count = 0;
int include[MAX + 1]; 
int correct[MAX_CASE][MAX + 1]; 

bool promising(int i, int weight, int total) {
  return (weight + total >= W) && (weight == W || (i + 1 <= n && weight + w[i + 1] <= W));
}

void sum_of_subset(int i, int weight, int total) {
  if (promising(i, weight, total)) {
    if (weight == W) {
      for (int k = 1; k <= n; k++) {
        correct[count][k] = include[k];
      }
      count++;
      return;
    }
    if (i + 1 <= n) {
      include[i + 1] = 1;
      sum_of_subset(i + 1, weight + w[i + 1], total - w[i + 1]);
      include[i + 1] = 0;
      sum_of_subset(i + 1, weight, total - w[i + 1]);
    }
  }
}

int main() {
  scanf("%d %d", &n, &W);
  if (n < 0 || n > MAX || W < 0) {
    printf("0\n");
    return 0;
  }

  int total = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    total += w[i];
  }

  for (int i = 0; i <= n; i++) {
    include[i] = 0;
  }
  sum_of_subset(0, 0, total);

  printf("%d\n", count);

  for (int i = 0; i < count; i++) {
    int first = 1; 
    for (int j = 1; j <= n; j++) {
      if (correct[i][j]) {
        if (first) {
          printf("%d", w[j]);
          first = 0;
        } else {
          printf(" %d", w[j]);
        }
      }
    }
    printf("\n");
  }

  return 0;
}