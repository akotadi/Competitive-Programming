/**
 * Two Pointers algorithm, iterate through the data structure in
 * tandem until one or both of the pointers hit a certain condition.
 *
 * @Complexity
 *     Time         O(n)
 *     Space        O(1)
 *
 * @Identify:
 *     - It will feature problems where you deal with sorted arrays
 *     (or Linked Lists) and need to find a set of elements that
 *     fulfill certain constraints
 *     - The set of elements in the array is a pair, a triplet, or
 *     even a subarray
 *
 * @Practice:
 *     - Squaring a sorted array (easy)
 *     - Triplets that sum to zero (medium)
 *     - Comparing strings that contain backspaces (medium)
 */
vector<int> twoPointers(const vector<int> &nums, const int &trgt) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        // Comparing two numbers to the 'target' can cause overflow
        // so, try to find a target difference instead
        int targetDiff = trgt - nums[left];

        if (targetDiff == nums[right])
            // Found the pair
            return { left, right };

        if (targetDiff > nums[right])
            // Need a pair with a bigger sum
            left++;
        else
            // Need a pair with a smaller sum
            right--;
    }

    return { -1, -1 };
}
