/*
 Fizzbuzz is one of the most basic problems in the coding interview world. Try to write a small and elegant code for this problem. 
Given a positive integer A, return an array of strings with all the integers from 1 to N. 
But for multiples of 3 the array should have “Fizz” instead of the number. 
For the multiples of 5, the array should have “Buzz” instead of the number. 
For numbers which are multiple of 3 and 5 both, the array should have “FizzBuzz” instead of the number.

Look at the example for more details.

Example

A = 5
Return: [1 2 Fizz 4 Buzz]
 */



vector<string> Solution::fizzBuzz(int A) {
    vector<string> result(A);
    for(int i = 1; i <= A; i++){
        //if(i % 15 == 0) result.emplace_back("FizzBuzz");
        //else if (i % 5 == 0) result.emplace_back("Buzz");
        //else if (i % 3 == 0) result.emplace_back("Fizz");
        //else result.emplace_back(to_string(i));
         result[i - 1] = (i % 15 == 0)?("FizzBuzz"):((i % 3 == 0)?("Fizz"):((i % 5 == 0)?("Buzz"):(to_string(i))));
    }
    return result;
}
