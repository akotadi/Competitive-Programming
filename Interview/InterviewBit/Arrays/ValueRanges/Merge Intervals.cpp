/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.
*/



/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;
    bool search = true, end = false;
    Interval overlap;
    if(newInterval.end < newInterval.start){
        newInterval.start ^= newInterval.end;
        newInterval.end ^= newInterval.start;
        newInterval.start ^= newInterval.end;
    }
    for(auto it : intervals){
        // cout << "Checking... " << it.start << " : " << it.end << endl;
        if(search){
            if (newInterval.start <= it.start){
                overlap.start = newInterval.start;
                search = false;
            }else if(newInterval.start <= it.end){
                overlap.start = it.start;
                search = false;
            }else{
                result.emplace_back(it);
            }
        }
        if(!end){
            if (newInterval.end < it.start){
                overlap.end = newInterval.end;
                end = true;
                result.emplace_back(overlap);
                result.emplace_back(it);
            }else if(newInterval.end == it.start || newInterval.end <= it.end){
                overlap.end = it.end;
                end = true;
                result.emplace_back(overlap);
            }
        }else{
            result.emplace_back(it);
        }
    }
    if(search){
        result.emplace_back(newInterval);
    }else if(!end){
        overlap.end = newInterval.end;
        result.emplace_back(overlap);
    }
    return result;
}
