#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <type_traits>
#include <math.h>
#include <stdexcept>

#include "Hash.h"

using std::pair;
using std::vector;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState
{
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
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
    int hashit(const int key, int Vsize)
    {
        return key % Vsize;
    }

    int hashit(const std::string key, int Vsize)
    {
        int hash = 0;
        for (int i = 0; i < key.size(); i++)
            hash += int(key[i]) * pow(31, i);
        return hash % Vsize;
    }

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
        return -1;
    }

    V operator[](const K &key)
    {
        return -1;
    }

    bool insert(const std::pair<K, V> &pair)
    {
        if (storage[hashit(pair.first, storage.size())].deleted)
        {
            storage[hashit(pair.first, storage.size())].data = pair;
        }
        else
        {
            int index = hashit(pair.first, storage.size()) + 1;
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

    void erase(const K &key)
    {
        storage[hashit(key, storage.size())].deleted = true;
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
        return -1;
    }

    float load_factor()
    {
        return -1;
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
        return 0;
    }
};

#endif //__P