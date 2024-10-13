/*
 * Assignment - 1: Design and Analysis of Algorithms (DAA)
 * Developer    : Sunay Bhoyar
 * Description  : 
 * This program includes both non-recursive and recursive implementations
 * to calculate Fibonacci numbers. Additionally, their time and space
 * complexities are analyzed for performance comparison.
 */

#include <iostream>
using namespace std ; 

// Recursive approach for the fibonacci calculation 
// Time Complexity - O(2^n) , Space Complexity - O(n)
long long fiboRecursion (long long n){
    if(n == 1 || n == 2){
        return 1 ; 
    }else if(n > 2){
        return fiboRecursion(n - 1) + fiboRecursion(n - 2) ;
    }else{
        return -1 ; 
    }
}


// itterative approach for the fibonacci calculation 
// Time Complexity - O(n) , Space Complexity - O(1)
long long fiboIterative(long long n){
    long long result = 1 ; 
    long long temp1 = 1 ; 
    long long temp2 = 1 ; 
    if(n <= 0){
        return -1 ; 
    }
    for (int i = 2 ; i < n ; i ++ ){
        result = temp1 + temp2 ; 
        temp2 = temp1 ; 
        temp1 = result ; 
    }
    return result ; 
}

int main (){

    // recursive testing  
    cout <<"recursive test for value n = -3 , expected value = -1, actual value = "<<fiboRecursion(-3) << endl ;
    cout <<"recursive test for value n =  1, expected value = 1, actual value = "<<fiboRecursion(1) << endl ;
    cout <<"recursive test for value n =  6, expected value = 8, actual value = "<<fiboRecursion(6) << endl ;

    // itterative testing
    cout <<"itterative test for value n = -3 , expected value = -1, actual value = "<<fiboIterative(-3) << endl ;
    cout <<"itterative test for value n = 1 , expected value = 1, actual value = "<<fiboIterative(1) << endl ;
    cout <<"itterative test for value n = 6 , expected value = 8, actual value = "<<fiboIterative(6) << endl ;
    return 0 ; 
}

