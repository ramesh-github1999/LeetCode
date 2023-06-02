class Solution {
public:
    int getNext(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int>s;
            
        while(n!=1 && s.find(n)==s.end()){
            s.insert(n);
            n=n=getNext(n);
        }
        if(n==1) return true;
        return false;
    }
};
