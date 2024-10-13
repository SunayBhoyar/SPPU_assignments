/*
 * Assignment - 3: Design and Analysis of Algorithms (DAA)
 * Developer    : Sunay Bhoyar
 * Description  : 
 * Knapsack problem using dynamic programming or branch and
 * bound strategy.
 */

#include <iostream>
#include <string>
#include <queue>

using namespace std ; 

int knapsackDP(string item_list[] , int weight[] , int  value[], int capacity, int items){
    int DP[items+1][capacity+1] ; 
    for (int i = 0 ; i <= items ;  i ++ ){
        DP[0][i] = 0 ;
    }
    for (int i = 0 ; i <= capacity ;  i ++ ){
        DP[i][0] = 0 ;
    }
    for (int i = 1 ; i <= items ; i ++){
        for (int j = 1 ; j <= capacity ; j ++){
            if ((j-weight[i-1]) >= 0){
                DP[i][j] = max ( DP[i-1][j],value[i-1] + DP[i-1] [j-weight[i-1]]) ;
            }else{
                DP[i][j] = DP[i-1][j] ; 
            }
        }
    }
    return DP[items][capacity] ;
    
}


int main(){
    string item_list[] = {"1","2","3","4"};
    int weight[] = {2,3,4,5} ;
    int value[] = {3,4,5,6} ;  
    int capacity = 5 ;
    int items = 4;
    cout << knapsackDP(item_list , weight , value, capacity,items) ;
    return 0 ; 
}