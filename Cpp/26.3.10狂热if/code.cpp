class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        while(num>=1000){
            ans=ans+'M';
            num-=1000;
        }
        if(num>=900){
            ans=ans+"CM";
            num-=900;
        }
        if(num>=500){
            ans=ans+'D';
            num-=500;
        }
        if(num>=400){
            ans=ans+"CD";
            num-=400;
        }
        while(num>=100){
            ans=ans+'C';
            num-=100;
        }
        if(num>=90){
            ans=ans+"XC";
            num-=90;
        }
        if(num>=50){
            ans=ans+'L';
            num-=50;
        }
        if(num>=40){
            ans=ans+"XL";
            num-=40;
        }
        while(num>=10){
            ans=ans+'X';
            num-=10;
        }
        if(num==9){
            ans=ans+"IX";
            return ans;
        }
        if(num>=5){
            ans=ans+'V';
            num-=5;
        }
        if(num==4){
            ans=ans+"IV";
            return ans;
        }
        while(num>=1){
            ans=ans+'I';
            num--;
        }
        return ans;
    }
};