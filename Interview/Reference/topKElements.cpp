/**
 * Top K elements algorithm, the best data structure to keep track
 * of ‘K’ elements is Heap.
 *
 * @Complexity
 *     Time         O(n)
 *     Space        O(k)
 *
 * @Identify:
 *     - If you’re asked to find the top/smallest/frequent ‘K’
 *     elements of a given set
 *     - If you’re asked to sort an array to find an exact element
 *
 * @Practice:
 *     - Top ‘K’ Numbers (easy)
 *     - Top ‘K’ Frequent Numbers (medium)
 */
int findKthLargest(const vector<int> &nums, const int &k) {
    priority_queue<int> minHeap;

    for (const auto &num : nums) {
        // Put first 'k' numbers in the min heap
        minHeap.push(num);

        // Go through the remaining numbers of the input array and
        // delete the top of the min heap at each iteration to have
        // the k lowest elements in the min heap
        if (minHeap.size() > k)
            minHeap.pop();
    }

    // The heap has 'k' lowest points, so, return the first one
    return minHeap.top();
}
