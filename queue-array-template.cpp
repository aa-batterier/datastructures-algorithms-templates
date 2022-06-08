#include <assert.h>

/*
 * Queue(FIFO, First In First Out) example in C++.
 * Implemented through an array.
 */

class Stack
{
        private:
                int _capacity, _size, _begining;
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
                        _capacity = 1;
                        _size = 0;
                        _begining = 0;
                        _pArr = new double [_capacity];
                }

                Stack(const Stack& other)
                {
                        _capacity = other.getCapacity();
                        _size = other.getSize();
                        _begining = other.getBegining();
                        _pArr = new double[_capacity];
                        copyArray(other.getArr(),_pArr,_size);
                }

                ~Stack()
                {
                        delete [] _pArr;
                }

                void push(const double data)
                {
                        if (_size >= _capacity)
                        {
                                int newCapacity = _capacity * 2;
                                double *newArr = new double [newCapacity];
                                copyArray(_pArr,newArr,_capacity);
                                _capacity = newCapacity;
                                delete [] _pArr;
                                _pArr = newArr;
                        }
                        _pArr[(_begining + _size) % _capacity] = data;
                        _size++;
                }

                void pop(void)
                {
                        assert(_size > 0);
                        _begining = (_begining + 1) % _capacity;
                        _size--;
                }

                double& getBegining(void)
                {
                        assert(_size > 0);
                        return _pArr[_begining];
                }

                double& getEnd(void)
                {
                        assert(_size > 0);
                        return _pArr[(_begining + _size - 1) % _capacity];
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
