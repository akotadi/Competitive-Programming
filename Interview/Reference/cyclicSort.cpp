/**
 * Cyclic Sort algorithm, involves arrays containing numbers in a
 * given range, it iterates over the array one number at a time, and
 * if the current number you are iterating is not at the correct
 * index, you swap it with the number at its correct index.
 *
 * @Complexity
 *     Time         O(n)
 *     Space        O(1) - vector by copy, strictly is O(n)
 *
 * @Identify:
 *     - They will be problems involving a sorted array with numbers
 *     in a given range
 *     - If the problem asks you to find the missing / duplicate /
 *     smallest number in an sorted/rotated array
 *
 * @Practice:
 *     - Find the Missing Number (easy)
 *     - Find the Smallest Missing Positive Number (medium)
 */
int firstMissingPositive(vector<int> nums) {
    int n = nums.size();

    if (n == 0) return 1;

    // Iterate over the array
    for (int i = 0; i < n; i++) {
        // Swap the number if is in the range [1, n] to his
        // right place
        if (nums[i] > 0 && nums[i] <= n
            && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
            i--;
        }
    }

    // The first possible answer is 1
    int result = 1;

    while (result <= n) {
        // If the place isn't equal to the number, there is
        // the answer
        if (nums[result - 1] != result) return result;

        result++;
    }

    return result;
}
