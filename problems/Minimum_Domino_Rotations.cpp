/**
 * Solution to Minimum Domino Rotations For Equal Row at LeetCode in C++
 *
 * author: kashish808
 * ref: https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3500/
 */

Minimum Domino Rotations For Equal Row
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int a[6] = {-1,-1,-1,-1,-1,-1}, m = INT_MAX;
        bool flag = true;
        int n = A.size();
        for(int i=0;i<6;i++) {
            int t = 0, count1 = 0, count2 = 0;
            for(int j=0;j<n;j++) {
            if( (A[j] == i+1)||(B[j] == i+1) )
                t++;
            if(t == n) {
                for(int k=0;k<n;k++)
                    if(A[k] == i+1) count1++;
                for(int k=0;k<n;k++)
                    if(B[k] == i+1) count2++;
                // cout<<"Count of "<<i+1<<" is "<<count<<endl;
                a[i] = min(n - count1, n - count2);
                flag = false;
            }
        }
    }
        for(int k=0;k<6;k++) cout<<a[k]<<endl;
        if(flag) return -1;
        else {
                for(int k=0;k<6;k++)
                    if(a[k] < m && a[k] != -1)
                        m = a[k];
            }
        return m;
    }
};
