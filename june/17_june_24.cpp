class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        for (; a * a <= c; a++) {
            double b = sqrt(c - a * a);
            if (b == floor(b))
                return true;
        }
        return false;
    }
};