// You are given three integers start, finish, and limit. You are also given a 0-indexed string s representing a positive integer.
// A positive integer x is called powerful if it ends with s (in other words, s is a suffix of x) and each digit in x is at most limit.
// Return the total number of powerful integers in the range [start..finish].
// A string x is a suffix of a string y if and only if x is a substring of y that starts from some index (including 0) in y and extends to the index y.length - 1. For example, 25 is a suffix of 5125 whereas 512 is not.


class Solution {
long long dp[17][2];
private:
    long long getAns(string& s,int n,bool tight,int limit,int m,long long t){
        if(n == m) {
            if(!tight) return 1ll;
            else{
                string temp=s.substr(s.length()-m);
                long long ele=stoll(temp);
                if(ele >= t) return 1ll;
                return 0ll;
            }
        }
        if(n < m) return 0ll;
        if(dp[n][tight] != -1) return dp[n][tight];
        int ub=tight ? s[s.length()-n]-'0' : 9;
        long long ans=0;
      
            for(int i=0;i<=min(ub,limit) ;i++){
                ans+=getAns(s,n-1,tight&(ub==i),limit,m,t);
            }
       
        return dp[n][tight]=ans;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        start--;

        string st=to_string(start);
        
        string f=to_string(finish);
        long long t=stoll(s);
        memset(dp,-1,sizeof(dp));
        long long left=getAns(st,st.length(),1,limit,s.length(),t);
        memset(dp,-1,sizeof(dp));
        long long right=getAns(f,f.length(),1,limit,s.length(),t);

        return (right-left);
    }
};
