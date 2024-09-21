#include<iostream>
using namespace std;
struct Node {
   int d;
   struct Node *l;
   struct Node *r;
}*r;
class Tree {
   public:
      int height(Node *t) {
        int h = 0;
        if (t != NULL) {
            int l_height = height(t->l);
            int r_height = height(t->r);
            int max_height = max(l_height, r_height);
            h = max_height + 1;
        }
        return h;
        }

      int getBfFactor(Node *t) {
        int l_height = height(t->l);
        int r_height = height(t->r);
        int b_factor = l_height - r_height;
        return b_factor;
        }

      Node* RR(Node *parent) {
        Node *t;
        t = parent->r;
        parent->r = t->l;
        t->l = parent;
        cout<<"Right-Right Rotation";
        return t;
        }
      Node* LL(Node *parent) {
        Node *t;
        t = parent->l;
        parent->l = t->r;
        t->r = parent;
        cout<<"Left-Left Rotation";
        return t;
        }
      Node* LR(Node *parent) {
        Node *t;
        t = parent->l;
        parent->l = RR(t);
        cout<<"Left-Right Rotation";
        return LL(parent);
        }
      Node* RL(Node *parent) {
        Node *t;
        t = parent->r;
        parent->r = LL(t);
        cout<<"Right-Left Rotation";
        return RR(parent);
        }

      Node* balance(Node *t) {
        int bal_factor = getBfFactor(t);
        if (bal_factor > 1) {
            if (getBfFactor(t->l) > 0)
                t = LL(t);
            else
                t = LR(t);
        } else if (bal_factor < -1) {
            if (getBfFactor(t->r) > 0)
                t = RL(t);
            else
                t = RR(t);
        }
        return t;
}
      Node* insert(Node *r, int v) {
        if (r == NULL) {
            r = new Node;
            r->d = v;
            r->l = NULL;
            r->r = NULL;
            return r;
        } else if (v< r->d) {
            r->l = insert(r->l, v);
            r = balance(r);
        } else if (v >= r->d) {
            r->r = insert(r->r, v);
            r = balance(r);
        } return r;
        }
      
      void inorder(Node *t) {
        if (t == NULL)
            return;
            inorder(t->l);
            cout << t->d << " ";
            inorder(t->r);
        }
      void preorder(Node *t) {
        if (t == NULL)
            return;
            cout << t->d << " ";
            preorder(t->l);
            preorder(t->r);
        }
      void postorder(Node *t) {
        if (t == NULL)
            return;
            postorder(t ->l);
            postorder(t ->r);
            cout << t->d << " ";
        }
      Tree() {
         r = NULL;
      }
};
int main() {
   int c, i;
   Tree Node;
   while (1) {
      cout << "1.Insert Element into the tree" << endl;
      cout << "2.InOrder traversal" << endl;
      cout << "3.PreOrder traversal" << endl;
      cout << "4.PostOrder traversal" << endl;
      cout << "0.Exit" << endl;
      cout << "Enter your Choice: ";
      cin >> c;
      switch (c) {
         case 1:
            cout << "Enter value to be inserted: ";
            cin >> i;
            r = Node.insert(r, i);
         break;
         case 2:
            cout << "Inorder Traversal:" << endl;
            Node.inorder(r);
            cout << endl;
         break;
         case 3:
            cout << "Preorder Traversal:" << endl;
            Node.preorder(r);
            cout << endl;
         break;
         case 4:
            cout << "Postorder Traversal:" << endl;
            Node.postorder(r);
            cout << endl;
         break;
         case 0:
            exit(1);
         break;
         default:
            cout << "Wrong Choice" << endl;
      }
   }
   return 0;
}