class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        map<int,int> countMap;
        for(auto& interval: intervals) {
            int start=interval[0];
            int end=interval[1];
            countMap[start]++;
            countMap[end+1]--;
        }
        int currCount=0;
        int result=-1;
        int prev=-1;
        for(auto& [point,delta]: countMap) {
            if(prev!=-1 && currCount>=k) {
                result=max(result,point-1);
            }
            currCount+=delta;
            prev=point;
        }
        return result;
    }
};
