/**
 * Used to search for an element or condition which can be
 * determined by accessing a single index in the array.
 *
 * @Complexity
 *     Time         O(log n)
 *     Space        O(1)
 *
 * @Identify:
 *     - If you're asked to find a certain element in an array,
 *     linked list, or matrix
 *
 * @Practice:
 *     - Order-agnostic Binary Search (easy)
 *     - Search in a Sorted Infinite Array (medium)
 */
int binarySearchI(const vector<int> &nums, const int &target) {
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        // Prevent (left + right) overflow
        int mid = left + ((right - left) >> 1);

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target)  left = mid + 1;
        else  right = mid - 1;
    }

    // End Condition: left > right
    return -1;
}
