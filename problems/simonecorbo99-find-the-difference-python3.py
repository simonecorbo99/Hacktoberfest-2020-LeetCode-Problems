/**
 * Solution to find-the-difference at LeetCode in Python3
 *
 * author: simonecorbo99
 * ref: leetcode.com/problems/find-the-difference
 */
 
 class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s = list(s)
        for l in t:
            if l in s:
                s.remove(l)
            else:
                return l
            
