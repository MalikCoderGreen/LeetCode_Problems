"""
73. Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Input: matrix = [[1,1,1],
                 [1,0,1],
                 [1,1,1]]
Output: [[1,0,1],
         [0,0,0],
         [1,0,1]]
"""
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # Runtime: O(MN)
        # Space Complex: O(M + N)
        
        # Keep track of the zeroes that are given by default
        true_zeroes = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    true_zeroes.append([i, j])
        
        def set_zeroes_util(g, r, c):
            # Keep track of the starting positon
            origin = [r, c]
            while r < len(g):
                g[r][c] = 0
                r += 1
                
            # Move r above the origin row    
            r = origin[0] - 1
            while r >= 0:
                g[r][c] = 0
                r -= 1
                
            r = origin[0]
            while c < len(g[0]):
                g[r][c] = 0
                c += 1
            
            # Move c to the left of the origin column
            c = origin[1] - 1
            while c >= 0:
                g[r][c] = 0
                c -= 1
        
        
        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                if [row, col] in true_zeroes:
                    set_zeroes_util(matrix, row, col)
