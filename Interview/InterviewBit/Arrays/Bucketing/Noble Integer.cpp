/*
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.
 */



int binarySearch(vector<int> &A, int left, int right){
    if(right < left) return -1;
    int mid = left + ((right - left) / 2);
    auto aux = upper_bound(A.begin(), A.end(), A[mid]);
    int greaters = (aux == A.end())?0:(A.size() - (aux - A.begin()));
    if(greaters == A[mid]) return 1;
    else if(greaters > A[mid]) return binarySearch(A, mid + 1, right);
    else return binarySearch(A, left, mid - 1);
}

int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    return binarySearch(A, 0, A.size() - 1);
}
