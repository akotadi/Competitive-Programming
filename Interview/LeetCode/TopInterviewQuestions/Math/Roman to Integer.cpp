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
    int romanToInt(string s) {
        string aux = "";
        int index = 0, result = 0;
        while(index < s.size()){
            if(s[index] == 'M'){
                while(index < s.size() && (s[index] == 'M')) aux += s[index++];
                result += parseThousands(aux);
                aux = "";
            }
            if(s[index] == 'C' || s[index] == 'D'){
                while(index < s.size() && (s[index] == 'C' || s[index] == 'D' || s[index] == 'M')) aux += s[index++];
                result += parseHundreds(aux);
                aux = "";
            }
            if(s[index] == 'X' || s[index] == 'L'){
                while(index < s.size() && (s[index] == 'X' || s[index] == 'L' || s[index] == 'C')) aux += s[index++];
                result += parseTens(aux);
                aux = "";
            }
            if(s[index] == 'I' || s[index] == 'V'){
                while(index < s.size() && (s[index] == 'I' || s[index] == 'V' || s[index] == 'X')) aux += s[index++];
                result += parseUnits(aux);
                aux = "";
            }
        }
        return result;
    }
private:
    int parseUnits(string s){
        if(s.size() == 0) return 0;
        if(s[0] == 'I'){
            if(s.size() == 1) return 1;
            if(s[1] == 'V') return 4;
            if(s[1] == 'X') return 9;
            return s.size();
        }else if(s[0] == 'V'){
            return (5 + (s.size() - 1));
        }
        return 0;
    }

    int parseTens(string s){
        if(s.size() == 0) return 0;
        if(s[0] == 'X'){
            if(s.size() == 1) return 10;
            if(s[1] == 'L') return 40;
            if(s[1] == 'C') return 90;
            return 10 * s.size();
        }else if(s[0] == 'L'){
            return 50 + (10 * (s.size() - 1));
        }
        return 0;
    }

    int parseHundreds(string s){
        if(s.size() == 0) return 0;
        if(s[0] == 'C'){
            if(s.size() == 1) return 100;
            if(s[1] == 'D') return 400;
            if(s[1] == 'M') return 900;
            return 100 * s.size();
        }else if(s[0] == 'D'){
            return 500 + (100 * (s.size() - 1));
        }
        return 0;
    }

    int parseThousands(string s){
        return s.size() * 1000;
    }
};