class Solution 
{
public:
    int minimumDeletions(string s) 
    {
        vector<char> stk;
        int res = 0;
        for(auto& c : s)
        {
            if(!stk.empty() && stk.back() == 'b' && c == 'a')
            {
                res++;
                stk.pop_back();
            }
            else stk.push_back(c);
        }
        return res;
    }
};