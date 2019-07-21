/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n < 2) return;
        
        rotateMatrix(matrix, 0, n);
    }
private: 
    void rotateMatrix(vector<vector<int>>& matrix, int index, int size){
        if(size < 2) return;
        
        if(size == 2){
            int aux = matrix[index][index];
            swap(aux, matrix[index][size-1 + index]);
            swap(aux, matrix[size-1 + index][size-1 + index]);
            swap(aux, matrix[size-1 + index][index]);
            swap(aux, matrix[index][index]);
        }else{
            for(int i = 0; i < size-1; i++){
                int aux = matrix[index][index + i];
                swap(aux, matrix[index + i][size-1 + index]);
                swap(aux, matrix[size-1 + index][size-1 - i + index]);
                swap(aux, matrix[size-1 - i + index][index]);
                swap(aux, matrix[index][index + i]);
            }
            rotateMatrix(matrix, index + 1, size - 2);
        }
    }
};