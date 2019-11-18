#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <vector>
#include <type_traits>

template <class T>
class Container {
private:
	class Nodo {
	public:
		T info;
		Nodo* prev, *next;
		Nodo(T val, Nodo* p=nullptr, Nodo* n=nullptr): info(val), prev(p), next(n) {}
		Nodo(const Nodo& n): info(n.info), prev(n.prev), next(n.next) {}
		~Nodo() {}
	};
	Nodo* first;
	static Nodo* copia(Nodo*);
	static void distruggi(Nodo*);
public:
	class Iterator {
		friend class Container;
	private:
		Container::Nodo* punt;
	public:
		bool operator==(const Iterator&) const;
		bool operator!=(const Iterator&) const;
		Iterator& operator++();
		Iterator& operator++(int); //postfisso
		Iterator& operator--();
		Iterator& operator--(int); //postfisso
		T& operator*() const;
		Nodo* operator->() const;
	};
	class const_Iterator {
		friend class Container;
	private:
		Container::Nodo* punt;
	public:
		bool operator==(const const_Iterator&) const;
		bool operator!=(const const_Iterator&) const;
		const_Iterator& operator++();
		const_Iterator& operator++(int); //postfisso
		const_Iterator& operator--();
		const_Iterator& operator--(int); //postfisso
		T& operator*() const;
		Nodo* operator->() const;
	};
	Container(Nodo* =nullptr);
	~Container();
	Container(const Container&);
	Container& operator=(const Container&);
	bool isEmpty();
	void insert(const T);
	void remove(const T);
	template<class Ptr=T>
	std::vector<Ptr> search(const Ptr val, typename std::enable_if<std::is_pointer<Ptr>::value>::type* =0) const{
	    std::vector<T> ricerca;
		Nodo* aux=first;
		while(aux){
			if(*(aux->info)==(*val)){
				T temp=aux->info;
				ricerca.push_back(temp);
			}aux=aux->next;
		}return ricerca;
	}
	template<class Ptr=T>
	std::vector<Ptr> search(const Ptr val, typename std::enable_if<!std::is_pointer<Ptr>::value>::type* =0) const{
	    std::vector<T> ricerca;
		Nodo* aux=first;
		while(aux){
			if(aux->info==val){
				T temp=aux->info;
				ricerca.push_back(temp);
			}aux=aux->next;
		}return ricerca;
	}
	unsigned int size() const;
	Iterator begin() const;
	Iterator end() const;
	T& operator[](const Iterator&);
	T& operator[](const const_Iterator&);
};

template <class T>
typename Container<T>::Nodo* Container<T>::copia(Nodo* n) {
	if(!n) return nullptr;
	else{
		Nodo* aux=new Nodo(n->info, nullptr, copia(n->next));
		if(aux->next) aux->next->prev=aux;
		return aux;
	}
}

template <class T>
void Container<T>::distruggi(Nodo* n) {
	if(n){
		distruggi(n->next);
		delete n;
	}
}

//metodi di Iterator

template <class T>
bool Container<T>::Iterator::operator==(const Iterator& it) const {
    return punt==it.punt;
}

template <class T>
bool Container<T>::Iterator::operator!=(const Iterator& it) const {
	return punt!=it.punt;
}

template <class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator++() {
	if(punt) punt=punt->next;
	return *this;
}

template <class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator++(int) {
	Iterator aux=*this;
	if(punt) punt=punt->next;
	return aux;
}

template <class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator--() {
	if(punt) punt=punt->prev;
	return *this;
}

template <class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator--(int) {
	Iterator aux=*this;
	if(punt) punt=punt->prev;
	return aux;
}

template <class T>
T& Container<T>::Iterator::operator*() const {
	return punt->info;
}

template <class T>
typename Container<T>::Nodo* Container<T>::Iterator::operator->() const {
	return punt;
}

//metodi di const_Iterator

template <class T>
bool Container<T>::const_Iterator::operator==(const const_Iterator& it) const {
	return punt==it.punt;
}

template <class T>
bool Container<T>::const_Iterator::operator!=(const const_Iterator& it) const {
	return punt!=it.punt;
}

template <class T>
typename Container<T>::const_Iterator& Container<T>::const_Iterator::operator++() {
	if(punt) punt=punt->next;
	return *this;
}

template <class T>
typename Container<T>::const_Iterator& Container<T>::const_Iterator::operator++(int) {
	const_Iterator aux=*this;
	if(punt) punt=punt->next;
	return aux;
}

template <class T>
typename Container<T>::const_Iterator& Container<T>::const_Iterator::operator--() {
	if(punt) punt=punt->prev;
	return *this;
}

template <class T>
typename Container<T>::const_Iterator& Container<T>::const_Iterator::operator--(int) {
	const_Iterator aux=*this;
	if(punt) punt=punt->prev;
	return aux;
}

template <class T>
T& Container<T>::const_Iterator::operator*() const {
	return punt->info;
}

template <class T>
typename Container<T>::Nodo* Container<T>::const_Iterator::operator->() const {
	return punt;
}

//metodi di Container

template <class T>
Container<T>::Container(Nodo* n): first(n) {}

template <class T>
Container<T>::~Container() { if(first) distruggi(first); }

template <class T>
Container<T>::Container(const Container& c): first(copia(c.first)) {}

template <class T>
Container<T>& Container<T>::operator=(const Container& c) {
	if(this!=&c) {
		distruggi(first);
		first=copia(c.first);
	} return *this;
}

template <class T>
bool Container<T>::isEmpty() { return first==0; }

template <class T>
void Container<T>::insert(const T val) {
	first=new Nodo(val,nullptr,first);
	if(first->next) first->next->prev=first;
}

template <class T>
void Container<T>::remove(T val) {
	Nodo *aux=first;
	while(aux) {
		if(aux->info==val) {
			Nodo* del=aux;
			if(aux->prev==nullptr && aux->next==nullptr) {
				first=nullptr;
			}else if(aux->prev==nullptr) {
				first=first->next;
				aux->next->prev=nullptr;
			}else if(aux->next==nullptr) {
				aux->prev->next=nullptr;
			}else{
				aux->next->prev=aux->prev;
				aux->prev->next=aux->next;
			} aux=aux->next;
			delete del;
		}
		else aux=aux->next;
	}
}

template <class T>
unsigned int Container<T>::size() const {
	unsigned int count=0;
	Nodo* aux=first;
	while(aux){
		count++;
		aux=aux->next;
	} return count;
}

template <class T>
typename Container<T>::Iterator Container<T>::begin() const {
	Iterator aux;
	aux.punt=first;
	return aux;
}

template <class T>
typename Container<T>::Iterator Container<T>::end() const {
	Iterator aux;
	aux.punt=0;
	return aux;
}

template <class T>
T& Container<T>::operator[](const Iterator& it) {
	return (it.punt)->info;
}

template <class T>
T& Container<T>::operator[](const const_Iterator& it) {
 	return (it.punt)->info;
}

#endif
