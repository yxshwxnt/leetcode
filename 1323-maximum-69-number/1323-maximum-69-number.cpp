class Solution {
public:
    int maximum69Number (int num) {        
        int rightCount = -1; 
        int digCount = 0;
        int temp = num; 
        while(temp > 0){
            int dig = temp % 10;
            if (dig == 6){
                rightCount = digCount;
            }
            digCount++;
            temp = temp / 10;
        }
        if (rightCount == -1) return num;
        int ans = num + (3 * pow(10, rightCount));
        return ans;
    }
};