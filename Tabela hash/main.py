class Node:
    def __init__(self, key):
        self.key = key
        self.next = None

class SecondLevelHashTable:
    def __init__(self, num_buckets):
        self.num_buckets = num_buckets
        self.buckets = [None] * num_buckets

class HashTable:
    def __init__(self, n):
        self.n = n
        self.second_level_size = max(n // 10, 1)  # Garante mínimo 1 bucket
        self.first_level = [SecondLevelHashTable(self.second_level_size) for _ in range(10)]

    # Primeira função hash (soma dos caracteres módulo 10)
    def h1(self, key):
        return sum(ord(c) for c in key) % 10
    
    # Segunda função hash (djb2 modificada)
    def h2(self, key, num_buckets):
        hash_val = 5381
        for c in key:
            hash_val = ((hash_val << 5) + hash_val) + ord(c)
        return hash_val % num_buckets

    def insert(self, key):
        idx1 = self.h1(key)
        sht = self.first_level[idx1]
        idx2 = self.h2(key, sht.num_buckets)
        
        current = sht.buckets[idx2]
        # Verificar se já existe
        while current:
            if current.key == key:
                print(f"Chave '{key}' já existe!")
                return
            current = current.next
        
        # Inserir no início da lista
        new_node = Node(key)
        new_node.next = sht.buckets[idx2]
        sht.buckets[idx2] = new_node
        print(f"Chave '{key}' inserida com sucesso!")

    def search(self, key):
        idx1 = self.h1(key)
        sht = self.first_level[idx1]
        idx2 = self.h2(key, sht.num_buckets)
        
        current = sht.buckets[idx2]
        while current:
            if current.key == key:
                print(f"Chave '{key}' encontrada!")
                return
            current = current.next
        print(f"Chave '{key}' não encontrada!")

def main():
    n = int(input("Digite o número total de objetos (n): "))
    if n < 1:
        print("n deve ser positivo!")
        return
    
    ht = HashTable(n)
    
    while True:
        print("\n--- Menu ---")
        print("1. Inserir chave")
        print("2. Buscar chave")
        print("3. Sair")
        opcao = input("Escolha uma opção: ")
        
        if opcao == "1":
            key = input("Digite a chave: ").strip()
            ht.insert(key)
        elif opcao == "2":
            key = input("Digite a chave: ").strip()
            ht.search(key)
        elif opcao == "3":
            print("Saindo...")
            break
        else:
            print("Opção inválida!")

if __name__ == "__main__":
    main()