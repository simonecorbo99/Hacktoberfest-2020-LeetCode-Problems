/**
solution to container with most water at leetcode in Java.
author : Neha Labhasetwar
Ref: https://leetcode.com/problems/container-with-most-water
*/


class Solution {
    public int maxArea(int[] height) {
        
        int area=0;
        int maxarea=0;
        for(int i=0;i<height.length;i++)
        {
            for(int j=i+1;j<height.length;j++)
            {
                area=Math.min(height[i],height[j])*(j-i);
                if(maxarea<area)
                    maxarea=area;
            }
        }
        return maxarea;
    }
}