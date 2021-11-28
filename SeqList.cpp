#include <iostream>
#include <string>

using namespace std;

/**
 * 顺序表
 * @tparam T
 */
template <class T>
class SeqList {
private:
    T* array;
    int max{};
    int last;
public:
    SeqList(int max);
    SeqList(SeqList& L);
    ~SeqList();
    int size();
    int length();
    int search(T& x);
    bool getData(int index, T& x);
    bool setData(int index, T& x);
    bool insert(int index, T& x);
    bool remove(int index, T& x);
    bool isEmpty();
    bool isFull();
    void makeEmpty();
};

template <class T>
SeqList<T>::SeqList(int max) {
    array = new T[max];
    if (array == NULL)cout << "´¢´æ·ÖÅä´íÎó" << endl;
    this->max = max;
    last = -1;
}

template <class T>
SeqList<T>::SeqList(SeqList& L) {
    this->max = L.max;
    this->last = L.last;
    this->array = new T[max];
    if (array == NULL)cout << "´¢´æ·ÖÅä´íÎó" << endl;
    for (int i = 0; i <= last; i++)
    {
        this->array[i] = L.array[i];
    }
}

template <class T>
SeqList<T>::~SeqList() {
    delete[]array;
}

template <class T>
int SeqList<T>::size() {
    return max;
}

template <class T>
int SeqList<T>::length() {
    return last+1;
}

template <class T>
int SeqList<T>::search(T& x) {
    for (int i = 0; i <= last; i++) {
        if (array[i] == x) {
            return i;
        }

    }return -1;
}

template <class T>
bool SeqList<T>::getData(int index, T& x) {
    if (index >= 0 || index <= last) {
        x = array[index];
        return true;
    }
    return false;
}

template <class T>
bool SeqList<T>::setData(int index, T& x) {
    if (index >= 0 || index <= last) {
        array[index] = x;
        return true;
    }
    return false;
}

template <class T>
bool SeqList<T>::insert(int index, T& x) {
    if (index < 0 || index >= max)return false;
    for (int i = last; i >= index; i--) {
        array[i + 1] = array[i];
    }
    array[index] = x;
    last++;
    return true;
}

template <class T>
bool SeqList<T>::remove(int index, T& x) {
    if (index<0 || index>max)return false;
    x = array[index];
    for (int i = 0; i < last; i++) {
        if (i >= index) {
            array[i] = array[i + 1];
        }
    }
    last--;
    return true;
}

template <class T>
bool SeqList<T>::isEmpty() {
    if (last == -1)
        return true;
    else return false;
}

template <class T>
bool SeqList<T>::isFull() {
    if (last == max - 1)
        return true;
    else return false;
}

template <class T>
void SeqList<T>::makeEmpty() {
    last = -1;
}

