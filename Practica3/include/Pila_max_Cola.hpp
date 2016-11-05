#include "cola.hpp"

template <class T>
class PilaMax{
  private:
    struct Elemento{
      T elem;
      T max;

      Elemento(){}
      Elemento(T e, T m): elem(e), max(m){}
    };

    Cola<Elemento> datos;

  public:
    /*
    Constructores, destructores y op asignacion
     */
    PilaMax<T>(){}
    PilaMax<T>(const PilaMax<T>& p):datos(p.datos){}
    ~PilaMax<T>();
    PilaMax<T>& operator=(const PilaMax<T>& p){
      datos = p.datos;
    }

    /*
    Metodos propios de una pila
     */

    bool vacia() const{return datos.vacia();}
    void poner(const T& elem);
    void quitar(){datos.quitar();}
    T tope() const{return datos.frente().elem;}
    T max() const{return tope().max;}
};

#include "../src/Pila_max_Cola.cpp"
