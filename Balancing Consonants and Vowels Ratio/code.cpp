class Solution {
  public:
    int countBalanced(vector<string>& arr) {
    int ans=0;
    set<char>vowel{'a','e','i','o','u'};
    map<int,int>m;
    m[0]=1;
    int sum=0;
    
    for(auto i: arr){
        int val=0;
        for(char ch: i){
            if(vowel.find(ch)!=vowel.end()){
                val++;
            }else{
                val--;
            }
        }
        sum+=val;
        ans+=m[sum];
        m[sum]++;
    }
    return ans;
        
    }
};