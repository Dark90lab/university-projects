#ifndef _SET_H_
#define _SET_H_

#include <iostream>

using namespace std;
template <typename T=int>
class Set;
template <typename T=int>
class Node {
	T data;
	Node *next;
public:
	Node(T d, Node* n = nullptr) : data(d), next(n) {}
	friend class Set<T>;
};
template <typename T>
class Set {
	Node<T> *begin;
public:
	Set();
	~Set();
	Set(const Set<T>& );
	Set<T>& operator=(const Set<T>& );

	bool isEmpty() const { return begin == nullptr; }
	bool inSet(T) const;
	void insert(T);
	void free();
	void copyFrom(const Set<T>&);
	T pop();
	void print(ostream& ) const;
	template <typename T>
	friend ostream& operator<<(ostream& , const Set<T>& );
	template <typename T>
	friend Set<T> operator+(const Set<T> &, const Set<T> &);
	template <typename T>
	friend Set<T> operator-(const Set<T>&, const Set<T>&);
};

#endif //_SET_H_

template <typename T>
Set<T>::Set() : begin(nullptr) {}

template <typename T>
Set<T>::~Set() {
	free();
}
template <typename T>
Set<T>::Set(const Set<T>& s) : begin(nullptr) {
	copyFrom(s);
}
template <typename T>
void Set<T>::free() {
	while (begin) {
		Node<T>* tmp = begin->next;
		delete begin;
		begin = tmp;
	}
	begin = nullptr;
}
template <typename T>
bool Set<T>::inSet(T v) const {
	Node<T>* tmp = begin;
	while (tmp) {
		if (tmp->data == v) return true;
		tmp = tmp->next;
	}
	return false;
}
template <typename T>
void Set<T>::copyFrom(const Set<T>& s) {
	Node<T>* tmp = s.begin;
	while (tmp) {
		insert(tmp->data);
		tmp = tmp->next;
	}
}
template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& s) {
	if (&s != this) {
		free();
		copyFrom(s);
	}
	return *this;
}
template <typename T>
void Set<T>::insert(T d) {
	if (inSet(d)) {
		cout << "Already in set, no insert" << endl;
		return;
	}
	if (begin == nullptr) {
		begin = new (nothrow) Node<T>(d);
	}
	else {
		begin = new (nothrow) Node<T>(d, begin);
	}
	if (begin == nullptr) cout << "Memory error, no insert" << endl;
}
template <typename T>
T Set<T>::pop() {
	
	string except = "No element in set";
	if(begin == nullptr)
		throw  except;

	Node<T>* tmp = begin;
	begin = begin->next;
	int d = tmp->data;
	delete tmp;
	return d;
}
template <typename T>
void Set<T>::print(ostream& os) const {
	Node<T>* tmp = begin;
	while (tmp) {
		os << tmp->data << " ";
		tmp = tmp->next;
	}
}

template <typename T>
ostream& operator<<(ostream& os, const Set<T>& s) {
	s.print(os);
	return os;
}
template <typename T>
Set<T> operator+(const Set<T>& lh, const Set<T>& rh) // suma zbiorow
{
	Set<T> S = lh;
	S.copyFrom(rh);
	return S;
}

//PART 2
template <>
bool Set<char>::inSet(char v) const
{
	Node<char>* tmp = begin;
	while (tmp) {
		if (tmp->data == v || tmp->data== tolower(v)) return true;
		tmp = tmp->next;
	}
	return false;

}

//PART 4
template <typename T>
Set<T> operator-(const Set<T>& s3, const Set<T>& s1)//ró¿nica zbiorów
{
	Set<T> S3 = s3;
	Set<T> n;
	while (S3.begin)
	{
		T val = S3.pop();
		if (!s1.inSet(val))
			n.insert(val);
	}
	return n;
	
}