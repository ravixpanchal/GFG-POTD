class Solution {
  public:
    vector<int> asciirange(string& s) {
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        vector<int>ans;
        
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
            if(first[idx]==-1) first[idx]=i; 
            last[idx]=i;
        }
        
        for(int i=0;i<26;i++){
            if(first[i]!=-1 && last[i]!=-1 && first[i]<last[i]){
                int sum=0;
                for(int j=first[i]+1;j<last[i];j++){
                    sum+=s[j];
                }
                if(sum) ans.push_back(sum);
            }
        }
        return ans;
        
    }
};