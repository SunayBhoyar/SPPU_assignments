// Sunay Bhoyar
// 21110 SE 1
// 27/04/2023

#include<iostream>
#include<string>
#include<vector>
using namespace std ;


template<class T>
class queue{
		T arr[20];
		int front;
		int rear;
	public:

		queue(){
			front=-1;
			rear=-1;
		}

		bool isfull(){
			if(rear==19){
				return true;
			}
			else{
				return false;
			}
		}

		bool isempty(){
			if(front==rear && rear==-1){
				return true;
			}
			else{
				return false;
			}
		}

		void push(T x){
			if(isfull()){
				cout<<"Queue is full"<<endl;
			}
			else if(isempty()){
				front++;
				rear++;
				arr[rear]=x;
			}
			else{
				rear++;
				arr[rear]=x;
			}
		}
		T pop(){
			if(isempty()){
				cout<<"Queue is empty"<<endl;
				return NULL ;
			}
			else if(front==rear){
				T res =  arr[front];
				front=-1;
				rear=-1;
				return res ;
			}
			else{
				T res  = arr[front];
				front=front+1;
				return res ;
			}
		}
};
template<class T>
class stack{
	int top;
	T arr[20];
public:
	bool isempty(){
		if(top==-1){
			return true;
		}
		return false;

	};
	bool isfull(){
		if(top==19){
			return true;
		}
		return false;
	};
	void push(T x){
		if(isfull()){
			cout<<"stack is full"<<endl;
		}
		else{
			top++;
			arr[top]=x;
		}
	}
	T pop(){
		if(isempty()){
			cout<<"Stack is empty"<<endl;
			return NULL ;
		}
		else{
			top--;
			return arr[top+1];
		}
	}

	stack(){
		top=-1;
	}

};

class Node{

public:
	int value ;
//	string value ;
	Node* next ;
	Node(int value_ = 0){
		value = value_ ;
		next = NULL ;
//		value = value_ ;
	}
};

class Graph{
	int verticesNumber ;
	int edgeNumber ;
	int** vertices ;
//	bool* visited ;

public:
	void createGraph(){
		cout<<"enter the number of vertices in graph"<<endl;
		cin>>verticesNumber ;
		cout<<"enter the number of edges in graph"<<endl;
		cin>>edgeNumber ;
		vertices = new int*[verticesNumber];
		for (int i = 0 ; i < verticesNumber ; i ++){
			vertices[i] = new int[verticesNumber];
		}

		for (int i = 0 ; i < verticesNumber ; i ++ ){
			for (int j = 0 ; j < verticesNumber ; j ++ ){
				vertices[i][j] = 0 ;
			}
		}

		for (int i = 0 ; i < edgeNumber ; i ++ ){
			int  vertex1=0 , vertex2=0 , cost=0 ;
			cout<< "enter the edges"<<endl<<"enter vertex1"<<endl ;
			cin >> vertex1 ;
			cout<<"enter vertex2"<<endl ;
			cin >> vertex2 ;
			cout<<"enter the cost of edge"<<endl ;
			cin >> cost ;
			vertices[vertex1][vertex2] = cost ;
			vertices[vertex2][vertex1] = cost ;
		}
	}

void primsAlgorithm(int v1){

	// debug
	verticesNumber = 4 ;
	edgeNumber = 5 ;

	int vertices1[4][4] = {{0,10,3,4},{10,0,2,0},{3,2,0,5},{4,0,5,0}};
	for (int i = 0 ; i < verticesNumber ; i ++ ){
		for (int j = 0 ; j < verticesNumber ; j ++ ){
			cout<< vertices1[i][j] << " ";
		}
		cout<<endl ;
	}
	// debug

    int count = 0;
    int count1 = 0 ;
    int min = 999 ;
    int t1=0 ,t2=0 ;
    int root_temp1=0 ,root_temp2=0 ;
    int* father = new int [verticesNumber] ;
    int* visited = new int [verticesNumber] ;
    for (int i = 0 ; i < verticesNumber ; i ++){
        father[i] = -1 ;
        visited[i] = 0 ;
    }
    int** Res = new int*[verticesNumber];
    for (int i = 0 ; i < verticesNumber ; i ++){
        Res[i] = new int[verticesNumber];
    }

    for (int i = 0 ; i < verticesNumber ; i ++ ){
        for (int j = 0 ; j < verticesNumber ; j ++ ){
            Res[i][j] = 0 ;
        }
    }
    int weight = 0 ;

    visited[count1] =  v1;
    count1++ ;
    while(count<verticesNumber-1){
        min = 999;
        for(int v1 = 0 ; v1 < count1 ; v1++){
            for(int v2 = 0 ; v2 < verticesNumber ; v2 ++){
                if(vertices1[visited[v1]][v2]!= 0 && vertices1[visited[v1]][v2] < min){
                    min = vertices1[visited[v1]][v2] ;
                    t1 = visited[v1] ;
                    t2 = v2 ;
                }
            }
        }
        int temp1 = t1 ;
        int temp2 = t2 ;

        vertices1[t1][t2] = 0 ;
        vertices1[t2][t1] = 0 ;
        while(t1>=0){
            root_temp1 = t1 ;
            t1 = father[t1] ;
        }
        while(t2>=0){
            root_temp2 = t2 ;
            t2 = father[t2] ;
        }
        if(root_temp1 != root_temp2){
            Res[temp1][temp2] = min ;
            Res[temp2][temp1] = min ;
            cout<<"The Edge selected is - ("<<temp1<<" , "<<temp2<<") with weight - "<<min<<endl;
            weight += min ;
            father[root_temp2] = root_temp1 ;
            count++ ;
            visited[count1-1] = temp2 ;
            count1 ++ ;
        }

    }
    cout<<"The min weight is - "<<weight<<endl ;
    // debug

    cout<<endl;
    for (int i = 0 ; i < verticesNumber ; i ++ ){
		for (int j = 0 ; j < verticesNumber ; j ++ ){
			cout<< Res[i][j] << " ";
		}
		cout<<endl ;
	}
    // debug
}
void kruskalAlgorithm(){

	// debug
	verticesNumber = 4 ;
	edgeNumber = 5 ;

	int vertices1[4][4] = {{0,10,3,4},{10,0,2,0},{3,2,0,5},{4,0,5,0}};
	for (int i = 0 ; i < verticesNumber ; i ++ ){
		for (int j = 0 ; j < verticesNumber ; j ++ ){
			cout<< vertices1[i][j] << " ";
		}
		cout<<endl ;
	}
	// debug

    int count = 0;
    int min = 999 ;
    int t1=0 ,t2=0 ;
    int root_temp1=0 ,root_temp2=0 ;
    int* father = new int [verticesNumber] ;
    for (int i = 0 ; i < verticesNumber ; i ++){
        father[i] = -1 ;
    }
    int** Res = new int*[verticesNumber];
    for (int i = 0 ; i < verticesNumber ; i ++){
        Res[i] = new int[verticesNumber];
    }

    for (int i = 0 ; i < verticesNumber ; i ++ ){
        for (int j = 0 ; j < verticesNumber ; j ++ ){
            Res[i][j] = 0 ;
        }
    }
    int weight = 0 ;

    while(count<verticesNumber-1){
        min = 999;
        for(int v1 = 0 ; v1 < verticesNumber ; v1++){
            for(int v2 = 0 ; v2 < verticesNumber ; v2 ++){
                if(vertices1[v1][v2]!= 0 && vertices1[v1][v2] < min){
                    min = vertices1[v1][v2] ;
                    t1 = v1 ;
                    t2 = v2 ;
                }
            }
        }

        int temp1 = t1 ;
        int temp2 = t2 ;

        vertices1[t1][t2] = 0 ;
        vertices1[t2][t1] = 0 ;
        while(t1>=0){
            root_temp1 = t1 ;
            t1 = father[t1] ;
        }
        while(t2>=0){
            root_temp2 = t2 ;
            t2 = father[t2] ;
        }
        if(root_temp1 != root_temp2){
            Res[temp1][temp2] = min ;
            Res[temp2][temp1] = min ;
            cout<<"The Edge selected is - ("<<temp1<<" , "<<temp2<<") with weight - "<<min<<endl;
            weight += min ;
            father[root_temp2] = root_temp1 ;
            count++ ;
        }

    }
    cout<<"The min weight is - "<<weight<<endl ;
    // debug
    cout<<endl;
    for (int i = 0 ; i < verticesNumber ; i ++ ){
		for (int j = 0 ; j < verticesNumber ; j ++ ){
			cout<< Res[i][j] << " ";
		}
		cout<<endl ;
	}
    // debug
}
	void print(){
		for (int i = 0 ; i < verticesNumber ; i ++ ){
			for (int j = 0 ; j < verticesNumber ; j ++ ){
				cout<< vertices[i][j] << " ";
			}
			cout<<endl ;
		}
	}

};

int main(){
	Graph G ;
//	G.createGraph();
//	G.print();
	cout<<"solution by prims algorithm"<<endl;
	G.primsAlgorithm(0);
	cout<<"solution by Kruskals algorithm"<<endl;
	G.kruskalAlgorithm();
	cout<<"done";
}





