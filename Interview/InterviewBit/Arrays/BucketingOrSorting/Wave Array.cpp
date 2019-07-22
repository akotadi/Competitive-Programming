/*
Given an array of integers, sort the array into a wave like array and return it, 
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
 NOTE : If there are multiple answers possible, return the one thats lexicographically smallest. 
 So, in example case, you will return [2, 1, 4, 3] 
 */



vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<int> result;
    for(int i = 0, j = 1; i < A.size() || j < A.size(); i+=2, j+=2){
        if(j == A.size()){
            result.emplace_back(A[i]);
        }else{
            result.emplace_back(A[j]);
            result.emplace_back(A[i]);
        }
    }
    return result;
}
