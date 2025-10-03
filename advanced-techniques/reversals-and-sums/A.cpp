#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node{
  int val;
  bool rev;
  int weight, size;
  ll sum;
  Node *left, *right;

  Node (int x) : val(x), rev(false), weight(rand()), size(1), sum(x), left(NULL), right(NULL) {} 
} * root;

int size(Node * treap){ return treap ? treap -> size : 0; }
ll sum(Node * treap){ return treap ? treap -> sum : 0ll; }

void update(Node * treap){
  treap -> size = 1 + size(treap -> left) + size(treap -> right);
  treap -> sum = treap -> val + sum(treap -> left) + sum(treap -> right);
}

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

  update(treap);
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

  if (left -> weight < right->weight) {
		merge(left -> right, left -> right, right);
		treap = left;
	} else {
		merge(right -> left, left, right -> left);
		treap = right;
	}

  update(treap);
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m; cin >> n >> m;

  vector<int> a(n); for(auto & x : a) cin >> x;

  for(auto & x : a) merge(root, root, new Node(x));

  for(int i = 0; i < m; i++){
    int type, l, r; cin >> type >> l >> r;

    Node * t1, * t2, * t3;

    split(root, t1, t2, l - 1);
    split(t2, t2, t3, r - l + 1);
    if(type & 1){
      t2 -> rev ^= true;
    } else{
      cout << t2 -> sum << '\n';
    }
    merge(root, t1, t2);
    merge(root, root, t3);
  }

  return 0;
}