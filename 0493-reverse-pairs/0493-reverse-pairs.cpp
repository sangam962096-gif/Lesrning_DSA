class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;

        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)nums[i] > 2LL * nums[right]) {
                right++;
            }
            cnt += right - (mid + 1);
        }

        return cnt;
    }

    int ms(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;
        int cnt = 0;

        cnt += ms(nums, low, mid);
        cnt += ms(nums, mid + 1, high);

        cnt += countPairs(nums, low, mid, high);

        merge(nums, low, mid, high);

        return cnt;
    }

    int mergeSort(vector<int>& nums, int n) {
        return ms(nums, 0, n - 1);
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, nums.size());
    }
};