#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int n, m;
int edge[MAX][MAX];
int count = 0;
int min_color = MAX;
int vcolor[MAX];

int promising(int i) {
  int j = 1;
  while (j < i) {
    if (edge[i][j] && (vcolor[i] == vcolor[j])) {
      return 0;
    }
    j++;
  }
  return 1;
}

void m_coloring(int i) {
  if (i == n) {
    int max_used = 0;
    for (int k = 1; k <= n; k++) {
      if (vcolor[k] > max_used) {
        max_used = vcolor[k];
      }
    }

    if (max_used < min_color) {
      min_color = max_used;
      count = 1;
    } else if (max_used == min_color) {
      count++;
    }
    return;
  }

  for (int color = 1; color <= n; color++) {
    vcolor[i] = color;
    if(promising(i)) {
      m_coloring(i + 1);
    }
    vcolor[i] = 0;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  memset(vcolor, 0, sizeof(vcolor));
  memset(edge, 0, sizeof(edge));
  int u, v;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &u, &v);
    edge[u][v] = edge[v][u] = 1;
  }

  m_coloring(0);

  printf("%d\n%d\n", min_color, count);
  return 0;
}
