// Project 1-1
// Fibonnachi Memoizatoin : Recursion
// Fibonacci.hpp

#include <iostream>
using namespace std;

static int recurFuncCount = 0;
static int recurFuncCountMemoization = 0;

// ASSUME that N is always < 50
#define MAX_SIZE 50
static int memoization[MAX_SIZE + 1];


int NaiveFibonacci(int n) {
    recurFuncCount++; // <- Do NOT edit nor move this instruction

    if (n == 0 || n == 1)
        return 1;
    else
        return NaiveFibonacci(n - 1) + NaiveFibonacci(n - 2);
}


int FibonacciMemoization(int n) {
    recurFuncCountMemoization++; // <- Do NOT edit nor move this instruction
    if (n == 0 || n == 1) return 1;

    if (memoization[n] > 0) return memoization[n];
    else {
        memoization[n] = FibonacciMemoization(n - 1) + FibonacciMemoization(n - 2);
        return memoization[n];
    }

}
/*
int main() {
    for (int i = 0; i < MAX_SIZE + 1; i++) {
        memoization[i] = -1;
    }

    FibonacciMemoization(44);
    cout << "FibonacciMemoization has been invoked " << recurFuncCountMemoization << " times" << endl;

    NaiveFibonacci(44);
    cout << "NaiveFibonacci has been invoked " << recurFuncCount << " times" << endl; // �̰� int���� overflow��.

    return 0;
}
*/
