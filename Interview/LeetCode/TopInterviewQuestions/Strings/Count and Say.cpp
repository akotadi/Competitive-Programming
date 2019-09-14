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
    string countAndSay(int n) {
        if(n < 2) return "1";
        
        string last = "1";
        for(int i = 2; i <= n; i++){
            string aux = "";
            char check = 'a';
            int counter = 0;
            for(auto c : last){
                if(c != check){
                    if(counter != 0){
                        aux += (counter + '0');
                        aux += check;
                    }
                    counter = 0;
                    check = c;
                    counter++;
                }else counter++;
            }
            if(counter){
                aux += (counter + '0');
                aux += check;
            }
            
            last = aux;
        }
        
        return last;
    }
};