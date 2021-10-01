class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> v1;
        v1 = heights;
        int cnt = 0;
        sort(v1.begin(), v1.end());
        for(int i = 0; i < n; i++)
        {
            if(v1[i] != heights[i])
                cnt++;
        }
        return cnt;
    }
};
