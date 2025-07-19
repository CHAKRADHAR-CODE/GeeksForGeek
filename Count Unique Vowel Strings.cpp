class Solution {
  public:
    int vowelCount(string& s) {
        unordered_map<char, vector<int>> vowelMap;
        string vowels = "aeiou";
        for (int i=0;i<s.size();++i) {
            if (vowels.find(s[i]) != string::npos) {
                vowelMap[s[i]].push_back(i);
            }
        }
        vector<int>counts;
        for (char v:vowels) {
            if (vowelMap.count(v)) {
                counts.push_back(vowelMap[v].size());
            }
        }
        int ways=1;
        int n=counts.size();
        if (n==0) return 0;
        for (int cnt:counts) {
            ways*=cnt;
        }
        int perm=1;
        for (int i=2;i<=n;++i) {
            perm*=i;
        }
        return ways*perm;
    }
};
