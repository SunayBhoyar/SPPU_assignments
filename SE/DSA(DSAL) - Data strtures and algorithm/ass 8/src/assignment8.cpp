#include<iostream>
using namespace std ;

class Node {
public:
  int val ;
  Node * next ;

  Node(int val_ = 0){
      val = val_ ;
      next = NULL ;
  }
};

class LinkedList{
public:
  Node* Start ;
  LinkedList(){
      Start = NULL;
  }

  void insert_start(int val){
     Node* new_node = new Node(val);
     if(Start == NULL){
         Start = new_node ;
     }
     else {
         new_node -> next = Start ;
         Start = new_node ;
     }
  }

  void insert_end(int val){
     Node* new_node = new Node(val);
     Node* temp = Start;
     if(temp == NULL){
    	 Start = new_node ;
     }
     else{
		 while(temp->next != NULL){
			 temp = temp -> next  ;
		 }
		 temp -> next = new_node ;

	  }
  }

  void insert_before(int bef , int val_){


	  Node* new_node = new Node(val_);
	  Node* temp = Start;
	  Node *prev ;

	  if(temp->val == bef){
		  new_node -> next = Start ;
		  Start = new_node ;
	      }
	  else{
		  while	(temp->val != bef ){
			  prev = temp ;
			  temp = temp->next ;
			  if(temp == NULL){
				  break ;
			  }
		  }
		  if(temp == NULL){
			  cout<<"Not in list"<<endl ;
		  }
		  else{
			  prev -> next = new_node ;
			  new_node -> next = temp ;
		  }

	  }
  }

  int search(int key){
	  Node *temp = Start ;
	  int iterator = 0 ;
	  while(temp != NULL){
		  if(temp->val == key){
			  return iterator;
		  }
		  else{
			  iterator ++ ;
			  temp = temp -> next ;
		  }
	  }
	  return -1 ;
  }

  void display_all(){
	  Node *temp = Start ;
	  while(temp != NULL ){
		  cout<<temp -> val <<endl;
		  temp = temp->next ;
	  }
  }
  void Union(LinkedList l1 ,LinkedList l2){
	  LinkedList temp ;
	  temp = l1 ;
	  Node *temp_ptr = l2.Start ;
	  while(temp_ptr != NULL){
		  if(temp.search(temp_ptr->val) == -1){
			  temp.insert_end(temp_ptr ->val);
		  }
		  temp_ptr = temp_ptr ->next ;
	  }
	  temp.display_all();
  }

  void Intersection(LinkedList l1 ,LinkedList l2){
      cout<<endl ;
	  LinkedList temp ;
	  Node *temp_ptr = l2.Start ;
	  while(temp_ptr != NULL){
		  if(l1.search(temp_ptr->val) != -1){
			  temp.insert_end(temp_ptr ->val);
		  }
		  temp_ptr = temp_ptr ->next ;
	  }
	  LinkedList temp2 ; 
	  temp_ptr = temp.Start ;

	  while(temp_ptr != NULL){
		  if(l1.search(temp_ptr->val) != -1){
		      temp2.insert_end(temp_ptr ->val);
		  }
		  temp_ptr = temp_ptr ->next ;
	  }
	  temp2.display_all();
  }

  void Symdiffreence(LinkedList l1 ,LinkedList l2){
	  LinkedList temp ;
	  	  Node *temp_ptr = l2.Start ;
	  	  while(temp_ptr != NULL){
	  		  if(l1.search(temp_ptr->val) != -1){
	  			  temp.insert_end(temp_ptr ->val);
	  		  }
	  		  temp_ptr = temp_ptr ->next ;
	  	  }
  	  LinkedList temp2 ;
  	  temp_ptr = l1.Start ;
  	  while(temp_ptr != NULL){
  		  if(temp.search(temp_ptr->val) == -1){
  			  temp2.insert_end(temp_ptr ->val);
  		  }
  		  temp_ptr = temp_ptr ->next ;
  	  }
  	  temp_ptr = l2.Start ;
  	  	  while(temp_ptr != NULL){
  	  		  if(temp.search(temp_ptr->val) == -1){
  	  			  temp2.insert_end(temp_ptr ->val);
  	  		  }
  	  		  temp_ptr = temp_ptr ->next ;
  	  	  }
  	  temp2.display_all();
    }
};

int main(){
	LinkedList obj ,obj2,obj3 ;
	obj.insert_end(10);
	obj.insert_end(20);
	obj.insert_end(30);
	obj2.insert_end(30);
	obj2.insert_end(40);

	while(1>0){
		int menu  ; 
		cout<<"1)students who like both ice cream\n2)students who like either but not both\nstudents who like \n0)Exit";
		cin >> menu ;
		if(menu == 0 ){
			break ;
		}
		else if(menu == 1){
			obj.Union(obj,obj2);
		}
		else if(menu == 2){
			obj.Symdiffreence(obj,obj2);
		}
		else if(menu == 3){
			cout<< 0 ;
		}
		else {
			cout<<"enter valid number"<<endl;
		}
	}
	return 1;
}