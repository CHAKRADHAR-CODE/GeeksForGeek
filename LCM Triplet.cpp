class Solution {
  public:
    long long gcd(long long a,long long b) {
        while(b) {
            long long temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    long long lcm(long long a,long long b) {
        return a/gcd(a,b)*b;
    }
    int lcmTriplets(int n) {
        long long ans=0;
        for(int i=n;i>=std::max(1,n-5);--i) {
            for(int j=i;j>=std::max(1,n-5);--j) {
                for(int k=j;k>=std::max(1,n-5);--k) {
                    long long curLCM=lcm(lcm(i,j),k);
                    ans=std::max(ans,curLCM);
                }
            }
        }
        return (int)ans;
    }
};
