/*
 * Assignment - 2: Design and Analysis of Algorithms (DAA)
 * Developer    : Sunay Bhoyar
 * Description  : 
 * To Implement Huffman Encoding using a greedy strategy.
 */

#include <iostream>
#include <string>
#include <queue>

using namespace std ; 

struct Node {
    int freq ; 
    string symbol ; 
    Node* left ; 
    Node* right ;

    Node(int freq_ = 0, string symbol_ = "", Node* left_ = NULL , Node* right_ = NULL){
        freq = freq_ ;
        symbol = symbol_ ; 
        left = left_ ;
        right = right_ ; 
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; 
    }
};

void printData(Node* curr , string code){
    if(curr->symbol.size() == 1){
        cout << curr->symbol << " : "<<code <<endl ; 
    }else{
        printData(curr->left, code+"0");
        printData(curr->right, code+"1");
    }
}

void printHuffmanCode(int freq_table[] , string symbol_table[], int N){
    priority_queue<Node*, vector<Node*>, Compare> pq ; 

    for (int i = 0 ; i < N ; i ++){
        Node* new_node = new Node(freq_table[i] , symbol_table[i]) ;
        pq.push(new_node) ;
    }

    while(pq.size() > 1){
        Node* temp1 = pq.top() ; pq.pop() ;
        Node* temp2 = pq.top() ; pq.pop() ;

        string new_node_symbol = temp1->symbol + temp2->symbol ;
        int new_node_freq = temp1->freq + temp2->freq ;

        Node* new_node_min = new Node(new_node_freq , new_node_symbol ,temp1,temp2) ;
        pq.push(new_node_min) ;
    }

    Node* root = pq.top() ; pq.pop() ;
    printData(root,"");
}

int main (){
    int N ; 
    cout << "enter the size of the array " ;

    string symbol_table[] = {"a", "b" , "c" , "d" ,"e" ,"f"} ;
    int freq_table [] = {5 ,9 , 12 , 13 , 16 , 45} ;
    printHuffmanCode(freq_table,symbol_table,6);
    return 0 ;
}