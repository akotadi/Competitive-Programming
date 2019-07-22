/*
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50
Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

 Warning : DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of Library functions will disqualify your submission retroactively and will give you penalty points.
 */



void Solution::nextPermutation(vector<int> &A) {
    auto start = A.begin();
    auto end = A.end();
    
    if(start == end) return;
    
    auto aux = start + 1;
    if(aux == end) return;
    
    aux = end - 1;
    while(true){
        auto last = aux;
        aux--;
        
        if(*aux < *last){
            auto check = end;
            while(*--check <= *aux) continue;
            
            iter_swap(aux, check);
            reverse(last, end);
            return;
        }
        if(aux == start) {
            reverse(start, end);
            return;
        }
    }
}
