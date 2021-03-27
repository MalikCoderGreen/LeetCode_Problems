"""
290. Word Pattern

Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

"""
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        # Use two maps for chars in 'pattern' and words in 's'.
        pat_map = {pattern[i]: i for i in range(len(pattern))}
        s_words = s.split()
        word_map = {s_words[i]: i for i in range(len(s_words))}
        
        # Append values from both maps to seperate lists 'l1' and 'l2'.
        # In the end, if these lists do not equal, the patterns are not the same.
        l1 , l2 = [], []
        for c in pattern:
            l1.append(pat_map[c])
        
        for word in s_words: 
            l2.append(word_map[word])
        
        return l1 == l2
        
