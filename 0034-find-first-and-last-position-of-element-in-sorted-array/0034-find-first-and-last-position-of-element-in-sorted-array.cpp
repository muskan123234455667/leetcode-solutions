class Solution {
public:
    // Function to find first occurrence
    int firstOccurrence(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;          // Store answer
                right = mid - 1;    // Search on left side
            }
            else if (nums[mid] < target) {
                left = mid + 1;     // Search right half
            }
            else {
                right = mid - 1;    // Search left half
            }
        }

        return ans;
    }

    // Function to find last occurrence
    int lastOccurrence(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;         // Store answer
                left = mid + 1;    // Search on right side
            }
            else if (nums[mid] < target) {
                left = mid + 1;    // Search right half
            }
            else {
                right = mid - 1;   // Search left half
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = firstOccurrence(nums, target);
        int last = lastOccurrence(nums, target);

        return {first, last};
    }
};