#include <assert.h>
#include <exception>

#include "ShortTest.h"
#include "IndexedList.h"
#include "ListIterator.h"




void testAll() {
    IndexedList list = IndexedList();
    assert(list.isEmpty());
    list.addToEnd(1);
    assert(list.size() == 1);
    list.addToPosition(0,2);
    assert(list.size() == 2);
    ListIterator it = list.iterator();
    assert(it.valid());
    it.next();
    assert(it.getCurrent() == 1);
    it.first();
    assert(it.getCurrent() == 2);
    assert(list.search(1) == 1);
    assert(list.setElement(1,3) == 1);
    assert(list.getElement(1) == 3);
    assert(list.remove(0) == 2);
    assert(list.size() == 1);

    ///test extra implementation:
    IndexedList lista = IndexedList();
    lista.addToEnd(1);
    lista.addToEnd(2);
    lista.addToEnd(3);
    lista.addToEnd(4);
    lista.addToEnd(5);
    lista.addToEnd(6);
    lista.addToEnd(7);
    lista.addToEnd(8);
    lista.addToEnd(9);
    lista.addToEnd(10);
    assert(lista.removeFromKtoK(11)==0);
    try {
        lista.removeFromKtoK(-1);
        assert(false);
    }
    catch (std::exception e) {
        assert(true);
    }
    assert(lista.removeFromKtoK(3)==3);
    assert(lista.search(3) == -1);
    assert(lista.search(6) == -1);
    assert(lista.search(9) == -1);
}
