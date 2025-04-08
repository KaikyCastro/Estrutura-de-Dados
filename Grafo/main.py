from graph import Graph

def load_from(fileName):

    with open(fileName, 'r') as f:  # Carrega o grafo a partir de um arquivo
        n = int(f.readline())
        g = Graph(n)

        for l in range(n):
            line = f.readline().strip()
            numeros = list(map(int, line.split("\t")))

            for c in range(n):
                g.M[l][c] = numeros[c]
                if numeros[c] != 0:
                    g.L[l].append(c)
        return g

def menu():

    print("MENU" .center(30, '-'))
    print("1 - Imprimir Lista de Adjacência")
    print("2 - Imprimir Matriz de Adjacência")
    print("3 - Testar DFS (Iterativo)")
    print("4 - Imprimir Caminho entre Vértices (BFS)")
    print("5 - Sair")
    return input("Escolha uma opção: ")

if __name__ == "__main__":

    # Carrega o grafo

    try:
        g = load_from("pcv4.txt")
        print("Grafo carregado com sucesso!")
    except FileNotFoundError:
        print("Erro: Arquivo 'pcv4.txt' não encontrado.")
        exit()

    while True:

        opcao = menu()

        if opcao == "1":
            print('-' *30)
            print("\nLista de Adjacência:")
            for i, adj in enumerate(g.L):
                print(f"{i}: {adj}")

        elif opcao == "2":
            print('-' *30)
            print("\nMatriz de Adjacência:")
            for row in g.M:
                print(row)

        elif opcao == "3":
            print('-' *30)
            start = int(input("Vértice inicial para DFS: "))
            pred = g.dfs_iterative(start)
            print("\nDFS Iterativo (Predecessores):")
            print(pred)

        elif opcao == "4":
            print('-' *30) 
            s = int(input("Vértice de origem: "))
            t = int(input("Vértice de destino: "))
            g.print_path_bfs(s, t)

        elif opcao == "5":
            print("Saindo...")
            break

        else:
            print("Opção inválida. Tente novamente.")