class Solution {
  public:
    int countValid(int n,vector<int>& arr) {
        vector<int> allowed(10,0);
        for (int d : arr) allowed[d]=1;
        int dp[10][2][2][2] = {};
        memset(dp, -1, sizeof(dp));
        function<int(int,bool,bool,bool)> dfs = [&](int pos, bool tight, bool hasAllowed, bool leadingZero) {
            if (pos == n) return hasAllowed ? 1 : 0;
            if (dp[pos][tight][hasAllowed][leadingZero] != -1) 
                return dp[pos][tight][hasAllowed][leadingZero];
            int res = 0;
            int maxDigit = tight ? 9 : 9;
            for (int d = 0; d <= maxDigit; ++d) {
                if (leadingZero && d == 0) continue;
                bool newHasAllowed = hasAllowed || allowed[d];
                res+=dfs(pos+1,tight&&(d==maxDigit),newHasAllowed,false);
            }
            return dp[pos][tight][hasAllowed][leadingZero]=res;
        };
        return dfs(0,true,false,true);
    }
};
