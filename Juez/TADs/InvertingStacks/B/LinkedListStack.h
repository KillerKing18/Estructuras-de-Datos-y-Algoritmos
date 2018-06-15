/**
@file LinkedListStack.h

Implementación del TAD Pila utilizando una
lista enlazada de nodos.

Estructura de Datos y Algoritmos
Facultad de Informática
Universidad Complutense de Madrid

(c) Marco Antonio Gómez Martín, 2012
*/
#ifndef __PILA_LISTA_ENLAZADA_H
#define __PILA_LISTA_ENLAZADA_H

#include "Exceptions.h"

/**
Implementación del TAD Pila utilizando una lista enlazada de nodos.

Las operaciones son:

- EmptyStack: -> Stack. Generadora implementada en el
constructor sin parámetros.
- Push: Stack, Elem -> Stack. Generadora
- pop: Stack - -> Stack. Modificadora parcial.
- top: Stack - -> Elem. Observadora parcial.
- empty: Stack -> Bool. Observadora.
- size: Stack -> Entero. Observadora.

@author Marco Antonio Gómez Martín
*/
template <class T>
class LinkedListStack {
public:

	/** Constructor; operación PilaVacia */
	LinkedListStack() : _cima(NULL), _numElems(0) {
	}

	/** Destructor; elimina la lista enlazada. */
	~LinkedListStack() {
		libera();
		_cima = NULL;
	}

	/**
	Apila un elemento. Operación generadora.

	@param elem Elemento a apilar.
	*/
	void push(const T &elem) {
		_cima = new Nodo(elem, _cima);
		_numElems++;
	}

	void invertBase(int m) {
		if (m == _numElems || m == _numElems - 1)
			return;

		Nodo *aux = _cima;
		Nodo *actual = NULL;

		for (int i = 0; i < m; i++) {
			actual = aux;
			aux = aux->_sig;
		}
		Nodo *invertido = aux;
		Nodo *inmediato = aux->_sig;
		aux = NULL;
		invertido->_sig = NULL;
		Nodo *nextInmediato;

		for (int i = 0; i < _numElems - m - 1; i++) {
			nextInmediato = inmediato->_sig;
			inmediato->_sig = invertido;
			invertido = inmediato;
			inmediato = nextInmediato;
		}

		if (actual != NULL)
			actual->_sig = invertido;
		else
			_cima = invertido;
	}


	/**
	Desapila un elemento. Operación modificadora parcial,
	que falla si la pila está vacía.

	pop(Push(elem, p) = p
	error: pop(EmptyStack)
	*/
	void pop() {
		if (empty())
			throw EmptyStackException();
		Nodo *aBorrar = _cima;
		_cima = _cima->_sig;
		delete aBorrar;
		--_numElems;
	}

	/**
	Devuelve el elemento en la cima de la pila. Operación
	observadora parcial, que falla si la pila está vacía.

	top(Push(elem, p) = elem
	error: top(EmptyStack)

	@return Elemento en la cima de la pila.
	*/
	const T &top() const {
		if (empty())
			throw EmptyStackException();
		return _cima->_elem;
	}

	/**
	Devuelve true si la pila no tiene ningún elemento.

	empty(EmptyStack) = true
	empty(Push(elem, p)) = false

	@return true si la pila no tiene ningún elemento.
	*/
	bool empty() const {
		return _cima == NULL;
	}

	/**
	Devuelve el número de elementos que hay en la
	pila.
	size(EmptyStack) = 0
	size(Push(elem, p)) = 1 + size(p)

	@return Número de elementos.
	*/
	int size() const {
		return _numElems;
	}

	// //
	// MÉTODOS DE "FONTANERÍA" DE C++ QUE HACEN VERSÁTIL
	// A LA CLASE
	// //

	/** Constructor copia */
	LinkedListStack(const LinkedListStack<T> &other) : _cima(NULL) {
		copia(other);
	}

	/** Operador de asignación */
	LinkedListStack<T> &operator=(const LinkedListStack<T> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparación. */
	bool operator==(const LinkedListStack<T> &rhs) const {
		if (_numElems != rhs._numElems)
			return false;
		Nodo *cima1 = _cima;
		Nodo *cima2 = rhs._cima;
		while ((cima1 != NULL) && (cima2 != NULL)) {
			if (cima1->_elem != cima2->_elem)
				return false;
			cima1 = cima1->_sig;
			cima2 = cima2->_sig;
		}

		return (cima1 == NULL) && (cima2 == NULL);
	}

	bool operator!=(const LinkedListStack<T> &rhs) const {
		return !(*this == rhs);
	}

protected:

	void libera() {
		libera(_cima);
	}

	void copia(const LinkedListStack &other) {

		if (other.empty()) {
			_cima = NULL;
			_numElems = 0;
		}
		else {
			Nodo *act = other._cima;
			Nodo *ant;
			_cima = new Nodo(act->_elem);
			ant = _cima;
			while (act->_sig != NULL) {
				act = act->_sig;
				ant->_sig = new Nodo(act->_elem);
				ant = ant->_sig;
			}
			_numElems = other._numElems;
		}
	}

private:

	/**
	Clase nodo que almacena internamente el elemento (de tipo T),
	y un puntero al nodo siguiente, que podría ser NULL si
	el nodo es el último de la lista enlazada.
	*/
	class Nodo {
	public:
		Nodo() : _sig(NULL) {}
		Nodo(const T &elem) : _elem(elem), _sig(NULL) {}
		Nodo(const T &elem, Nodo *sig) :
			_elem(elem), _sig(sig) {}

		T _elem;
		Nodo *_sig;
	};

	/**
	Elimina todos los nodos de la lista enlazada cuyo
	primer nodo se pasa como parámetro.
	Se admite que el nodo sea NULL (no habrá nada que
	liberar).
	*/
	static void libera(Nodo *prim) {
		while (prim != NULL) {
			Nodo *aux = prim;
			prim = prim->_sig;
			delete aux;
		}
	}

	/** Puntero al primer elemento */
	Nodo *_cima;

	/** Número de elementos */
	int _numElems;
};

#endif // __PILA_LISTA_ENLAZADA_H
