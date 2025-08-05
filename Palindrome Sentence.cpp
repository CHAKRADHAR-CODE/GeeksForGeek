class Solution {
  public:
    bool isPalinSent(string &s) {
        string x;
        for(char c:s){
            if(isalnum(c))x+=tolower(c);
        }
        int m=x.length();
        for(int i=0;i<m/2;i++){
            if(x[i]!=x[m-1-i])
                return false;
        }
        return true;
    }
};
