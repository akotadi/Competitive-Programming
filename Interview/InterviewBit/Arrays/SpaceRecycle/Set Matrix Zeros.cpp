/*
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1
Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.
 */



void Solution::setZeroes(vector<vector<int> > &A) {
    vector<bool> rows(A.size(), false);
    vector<bool> columns(A[0].size(), false);
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[0].size(); j++){
            if(A[i][j] == 0) rows[i] = columns[j] = true;
        }
    }
    for(int i = 0; i < rows.size(); i++){
        if(rows[i] == true){
            for(int j = 0; j < A[0].size(); j++){
                A[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < columns.size(); i++){
        if(columns[i] == true){
            for(int j = 0; j < A.size(); j++){
                A[j][i] = 0;
            }
        }
    }
    //for(auto it : rows) cout << it << " ";
    //cout << endl;
    //for(auto it : columns) cout << it << " ";
    //cout << endl;
}
