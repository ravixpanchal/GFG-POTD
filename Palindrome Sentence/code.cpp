class Solution {
  public:
    bool isPalinSent(string &s) {
        int st=0;
        int end=s.size()-1;
        while(st<end){
            if(!isalnum(s[st]))st++;
            else if(!isalnum(s[end]))end--;
            
            else if(tolower(s[st])==tolower(s[end])) st++,end--;
            else return false;
        }
        return true;
        
    }
};