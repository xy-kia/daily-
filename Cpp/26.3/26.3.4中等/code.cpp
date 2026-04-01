class Solution {
public:
    char findKthBit(int n, int k) {
        int turn=0;
        int l=(1<<n)-1;
        while(l>1){
            int x=l/2+1;
            if(k==x){
                 return turn == 1 ? '0' : '1';
            }else if(k<x){
                l/=2;
            }else if(k>x){
                k=x-(k-x);
                l/=2;
                turn=(turn+1)%2;
            }
        }
        if(turn==1){
            return '1';
        }else{
            return '0';
        }
    }
};