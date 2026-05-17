#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ostream;

struct out_of_range_ {
    size_t sz;
    size_t space;
};


namespace Vector
{
    template<typename T>
    class vector {
    private:
        size_t sz;
        T* elem;
        size_t space;
    public:
        //constructors
        vector() : sz(0), space(0), elem(new T[space]) {

        }

        // constructor with argumet
        explicit vector(size_t s) : sz(s), elem(new T[s]), space(s) {

        }

        // copy constructor
        vector(const vector& v) : sz(v.sz), space(v.space) , elem(new T[v.space]) {
            for (int i = 0; i < sz; i++){
                elem[i] = v.elem[i];
            }
        }


        // copy assignment
        vector& operator=(const vector& v) {
            if (this == &v) { // check if the adress is the same
                return *this;
            }
            if(v.sz <= space){
                for (int i = 0; i < v.sz; i++) {
                    elem[i] = v.elem[i];
                }
                sz = v.sz;
                //space = v.space;
                return *this; // in case the left object is smaller, we dont need to increase the space
            }
            
            T* ptr = new T[v.sz];
            for (int i = 0; i < v.sz; i++){
                ptr[i] = v.elem[i];
            }
            delete[] elem;
            elem = ptr;
            sz = v.sz;
            space = v.sz;
            return *this;
        }
        
        // destructor
        ~vector() {
            cout << " destructor  called" << endl;
            delete[] elem;
        }

        // checked access
        T& at(size_t n) { // this at is called when the vector object is non-const
            if (n < 0 || sz < n) {
                throw out_of_range_(sz, space);
            }
            return elem[n];
        }
        // checked access
        const T& at(size_t n) const { // this at is called when the vector object is const
            if (n < 0 || sz < n) {
                throw out_of_range_(sz, space);
            }
            return elem[n];
        }


        // unchecked access
        T& operator[](size_t n) {
            return elem[n];
        }

        // unchecked access
        const T& operator[](size_t n) const {
            return elem[n];
        }


        // the current size
        size_t size() const {
            return sz;
        }

        // grow
        void resize(size_t newsize) {
            if (newsize <= sz) {
                sz = newsize;
                return;
            }else{
                size_t space_ = newsize * 2;
                T* ptr = new T[space_];
                for (size_t i = 0; i < sz; i++) {
                    ptr[i] = elem[i];
                }
                for (size_t i = sz; i < newsize; i++) {
                    ptr[i] = T();
                }
                sz = newsize;
                space = space_;
                delete[] elem;
                elem = ptr;
            }
        }
        // add element
        void push_back(T d) {
            if (sz == 0) {
                reserve(8);
                elem[0] = d;
                sz++;
            }else if(sz < space){
                elem[sz] = d;
                sz++;
            }
            else {
                reserve(space * 2);
                elem[sz] = d;
                sz++;
            }
        }


        // get more space
        void reserve(size_t newalloc) {
            if (space < newalloc) {
                T* ptr = new T[newalloc];
                for (size_t i = 0; i < sz; i++) {
                    ptr[i] = elem[i];
                }
                delete[] elem;
                elem = ptr;
                space = newalloc;
            }
        }

        // current available space
        int capacity() const {
            return space;
        }

    };


    template<class T>
    ostream& operator<<(ostream& os, const vector<T>& v) {  ///output elements separated by spaces ' '
        return os;
    }
}

#endif