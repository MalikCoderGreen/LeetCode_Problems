"""
1122. Relative Sort Array

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  
Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
"""
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        # Create a map for numbers and their frequency in arr1.
        arr1_freq = {x:0 for x in arr1}
        for i in range(len(arr1)):
            arr1_freq[arr1[i]] += 1
        
        # Loop through arr2 and append values from arr1 that are in arr2 to rtn_list.
        rtn_list = []
        for i in range(len(arr2)): 
            count = 0
            # This loop will add the values from arr2 into rtn list-
            # based on their frequency in the arr1 map.
            while count < arr1_freq[arr2[i]]:
                rtn_list.append(arr2[i])
                count += 1
        
        # Keep track of the rtn_list size before appending additional elements-
        # from arr1 that are not in arr2.
        sz = len(rtn_list)
        for i in arr1: 
            if i not in arr2: 
                rtn_list.append(i)
        
        # Sort the rest of the list after adding any additional values-
        # from arr1 that are not in arr2. 
        rtn_list[sz:] = sorted(rtn_list[sz:])
        
        return rtn_list
