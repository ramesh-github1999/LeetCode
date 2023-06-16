class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.length(),j=b.length();
        i--,j--;
        int carry=0;
        while(i>=0 && j>=0){
            if(carry==0){
                if(a[i]=='1' && b[j]=='1'){
                    ans="0"+ans;
                    carry=1;
                }
                else if(a[i]=='0' && b[j]=='0'){
                    ans="0"+ans;
                    carry=0;
                }
                else{
                    ans="1"+ans;
                    carry=0;
                }
            }
            else {
                if(a[i]=='1' && b[j]=='1'){
                    ans="1"+ans;
                    carry=1;
                }
                else if(a[i]=='0' && b[j]=='0'){
                    ans="1"+ans;
                    carry=0;
                }
                else{
                    ans="0"+ans;
                    carry=1;
                }
                
            }
            i--;j--;
            
            
            }
        while(i>=0){
            if(carry==0){
               
                    ans=a[i]+ans;
                    carry=0;
            }
                else{
                    if(a[i]=='1'){
                    ans="0"+ans;
                    carry=1;
                    }
                    else{
                        ans="1"+ans;
                        carry=0;
                    }
                }
                i--;
        }
         while(j>=0){
            if(carry==0){
               
                    ans=b[j]+ans;
                    carry=0;
            }
                else{
                    if(b[j]=='1'){
                    ans="0"+ans;
                    carry=1;
                    }
                    else{
                        ans="1"+ans;
                        carry=0;
                    }
                }
                j--;
        }
        
        if(carry==1) ans="1"+ans;
        
        return ans;
    }
};


class Solution2 {
public:
    string addBinary(string a, string b) {
        string res="";
        int n=a.length(),m=b.length();
        int i=n-1,j=m-1;
        int s=0;
        while(i>=0 || j>=0 || s==1)
        {
            s+=((i>=0)?a[i]-'0':0);
             s+=((j>=0)?b[j]-'0':0);
            res=char(s%2+'0')+res;
            s/=2;
            i--,j--;
            
        }
        return res;
    }
};
 
