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
    uint32_t reverseBits(uint32_t n) {
        int result = 0;
        for(int i = 0; i < 16; i++){
            bool lsb = (n & (1 << i)), msb = (n & (1 << (31 - i)));
            // cout << "Iteracion " << i << "= " << lsb <<" : " << msb << endl;
            result |= (lsb << (31 - i));
            result |= (msb << i);
        }
        return result;
    }
};