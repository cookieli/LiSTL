//
// Created by lzx on 10/1/19.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <error.h>
#include <string>
#include <sstream>
#include <iostream>
//#include <tic.h>

/*
 * declaration for << and >>
 * */



template<typename ValueType>
class Vector {
public:
    Vector();

    explicit Vector(int n, ValueType v = ValueType());

    virtual ~Vector();


    void add(const ValueType &value);

    void remove(int index);

    void checkIndex(int index, int min, int max, std::string prefix) const;

    void expandCapacity();

    void insert(int index, const ValueType &value);

    void push_back(const ValueType &value);

    void push_front(const ValueType &value);

    ValueType pop_back();

    ValueType pop_front();

    const ValueType &get(int index) const;


    bool isEmpty() const { return count == 0; };

    int size() const { return count; }

    int capacity() const { return _capacity; }

    bool equals(const Vector<ValueType> & vector) const;

    bool operator !=(const Vector &v2) const;
    bool operator ==(const Vector &v2) const;

private:
    ValueType *_elements;
    int _capacity;
    int count;
public:

    class iterator :
            public std::iterator<std::random_access_iterator_tag, ValueType> {
    private :
        const Vector *vp;
        int index;
    public:
        iterator():
        vp(nullptr),
        index(0){

        }

        iterator(const iterator& it)
        : vp(it.vp),
        index(it.index){
            //empty
        }
        iterator(const Vector *the_vec, int idx):
        vp(the_vec),
        index(idx){

        }

        bool operator ==(const iterator& rhs){
            return vp == rhs.vp && index == rhs.index;
        }

        bool operator !=(const iterator& rhs){
            return !(*this == rhs);
        }

        iterator&  operator ++(){
            index++;
            return *this;
        };

        iterator operator ++(int){
            iterator copy(*this);
            operator ++();
            return copy;
        }



        ValueType&   operator*(){
            return vp->_elements[index];
        }

        ValueType*  operator->(){
            return &vp->_elements[index];
        }
    };

    iterator begin() {
        return iterator(this, 0);
    }
    iterator begin() const{
        return iterator(this, 0);
    };

    iterator end() {
        return iterator(this, count);
    }
};

/*
 * Implementation LiSTL constructor and destructor
 *
 * */
template<typename ValueType>
Vector<ValueType>::Vector()
        :_elements(nullptr),
         _capacity(0),
         count(0) {
    //empty
}


template<typename ValueType>
Vector<ValueType>::Vector(int n, ValueType value)
        :_elements(nullptr),
         _capacity(n),
         count(n) {
    if (n < 0) {
        throw "LiSTL::constructor: n can't be negative";
    } else if (n > 0) {
        _elements = new ValueType[n];
        for (int i = 0; i < n; i++) {
            _elements[i] = value;
        }
    }
}

template<typename ValueType>
Vector<ValueType>::~Vector() {
    delete[] _elements;
    _elements = nullptr;
}

template<typename ValueType>
void Vector<ValueType>::add(const ValueType &value) {
    insert(count, value);
}


/*
 * implementation for member function
 *
 * */
template<typename ValueType>
void Vector<ValueType>::checkIndex(int index, int min, int max, std::string prefix) const {
    if (index < min || index > max) {
        std::ostringstream out;
        out << "LiSTL::" << prefix << ": index of " << index;
        if (isEmpty()) {
            out << "empty vector";
        } else {
            out << " [ ";
            if (min < max) {
                out << min << ".." << max;
            } else if (min == max) {
                out << min;
            }

            out << " ]";
        }
        throw out.str();
    }

}

template<typename ValueType>
void Vector<ValueType>::expandCapacity() {
    _capacity = std::max(1, _capacity * 2);
    ValueType *array = new ValueType[_capacity];
    if (_elements) {
        for (int i = 0; i < count; i++) {
            array[i] = _elements[i];
        }
        delete[]_elements;
    }
    _elements = array;
}

template<typename ValueType>
void Vector<ValueType>::insert(int index, const ValueType &value) {
    checkIndex(index, 0, count, "insert");
    if (count == _capacity) expandCapacity();
    for (int i = count; i > index; i--) {
        _elements[i] = _elements[i - 1];
    }
    _elements[index] = value;
    count++;
}

template<typename ValueType>
void Vector<ValueType>::remove(int index) {
    checkIndex(index, 0, count - 1, "remove");
    for (int i = index; i < count - 1; i++) {
        _elements[i] = _elements[i + 1];
    }
    count--;
}


template<typename ValueType>
const ValueType &Vector<ValueType>::get(int index) const {
    checkIndex(index, 0, count, "get");
    return _elements[index];
}

template<typename ValueType>
void Vector<ValueType>::push_back(const ValueType &value) {
    add(value);
}

template<typename ValueType>
void Vector<ValueType>::push_front(const ValueType &value) {
    insert(0, value);
}

template<typename ValueType>
ValueType Vector<ValueType>::pop_front() {
    if (isEmpty()) {
        throw "this vector is empty";
    }
    ValueType value = _elements[0];
    remove(0);
    return value;
}

template<typename ValueType>
ValueType Vector<ValueType>::pop_back() {
    if (isEmpty()) {
        throw "this vector is empty";
    }
    ValueType value = _elements[count - 1];
    remove(count - 1);
    return value;
}

template <typename ValueType>
bool Vector<ValueType> ::equals(const Vector<ValueType> &vector) const {
    if(this == &vector){
        return true;
    }
    if(size() != vector.size()){
        return false;
    }
    int endIndex   = size();

    for(int cursor = 0; cursor < endIndex; cursor++){
        if (_elements[cursor] != vector._elements[cursor]){
            return false;
        }
    }

    return true;
}

/*
 * implementation for vector operator
 * */

template <typename ValueType>
bool Vector<ValueType>::operator!=(const Vector &v2) const {
    return !equals(v2);
}



template <typename ValueType>
bool Vector<ValueType>::operator==(const Vector &v2) const {
    return equals(v2);
}


#endif //VECTOR_VECTOR_H
