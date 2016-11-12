#ifndef VECTOR_DINAMICO_
#define VECTOR_DINAMICO_

template<class T>
class VectorDinamico{
	private:
		T *datos;
		int numelem;
		int reservados;

	public:
		// Constructores
		VectorDinamico<T>(int n = 0);
		VectorDinamico<T>(const VectorDinamico<T>& v);
		~VectorDinamico<T>();
		VectorDinamico<T>& operator=(const VectorDinamico& v);

		// Operaciones
		int size(){return numelem;}
		int capacity(){return reservados;}

		T& operator[](int i);
		const T& operator[](int i) const;

		void resize(int n);
		void reserve(int n);

		bool vacia(){return numelem == 0;}

		void pushback(T elem);
		void popback();

		T& getLast();
		const T& getLast()const;

};

#include "../src/vector_dinamico.cpp"


#endif
