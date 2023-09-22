#ifndef QONTAINER_H
#define QONTAINER_H

template <class T>
class Qontainer{
private:
    T* array;
    T* aux;
    unsigned int size;
    unsigned int capacity;
    void resize();
public:
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
    Qontainer();
    ~Qontainer();
    T& operator [](unsigned int) const;
    void erase(T);
    void push(T*);
    void pop(unsigned int =0);
    void switchItem(T*,unsigned int =0);
    unsigned int getSize() const;
    unsigned int getCapacity() const;
    bool isEmpty() const;
    void clear();
    bool operator==(const Qontainer<T>&) const;
    Qontainer<T> & operator= (const Qontainer<T> &);
    Iterator begin() const;
    Iterator end() const;
    Const_Iterator cbegin() const;
    Const_Iterator cend() const;
};


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

template<class T>
void Qontainer<T>::erase(T t)
{
    unsigned int i=0;
    for(auto it= begin() ; it!=end(); ++it){
        if((*it)== t)   return pop(i);
        else    i++;
    }
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
template <class T>
void Qontainer<T>::switchItem(T* t, unsigned int i){
    delete array[i];
    array[i]=*t;
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
bool Qontainer<T>::isEmpty() const
{
    return getSize()==0;
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
bool Qontainer<T>::operator==(const Qontainer<T> & t) const
{
    bool uguale=(t.size== size) && (t.capacity== capacity);
    auto it=cbegin();
    auto it2=t.cbegin();
    for (; it!=cend() && uguale; ++it, ++it2) {
        if(*it!=*it2)   uguale=false;
    }
    return uguale;
}

template<class T>
Qontainer<T> &Qontainer<T>::operator=(const Qontainer<T> & t)
{
    if(this!= &t){
        delete[] array;
        size=t.size;
        capacity=t.capacity;
        array= new T[capacity];
        for(unsigned int i=0; i<size; i++)
            array[i]=t.array[i];
    }

    return *this;
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
    if(p)   p++;
    return *this;
}

template <class T>
typename Qontainer<T>::Iterator& Qontainer<T>::Iterator::operator--(){
    if(p)   p--;
    return *this;
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
    if(p)   p++;
    return *this;
}

template <class T>
typename Qontainer<T>::Const_Iterator& Qontainer<T>::Const_Iterator::operator--(){
    if(p)   p--;
    return *this;
}

template <class T>
bool Qontainer<T>::Const_Iterator::operator==(const Const_Iterator& it) const{
    return p==it.p;
}

template <class T>
bool Qontainer<T>::Const_Iterator::operator!=(const Const_Iterator& it) const{
    return p!=it.p;
}
#endif // QONTAINER_H
