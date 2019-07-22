/*
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index
*/



vector<int> Solution::maxset(vector<int> &A) {
    vector<int> result, aux;
    uint64_t maxSum = 0, partialSum = 0;
    for(auto number : A){
        if(number >= 0){
            partialSum += number;
            aux.emplace_back(number);
        }else if(!aux.empty()){
            if(partialSum > maxSum){
                maxSum = partialSum;
                result = aux;
            }else if(partialSum == maxSum){
                if(aux.size() > result.size()){
                    result = aux;
                }else if(aux.size() == result.size()){
                    if(aux[0] < result[0]){
                        result = aux;
                    }
                }
            }
            aux.clear();
            partialSum = 0;
        }
    }
    if(!aux.empty()){
        if(partialSum > maxSum){
            return aux;
        }else if(partialSum == maxSum){
            if(aux.size() > result.size()){
                return aux;
            }else if(aux.size() == result.size()){
                if(aux[0] < result[0]){
                    return aux;
                }
            }
        }
        return result;
    }else{
        return result;
    }
}
