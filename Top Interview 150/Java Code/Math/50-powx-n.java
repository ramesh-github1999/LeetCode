class Solution {
    public double fun(double x,long n){
         if(n==0) return 1;
        if(x==1) return 1;
        if(x==-1 && n%2==0) return 1;
        if(x==-1 && n%2!=0) return -1;
       if(n<0) {
           x=1/x;
           n=Math.abs(n);
       }
        if(n%2==0)  return fun(x*x,n/2);
        else return x*fun(x,n-1);
    }
    public double myPow(double x, int n) {
          return fun(x,(long)n);
    }
}
