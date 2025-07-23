class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int t = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            int c = arr[i] * (i + 1) * (n - i);
            t += c;
        }
        return t;
    }
};
