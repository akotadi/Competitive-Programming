/**
 * Used to search for an element or condition which requires accessing
 * the current index and its immediate left and right neighbor's index
 * in the array.
 *
 * @Complexity
 *     Time         O(log n)
 *     Space        O(1)
 */
int binarySearchIII(const vector<int> &nums, const int &target) {
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1;

    while (left + 1 < right) {
        // Prevent (left + right) overflow
        int mid = left + ((right - left) >> 1);

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid;
        else
            right = mid;
    }

    // Post-processing:
    // End Condition: left + 1 == right
    if (nums[left] == target) return left;

    if (nums[right] == target) return right;

    return -1;
}
