//Happy Number
/*
A happy number
n is a positive integer defined by the following process:

Starting with 
n, replace it with the sum of the squares of its digits.
Repeat the process until the number reaches 1 (where it will stay in eternal happiness), or repeats in an infinite loop that does not include 1.
Those numbers for which this process ends in 1 are happy numbers.
For example, 23 is a happy number: 23 -> 13 -> 10 -> 1 -> 1.

However, 89 is not a happy number (cycle in bold): 89 -> 145 -> 42 -> 20 -> 4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4

Given two numbers 
a, b return the number of happy numbers between a and b (inclusive).

Standard Input
Each test contains two space separated integers a, b

Standard Output
For each test case, output a single integer, the number of happy numbers between a and b (inclusive).

Constraints
1≤a≤b≤10^16
 
Input
1 44
Output : 10
Explanation: There are 10 happy numbers between 1 and 44 (inclusive):

1, 7, 10, 13, 19, 23, 28, 31, 32, 44
*/
#include <iostream>
#include <unordered_set>

// Function to calculate the sum of the squares of digits
int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

// Function to check if a number is a happy number
bool isHappy(int n) {
    std::unordered_set<int> seen;
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = sumOfSquares(n);
    }
    return n == 1;
}

// Function to count the happy numbers between a and b
int countHappyNumbers(int a, int b) {
    int count = 0;
    for (int i = a; i <= b; i++) {
        if (isHappy(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    int result = countHappyNumbers(a, b);
    std::cout << result << std::endl;
    return 0;
}
