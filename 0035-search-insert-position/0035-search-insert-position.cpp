#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int> newer = nums;  
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                return i;
            }
        }
        
        newer.push_back(target);
        sort(newer.begin(), newer.end());
        
        for(int i = 0; i < newer.size(); i++) {
            if(newer[i] == target) {
                return i;
            }
        }
        return -1;
    }
};


