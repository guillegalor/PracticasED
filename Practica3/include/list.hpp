#ifndef LIST_
#define LIST_

template<class T>
class List{
	private:
	  struct Celda {
	  	T elemento;        ///< Elemento de informaci�n.
	    Celda *siguiente;  ///< Puntero al siguiente nodo.

	    /**
	     * @brief Constructor por defecto
	     */
	    Celda() : siguiente(0){
	    }
	    /**
	     * @brief Constructor con par�metros
	     * @param elem Elemento de informaci�n.
	     * @param sig Puntero al siguiente nodo.
	     */
	    Celda(const T & elem, Celda * sig): elemento(elem), siguiente(sig){
	    }
	  };

		Celda *cab;
		Celda *ultima;
	public:
		List();
		List(const List& l);
		~List();
		List& operator=(const List& l);

		bool vacia()const;
		void pushback(T elem);
		void popback();
		T& getLast();
		const T& getLast()const;

};

#include "../src/list.cpp"

#endif
