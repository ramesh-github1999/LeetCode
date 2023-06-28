class Solution {
public:
    double fun(double x,long long int n){
        if(n==0) return 1;
        if(n%2==0) return fun(x*x,n/2);
        else return x*fun(x,n-1);
    }
    double myPow(double x, int n) {
        if(x==1) return 1;
        if(x==-1 && n%2==0) return 1;
        if(x==-1 && n%2!=0) return -1;
       if(n<0) {
           x=1/x;
           n=abs(n);
       }
        return fun(x,n);
    }
};



class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==1) return 1;
        if(x==-1 && n%2==0) return 1;
        if(x==-1 && n%2!=0) return -1;
       if(n<0) {
           x=1/x;
           n=abs(n);
       }
        if(n%2==0)  return myPow(x*x,n/2);
        else return x*myPow(x,n-1);
    }
};
