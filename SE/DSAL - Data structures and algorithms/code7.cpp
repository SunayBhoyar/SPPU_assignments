Sunay Bhoyar																				ASS 1
#include<iostream>
#include<string>
using namespace std ;

class Node{
private :
	string word ;
	string meaning ;
	Node* left ;
	Node* right ;
public:
	Node(string word_ ="",string meaning_ =""){
		word = word_ ;
		meaning = meaning_ ;
		left = NULL ;
		right = NULL ;
	}

	friend class BST ;
};
class BST{
private:
	Node* root ;

public:


	BST(){
			root = NULL ;
		}
	void insert(string word , string meaning){
		Node* new_node = new Node(word , meaning);
		if(root == NULL){
			root = new_node ;
		}
		else {
			Node* curr = root ;
			Node* parent = NULL;
			while(curr!=NULL){
				if(word<curr->word){
					parent = curr ;
					curr = curr -> left ;
				}
				else{
					parent = curr ;
					curr = curr -> right ;
				}
			}
			if(word < parent->word){
				parent->left = new_node ;
			}
			else{
				parent->right = new_node ;
			}
		}
	}
	Node* get(){
		return root ;
	}
	bool search(string key,Node* &current, Node* &parentin){
		Node* curr = root ;
		int counter = 0 ;
		while(curr!=NULL){
			counter++ ;
			if(curr ->word == key){
				cout<<"the element found after - "<<counter<<" iterations"<<endl ;
				current = curr ;
				return true ;
			}
			else if (key < curr ->word ){
				parentin =  curr ;
				curr = curr->left ;
			}
			else{
				parentin = curr ;
				curr = curr->right ;
			}
		}
		parentin = NULL ;
		current = NULL ;
		return false ;
	}

	void remove(string x){
		Node* curr = NULL ;
		Node* parent = NULL ;
		Node* child = NULL;
		this->search(x,curr,parent);
		if(curr == NULL){
			cout<<"the element not present";
			return ;
		}
		if(curr->left != NULL && curr->right != NULL){
			Node* temp = curr->right ;
			while(temp->left!=NULL){
				temp = temp ->left ;
			}

			string strword = temp->word ;
			string strmeaning = temp->meaning ;
			this->remove(strword);
			curr->word = strword ;
			curr->meaning = strmeaning ;
		}
		else{
			if(curr->left != NULL){
				child = curr->left ;
			}
			else if(curr->right != NULL){
				child = curr->right ;
			}
			else {
				child = NULL ;
			}

			if(x<parent->word){
				parent->left = child ;
			}
			else{
				parent->right = child ;
			}
			delete curr ;
		}

	}

	void update(string key , string new_meaning){
			Node* curr = root ;
			while(curr!=NULL){
				if(curr ->word == key){
					curr->meaning = new_meaning ;
					return;
				}
				else if (key < curr ->word ){
					curr = curr->left ;
				}
				else{
					curr = curr->right ;
				}
			}
			cout<<"the element not found"<<endl ;
		}

	void  inorder(Node* n){
		if(n != NULL){
			inorder(n->left);
			cout<<n->word<<" - "<<n->meaning<<endl ;
			inorder(n->right);
		}
	}
	void  inorderR(Node* n){
		if(n != NULL){
			inorderR(n->right);
			cout<<n->word<<" - "<<n->meaning<<endl ;
			inorderR(n->left);
		}
	}
};

int main(){
	BST L ;
	while(true){
		int  menu ;
		cout<<"\n1)insert 2)print 3)print reverse 4)update 5)search 6)remove 0)Exit"<<endl;
		cin>>menu ;
		if(menu == 1){
			cout<<endl<<"Enter the word you want to enter"<<endl ;
			string word_ ;
			cin>>word_ ;
			cout<<endl<<"Enter the meaning of word"<<endl ;
			string meaning_ ;
			cin>>meaning_ ;
			L.insert(word_,meaning_);
		}
		else if(menu == 2){
			L.inorder(L.get());
		}
		else if(menu == 3){
			L.inorderR(L.get());
		}
		else if(menu == 4){
			cout<<endl<<"Enter the word you want to update"<<endl ;
			string word_ ;
			cin>>word_ ;
			cout<<endl<<"Enter the new meaning of word"<<endl ;
			string meaning_ ;
			cin>>meaning_ ;
			L.update(word_,meaning_);
		}
		else if(menu == 5){
			cout<<endl<<"Enter the word you want to search"<<endl ;
			string word_ ;
			cin>>word_ ;
			Node* curr = NULL ;
			Node* parent = NULL ;
			L.search(word_,curr,parent);
		}
		else if(menu == 6){
			cout<<endl<<"Enter the word you want to delete"<<endl ;
			string word_ ;
			cin>>word_ ;
			L.remove(word_);
		}
		else if(menu == 0){
			break ;
		}
		else {
			cout<<"enter valid input"<<endl ;
		}

	}
	return 1 ;
}

Sunay Bhoyar																				ASS 2
#include<iostream>
using namespace std ;
															// Queue class
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
															// Stack Class
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

															// Node Class
class Node{
private :
	int data ;
	Node* lc ;
	Node* rc ;
public:
	Node(int data_){
		data = data_ ;
		lc = NULL ;
		rc = NULL ;
	}

	friend class BT ;
};
															// BST Class

class BT{
private:
	Node* root ;
public:
	BT(){
		root = NULL ;
	}
															// all itterative meathods ->
	void createItr(){
		queue <Node*> Q ;
		cout<<"Enter Root node value"<<endl;
		int temp ;
		cin>>temp ;
		Node* new_node = new Node(temp) ;
		root = new_node ;
		Q.push(new_node);
		while(!Q.isempty()){
			Node* retrive = Q.pop() ;
			cout<<"Enter the left child value of node child to "<<retrive->data<<endl ;
			cin>>temp ;
			if(temp != -1 ){
				Node * new_node = new Node(temp);
				retrive->lc = new_node ;
				Q.push(new_node);
			}
			cout<<"Enter the right child value of node child to "<<retrive->data<<endl ;
			cin>>temp ;
			if(temp != -1 ){
				Node * new_node = new Node(temp);
				retrive->rc = new_node ;
				Q.push(new_node);
			}
		}

	}

	void preItr(Node *n){
		stack<Node*> s ;
		s.push(n);
		Node* temp = NULL ;
		while(!s.isempty()){
			temp = s.pop();
			cout<<temp->data<<" ";
			if(temp->lc != NULL){
				s.push(temp->lc);
			}
			if(temp->lc != NULL){
				s.push(temp->lc);
			}
		}
	}
	void printPreItr(){
		preItr(root);
	}

	void inoItr(Node* n){
		stack<Node*> s ;
		s.push(n);
		Node* temp = n ;
		while(!s.isempty()){
			while( temp->lc!= NULL){
				s.push(temp->lc);
				temp = temp ->lc ;
			}
			temp = s.pop();
			cout<<temp->data<<" ";
			if(temp->rc!=NULL){
				temp = temp -> rc ;
			}
		}
	}
	void printInoItr(){
		inoItr(root);
	}

	void posItr(Node* n){
		stack<Node*> s1 ;
		stack<Node*> s2 ;
		Node* temp = n ;
		s1.push(n);
		while(!s1.isempty()){
			temp = s1.pop();
			s2.push(temp);
			if(temp->lc != NULL){
				s1.push(temp->lc);
			}
			if(temp->rc != NULL){
				s1.push(temp->rc);
			}
		}
		while(!s2.isempty()){
			temp = s2.pop();
			cout<<temp->data<<" ";
		}
	}
	void printPosItr(){
		posItr(root);
	}

															// all recursive meathods ->
	void createRecursive(){
		cout<<"Enter Root node value"<<endl;
		int temp ;
		cin>>temp ;
		Node* new_node = new Node(temp) ;
		root = new_node ;
		creater(new_node);

	}
	void creater(Node* giv){
			int temp1 ;
			cout<<"Enter the left child value of node child to "<<giv->data<<endl ;
			cin>>temp1 ;
			if(temp1 != -1 ){
				Node * new_node = new Node(temp1);
				giv->lc = new_node ;
				creater(new_node);
			}
			cout<<"Enter the right child value of node child to "<<giv->data<<endl ;
			cin>>temp1 ;
			if(temp1 != -1 ){
				Node * new_node = new Node(temp1);
				giv->rc = new_node ;
				creater(new_node);
			}
		}
	void  inorderR(Node* n){
			if(n != NULL){
				inorderR(n->lc);
				cout<<n->data<<endl ;
				inorderR(n->rc);
			}
		}
	void printIR(){
		inorderR(root);
	}
	void  postR(Node* n){
			if(n != NULL){
				postR(n->lc);
				postR(n->rc);
				cout<<n->data<<endl ;
			}
		}
	void printporR(){
		postR(root);
	}
	void  preR(Node* n){
			if(n != NULL){
				cout<<n->data<<endl ;
				preR(n->lc);
				preR(n->rc);
			}
		}
	void printpreR(){
		preR(root);
	}
};

int main(){
	BT L ;
	int menu,menu1,menu2 ;
	while(true){
		cout<<"\n\nSelect the meathod of procedure\n1)recursive\n2)itterative\n0)exit\n";
		cin>>menu ;
		if(menu == 1){
			while(true){
				cout<<"\n\nSelect the operation you want to perform\n1)creation\n2)transversal\n0)return to lastmenu\n";
				cin>>menu1 ;
				if(menu1 == 1){
					L.createRecursive();
				}
				else if (menu1 == 2){
					while(true){
						cout<<"Select the type of tranversal\n1)Preorder\n2)Inorder\n3)Postorder\n";
						cin>>menu2 ;
						if(menu2 == 1){
							L.printpreR();
						}
						else if(menu2 == 2 ){
							L.printIR();
						}
						else if(menu2 == 3){
							L.printporR();
						}
						else if(menu2 == 0 ){
							break ;
						}
						else{
							cout<<"Enter vaild option\n";
						}
					}
				}
				else if(menu1 == 0){
					break;
				}
				else {
					cout<<"enter vaild option\n";
				}
			}
		}
		else if(menu == 2){
			cout<<"\n\nSelect the meathod of procedure\n1)recursive\n2)itterative\n0)exit\n";
		cin>>menu ;
		if(menu == 1){
			while(true){
				cout<<"\n\nSelect the operation you want to perform\n1)creation\n2)transversal\n0)return to lastmenu\n";
				cin>>menu1 ;
				if(menu1 == 1){
					L.createItr();
				}
				else if (menu1 == 2){
					cout<<"Select the type of tranversal\n1)Preorder\n2)Inorder\n3)Postorder\n";
					cin>>menu2 ;
					if(menu2 == 1){
						L.printPreItr();
					}
					else if(menu2 == 2 ){
						L.printInoItr();
					}
					else if(menu2 == 3){
						L.printPosItr();
					}
					else{ 
						cout<<"Enter vaild option\n";
					}
				}
				else if(menu1 == 0){
					break;
				}
				else {
					cout<<"enter vaild option\n";
				}
			}
		}
		else if(menu == 0){
			break;
		}
		else{
			cout<<"Enter vaild option\n";
		}
	}
}
}

Sunay Bhoyar																				ASS 3
#include<iostream>
using namespace std;

class Node{

    private:
    int data;
    Node *lc, *rc;
    bool lf, rf;

    public:
    Node(int data=-1){
        this->data = data;
        this->lc = NULL;
        this->rc = NULL;
        this->lf = 0;
        this->rf = 0;
    }

    friend class TBST;
};


class TBST{

    private:
    Node *root, *header;

    Node* search(Node* &parent, Node* &current, int key){
        
        while(current!=header){
            if(current->data == key){
                return current;
            }
            else if(current->data < key){
                parent = current;
                current = current->rc;
            }
            else{
                parent=current;
                current = current->lc;
            }
        }
        return NULL;
    }

    public:
    
    TBST(){
        root = NULL;
        header = new Node(-1);
    }


    Node* getRoot(){
        return this->root;
    }


    void insert(int data){

        if(root == NULL){
            root = new Node(data);
            root->lc = header;
            root->rc = header;
            header->lc = root;
            header->lf = 1;
        }else{

            Node *parent = root;

            while(true){

                if(data < parent->data){

                    if(parent->lf == 1){
                        parent = parent->lc;
                    }else{
                        Node *newNode = new Node(data);
                        newNode->lc = parent->lc;
                        newNode->rc = parent;
                        parent->lc = newNode;
                        parent->lf = 1;
                        break;
                    }

                }else if(data > parent->data){

                    if(parent->rf == 1){
                        parent = parent->rc;
                    }else{
                        Node *newNode = new Node(data);
                        newNode->rc = parent->rc;
                        newNode->lc = parent;
                        parent->rc = newNode;
                        parent->rf = 1;
                        break;
                    }

                }

            }

        }

    }


    void deleteN(int key){

        Node *parent = NULL;
        Node *current = root;

        if(search(parent, current, key) == NULL ){
            cout<<"Key not found"<<endl;
        }else{

            // 2 child case
            if(current->lf == 1 && current->rf == 1){
                Node *c = current->rc;
                Node *cs = current;
                while(c->lf != 0){
                    cs = c;
                    c = c->lc;
                }
                current->data = c->data;
                current = c;
                parent = cs;
            }

            // no child case
            if(current->lf == 0 && current->rf == 0){
                if(parent->lc == current){
                    parent->lf = current->lf;
                    parent->lc = current->lc;
                }
                else if(parent->rc == current){
                    parent->rf = current->rf;
                    parent->rc = current->rc;
                }
                delete current;
            }

            // left child case
            if(current->lf == 1 && current->rf == 0){
                Node *child = current->lc;
                Node *t = child;
                while(t->rf != 0){
                    t = t->rc;
                }
                t->rf = current->rf;
                t->rc = current->rc;
                parent->lc = child;
                delete current;
            }

            // right node case
            if(current->rf == 1 && current->lf == 0){
                Node *child = current->rc;
                Node *t = child;
                while(t->lf != 0){
                    t->lf = current->lf;
                    t->lc = current->lc;
                    parent->rc = child;
                    delete current;
                }
            }

        }

    }


    void inOrder(Node *temp)
    {

        while (temp->lf == 1)
        {
            temp = temp->lc;
        }
        while (temp != header)
        {
            cout << temp->data << " ";

            if (temp->rf == 1)
            {
                temp = temp->rc;
                while (temp->lf == 1)
                {
                    temp = temp->lc;
                }
            }
            else
            {
                temp = temp->rc;
            }
        }
    }
    
    
    void preOrder(Node *temp)
    {
        while (temp != header)
        {
            cout << temp->data << " ";
            if (temp->lf == 1)
            {
                temp = temp->lc;
            }
            else if (temp->rf == 1)
            {
                temp = temp->rc;
            }
            else
            {
                while (temp != header && temp->rf == 0)
                {
                    temp = temp->rc;
                }
                if (temp != header)
                {
                    temp = temp->rc;
                }
            }
        }
    }

};

int main(){

    TBST tbst;
    
    tbst.insert(10);
    tbst.insert(5);
    tbst.insert(15);
    tbst.insert(3);
    tbst.insert(8);

    tbst.inOrder(tbst.getRoot());
    cout<<endl;

    tbst.deleteN(8);

    tbst.inOrder(tbst.getRoot());

    return 0;
}

Sunay Bhoyar																				ASS 4
#include<iostream>
#include<string>
using namespace std ;

class entry{

public:
	long int number ;
	string name ;
	entry(long int number_ = -1 , string name_ = "----------"){
		number = number_ ;
		name = name_;
	}
};

class hashTable{
	int size;
	entry *data ;

	int hashFunction(long int key){
		int res = 0 , temp = 0;
		temp = key / 100000000 ;
		res += temp ;
		temp = key / 1000000 - (temp*100) ;
		res += temp ;
		temp = key / 1000000;
		temp = key/ 10000 - (temp*100) ;
		res += temp ;
		temp = key / 10000;
		temp = key / 100 - (temp*100) ;
		res += temp ;
		temp = key / 100;
		temp = key / 1 - (temp*100) ;
		res += temp ;
		temp = key / 1;
		return res % size;
	}

public:
	hashTable(int size_=10){
		size = size_ ;
		data = new entry [size];
	}
	void insertWithOutReplacement(entry newEntry){
		int hc = hashFunction(newEntry.number);
		if(data[hc].number == -1){
			data[hc] = newEntry ;
		}
		else{
			int temp = hc + 1;
			while(temp!=hc){
				if(temp == size){
					temp = 0 ;
				}
				if(data[temp].number == -1){
					data[temp] = newEntry ;
					return ;
				}
				temp++;
			}
			cout<<"sorry the hashTable is now at max limit";
		}
	}
	void insertWithReplacement(entry newEntry){
			int hc = hashFunction(newEntry.number);
			if(data[hc].number == -1){
				data[hc] = newEntry ;
			}
			else{
				if(hc == hashFunction(data[hc].number)){
					int temp = hc + 1;
					while(temp!=hc){
						if(temp == size){
							temp = 0 ;
						}
						if(data[temp].number == -1){
							data[temp] = newEntry ;
							return ;
						}
						temp++;
					}
				}
				else{
					entry retrive  = data[hc] ;
					data[hc] = newEntry ;
					insertWithReplacement(retrive);
					return ;
				}

				cout<<"sorry the hashTable is now at max limit";
			}
		}

	int search(long int key){
		int hc = hashFunction(key);
		if(data[hc].number == -1){
			cout<<"the data not present" <<endl;
			return -1 ;
		}
		if(data[hc].number == key){
			cout<<"the element found at correct hash location of "<<hc<<endl;
			return hc ;
		}
		else{
				int cnt = 1 ;
				int temp = hc + 1;
				while(temp!=hc){
					if(temp == size){
						temp = 0 ;
					}
					if(data[temp].number == key){
						cout<<"the element found devaited "<<cnt<<" position from "<<hc<<" to "<<temp<<" location "<<endl;
						return temp;
					}
					temp++;
					cnt ++ ;
				}
			cout<<"the data not present";
			return -1 ;
			}
		}

	void update(long int key , long number_ , string name_){
		int loc = search(key);
		if(loc != -1){
			data[loc].number = number_ ;
			data[loc].name = name_ ;
 		}

	}

	void displayTable(){
		for (int i = 0 ; i < size ; i ++){
			cout<<i<<" "<<data[i].number<<" "<<data[i].name<<endl ;
		}
	}

	void deleteElem(long int key){
		int loc = search(key);
		if(loc == -1){
			cout<<"the element is not present"<<endl ;
		}
		else{
			int hc = hashFunction(key);
			data[loc].number = -1;
			data[loc].name =  "----------";
			int lastloc = loc ,temp = loc+1 ;
			while(temp!=hc){
				if(temp == size){
					temp = 0 ;
				}
				if(hashFunction(data[temp].number)==hc){
					data[lastloc] = data[temp] ;
					data[temp].number = -1;
					data[temp].name =  "----------";
					lastloc = temp ;
				}
				temp ++ ;
			}
		}
	}

};
int main(){
	int size = 0 ;
	hashTable *H ;
	cout<<"enter the size of the hash table\n";
	cin>>size ;

	H = new hashTable(size);

	int menu;
		while(true){
			cout<<"\n\nSelect the option\n1)enter data with replacement\n2)enter data without replacement\n3)search data\n4)update data\n5)delete data\n6)display data\n0)exit\n";
			cin>>menu ;
			if(menu == 1){
				long int number_ = 0;
				string name_ = "----------";
				cout<<"\nenter the number\n";
				cin>>number_;
				cout<<"\nenter the name\n";
				cin>>name_ ;
				H->insertWithReplacement(entry(number_,name_));

			}
			else if(menu == 2){
				long int number_ = 0;
				string name_ = "----------";
				cout<<"\nenter the number\n";
				cin>>number_;
				cout<<"\nenter the name\n";
				cin>>name_ ;
				H->insertWithOutReplacement(entry(number_,name_));
			}
			else if(menu == 3){
				long int number_ = 0;
				cout<<"\nenter the key you want to search\n";
				cin>>number_;
				H->search(number_);

			}
			else if(menu == 4){
				long int keynumber_ = 0;
				cout<<"\nenter the key you want to search\n";
				cin>>keynumber_;
				long int number_ = 0;
				string name_ = "----------";
				cout<<"\nenter the new number\n";
				cin>>number_;
				cout<<"\nenter the new name\n";
				cin>>name_ ;
				H->update(keynumber_,number_,name_);

			}
			else if(menu == 5){
				long int keynumber_ = 0;
				cout<<"\nenter the key you want to search\n";
				cin>>keynumber_;
				H->deleteElem(keynumber_);

			}
			else if(menu == 6){
				H->displayTable();
			}
			else if(menu == 0){
				break;
			}
			else{
				cout<<"Enter vaild option\n";
			}

		}
}

Sunay Bhoyar																				ASS 5

#include<iostream>
#include<string>
using namespace std ;

class entry{

public:
	string word;
	string meaning ;
	entry* next ;
	entry(string word_ = "-----" , string meaning_ = "-----"){
		word = word_ ;
		meaning = meaning_;
		next = NULL;
	}
};

class hashTableClosed{
	int size = 10;
	entry *data[10] ;

	int hashFunction(string key){
		int res = 0 ;
		for(long unsigned int i = 0 ; i < key.length() ; i ++){
			res += (int)key[i] ;
		}
		return res % size;
	}
public:


	hashTableClosed(){
		for(int i = 0 ; i < size ; i++ ){
			data[i] = NULL ;
		}
	}
	void insert(string word_ = "-----" , string meaning_ = "-----"){
			entry *newEntry = new entry(word_,meaning_);
			int hc = hashFunction(newEntry->word);
			if(data[hc] == NULL){
				data[hc] = newEntry ;
			}
			else{
				entry* temp = data[hc];
				while(temp->next!=NULL){
					temp = temp->next;
				}
				temp->next = newEntry;
			}
		}

	entry* search (string key_){
		int hc = hashFunction(key_);
		if(data[hc] == NULL){
			cout<<"data not found"<<endl ;
			return NULL;
		}
		if(data[hc]->word == key_){
			cout<<"the data found at "<<hc<<" index of hashtable at first postion in chain"<<endl ;
			return data[hc];
		}
		else{
			entry *temp = data[hc] ;
			int count = 1 ;
			while(temp!=NULL){
				if(temp->word == key_){
					cout<<"the data found at "<<hc<<" index of hashtable at postion "<< count<<" in chain"<<endl ;
					return temp;
				}
				count ++ ;
				temp = temp->next;
			}
			cout<<"data not found"<<endl ;
			return NULL;
		}
	}

	void deleteElem(string key_){
		int hc = hashFunction(key_);
		entry* temp2 = NULL ;
		if(data[hc] == NULL){
			cout<<"data not found"<<endl ;
			return ;
		}
		if(data[hc]->word == key_){
			temp2 = data[hc] ;
			data[hc] = temp->next ;
			delete temp2 ;
		}
		else{
			entry *temp = data[hc] ;
			while(temp->next!=NULL){
				if(temp->next->word == key_){
					temp2 = temp ->next ;
					temp ->next = temp->next ->next;
					delete temp2 ;
					return ;
				}
				temp = temp->next;
			}
			cout<<"data not found"<<endl ;
			return;
		}

	}

	void update(string key_ ,string meaning_ ){
		entry* temp = search(key_);
		if(temp == NULL){
			cout<<"data absent"<<endl ;
		}
		else{
			temp->meaning = meaning_ ;
		}
	}

	void displayTable(){
		for (int i = 0 ; i < size ; i ++){
			entry* temp = data[i];
			cout<<i;
			while(temp != NULL){
				cout<<" "<<temp->word<<" "<<temp->meaning <<"  ->   ";
				temp = temp->next;
			}
			cout<<endl ;
		}
	}

};
int main(){

	hashTableClosed H;
	H.displayTable();

	int menu;
		while(true){
			cout<<"\n\nSelect the option\n1)enter data\n2)search data\n3)update data\n4)delete data\n5)display data\n0)exit\n";
			cin>>menu ;
			if(menu == 1){
				string word_ = "-----";
				string meaning_ = "-----";
				cout<<"\nenter the word\n";
				cin>>word_;
				cout<<"\nenter the meaning\n";
				cin>>meaning_ ;
				H.insert(word_,meaning_);

			}
			else if(menu == 2){
				string key_;
				cout<<"\nenter the key you want to search\n";
				cin>>key_;
				H.search(key_);

			}
			else if(menu == 3){
				string key_;
				cout<<"\nenter the key you want to update\n";
				cin>>key_;
				string newMeaning_;
				cout<<"\nenter the new meaning\n";
				cin>>newMeaning_;
				H.update(key_,newMeaning_);

			}
			else if(menu == 4){
				string key_;
				cout<<"\nenter the key you want to update\n";
				cin>>key_;
				H.deleteElem(keynumber_);

			}
			else if(menu == 5){
				H.displayTable();
			}
			else if(menu == 0){
				break;
			}
			else{
				cout<<"Enter vaild option\n";
			}
		}
}


Sunay Bhoyar																				ASS 6

Sunay Bhoyar
21110 SE 1
13/04/2023

#include<iostream>
#include<string>
#include<map>
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
	int vertice ;
	string value ;
	Node* next ;
	Node(int vertice_ = 0,string value_ = ""){
		vertice = vertice_ ;
		next = NULL ;
		value = value_ ;
	}
};

class Graph{
	int verticesNumber ;
	Node* vertices ;
	bool* visited ;

public:
	void CreateGraph(){
		int temp1  ,temp2;
		string data ;
		cout<<"Enter the number of vertices in graph";
		cin >> verticesNumber ;
		vertices = new Node[verticesNumber];
		visited= new bool[verticesNumber];
		Node* temp ;
		for (int i = 0 ; i < verticesNumber ; i++){
			visited[i] = false ;
			temp = &vertices[i];
			temp->vertice = i ;
			cout<<"enter the value of the vertex number - "<<i<<" ";
			cin>> data ;
			temp->value = data ;
		}
		for (int i = 0 ; i < verticesNumber ; i++){
			cout<<"Enter the number of vertices "<<vertices[i].value<<" is connected with"<<endl ;
			cin >> temp1 ;
			temp = &vertices[i];
			for (int j = 0 ; j < temp1 ; j ++){
				cout<<"Enter the vertice number "<<vertices[i].value<<"is connected to (more to provide "<<temp1 - j<<") ";
				cin>>temp2 ;
				temp->next = new Node(temp2);
				temp->next->value = vertices[temp2].value;
				temp = temp->next ;

			}
		}
	}


	void PrintAd(){
		Node* temp ;
		for (int i = 0 ; i < verticesNumber ; i ++){
			temp = &vertices[i];
			while(temp!=NULL){
				cout<<temp->vertice<<" ("<<temp->value<<") "<<" -> ";
				temp = temp->next ;
			}
			cout<<endl ;

		}
	}

	void printDfsRecursive(int start){
		visited[start] = true ;
		Node* temp = &vertices[start];
		cout<<temp->vertice<<" ("<<temp->value<<") "<<" -> ";
		while(temp->next!=NULL){
			if(visited[temp->next->vertice] == false){
				printDfsRecursive(temp->next->vertice);
			}
			temp = temp->next ;
		}
	}

	void printDfsIttrative(int start){
		visited[start] = true ;
		Node* ret ;
		stack<Node*> s ;
		s.push(&vertices[start]);
		while(!s.isempty()){
			ret = s.pop();
			Node* temp = &vertices[ret->vertice];
			cout<<temp->vertice<<" ("<<temp->value<<") "<<" -> ";
			while(temp->next!=NULL){
				if(visited[temp->next->vertice] == false){
					s.push(temp->next);
					visited[temp->next->vertice] = true;
				}
				temp = temp->next ;
			}
		}
	}

	void printBfsIttrative(int start){
			visited[start] = true ;
			Node* ret ;
			queue<Node*> s ;
			s.push(&vertices[start]);
			while(!s.isempty()){
				ret = s.pop();
				Node* temp =  &vertices[ret->vertice];
				cout<<temp->vertice<<" ("<<temp->value<<") "<<" -> ";
				while(temp->next!=NULL){
					if(visited[temp->next->vertice] == false){
						s.push(temp->next);
						visited[temp->next->vertice] = true;
					}
					temp = temp->next ;
				}
			}
		}
	void reset(){
		for (int i = 0 ; i < verticesNumber ; i++){
			visited[i] = false ;
		}
	}

};

int main(){
	Graph G ;
	while(true){
		G.CreateGraph();
		int menu ;
		cout<< "Select the option you want to select\n1) Print the Adjacent matrix\n2) Print the DFS Recursive\n3) Print the DFS Itterative\n4) Print the BFS Itterative\n0) Exit"<<endl ;
		cin >> menu ; 
		if(menu == 0){
			break ; 
		}
		else if (menu == 1){
			G.PrintAd();		
		}
		else if(menu == 2){
			G.reset();
			G.printDfsRecursive(0);
		}
		else if(menu == 3){
			G.reset();
			G.printDfsIttrative(0);
		}
		else if(menu == 4){
			G.reset();
			G.printBfsIttrative(0);
		}
		else {
			cout<<"Enter a valid number";
		}
		cout<<endl;

	}
}





Sunay Bhoyar																				ASS 7
Sunay Bhoyar
21110 SE 1
27/04/2023

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

	int vertices1[4][4] = {{0,1,3,4},{1,0,2,0},{3,2,0,5},{4,0,5,0}};
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
    cout<<"The min weight is -"<<weight<<endl ;
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

	int vertices1[4][4] = {{0,1,3,4},{1,0,2,0},{3,2,0,5},{4,0,5,0}};
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
    cout<<"The min weight is -"<<weight<<endl ;
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




