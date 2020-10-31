/**
 * Solution to <problem-name> at LeetCode in <language>
 *
 * author: <username>
 * ref: <problem-source>
 */
 
 class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s = list(s)
        for l in t:
            if l in s:
                s.remove(l)
            else:
                return l
            
