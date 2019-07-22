/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]
 */



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

void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();
    if(n < 2) return;
    
    rotateMatrix(A, 0, n);
}
