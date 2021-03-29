"""
429. N-ary Tree Level Order Traversal

Given an n-ary tree, return the level order traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
"""
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root: return []
        # 'lvls' will keep track of the values of nodes at levels in tree.
        # 'nodes' will act as a queue to hold nodes.
        lvls = [[root.val]]
        nodes = [root]
        
        while len(nodes) > 0: 
            tmp = []
            i = 0
            # Keep track of the length of nodes.
            curr_lvl = len(nodes)
            # Append to nodes all of the children below the current level.
            # Append node values to 'tmp' which will be added to 'lvls'.
            for i in range(curr_lvl): 
                for kid in nodes[i].children:
                    tmp.append(kid.val)
                    nodes.append(kid)
            
            # Want to remove all nodes from current level that have already-
            # been checked for children.
            for i in range(curr_lvl):
                nodes.pop(0)
            # Only want to append 'tmp' to 'lvls' if list has children values.
            if len(tmp) > 0: 
                lvls.append(tmp)       
                
        return lvls
