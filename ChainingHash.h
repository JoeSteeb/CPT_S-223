/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

// Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::list;
using std::pair;
using std::vector;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template <typename K, typename V>
class ChainingHash : public Hash<K, V>
{
private:
    int Ssize;
    std::vector<std::list<std::pair<K, V>>> storage;

public:
    ChainingHash(int n = 11)
    {
        Ssize = 0;
        storage.resize(n);
    }

    ~ChainingHash()
    {
        this->clear();
    }

    int size()
    {
        return Ssize;
    }

    V operator[](const K &key)
    {
        for (std::pair<K, V> element : storage[hash(key)])
        {
            if (element.first == key)
            {
                return element.second;
                break;
            }
        }
    }

    bool insert(const std::pair<K, V> &pair)
    {
        if (load_factor() > 0.75)
        {
            storage.resize(findNextPrime(storage.size() * 2));
        }
        //std::cout << pair.first << ' ' << pair.second;
        storage[hash(pair.first)].push_back(pair);
        Ssize++;
        return true;
    }

    void erase(const K &key)
    {
        for (std::pair<K, V> element : storage[hash(key)])
        {
            if (element.first == key)
            {
                storage[hash(key)].remove(element);
                break;
            }
        }
        Ssize--;
    }

    void clear()
    {
        for (std::list<std::pair<K, V>> List : storage)
        {
            List.clear();
        }
        Ssize = 0;
    }

    int bucket_count()
    {
        return storage.size();
    }

    float load_factor()
    {
        if (storage.size() != 0)
            return (float)Ssize / (float)storage.size();
        else
            return 0.0;
    }

private:
    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K &key)
    {
        //if (storage.size() != 0)
        return key % storage.size();
        // else
        //return 0;
    }
};

#endif //__CHAINING_HASH_H
