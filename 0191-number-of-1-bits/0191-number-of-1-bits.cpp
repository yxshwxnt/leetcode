class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0; 
        while(n!=0){
            //cheching last bit 
            if(n&1){          //and last digit with 1, if true means ki last dig. bhi 1 tha
                count++; 
            }
            n=n>>1;    //right shift by 1
        }
        return count; 
    }
};