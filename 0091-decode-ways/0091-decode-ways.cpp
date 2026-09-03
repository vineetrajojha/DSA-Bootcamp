class Solution {
    
public:
    int numDecodings(string s) {
        int n=s.size();
        int f1=0,f2=1;
        if(s[n-1]!='0') f1=1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='0')
            {
                f2=f1;
                f1=0;
                continue;
            }
            int w=f1;
            if(s[i]<'2' || (s[i]=='2' && s[i+1]<='6'))
            {
                w+=f2;
            }
            f2=f1;
            f1=w;
        }       return f1;
    }
};