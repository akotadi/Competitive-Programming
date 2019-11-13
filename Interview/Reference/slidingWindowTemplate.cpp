/**
 * Sliding Window algorithm, used to perform a required operation
 * on a specific window size of a given array or linked list, such
 * as finding the longest subarray containing all 1s.
 * Template to solve most of substring search problem.
 *
 * @Complexity
 *     Time         O(n)
 *     Space        O(n)
 *
 * @Identify:
 *     - The problem input is a linear data structure such as a
 *     linked list, array, or string
 *     - You’re asked to find the longest/shortest substring,
 *     subarray, or a desired value
 *
 * @Practice:
 *     - Maximum sum subarray of size ‘K’ (easy)
 *     - Longest substring with ‘K’ distinct characters (medium)
 *     - String anagrams (hard)
 */
vector<int> slidingWindowTemplate(const string &source,
                                  const string &target) {
    // Init a collection or int value to save the result according
    // the question.
    auto result = vector<int>();

    if (target.size() > source.size()) return result;

    // Create a hashmap to save the characters of the target.
    // (K, V) = (Character, Frequence of the characters)
    auto map = unordered_map<char, int>();

    for (const auto &c : target)
        map[c]++;

    // Maintain a counter to check whether match the target string,
    // must be the map size because the char may be duplicate.
    auto counter = map.size();
    // Two Pointers:
    //      begin - left pointer of the window;
    //      end - right pointer of the window
    auto begin{0}, end{0};
    // The length of the substring which match the target string.
    auto len{INT_MAX};

    // Loop at the begining of the source string
    while (end < source.size()) {
        // Get a character
        auto c = source[end];

        if (map.count(c)) {
            // Plus or minus one
            map[c]--;

            if (map[c] == 0)
                // Modify according the requirement
                // (different condition)
                counter--;
        }

        end++;

        // Increase begin pointer to make it invalid/valid again.
        // Counter condition: different question may have
        // different condition
        while (counter == 0) {
            // Be careful: choose the char at begin, NOT the end
            auto tempc = source[begin];

            if (map.count(tempc)) {
                // Plus or minus one
                map[tempc]++;

                if (map[tempc] > 0)
                    // Modify according the requirement
                    // (different condition)
                    counter++;
            }

            /* save / update(min/max) the result if find a target*/
            // Result collections or result int value
            begin++;
        }
    }

    return result;
}
