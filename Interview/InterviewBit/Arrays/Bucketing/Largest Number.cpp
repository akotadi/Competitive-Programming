/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
 */



bool cmp (int i,int j) {
    string a = to_string(i), b = to_string(j);
    string ab = a + b, ba = b + a;
    return ab > ba;
}

string Solution::largestNumber(const vector<int> &A) {
    string result = "";
    vector<int> B = A;
    sort(B.begin(), B.end(), cmp);
    for(auto number : B) result += to_string(number);
    if(result[0] == '0') return "0";
    return result;
}
