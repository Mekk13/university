#pragma once
#include<vector>
#include<utility>
//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<int,int>(-111111, -111111)
#define DELETED_TELEM pair<int,int>(-222222, -222222)

typedef bool(*Condition)(TKey);

class MultiMapIterator;

class MultiMap
{
	friend class MultiMapIterator;

private:
	TElem* elements;
	int mapsize, capacity;

	//function that returns a hash
	int hash(TKey key, int cap);

	void resize();
	void rehash(TElem* new_elements, int new_capacity);
	int nextPrime(int n);
	

public:

	//extra:
	void filter(Condition cond);

	//constructor
	MultiMap();

	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	//descturctor
	~MultiMap();


};

