#ifndef SEM1_HPP
#define SEM1_HPP

#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int sum = 0;

    while (left < right) {
        sum = nums[left] + nums[right];

        if (sum == target) {
            return {left, right};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

void reverseArray(vector<int>& arr, int left, int right) {
    if (arr.size() == 0) {
        return;
    }

    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

vector<int> reverseArray(vector<int>& arr) {
    reverseArray(arr, 0, arr.size() - 1);
    return arr;
}

vector<int> rotateArray(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) {
        return arr;
    }

    reverseArray(arr, 0, n - 1);
    reverseArray(arr, 0, (k % n) - 1);
    reverseArray(arr, (k % n), n - 1);

    return arr;
}

vector<int> merge_sorted_arrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged_array = {};

    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged_array.push_back(arr1[i]);
            i++;
        } else {
            merged_array.push_back(arr2[j]);
            j++;
        }
    }

    for (i; i < arr1.size(); i++) {
        merged_array.push_back(arr1[i]);
    }
    
    for (j; j < arr2.size(); j++) {
        merged_array.push_back(arr2[j]);
    }

    return merged_array;
}

vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
    int ptr1 = arr1.size() - arr2.size() - 1;
    int ptr2 = arr2.size() - 1;
    int ptr3 = arr1.size() - 1;

    while (ptr2 >= 0) {
        if (ptr1 >= 0 && arr1[ptr1] > arr2[ptr2]) {
            arr1[ptr3] = arr1[ptr1];
            ptr1--;
        } else {
            arr1[ptr3] = arr2[ptr2];
            ptr2--;
        }
        ptr3--;
    }

    return arr1;
}

vector<int> sort_binary_array(vector<int>& arr) {
    int zero_ptr = 0;
    int one_ptr = arr.size() - 1;

    while (zero_ptr < one_ptr) {
        if (arr[zero_ptr] == 1) {
            swap(arr[zero_ptr], arr[one_ptr]);
            one_ptr--;
        } else {
            zero_ptr++;
        }
    }

    return arr;
}

vector<int> sortColors(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else if (nums[mid] == 2) {
            swap(nums[mid], nums[high]);
            high--;
        }
    }

    return nums;
}

vector<int> evenFirst(vector<int>& nums) {
    int evenIdx = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 0) {
            swap(nums[i], nums[evenIdx]);
            evenIdx++;
        }
    }
    
    return nums;
}

vector<int> zeroLast(vector<int>& nums) {
    int zeroIdx = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[zeroIdx]);
            zeroIdx++;
        }
    }
    
    return nums;
}

#endif