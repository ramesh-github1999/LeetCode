class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]!=9) {
            digits[n-1]+=1;
            return digits;
        }
        int k=0 ;bool flag=false;
        digits[n-1]+=1; int rem=0;
        for(int i=n-1;i>=0;i--){
            
            if(digits[i]+rem>9){
                int k=rem+digits[i];
                digits[i]=k%10;
                rem=k/10;
                if(i==0) flag=true;
            }
            else {
                digits[i]+=rem;
                break;
            }
        }
        if(flag==true){
            digits.insert(digits.begin(),rem);
        }
        return digits; 

    }
};


class Solution2 {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]!=9) {
            digits[n-1]+=1;
            return digits;
        }
        for(int i=n-1;i>=0;i--){
            if(digits[i]==9){
                digits[i]=0;
            }
            else {
                digits[i]++;
                return digits;
              }
        }
        digits.insert(digits.begin(),1);
        return digits; 
    }
};
