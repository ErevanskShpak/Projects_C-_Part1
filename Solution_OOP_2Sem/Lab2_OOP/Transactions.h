#pragma once
#include <memory>
#include "File.h"

template <class T>
class Transaction {
	shared_ptr<T> currentState;
	shared_ptr<T> prevState;
public:
	Transaction() :prevState(nullptr), currentState(new T) {}
	Transaction(T object) : prevState(nullptr), currentState(new T(object)) {}
	Transaction(const Transaction& obj) : currentState(new T(*(obj.currentState))), prevState(NULL) {}

	Transaction& operator=(const Transaction& obj);
	void beginTransactions();
	void commit();
	void deleteTransactions();
	shared_ptr<T> operator->();
};

template class Transaction<File>;
//#pragma once
//#include <memory>
//#include "File.h"
//
//template <class T>
//class Transaction {
//	T* currentState;
//	T* prevState;
//public:
//	Transaction() :prevState(nullptr), currentState(new T) {}
//	Transaction(T object) : prevState(nullptr), currentState(new T(object)) {}
//	Transaction(const Transaction& obj) : currentState(new T(*(obj.currentState))), prevState(NULL) {}
//	~Transaction() {
//		delete currentState;
//		delete prevState;
//	}
//
//	Transaction& operator=(const Transaction& obj);
//	void beginTransactions();
//	void commit();
//	void deleteTransactions();
//	T* operator->();
//};