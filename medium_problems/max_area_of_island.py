'''
695. Max Area of Island
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
'''


class Solution:
    def __init__(self):
        self.v = []
        
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        M,N = len(grid), len(grid[0])
        q = []
        def valid(r, c):            
            return 0 <= r < M and 0 <= c < N
        
        def bfs(r, c):
            q.append((r,c))
            grid[r][c] = 0
            island_size = 1
            
            while len(q) > 0:
                # Cell represents the current piece of land that we are on
                cell = q.pop(0)
                # Check in all four of 'cells' directions for other neighbors with the value of 1
                for v,u in [(0, -1), (1, 0), (-1, 0), (0, 1)]:  
                    dx,dy = v+cell[0],u+cell[1]
                    if valid(dx, dy):
                        if grid[dx][dy] == 1:
                            island_size += 1
                            q.append((dx,dy))
                            grid[dx][dy] = 0 # sink the piece of land so we don't revisit it
            
            return island_size
        
        max_island = 0
        for i in range(M):
            for j in range(N):
                if grid[i][j] == 1:
                    max_island = max(max_island, bfs(i, j))
        return max_island
