class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        map<int,int>m;
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])){
                m[nums[i]]++;
            }else{
                m[nums[i]]=1;
            }
        }

        for(pair<int,int>p:m){
            if(p.second>nums.size()/3){
                ans.push_back(p.first);
            }
        }
       return ans;
        
    }
};