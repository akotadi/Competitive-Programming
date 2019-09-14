/*
 * Copyright (c) 2019 ManuelCH.
 *
 * This file is part of Interview-solutions 
 * (see https://github.com/akotadi).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
class Solution {
public:
    Solution(vector<int>& w) {
        values.resize(w.size(), 0);
        totalSum = 0;
        for (const int& num : w) 
            totalSum += num;
        for (int i = 1; i < w.size(); i++) 
            values[i] = values[i-1] + w[i-1];
        mt_rand.seed(chrono::high_resolution_clock::now().time_since_epoch().count());
    }
    
    int pickIndex() {
        int location = mt_rand() % totalSum;
        auto it = lower_bound (values.begin(), values.end(), location);
        if (it == values.end() || (*it != location && it != values.begin()))
            it--;
        return it - values.begin();
    }
private:
    vector<int> values;
    mt19937 mt_rand;
    int totalSum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
