#include <assert.h>

/*
 * Stack (LIFO, Last In First Out) example in C++.
 * Implemented through an array.
 */

class Stack
{
        private:
                int _capacity;
                int _size;
                double *_pArr;

                void copyArray(const double* source, double* destination, const int size)
                {
                        for (int i = 0; i < size; i++)
                        {
                                destination[i] = source[i];
                        }
                }

        public:
                Stack(void)
                {
                        _capacity = 1000;
                        _size = 0;
                        _pArr = new double[_capacity];
                }

                Stack(const Stack& other)
                {
                        _capacity = other.getCapacity();
                        _size = other.getSize();
                        _pArr = new double[_capacity];
                        copyArray(other.getArr(),_pArr,_size);
                }

                ~Stack()
                {
                        delete _pArr;
                        _size = 0;
                        _capacity = 1000;
                }

                void push(const double data)
                {
                        if (_size >= _capacity)
                        {
                                double *newArr = new double[_capacity*2];
                                copyArray(_pArr,newArr,_capacity);
                                delete _pArr;
                                _pArr = newArr;
                                _capacity =* 2;
                        }
                        _arr[_size] = x;
                        _size++;
                }

                void pop(void)
                {
                        assert(_size > 0);
                        _size--;
                }

                double& getTop(void)
                {
                        return _pArr[_size];
                }

                double* getArr(void)
                {
                        return _pArr;
                }

                const int getSize(void)
                {
                        return _size;
                }

                const int getCapacity(void)
                {
                        return _capacity;
                }
};
