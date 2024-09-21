#include<iostream>
#include<cstdlib>

using namespace std ; 

template<class T>
    void selection_sort(T arr[] ,int N){
        for (int i = 0 ; i < N-1 ; i++){
            T temp = arr[i] ;
            int min_index = i;
            for (int j = i + 1 ; j < N  ; j++){
                if(arr[j] < temp ){
                    min_index = j ;
                    temp = arr[j];
                }
            }
            // cout<<arr[min_index]<<endl;
            T swap_temp = arr[i];
            arr[i] = arr[min_index] ;
            arr[min_index] = swap_temp ;
        }
    }
int main(){
    int data[] = {6,2,4,3};
    selection_sort(data,4);
    float data1[] = {1.5, 1.4 , 4.6 ,3.7};
    selection_sort(data1,4);
    for (int i = 0 ; i < 4 ;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
    for (int i = 0 ; i < 4 ;i++){
        cout<<data1[i]<<" ";
    }
}