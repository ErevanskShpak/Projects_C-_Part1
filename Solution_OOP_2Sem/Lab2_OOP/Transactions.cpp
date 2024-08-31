#include "Transactions.h"

template <class T>
Transaction<T>& Transaction<T>::operator=(const Transaction<T>& obj) {
	if (this != &obj) {
		currentState.reset();
		currentState = obj.currentState;
	}
	return *this;
}

template<class T>
shared_ptr<T> Transaction<T>::operator->() {
	return currentState;
}

template <class T>
void Transaction<T>::beginTransactions()  {
	prevState.reset();
	prevState = currentState;
	currentState = prevState;
}

template <class T>
void Transaction<T>::commit() {
	prevState.reset();
	prevState = NULL;
}

template <class T>
void Transaction<T>::deleteTransactions() {
	if (prevState != NULL) {
		currentState.reset();
		currentState = prevState;
		prevState = NULL;
	}
}

//#include "Transactions.h"
//
//template <class T>
//Transaction<T>& Transaction<T>::operator=(const Transaction<T>& obj) {
//	if (this != &obj) {
//		delete currentState;
//		currentState = new T(*(obj.currentState));
//	}
//	return *this;
//}
//
//template<class T>
//T* Transaction<T>::operator->() {
//	return currentState;
//}
//
//template <class T>
//void Transaction<T>::beginTransactions() {
//	delete prevState;
//	prevState = currentState;
//	currentState = new T(*prevState);
//}
//
//template <class T>
//void Transaction<T>::commit() {
//	delete prevState;
//	prevState = NULL;
//}
//
//template <class T>
//void Transaction<T>::deleteTransactions() {
//	if (prevState != NULL) {
//		delete currentState;
//		currentState = prevState;
//		prevState = NULL;
//	}
//}
//
//template class Transaction<File>;