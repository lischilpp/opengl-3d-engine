#include <vector>
#include <iostream>
#include <initializer_list>

template <class T> class StorageVector
{
public:
    T& operator[](int i);
    void Add(T num);
    void Add(std::initializer_list<T> list);
    void AddMultible(std::initializer_list<T> list, int amount);
    int Size();
private:
    std::vector<T> data;
};

template <class T> void StorageVector<T>::Add(T arg)
{
    data.push_back(arg);
}

template <class T> void StorageVector<T>::Add(std::initializer_list<T> list)
{
    data.insert(data.end(), list.begin(), list.end());
}

template <class T> void StorageVector<T>::AddMultible(std::initializer_list<T> list, int amount)
{
    for (int i = 0; i < amount; i++)
        data.insert(data.end(), list.begin(), list.end());
}

template <class T> int StorageVector<T>::Size()
{
    return data.size();
}

template <class T> T& StorageVector<T>::StorageVector::operator[](int i)
{
    return data[i];
}
