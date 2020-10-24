/**
 * Solution to Find the Duplicate Number at LeetCode in C++
 *
 * author: ashk3301
 * ref: https://leetcode.com/problems/find-the-duplicate-number
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int last = nums.size()-1,n;
        int a[last+1];
        for(int i=0;i<last+1;i++)
            a[i] = 0;
        for(int i=0;i<=last;i++){
           if(a[nums[i]] != 0)
           {    
               n = nums[i];
               break;
           }
        a[nums[i]] = 1;
        }
        return n;
    }
};