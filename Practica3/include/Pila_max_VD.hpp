#ifndef PILA_MAX
#define PILA_MAX

#include "vector_dinamico.hpp"

template <class T>
class PilaMax{
  private:
    struct Elemento{
      T elem;
      T max;

      Elemento(){}
      Elemento(T e, T m): elem(e), max(m){}
    };

    VectorDinamico<Elemento> datos;

  public:
    /*
    Constructores, destructores y op asignacion
     */
    PilaMax<T>(){}
    PilaMax<T>(const PilaMax<T>& p):datos(p.datos){}
    //~PilaMax<T>();
    PilaMax<T>& operator=(const PilaMax<T>& p){datos = p.datos;}

    /*
    Metodos propios de una pila
     */

    bool vacia() const{return datos.vacia();}
    void poner(const T& t_elem);
    void quitar(){datos.popback();}
    T tope() const{return datos.getLast().elem;}
    T max() const{return datos.getLast().max;}
};

#include "../src/Pila_max_VD.cpp"


#endif
