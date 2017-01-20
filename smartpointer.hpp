#ifndef SMARTPOINTER_HPP
#define SMARTPOINTER_HPP

#include <stdio.h>

namespace kgk {

class ref_count {
    private:
        size_t *count;

    public:

        ref_count() {
            count = new size_t;
            *count = 0;
        }

        ~ref_count() {
            delete count;
        }

        void increment() {
            *count++;
        }

        void decrement() {
            *count--;
        }

        size_t get_count() {
            return *count;
        }
};

template <typename T>
class smart_pointer {
    private:
        T* data;
        ref_count c;

    public:
        smart_pointer(T* ptr) { 
            data = ptr;
            c.increment();
        }

        smart_pointer(const smart_pointer<T>& smrt) {
            c.increment();
        }

        //smart_pointer() {
            //;
        //}

        ~smart_pointer() {
            c.decrement();
            if (c.get_count() == 0) {
                delete data;
            }
        }

        T& operator* () {
            return *data;
        }

        T* operator-> () {
            return data;
        }

        /*
        T& operator= (kgk::smart_pointer<T>& other) {
            c.increment();
            other.data = data;
            return *data;
        }
        */
};

}; // namespace kgk

#endif // SMARTPOINTER_HPP
