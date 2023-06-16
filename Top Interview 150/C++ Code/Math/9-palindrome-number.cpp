class Solution {
public:
    bool isPalindrome(int x) {
        int p=x;
        if(x<0) return false;
       long long int rev=0;
        while(x!=0){
            rev=rev*10+x%10;
            x/=10; 
        }
        if(p==rev) return true;
        return false;
    }
};
