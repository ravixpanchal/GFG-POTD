class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
 map<int, int> mpp;

    // Mark interval start and 
    // end+1 with +1 and -1 respectively
    for (auto& x : intervals) {
        mpp[x[0]] += 1;
        mpp[x[1] + 1] -= 1;
    }

    int ans = -1;
    int temp = 0;

    // Traverse the map (sorted keys) and 
    // track frequency using prefix sum
    for (auto& x : mpp) {
        if (mpp[x.first] >= 0) {
            temp += mpp[x.first];
            if (temp >= k) {
                ans = x.first;
            }
        } else {
            if (temp >= k) {
                ans = x.first - 1;
            }
            temp += mpp[x.first];
        }
    }

    return ans;
        
    }
};