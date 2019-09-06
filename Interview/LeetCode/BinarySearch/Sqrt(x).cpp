class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        
        int left = 0, right = x;
        while(left < right) {
            int64_t mid = left + ((right - left) >> 1);
            if (mid * mid == x) return mid;
            else if (mid * mid < x) left = mid+1;
            else right = mid-1;
        }
        int64_t check = left*left;
        return (check <= x)?(left):(left-1);
    }
};
