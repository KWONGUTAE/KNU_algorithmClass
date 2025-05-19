#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid(int v, int pos, int *path, int **graph, int n) {
  if (graph[path[pos-1]][v] == 0) 
      return 0;
  
  for (int i = 0; i < pos; i++)
      if (path[i] == v)
          return 0;
  
  return 1;
}

int hamiltonian_util(int **graph, int *path, int pos, int n, int count) {
  if (pos == n) {
      if (graph[path[pos-1]][path[0]] == 1)
          return count + 1;
      return count;
  }
  

  for (int v = 0; v < n; v++) {
      if (is_valid(v, pos, path, graph, n)) {
          path[pos] = v;
          count = hamiltonian_util(graph, path, pos + 1, n, count);
          path[pos] = -1;  
      }
  }
  
  return count;
}

int hamiltonian_circuit(int n, int m, int **edges) {
  int **graph = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
      graph[i] = (int *)calloc(n, sizeof(int));
  }
  
  for (int i = 0; i < m; i++) {
      int u = edges[i][0] - 1;  
      int v = edges[i][1] - 1;
      graph[u][v] = 1;
      graph[v][u] = 1;  
  }
  
  int *path = (int *)malloc(n * sizeof(int));
  memset(path, -1, n * sizeof(int));
  path[0] = 0; 
  
  int count = hamiltonian_util(graph, path, 1, n, 0);
  
  for (int i = 0; i < n; i++)
      free(graph[i]);
  free(graph);
  free(path);
  
  return count;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  
  int **edges = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
      edges[i] = (int *)malloc(2 * sizeof(int));
      scanf("%d %d", &edges[i][0], &edges[i][1]);
  }
  
  printf("%d\n", hamiltonian_circuit(n, m, edges));
  
  for (int i = 0; i < m; i++)
      free(edges[i]);
  free(edges);
  
  return 0;
}