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
    int myAtoi(string str) {
        int n = str.size();
        
        if(n == 0) return 0;
        
        int i = 0;
        bool flag = false;
        while(i < n && str[i] == ' ') i++;
        // All the characters are whitespaces
        if(i == n) return 0;
        // The number is negative
        if(str[i] == '-'){
            flag = true;
            i++;
        }else if(str[i] == '+') i++;
        // If not number, the answer is not possible
        if(!isdigit(str[i])) return 0;
        while(i < n && isdigit(str[i])){
            if(str[i] == '0') i++;
            else break;
        }
        if(i == n) return 0;
        if(!isdigit(str[i])) return 0;
        // We check where is the end of the number
        int j = i+1;
        while(j < n){
            if(isdigit(str[j])) j++;
            else break;
        }
        
        // Overflow the integer by digits
        if(j - i >= 11) return ((flag)?(INT_MIN):(INT_MAX));
        
        int64_t aux = 0;
        while(i < j) aux = ((aux*10) + (str[i++] - '0'));
        
        if(flag){
            aux *= -1;
            if(aux < INT_MIN) return INT_MIN;
            else return aux;
        }else if(aux > INT_MAX) return INT_MAX;
        else return aux;
    }
};