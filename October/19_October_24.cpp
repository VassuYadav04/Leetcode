class Solution {
public:
    char findKthBit(int n, int k) {
        int flip = 0;
        for (int l = (1 << n) - 1; k > 1; l /= 2) { 
            if (k == l / 2 + 1) {
                flip ^= 1; 
                break;
            }
            if (k > l / 2) {
                k = l + 1 - k;
                flip ^= 1;
            }
        }
        return '0' + flip;
    }
};