#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node{
  char val;
  bool rev;
  int weight, size;
  Node *left, *right;

  Node (char c) : val(c), rev(false), weight(rand()), size(1), left(NULL), right(NULL) {} 
} * root;

int size(Node * treap){ return treap ? treap -> size : 0; }

void push(Node * treap){
  if(treap && treap -> rev){
    treap -> rev = false;
    swap(treap -> left, treap -> right);
    if(treap -> left) treap -> left -> rev ^= true;
    if(treap -> right) treap -> right -> rev ^= true;
  }
}

void split(Node * treap, Node *& left, Node *& right, int val){
  if(!treap){
    left = right = NULL;
    return;
  }

  push(treap);

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
  push(left);
  push(right);

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

void print(Node * treap){
  if(!treap) return;
  push(treap);
  print(treap -> left);
  cout << treap -> val;
  print(treap -> right);
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m; cin >> n >> m;

  string s; cin >> s;

  for(char & c : s) merge(root, root, new Node(c));

  for(int i = 0; i < m; i++){
    int l, r; cin >> l >> r;

    Node * t1, * t2, * t3;

    split(root, t1, t2, l - 1);
    split(t2, t2, t3, r - l + 1);
    t2 -> rev ^= true;
    merge(root, t1, t2);
    merge(root, root, t3);
  }

  print(root);

  return 0;
}