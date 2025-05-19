#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int n, m;
int line[MAX][MAX];        // 인접 행렬
int vcolor[MAX];           // 각 정점의 색
int min_color = MAX;
int count = 0;

int promising(int i) {
  int j = 1;

  while (j < i && flag) {
    if (line[i][j] && (vcolor[i] == vcolor[j])) {
      return 0; // false
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

    if (max_used < min_color) { // i > n 이니까 모든 vertex를 칠했고, 만약 더 적은 컬러를 사용했으면 
      min_color = max_used; // min_color를 갱신하고, 
      count = 1; // 해당 케이스의 count는 새로 시작해야 함.
    } else if (max_used == min_color) { // 그게 아니라 사용된 색이 같다면 
      count++; // 그냥 count 수만 증가.
    }
    return;
  }

  for (int color = 1; color <= n; color++) {
    vcolor[i] = color;
    if (promising(i)) {
      m_coloring(i + 1);
    }
    vcolor[i] = 0; // 백트래킹
  }
}


int main() {
  scanf("%d %d", &n, &m);
  int u, v;
  memset(line, 0, sizeof(line));
  memset(vcolor, 0, sizeof(vcolor));
  
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &u, &v);
    line[u][v] = 1;
    line[v][u] = 1;
  }
  m_coloring(1);

  printf("%d\n%d\n", min_color, count);

  return 0;
}




