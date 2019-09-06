class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        int64_t e = n;
        bool flag = (e < 0)?(true, e *= -1):(false);
        while(e){
            if(e & 1) result *= x;
            x *= x;
            e >>= 1;
        }
        return (flag)?(1.0 / result):(result);
    }
};
