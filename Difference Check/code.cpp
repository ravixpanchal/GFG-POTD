    class Solution {
  public:
  
  int toSec(string s){
      return stoi(s.substr(0,2))*3600+stoi(s.substr(3,2))*60+stoi(s.substr(6,2));
  }
  
    int minDifference(vector<string> &arr) {
     vector<bool>vis(86400,false);
     for(auto &i: arr){
         int sec=toSec(i);
         if(vis[sec]) return 0;
         vis[sec]=true;
     }
     
     int first=-1;
     int two=-1;
     int mini=INT_MAX;
     
     for(int i=0;i<86400;i++){
         if(!vis[i]) continue;
         if(two!=-1) mini=min(mini,i-two);
         else first=i;
         two=i;
     }
     //swap condition
     mini=min(mini,first+86400-two);
     return mini;
        
    }
};
