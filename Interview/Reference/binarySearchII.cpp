/**
 * Used to search for an element or condition which requires
 * accessing the current index and its immediate right neighbor's
 * index in the array.
 *
 * @Complexity
 *     Time         O(log n)
 *     Space        O(1)
 */
int binarySearchII(const vector<int> &nums, const int &target) {
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1;

    while (left < right) {
        // Prevent (left + right) overflow
        int mid = left + ((right - left) >> 1);

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target)  left = mid + 1;
        else  right = mid;
    }

    // Post-processing:
    // End Condition: left == right
    if (left != nums.size() && nums[left] == target) return left;

    return -1;
}
