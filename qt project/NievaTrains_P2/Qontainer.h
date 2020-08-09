#ifndef QONTAINER_H
#define QONTAINER_H


template <class T>
class Qontainer{
private:
    T* array;
    unsigned int size;
    unsigned int capacity;
    void resize();
public:
    Qontainer();
    ~Qontainer();
    T& operator [](unsigned int) const;
    void push(T*);
    void pop(unsigned int =0);
    unsigned int getSize() const;
    unsigned int getCapacity() const;
    void clear();
    class Iterator{
    private:
        T* p;
    public:
        Iterator(T*);
        T& operator *() const;
        T* operator ->() const;
        Iterator& operator++();
        Iterator& operator--();
        bool operator==(const Iterator&)const;
        bool operator!=(const Iterator&)const;
    };
    class Const_Iterator{
    private:
      T* p;
    public:
      Const_Iterator(T*);
      const T& operator *() const;
      const T* operator ->() const;
      Const_Iterator& operator ++ ();
      Const_Iterator& operator -- ();
      bool operator == (const Const_Iterator&) const;
      bool operator != (const Const_Iterator&) const;
    };
    Iterator begin() const;
    Iterator end() const;
    Const_Iterator cbegin() const;
    Const_Iterator cend() const;
};
#endif // QONTAINER_H

//DEFINIZIONE QONTAINER

template <class T>
Qontainer<T>::Qontainer():array(nullptr), size(0), capacity(0){}

template<class T>
Qontainer<T>::~Qontainer(){
    delete[] array;
}

template <class T>
void Qontainer<T>::resize(){
    if(capacity==0) capacity=1;
    else    capacity *=2;
    T* aux= array;
    array= new T[capacity];
    for(unsigned int i=0; i<size; i++){
        array[i]=aux[i];
    }
    delete[] aux;
}

template <class T>
T& Qontainer<T>::operator[](unsigned int tmp)const{
    return array[tmp];
}

template <class T>
void Qontainer<T>::push(T* t){
    if(size==capacity)  resize();
    array[size]= *t;
    size++;
}

template <class T>
void Qontainer<T>::pop(unsigned int i){
    if(size!=0 && i< size){
        size--;
        for(unsigned int j=i; j<size; j++){
            array[j]=array[j+1];
        }
        array[size]=nullptr;
    }
}

template<class T>
unsigned int Qontainer<T>::getSize() const
{
    return size;
}

template<class T>
unsigned int Qontainer<T>::getCapacity() const
{
    return capacity;
}

template<class T>
void Qontainer<T>::clear()
{
    unsigned int i=size;
    while (i>0) {
        pop(0);
        i--;
    }
}

template<class T>
typename Qontainer<T>::Iterator Qontainer<T>::begin() const
{
    return Iterator(array);
}

template<class T>
typename Qontainer<T>::Iterator Qontainer<T>::end() const
{
    return Iterator(array+size);
}

template<class T>
typename Qontainer<T>::Const_Iterator Qontainer<T>::cbegin() const
{
    return Const_Iterator(array);
}

template<class T>
typename Qontainer<T>::Const_Iterator Qontainer<T>::cend() const
{
    return Const_Iterator(array+size);
}


// Iteratori//////////

template<class T>
Qontainer<T>::Iterator::Iterator(T * pointer):p(pointer){}

template <class T>
T& Qontainer<T>::Iterator::operator*() const{
    return *p;
}

template <class T>
T* Qontainer<T>::Iterator::operator->() const{
    return p;
}

template <class T>
typename Qontainer<T>::Iterator& Qontainer<T>::Iterator::operator++(){
    p++;
    return this;
}

template <class T>
typename Qontainer<T>::Iterator& Qontainer<T>::Iterator::operator--(){
    p--;
    return this;
}

template <class T>
bool Qontainer<T>::Iterator::operator==(const Iterator& it) const{
    return p==it.p;
}

template <class T>
bool Qontainer<T>::Iterator::operator!=(const Iterator& it) const{
    return p!=it.p;
}


template<class T>
Qontainer<T>::Const_Iterator::Const_Iterator(T * pointer):p(pointer){}

template <class T>
const T& Qontainer<T>::Const_Iterator::operator*() const{
    return *p;
}

template <class T>
const T* Qontainer<T>::Const_Iterator::operator->() const{
    return p;
}

template <class T>
typename Qontainer<T>::Const_Iterator& Qontainer<T>::Const_Iterator::operator++(){
    p++;
    return this;
}

template <class T>
typename Qontainer<T>::Const_Iterator& Qontainer<T>::Const_Iterator::operator--(){
    p--;
    return this;
}

template <class T>
bool Qontainer<T>::Const_Iterator::operator==(const Const_Iterator& it) const{
    return p==it.p;
}

template <class T>
bool Qontainer<T>::Const_Iterator::operator!=(const Const_Iterator& it) const{
    return p!=it.p;
}
