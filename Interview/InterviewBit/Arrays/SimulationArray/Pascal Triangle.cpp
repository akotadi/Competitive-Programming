/*
Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
*/



vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> result;
    
    if(A == 0) return result;
    
    result.resize(A);
    vector<int> aux;
    aux.emplace_back(1);
    result[0] = aux;
    int counter = 2;
    for(int i = 1; i < A; i++, counter++){
        aux.clear();
        for(int j = 0; j < counter; j++){
            if(j == 0 || j == counter - 1) aux.emplace_back(1);
            else aux.emplace_back(result[i - 1][j] + result[i - 1][j - 1]);
        }
        result[i] = aux;
    }
    
    return result;
}
