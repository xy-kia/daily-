class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> visible(n);

        queue<int> q;
        q.push(0);
        visible[0] = true;
        int r = 0;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            r = max(r, i + minJump);
            while(r <= min(n-1, i + maxJump)){
                if(!visible[r] && s[r] == '0'){
                    if(r == n-1){
                        return true;
                    }
                    q.push(r);
                    visible[r] = true;
                }
                r++;
            }
        }
        return false;
    }
};