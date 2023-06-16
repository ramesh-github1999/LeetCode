// we can easily solve it by using map or sorting 
// Bit Manipulation solution (see the leetcode solution article that is very nice).
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int loner=0;
        for(int shift=0;shift<32;shift++){
            int bitsum=0;
            for(int i=0;i<nums.size();i++){
                bitsum+=(nums[i]>>shift) &1; 
            }   
            
            int lonerBit=bitsum%3;
            loner=loner|(lonerBit<<shift);
        }
        return loner;
    }
};


// Equation for Bitmask (see leetcode solution article for better understanding 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenOnce=0,seenTwice=0;
        for(int i=0;i<nums.size();i++){
            seenOnce=(seenOnce^nums[i])&(~seenTwice);
            seenTwice=(seenTwice^nums[i])&(~seenOnce);
        }
        return seenOnce;
    }
};
