#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
struct Node{
  char val;
  int weight, size;
  Node *left, *right;
 
  Node (char c) : val(c), weight(rand()), size(1), left(NULL), right(NULL) {} 
} * root;
 
int size(Node * treap){ return treap ? treap -> size : 0; }
 
void split(Node * treap, Node *& left, Node *& right, int val){
  if(!treap){
    left = right = NULL;
    return;
  }
 
  if(size(treap->left) < val){
    split(treap -> right, treap -> right, right, val - size(treap -> left) - 1);
    left = treap;
  } else{
    split(treap -> left, left, treap -> left, val);
    right = treap;
  }
 
  treap -> size = 1 + size(treap -> left) + size(treap -> right);
}
 
void merge(Node *& treap, Node * left, Node * right){
  if(left == NULL){
    treap = right;
    return;
  }
  if(right == NULL){
    treap = left;
    return;
  }
 
  if (left->weight < right->weight) {
		merge(left->right, left->right, right);
		treap = left;
	} else {
		merge(right->left, left, right->left);
		treap = right;
	}
 
	treap->size = 1 + size(treap->left) + size(treap->right);
}
 
ostream & operator<< (ostream & os, Node * n){
  if(!n) return os;
  os << n -> left;
  os << n -> val;
  os << n -> right;
  return os;
}
 
signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m; cin >> n >> m;
 
  string s; cin >> s;
 
  for(char & c : s) merge(root, root, new Node(c));
 
  for(int i = 0; i < m; i++){
    int l, r; cin >> l >> r;
 
    Node * a, * b, * c, * d;
 
    split(root, a, b, l - 1);
    split(b, c, d, r - l + 1);
    merge(root, a, d);
    merge(root, root, c);
  }
 
  cout << root;
 
  return 0;
}