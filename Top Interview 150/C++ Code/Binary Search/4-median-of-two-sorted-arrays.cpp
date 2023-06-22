// using extra space vector
// Time:O(m+n)
// Space= O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        vector<int>c(m+n);
        
        int i=0,j=0,k=0;
	while(i<n || j<m){
		if(j==m ||(i<n && a[i]<b[j] )){
			c[k++]=a[i++];
		}
		else{
			c[k++]=b[j++];
			
		}
	}
        for(int i=0;i<m+n;i++)
            cout<<c[i]<<" ";
     
      int s=m+n;
        if(s%2==0) return (c[s/2]+c[s/2-1])/2.0;
        else return c[s/2];
        

        
    }
};


class Solution {
public:
    // pepcoding solution 
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size()){
            vector<int>temp=a;
            a=b;
            b=temp;
        }
        int l=0,h=a.size();
        int te=a.size()+b.size();
        while(l<=h){
            int aleft=(l+h)/2;
            int bleft=(te+1)/2-aleft;
            // compare a[aleft] with b[bleft-1] and b[bleft] with a[aleft-1]
            int alm1= (aleft==0)? INT_MIN:a[aleft-1]; // a[left-1]
            int al= (aleft==a.size()) ? INT_MAX:a[aleft];
            int blm1= (bleft==0) ? INT_MIN:b[bleft-1];
            int bl= (bleft==b.size()) ?INT_MAX: b[bleft];
            
            if(alm1<=bl && al>=blm1){
                if(te%2!=0) return (double)max(alm1,blm1);
              else{
                int lmax=max(alm1,blm1);
                int rmin=min(al,bl);
                return (double)((lmax+rmin)/2.0);
              }
            }
            else{
                if(al<blm1) l=aleft+1;
                else h=aleft-1;
            }
             
            
        }
        return 0.0;
    }
};
