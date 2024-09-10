class Solution {
public:
    int minFlips(int a, int b, int c) {
        int diff = (a | b) ^ c;
        return number_of_1_bits(diff) + number_of_1_bits(diff & (a & b));
    }

private:
    int number_of_1_bits(int n) {
        int result = 0;
        for (; n; n &= n - 1, ++result);
        return result;
    }
};
