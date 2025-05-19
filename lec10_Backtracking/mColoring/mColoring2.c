#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int n, m;
int line[MAX][MAX];
int vcolor[MAX];
int min_color = MAX;
int count = 0;

int promising(int i) {
  int j = 1;
  
  while (j < i)
  {
     // i노드에 연결된 다른 노드가 존재하면서, 
     // i번째 노트에 칠해진 색상과 j번째 노드에 칠해진 색상이 동일하다면
     // non_promising
    if (line[i][j] && (vcolor[i] == vcolor[j])) {
      return 0;
    }
    j++;
  }
  return 1;
}

void m_coloring(int i) {
  // 이번에 방문한 노드가 마지막 노드라면.
  if (i == n) {
    int max_used = 0;
    for (int k = 1; k <= n; k++) {
      if(max_used < vcolor[k]) {
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
    if (promising(i)) {
      m_coloring(i + 1);
    }
    vcolor[i] = 0;
  }
  
}


int main() {
  scanf("%d %d", &n, &m);
  int u, v;

  memset(vcolor, 0, sizeof(vcolor));
  memset(line, 0, sizeof(line));

  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &u, &v);
    line[u][v] = line[v][u] = 1;
  }

  m_coloring(1);

  printf("%d\n%d\n", min_color, count);

  return 0;

}