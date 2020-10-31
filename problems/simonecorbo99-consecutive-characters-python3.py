/**
 * Solution to consecutive-characters at LeetCode in Python3
 *
 * author: simonecorbo99
 * ref: https://leetcode.com/problems/consecutive-characters/
 */
 
 class Solution:
    def maxPower(self, s: str) -> int:
        p=1
        c = 1
        for i in range(len(s)-1):
            if s[i]==s[i+1]:
                c = c+1
            else:
                if c>p:
                    p = c
                c=1
        if c>p:
            return c
        return p
