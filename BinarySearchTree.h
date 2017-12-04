/*
 * BinarySearchTree.h
 *
 *  Created on: Oct 30, 2017
 *      Author: fatma.serce
 * Modified by: Ephraim Scarf
 * 	-	Added searchReturn and treeSearchReturn functions (for use with
 * 		CS300Assignment4.cpp) which returns the data of a node when the
 * 		data matches the function parameter.
 * Updates:
 *
 * 		Added InOrderT overload:
 *			int inOrderT(node<T>*, T&); // for filtering
 *			int inOrderT(T& item)
 *		Changed inOrder() return type to int, along with inOrderT(node<T>*) so
 * 		we could count the number of Contacts
 *
 *

 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <iostream>
using namespace std;

template <class T>
struct node{
	T data;
	node<T>* left;
	node<T>* right;
};

template <class T>
class BinarySearchTree{
private:
	node<T>* root;
	int inOrderT(node<T>*);
	int inOrderT(node<T>*, T&); // for filtering

	void preOrderT(node<T>*);
	void postOrderT(node<T>*);
	void destroy(node<T>*);
	int treeHeight(node<T>*);
	int max(int, int);
	int treeNodeCount(node<T>*);
	int treeLeaveCount(node<T>*);
	void treeInsert(node<T>*&, T&);
	bool treeSearch(node<T>*, T&);
	node<T>* findMax(node<T>*);
	void deletenode(node<T>*&, T&);

	T treeSearchReturn(node<T>*, T&); // added for CS300 Assignment 4
	//void treeFilter(node<T>*, T&); //

public:
	BinarySearchTree();
	int inOrder(){return inOrderT(root);}

	void preOrder(){preOrderT(root);}
	void postOrder(){postOrderT(root);}
	int height(){return treeHeight(root);}
	int nodeCount(){return treeNodeCount(root);}
	int leaveCount(){return treeLeaveCount(root);}
	void insert(T& item){treeInsert(root, item);}
	bool search(T& item){return treeSearch(root,item);}
//	void insert(T&); //non-recursive function call
	node<T>* findMax(){return findMax(root);}
	void deletenode(T& item){deletenode(root, item);}
	~BinarySearchTree(){destroy(root);}

	T searchReturn(T& item){return treeSearchReturn(root, item);} // added for CS300 Assignment 4
	//void filter(T& item){treeFilter(root, item);}
	int inOrderT(T& item){return inOrderT(root, item);};
};

template <class T>
BinarySearchTree<T>::BinarySearchTree(){
	root = NULL;
}


template <class T>
int BinarySearchTree<T>::inOrderT(node<T>* p){
	if(p!=NULL){
		int leftCount;
		int rightCount;

		leftCount = inOrderT(p->left);
		cout<<p->data;
		rightCount = inOrderT(p->right);
		return leftCount + 1 + rightCount;
	}
	else return 0;
}

// for filtering
template <class T>
int BinarySearchTree<T>::inOrderT(node<T>* p, T& item){
	if(p!=NULL){
		int result;
		//result += inOrderT(p->left, item);

		if(p->data > item) {
			result = inOrderT(p->left, item);

		}
		else if(p->data == item){
			result = inOrderT(p->left, item);

		}

		else if (p->data < item) {
			result = inOrderT(p->left, item);
			cout<<p->data;
			result += 1 + inOrderT(p->right, item);

		}
		return result;
	}
	else return 0;
}

//inorder traversal without recursion
//template <class T>
//void BinarySearchTree<T>::inOrderT(node<T>* p){
//	stack< node<T>* > s;
//	while(p!= NULL || !s.isEmpty())
//	if(p!= NULL){
//		s.push(p);
//		p = p->left;
//	}else{
//		p = s.pop();
//		cout<<p->data:
//		p = p->right;
//	}
//}

template <class T>
void BinarySearchTree<T>::preOrderT(node<T>* p){
	if(p!=NULL){
		cout<<p->data;
		preOrderT(p->left);
		preOrderT(p->right);
	}
}

template <class T>
void BinarySearchTree<T>::postOrderT(node<T>* p){
	if(p!=NULL){
		postOrderT(p->left);
		postOrderT(p->right);
		cout<<p->data;
	}
}
template <class T>
int BinarySearchTree<T>::max(int x, int y){
	if (x>y)
		return x;
	return y;
}

template <class T>
int BinarySearchTree<T>::treeHeight(node<T>* p){
	if(p!=NULL){
		return 1 + max(height(p->left, p->right));
	}
	return 0;
}

template <class T>
int BinarySearchTree<T>::treeNodeCount(node<T>* p){
	if(p==NULL)
		return 0;
	else
		return 1 + treeNodeCount(p->left) + treeNodeCount(p->right);
}
template <class T>
int BinarySearchTree<T>::treeLeaveCount(node<T>* p){
	if(p==NULL)
		return 0;
	else if(p->left==NULL && p->right==NULL)
		return 1;
	else
		return treeLeaveCount(p->left) + treeLeaveCount(p->right);
}
template <class T>
void BinarySearchTree<T>::destroy(node<T>* p){
	if(p!= NULL){
		destroy(p->left);
		destroy(p->right);
		delete p;
		p= NULL;
	}
}
//non recursive insert function
//template <class T>
//void BinarySearchTree<T>::insert(T& item){
//	node<T>* newnode = new node<T>();
//	newnode->data = item;
//	newnode->left = newnode->right = NULL;
//	if(root == NULL){
//		root = newnode;
//	}
//	else{
//		node<T>* p = root;
//		node<T>* q;
//		while(p!=NULL){
//			q = p;
//			if(item==p->data){
//				cout<<p->data;
//				cout<<"error"<<endl;
//				return;
//			}
//			else if (item<p->data)
//				p = p->left;
//			else
//				p = p->right;
//		}
//		if(item<q->data)
//			q->left = newnode;
//		else
//			q->right = newnode;
//	}
//
//}
template <class T>
void BinarySearchTree<T>::treeInsert(node<T>*& p, T& item){
	if(p == NULL){
		p = new node<T>;
		p->data = item;
		p->left = p->right = NULL;
	}
	else if(item<p->data){
		treeInsert(p->left, item);
	}else{
		treeInsert(p->right, item);
	}

}

template <class T>
bool BinarySearchTree<T>::treeSearch(node<T>* p, T& item){
	if(p == NULL)
		return false;
	else if(item<p->data)
		return treeSearch(p->left, item);
	else if(item>p->data)
		return treeSearch(p->right, item);
	return true;
}

template <class T>
node<T>* BinarySearchTree<T>::findMax(node<T>* p){
	if (p==NULL)
		return NULL;
	else if(p->right == NULL)
		return p;
	else
		return findMax(p->right);
}

template <class T>
void BinarySearchTree<T>::deletenode(node<T>*& p, T& item){
	//item not found, do nothing
	if(p == NULL)
		return;
	else if (item<p->data)	//item is on the left subtree
		deletenode(p->left, item);
	else if (item>p->data)	//item is on the right subtree
		deletenode(p->right, item);
    else{//item is equal to data,  it is found
		if(p->left!= NULL && p->right != NULL){	//if it is with two children
			p->data = findMax(p->left)->data;
			deletenode(p->left, p->data);
		}else{
			node<T>* old = p;
			if(p->left != NULL)
				p = p->left;
			else
				p = p->right;

			delete old;
		}
	}
}

template <class T>
T BinarySearchTree<T>::treeSearchReturn(node<T>* p, T& item){
	if(p == NULL)
		return item;
	else if(item<p->data)
		return treeSearchReturn(p->left, item);
	else if(item>p->data)
		return treeSearchReturn(p->right, item);
	return p->data;
}

// No longer used
/*
template <class T>
void BinarySearchTree<T>::treeFilter(node<T>* p, T& item) {
	if(p == NULL) {
		return;
	}


	else if(item < p->data) {
		return treeFilter(p->left, item);
	}

	else if(item > p->data) {
		inOrderT(p->left);
		cout<<p->data;
		return treeFilter(p->right, item);
	}

	// item == p->data
	// so list objects in p->left
	inOrderT(p->left);

}
*/
#endif /* BINARYSEARCHTREE_H_ */
