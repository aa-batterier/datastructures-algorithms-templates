#include <assert.h>

/*
 * Queue (FIFO, First In First Out) example in C++.
 * Implemented through a linked list.
 */

class Queue
{

        private:
                struct Link
                {
                        // Constructor for the struct.
                        Link(const double data, Link* pNext) : _data(data), _pNext(pNext) {}
                        double _data;
                        Link *_pNext;
                };
                int _size;
                Link *_pBegining, *_pEnd;

        public:
                Queue() // Constructor for the class.
                {
                        _pBegining = nullptr;
                        _pEnd = nullptr;
                        _size = 0;
                }

                Queue(const Queue& other) // Copies the object.
                {
                        _pBegining = nullptr;
                        _pEnd = nullptr;
                        _size = 0;
                        while (_size < other.getSize())
                        {
                                push(other.getData());
                        }
                }

                ~Queue() // Destructor.
                {
                        while (_size > 0)
                        {
                                pop();
                        }
                        _pBegining = nullptr;
                        _pEnd = nullptr;
                        _size = 0;
                }

                void push(const double data)
                {
                        Link *pNew = new Link(data, nullptr);
                        (*_pEnd)._pNext = pNew;
                        _pEnd = pNew;
                        _size++;
                }

                void pop(void)
                {
                        assert(_size > 0);
                        Link *pDelete = _pBegining;
                        _pBegining = (*pDelete)._pNext;
                        delete pDelete;
                        _size--;
                }

                Link* getBegining(void)
                {
                        return _pBegining;
                }

                Link* getEnd(void)
                {
                        return _pEnd;
                }

                double& getData(void)
                {
                        return (*_pBegining)._data;
                }

                const int getSize(void)
                {
                        return _size;
                }
};
