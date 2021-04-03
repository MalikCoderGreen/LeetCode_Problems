"""
819. Most Common Word

Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. 
It is guaranteed there is at least one word that is not banned, and that the answer is unique.

The words in paragraph are case-insensitive and the answer should be returned in lowercase.

Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.

"""
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        # Create a map to assign words to their frequency in 'paragraph'.
        L = {}
        i = 0
        
        while i < len(paragraph):
            word = ""
            # We only want to get letters and not punctuation or whitespace chars.
            if paragraph[i].isalpha():
                j = i
                while j < len(paragraph) and paragraph[j].isalpha(): 
                    word += paragraph[j]
                    j += 1
                i = j
                # Only add the word to the map if it is not in 'banned'.
                if word.lower() not in banned:
                    if word.lower() not in L.keys():
                        L[word.lower()] = 1
                    else:
                        L[word.lower()] += 1
                        
            # Else to skip over non-alpha chars.
            else:
                i += 1
        
        # Return the key with the highest frequency as the answer.
        return max(L, key=L.get)
