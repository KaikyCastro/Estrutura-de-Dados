import queue

class Graph:

    def __init__(self, n):
        self.num_vertices = n
        self.M = [[0 for _ in range(n)] for _ in range(n)]  # Matriz de adjacência
        self.L = [[] for _ in range(n)]                     # Lista de adjacência

    def add_edge(self, u, v):  # Adiciona uma aresta entre u e v (grafo não direcionado)

        self.M[u][v] = 1
        self.M[v][u] = 1
        self.L[u].append(v)
        self.L[v].append(u)

    def print_graph(self):
        print("Número de Vértices:", self.num_vertices)
        print("Matriz de Adjacência:")
        for row in self.M:
            print(row)
        print("Lista de Adjacência:")
        for i, adj in enumerate(self.L):
            print(f"{i}: {adj}")

    def num_comp(self):  # Número de componentes conexos
        visitados = [False] * self.num_vertices
        num = 0

        for v in range(self.num_vertices):
            if not visitados[v]:

                # Faz uma DFS a partir de v
                stack = [v]
                visitados[v] = True

                while stack:
                    u = stack.pop()
                    for w in self.L[u]:
                        if not visitados[w]:
                            stack.append(w)
                            visitados[w] = True
                num += 1
        return num

    def bfs(self, source):  # Busca em largura, retorna distâncias e predecessores
        visitados = [False] * self.num_vertices
        pred = [-1] * self.num_vertices
        D = [-1] * self.num_vertices
        Q = queue.Queue()
        Q.put(source)
        visitados[source] = True
        D[source] = 0

        while not Q.empty():
            v = Q.get()
            for u in self.L[v]:
                if not visitados[u]:
                    Q.put(u)
                    visitados[u] = True
                    D[u] = D[v] + 1
                    pred[u] = v

        return D, pred

    def print_path_bfs(self, s, t):  # Imprime o caminho entre s e t usando BFS
        D, pred = self.bfs(s)

        if D[t] == -1:
            print(f"Não há caminho entre {s} e {t}.")
            return

        path = []
        current = t
        while current != -1:
            path.append(current)
            current = pred[current]

        path.reverse()
        print(f"Caminho de {s} para {t}: {' -> '.join(map(str, path))}")

    def dfs_iterative(self, start):  # DFS usando pilha (sem recursão), retorna predecessores
        visitados = [False] * self.num_vertices
        pred = [-1] * self.num_vertices
        stack = [start]
        visitados[start] = True

        while stack:
            v = stack.pop()
            for u in reversed(self.L[v]):  # reversed para manter ordem correta
                if not visitados[u]:
                    stack.append(u)
                    visitados[u] = True
                    pred[u] = v

        return pred
