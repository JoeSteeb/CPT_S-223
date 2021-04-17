#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
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
    struct bucket
    {
        bool deleted;
        std::pair<K, V> data;

        bucket()
        {
            deleted = true;
        }
    };

private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
    int Ssize;
    std::vector<bucket> storage;

public:
    int hashit(K key, int Vsize)
    {
        if (std::is_same<K, int>::value)
            return key % Vsize;
        else if (std::is_same<K, std::string>::value)
        {
            int hash = 0;
            for (int i = 0; i < key.size(); i++)
                hash += int(key[i]) * pow(31, i);
            return hash % Vsize;
        }
        else
            return -1;
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
            int index = hashit(pair.first) + 1;
            while (!storage[index].deleted)
            {
                if (index >= storage.size())
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
        //storage[hashit(key.first, storage.size())].deleted = true;
    }

    void clear()
    {
        for (bucket element : storage)
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

#endif //__PROBING_HASH_H
