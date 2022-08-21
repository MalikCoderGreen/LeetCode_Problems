"""
566. Reshape the Matrix
In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.
You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.
The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]
"""

class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        # Check if re-shape is legal. 
        if r*c != len(mat)*len(mat[0]):
            return mat
        
        new_mat = [[0 for j in range(c)] for i in range(r)]
        # By flattening the matrix, we will convert it to 1-D.
        flatten = []
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                flatten.append(mat[i][j])
        
        # Populate the return matrix.
        k = 0                
        for i in range(r):
            for j in range(c):
                new_mat[i][j] = flatten[k]
                k += 1
        
        
        return new_mat
