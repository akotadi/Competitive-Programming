/**
 * Merge Intervals algorithm, efficient technique to deal with
 * overlapping intervals. In a lot of problems involving intervals,
 * you either need to find overlapping intervals or merge intervals
 * if they overlap.
 *
 * @Complexity
 *     Time         O(n)
 *     Space        O(n)
 *
 * @Identify:
 *     - If you’re asked to produce a list with only mutually
 *     exclusive intervals
 *     - If you hear the term “overlapping intervals”.
 *
 * @Practice:
 *     - Intervals Intersection (medium)
 *     - Maximum CPU Load (hard)
 */
vector<Interval> mergeIntervals(const vector<Interval> &intervals) {
    if (intervals.empty()) return {};

    auto result = vector<Interval>();

    sort(intervals.begin(), intervals.end(),
    [](Interval & a, Interval & b) {
        return (a.start == b.start) ?
               (a.end < b.end) : (a.start < b.start);
    });
    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (result.back().end < intervals[i].start)
            result.push_back(intervals[i]);
        else
            result.back().end =
                max(result.back().end, intervals[i].end);
    }

    return result;
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
