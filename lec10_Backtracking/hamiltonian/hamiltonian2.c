#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int n, m;
int vindex[MAX];
int edge[MAX][MAX];
int count = 0;

int promising(int i) {
  if (i == n - 1 && !edge[vindex[n - 1]][vindex[0]]) {
    return 0;
  } else if (i > 0 && !edge[vindex[i - 1]][vindex[i]]) {
    return 0;
  } else {
    for (int j = 0; j < i; j++) {
      if (vindex[j] == vindex[i]) {
        return 0;
      }
    }
  }
  return 1;
}

void hamiltonian(int i) {
  if (promising(i)) {
    if (i == n - 1) {
      count++;
      return;
    } else {
      for (int j = 2; j <= n; j++) {
        vindex[i + 1] = j;
        hamiltonian(i + 1);
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  memset(vindex, 0, sizeof(vindex));
  memset(edge, 0, sizeof(edge));

  int u, v; 
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &u, &v);
    edge[u][v] = edge[v][u] = 1;
  }

  vindex[0] = 1;
  hamiltonian(0);
  
  printf("%d\n", count);

  return 0;
}



