#ifndef CircularNode.h
#define CircularNode.h

template<class T>
class CircularNode{
	T data;
	CircularNode* next;
	CircularNode(T val) : data(val), next(nullptr){
	}
};

#endif
