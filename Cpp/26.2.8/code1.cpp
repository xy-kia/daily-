class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int>a(n+1,0);
        vector<int>b(n+1,0);
        for(int i=1;i<n+1;i++){
            if(s[i-1]=='b'){
                a[i]=a[i-1]+1;
            }else{
                a[i]=a[i-1];
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                b[i]=b[i+1]+1;
            }else{
                b[i]=b[i+1];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n+1;i++){
            int x=a[i]+b[i];
            ans=min(ans,x);
        }
        return ans;        
    }
};