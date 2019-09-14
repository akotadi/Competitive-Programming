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
/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        
        // For all the rows, check if a number is twice with bitmask
        for(int i = 0; i < n; i++){
            int16_t check = 0;
            for(int j = 0; j < m; j++){
                if(board[i][j] != '.'){
                    if(check & (1 << (board[i][j] - '0'))) return false;
                    else check |= (1 << (board[i][j] - '0'));
                }
            }
        }
        
        // For all the columns, check if a number is twice with bitmask
        for(int i = 0; i < n; i++){
            int16_t check = 0;
            for(int j = 0; j < m; j++){
                if(board[j][i] != '.'){
                    if(check & (1 << (board[j][i] - '0'))) return false;
                    else check |= (1 << (board[j][i] - '0'));
                }
            }
        }
        
        // For all the squares 3x3, check if a number is twice with bitmask
        for(int i = 0; i < n; i+=3){
            for(int j = 0; j < m; j+=3){
                if(!validTail(board, i, j)) return false;
            }
        }
        
        return true;
    }
private:
    bool validTail(vector<vector<char>>& board, int row, int column){
        int16_t check = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[row+i][column+j] != '.'){
                    if(check & (1 << (board[row+i][column+j] - '0'))) return false;
                    else check |= (1 << (board[row+i][column+j] - '0'));
                }
            }
        }
        
        return true;
    }
};