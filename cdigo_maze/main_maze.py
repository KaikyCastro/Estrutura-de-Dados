import time
from maze import Maze
from collections import deque

def find_path(maze: Maze) -> bool:
    stack = deque()  
    start_pos = maze.get_init_pos_player()  
    stack.append(start_pos)  
    
    visited = set() 
    
    while stack:
        pos = stack.pop()  
        
        if pos in visited:
            continue 
        
        visited.add(pos) 
        
        if maze.find_prize(pos): 
            print("Caminho encontrado!")
            return True
        
        maze.mov_player(pos) 
        time.sleep(0.1)
        
        x, y = pos
        
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            new_pos = (x + dx, y + dy)
            if new_pos not in visited and maze.is_free(new_pos):
                stack.append(new_pos)
    
    print("Caminho não encontrado.")
    return False

if __name__ == "__main__":
    maze_csv_path = "labirinto1.txt"  # Caminho correto para o arquivo
    maze = Maze()
    maze.load_from_csv(maze_csv_path)
    maze.run()
    maze.init_player()
    
    time.sleep(1)  
    find_path(maze)
