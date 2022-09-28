"""
48. Rotate Image
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
"""
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # flatten the matrix
        flat = []
        sz = len(matrix) * len(matrix)
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                flat.append(matrix[i][j])

        k = sz - len(matrix)
        count = 1
        # re assign values to original matrix but rotated 90 degrees
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                matrix[i][j] = flat[k]
                k -= len(matrix)
            
            k = (sz - len(matrix)) + count
            count += 1
