class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (const auto& x : asteroids) {
            bool is_exploded = false;
            while (!empty(result) && x < 0 && 0 < result.back()) {
                if (result.back() < -x) {
                    result.pop_back();
                    continue;
                } else if (result.back() == -x) {
                    result.pop_back();
                }
                is_exploded = true;
                break;
            }
            if (!is_exploded) {
                result.emplace_back(x);
            }
        }
        return result;
    }
};