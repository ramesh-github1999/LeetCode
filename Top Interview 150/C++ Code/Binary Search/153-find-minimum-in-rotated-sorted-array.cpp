class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        if(n==1) return a[0];
        if(a[0]<a[n-1]) return a[0];
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
           if(a[mid+1]<a[mid]) return a[mid+1];
            else  if(a[mid]<a[mid-1]) return a[mid];
            else if(a[0]<a[mid]) l=mid+1;
            else h=mid-1;
        }
        return 0;
    }
};
