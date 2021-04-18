#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <math.h>
#include <stdexcept>

#include "Hash.h"

using std::pair;
using std::vector;

// Can be used for tracking lazy deletion for each element in your table
template <typename K, typename V>
struct bucket
{
    bool deleted;
    std::pair<K, V> data;

    bucket()
    {
        deleted = true;
    }
};

template <typename K, typename V>
class ProbingHash : public Hash<K, V>
{ // derived from Hash

private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
    int Ssize;
    std::vector<bucket<K, V>> storage;

public:
    ProbingHash(int n = 11)
    {
        Ssize = 0;
        storage.resize(n);
    }

    ~ProbingHash()
    {
        this->clear();
    }

    int size()
    {
        return Ssize;
    }

    V operator[](const K &key)
    {
        int hashVal = hash(key);
        if (storage[hashVal].data.first == key && !storage[hashVal].deleted)
            return storage[hashVal].data.second;
        else
        {
            for (int i = hashVal + 1; i != hashVal; i++)
            {
                if (storage[i].data.first == key && !storage[hashVal].deleted)
                    return storage[i].data.second;
                if (i >= (int)(storage.size() - 1))
                    i = 0;
            }
        }
        return -1;
    }

    bool insert(const std::pair<K, V> &pair)
    {
        Ssize++;
        if (load_factor() > 0.5)
        {
            storage.resize(storage.size() * 2);
        }

        if (storage[hash(pair.first)].deleted)
        {
            storage[hash(pair.first)].data = pair;
        }
        else
        {
            int index = hash(pair.first) + 1;
            while (!storage[index].deleted)
            {
                if (index >= (int)storage.size())
                    index++;
                else
                    index = 0;
            }
            storage[index].data = pair;
            storage[index].deleted = false;
            Ssize++;
        }
        return true;
    }

    //fixme completly wrong
    void erase(const K &key)
    {
        int hashVal = hash(key);
        if (storage[hashVal].data.first == key)
            storage[hashVal].deleted = true;
        else
        {
            for (int i = hashVal + 1; i != hashVal; i++)
            {
                if (storage[i].data.first == key)
                    storage[i].deleted = true;
                if (i >= (int)(storage.size() - 1))
                    i = 0;
            }
        }
    }

    void clear()
    {
        for (bucket<K, V> element : storage)
        {
            element.deleted = true;
        }
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
        return key % this->storage.size();
    }
};

#endif //__P