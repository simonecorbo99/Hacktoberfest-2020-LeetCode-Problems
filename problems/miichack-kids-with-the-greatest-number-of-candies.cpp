class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = *max_element(candies.begin(),candies.end()); 
        vector<bool> v(candies.size());
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i] + extraCandies >= m)
                v[i] = true;
        }
        return v;
    }
}; 
