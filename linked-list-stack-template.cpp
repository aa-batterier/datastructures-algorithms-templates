#include <assert.h>

/*
 * Stack (LIFO, Last In First Out) example in C++.
 * Implemented through a linked list.
 */

class Stack
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
                Link *_pTop;

        public:
                Stack() // Constructor for the class.
                {
                        _pTop = nullptr;
                        _size = 0;
                }

                Stack(const Stack& other) // Copies the object.
                {
                        _pTop = nullptr;
                        _size = 0;
                        while (_size < other.getSize())
                        {
                                push(other.getData());
                        }
                }

                ~Stack() // Destructor.
                {
                        while (_size > 0)
                        {
                                pop();
                        }
                        _pTop = nullptr;
                        _size = 0;
                }

                void push(const double data)
                {
                        _pTop = new Link(data, _pTop);
                        _size++;
                }

                void pop(void)
                {
                        assert(_size > 0);
                        Link *pDelete = _pTop;
                        _pTop = (*pDelete)._pNext;
                        delete pDelete;
                        _size--;
                }

                void insert(Link *pBefore, const double data)
                {
                        (*pBefore)._pNext = new Link(data, (*pBefore)._pNext);
                }

                void eraseAfter(Link *pBefore)
                {
                        assert(_size > 0);
                        Link *pDelete = (*pBefore)._pNext;
                        (*pBefore)._pNext = (*pDelete)._pNext;
                        delete pDelete;
                }

                Link* getTop(void)
                {
                        return _pTop;
                }

                double& getData(void)
                {
                        return (*_pTop)._data;
                }

                const int getSize(void)
                {
                        return _size;
                }
};
