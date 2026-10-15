class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums_copy = nums;
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1, sum = 0;
        vector<int> result = *(new vector<int>);

        while (left < right) {
            sum = nums[left] + nums[right];

            if (sum == target) result = {nums[left], nums[right]};

            if (sum < target) left++;

            else right--;
        }

        printf("%d and %d\n", result[0], result[1]);
        
        for (int i = 0; i < nums_copy.size(); i++)
            cout << nums_copy[i] << endl;

        // find index 
        for (int i = 0; i < nums_copy.size(); i++) {
            if (nums_copy[i] == result[0]) {
                result[0] = i;
                cout << result[0] << endl;
                break;
            }
        }

        for (int i = 0; i < nums_copy.size(); i++) {
            if (nums_copy[i] == result[1] && i != result[0]) {
                result[1] = i;
                break;
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
};
