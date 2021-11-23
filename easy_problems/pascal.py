class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        
        # Create initial base case.
        pascal_t = [[1]]
        if numRows == 1:
            return pascal_t
        
        # For this loop generate a new row that will be +1 greater in size-
        # than the one generated before it.
        # We only care about intermidate values (values in between the first & last element).
        # any integer 'k' > 1 in the ith row will be a result of adding two integers from the ith - 1 row above it. 
        # The two above integers from the ith - 1 row have to be in sequence in order to add up to k in the ith row.
        for i in range(1, numRows):
            pascal_t.append([1]*(i+1))
            if len(pascal_t[i]) > 2:
                for j in range(1, len(pascal_t[i]) - 1):
                    pascal_t[i][j] = pascal_t[i-1][j-1] + pascal_t[i-1][j]
        
        return pascal_t
                    
                
                
        
