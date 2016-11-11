#include <cassert>

// TODO Poner asserts

/*
Constructores
 */
template<class T>
VectorDinamico<T>::VectorDinamico(int n):numelem(0), reservados(n){
	datos = new T[n];
}

template<class T>
VectorDinamico<T>::VectorDinamico(const VectorDinamico<T>& v){									// TODO Preguntar si mantener tambien la capacidad o no
	this->datos = new T[v.capacity()];

	for (int i = 0; i < v.size(); i++) {
		datos[i] = v[i];
	}

	numelem = v.numelem;
	reservados = v.reservados;
}

// ~VectorDinamico<T>(){}																												// TODO Es necesario el destructor?
template<class T>
VectorDinamico<T>&  VectorDinamico<T>::operator=(const VectorDinamico& v){
	VectorDinamico<T> aux(v);

	T *p = datos;
	datos = aux.datos;
	aux.datos = p;

	int n = numelem;
	numelem = aux.numelem;
	aux.numelem = n;

	int r = reservados;
	reservados = aux.reservados;
	aux.reservados = r;

	return *this;
}

/*
Operaciones
 */
template<class T>
T& VectorDinamico<T>::operator[](int i){
	return datos[i];
}

template<class T>
const T& VectorDinamico<T>::operator[](int i) const{
	return datos[i];
}

template<class T>
void VectorDinamico<T>::resize(int n){
	T *aux = new T[n];
	int tope;

	if (n < numelem)
		tope = n;
	else
		tope = numelem;

	for (int i = 0; i < tope; i++) {
		aux[i] = datos[i];
	}

	delete[] datos;
	datos = aux;

	numelem = n;
	reservados = n;
}

template<class T>
void VectorDinamico<T>::reserve(int n){
	if (n > reservados) {
		T *aux = new T[n];
		for (int i = 0; i < numelem; i++)
			aux[i] = datos[i];

		delete[] datos;
		datos = aux;

		reservados = n;
	}
}

template<class T>
void VectorDinamico<T>::pushback(T elem){
	if (reservados == numelem) {
		reserve(numelem+1);
	}
	datos[numelem+1] = elem;
	++numelem;
}

template<class T>
void VectorDinamico<T>::popback(){
	resize(numelem-1);
}

template<class T>
T VectorDinamico<T>::getLast(){
	return datos[numelem];
}
