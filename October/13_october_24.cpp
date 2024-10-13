class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int totalElements = 0;
        for (auto& group : nums) totalElements += group.size();
      
        vector<pair<int, int>> sortedElements(totalElements);
      
        int numGroups = nums.size();
      
        for (int i = 0, index = 0; i < numGroups; ++i) {
            for (int value : nums[i]) {
                sortedElements[index++] = {value, i};
            }
        }
      
        sort(sortedElements.begin(), sortedElements.end());
      
        int startWindow = 0;
        unordered_map<int, int> groupCount;
      
        vector<int> range = {-1000000, 1000000};
      
        for (int endWindow = 0; endWindow < totalElements; ++endWindow) {
            int currentValue = sortedElements[endWindow].first;
            int currentGroup = sortedElements[endWindow].second;
          
            ++groupCount[currentGroup];
          
            while (groupCount.size() == numGroups) {
                int windowStartValue = sortedElements[startWindow].first;
                int windowStartGroup = sortedElements[startWindow].second;
              
                int currentRange = currentValue - windowStartValue;
                int bestRange = range[1] - range[0];
                if (currentRange < bestRange || (currentRange == bestRange && windowStartValue < range[0])) {
                    range[0] = windowStartValue;
                    range[1] = currentValue;
                }
              
                if (--groupCount[windowStartGroup] == 0) {
                    groupCount.erase(windowStartGroup);
                }
              
                ++startWindow;
            }
        }
      
        return range;
    }
};
