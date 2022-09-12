"""
492. Construct the Rectangle
A web developer needs to know how to design a web page's size. 
So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page, 
whose length L and width W satisfy the following requirements:

The area of the rectangular web page you designed must equal to the given target area.
The width W should not be larger than the length L, which means L >= W.
The difference between length L and width W should be as small as possible.
Return an array [L, W] where L and W are the length and width of the web page you designed in sequence.

Input: area = 4
Output: [2,2]
Explanation: The target area is 4, and all the possible ways to construct it are [1,4], [2,2], [4,1]. 
But according to requirement 2, [1,4] is illegal; according to requirement 3,  [4,1] is not optimal compared to [2,2]. So the length L is 2, and the width W is 2.

Input: area = 37
Output: [37,1]

Input: area = 122122
Output: [427,286]
"""

class Solution:
    def isPrime(self, x: int) -> bool:
        for i in range(2, x):
            if x % i == 0:
                return False
        return True
    
    def constructRectangle(self, area: int) -> List[int]:  
        if area == 1:
            return [1, 1]
        
        # Prime number edge cases
        if (self.isPrime(area)):
            return [area, 1]
        # L >= W
        # Diff between L <-> W should be minimum
        
        # Get factors for area and store into map
        area_map = {}
        for i in range(int(math.sqrt(area)), 1, -1):
            if area % i == 0:
                j = area / i
                L = int(max(j, i))
                W = int(min(j, i))
                area_map[tuple([L, W])] = abs(L - W)
        
        res_area = []
        min_diff = float('inf')
        for area in area_map.keys():
            if area_map[area] < min_diff:
                res_area = list(area)
                min_diff = area_map[area]
            
        return res_area
