class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 2) return true;
        
        int left = 1, right = num;
        while(left+1 < right) {
            int mid = left + ((right - left) >> 1);
            if(mid < num / mid) left = mid;
            else right = mid;
        }
        
        return (right > 46340)?(false):(right * right == num);
    }
};
