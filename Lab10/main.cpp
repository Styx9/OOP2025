#include <iostream>
#include <exception>
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
class IndexOutOfBounds : public std::exception {
public:
    const char* what() const noexcept override {
        return"Index out of bounds!";
    }
};
class CapacityExceeded : public std::exception {
public:
    const char* what() const noexcept override {
        return "Array capacity exceeded!";
    }
};
template<class T>
class ArrayIterator
{
private:
    int Current;
    T** List;// mai adaugati si alte date si functii necesare pentru iterator
public:
    ArrayIterator() {};
    ArrayIterator(T** List, int Curent);
    ArrayIterator& operator ++ ();
    ArrayIterator& operator -- ();
    T* operator*() const;
    bool operator= (ArrayIterator<T>&other);
    bool operator!=(ArrayIterator<T>&other);
    T* GetElement();
};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array(); // Lista nu e alocata, Capacity si Size = 0
    ~Array(); // destructor
    Array(int capacity); // Lista e alocata cu 'capacity' elemente
    Array(const Array<T>& otherArray); // constructor de copiere

    T& operator[] (int index); // arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T& newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T>& otherArray);

    void Sort(); // sorteaza folosind comparatia intre elementele din T
    void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
    void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator

    int Find(const T& elem); // cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

    int GetSize();
    int GetCapacity();

    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();
};

template<class T>
Array<T>::Array()
{
    Capacity = 0;
    Size = 0;
}

template<class T>
Array<T>::~Array()
{
    for (int i = 0; i < Size; i++)
        delete List[i];
    delete[] List;
}

template<class T>
Array<T>::Array(int capacity)
{
    this->Capacity = capacity;
    Size = 0;
    List = new T*[Capacity];
    for (int i = 1; i < Capacity; i++)
        List[i] = new T;
}

template<class T>
Array<T>::Array(const Array<T>& otherArray)
{
    Capacity = otherArray.Capacity;
    Size = otherArray.Size;
    List = new T * [Capacity];
    List = new T*[otherArray.Capacity];
    for (int i = 0; i < Size; i++)
        List[i] = new T(*otherArray.List[i]);
}

template<class T>
T& Array<T>::operator[](int index)
{
    //arunca exceptia;
    if (index < 0 || index >= Size)
        throw IndexOutOfBounds();
    return *List[index];
}

template<class T>
const Array<T>& Array<T>::operator+=(const T& newElem)
{
    if (Size >= Capacity)
        throw CapacityExceeded();
    List[Size] =new T(newElem);
    return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const T& newElem)
{
    if (index < 0 || index > Size || Size >= Capacity)
        throw IndexOutOfBounds();
    for (int i = Size; i > index; --i)
        List[i] = List[i - 1];
    List[index] = new T(newElem);
    ++Size;
    return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
    if (index < 0 || index > Size || Size + otherArray.Size > Capacity)
        throw IndexOutOfBounds();
    for (int i = Size - 1; i >= index; --i)
        List[i + otherArray.Size] = List[i];
    for (int i = 0; i < otherArray.Size; i++)
        List[index + i] = new T(*otherArray.List[i]);
    Size += otherArray.Size;
    return *this;
}

template<class T>
const Array<T>& Array<T>::Delete(int index)
{
    if (index < 0 || index >= Size)
        throw IndexOutOfBounds();
    delete List[index];
        for (int i = index; i < Size-1; i++)
            List[i] = List[i + 1];
        --Size;
    return *this;
}

template<class T>
bool Array<T>::operator=(const Array<T>& otherArray)
{
    if (this == otherArray) return *this;
    for (int i = 0; i < Size; i++)
        delete List[i];
    delete[] List;
    Capacity = otherArray.Capacity;
    Size = otherArray.Size;
    List = new T * [Capacity];
    for (int i = 0; i < Size; i++)
    {
        List[i] = new T(*otherArray.List[i]);
    }
    return *this;
}

template<class T>
void Array<T>::Sort()
{
    for (int i = 0; i < Size - 1; i++)
        for (int j = i + 1; j < Size; j++)
            if(*List[i]>*List[j])
            std::swap(List[i], List[j]);
}

template<class T>
void Array<T>::Sort(int(*compare)(const T&, const T&))
{
    for (int i = 0; i < Size - 1; i++)
        for (int j = i + 1; j < Size; j++)
            if (compare(*List[i], *List[j]) > 0)
                std::swap(List[i], List[j]);
}

template<class T>
void Array<T>::Sort(Compare* comparator)
{
    for (int i = 0; i < Size - 1; i++)
        for (int j = i + 1; j < Size; j++)
            if(comparator->CompareElements(List[i],List[j]) > 0)
                std::swap(List[i], List[j]);
}

template<class T>
int Array<T>::BinarySearch(const T& elem)
{
    int left = 0, right = Size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (*List[mid] == elem)
            return mid;
        else if (*List[mid] < elem)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
{
    int left = 0, right = Size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int cmp = compare(*List[mid], elem);
        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, Compare* comparator)
{
    int left = 0, right = Size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int cmp = comparator->CompareElements(List[mid],(void*)& elem);
        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

template<class T>
int Array<T>::Find(const T& elem)
{
    for (int i = 0; i < Size; i++)
        if (List[i] == elem)
            return elem;
    return -1;
}

template<class T>
int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&))
{
    for (int i = 0; i < Size; i++)
        if (compare(*List[i],elem)==0)
            return i;
    return -1;
}

template<class T>
int Array<T>::Find(const T& elem, Compare* comparator)
{
    for (int i = 0; i < Size; i++)
        if (comparator->CompareElements(List[i],(void*)&elem)==0)
            return i;
    return -1;
}

template<class T>
int Array<T>::GetSize()
{
    return Size;
}

template<class T>
int Array<T>::GetCapacity()
{
    return Capacity;
}

template<class T>
ArrayIterator<T> Array<T>::GetBeginIterator()
{
    return ArrayIterator<T>(List,0);
}

template<class T>
ArrayIterator<T> Array<T>::GetEndIterator()
{
    return ArrayIterator<T>(List,Size);
}
template<class T>
ArrayIterator<T>::ArrayIterator(T** List, int Current): List(List), Current(Current){}
template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator++()
{
    Current++;
    return *this;
}
template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator--()
{
    Current--;
    return *this;
}
template<class T>
T* ArrayIterator<T>::operator*() const
{
    return List[Current];
}

template<class T>
bool ArrayIterator<T>::operator=(ArrayIterator<T>& other)
{
    return Current ==other.Current;
}

template<class T>
bool ArrayIterator<T>::operator!=(ArrayIterator<T>&other)
{
    return Current != other.Current;
}

template<class T>
T* ArrayIterator<T>::GetElement()
{
    return List[Current];
}

int main() {
    try {
        Array<int> arr(3);

        arr += 10;
        arr += 20;
        arr += 30;

        //This will throw CapacityExceeded because the array is full
        std::cout << "Trying to add another element...\n";
        arr += 40;
    }
    catch (const CapacityExceeded& e) {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    try {
        Array<int> arr2(3);
        arr2 += 1;
        arr2 += 2;
        arr2 += 3;

        std::cout << "Trying to access element at index 5...\n";
        std::cout << arr2[5] << '\n';  //This will throw IndexOutOfBounds
    }
    catch (const IndexOutOfBounds& e) {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    try {
        Array<int> arr3(5);
        arr3 += 1;
        arr3 += 2;
        arr3.Insert(5, 99); //Invalid index
    }
    catch (const IndexOutOfBounds& e) {
        std::cerr << "Exception caught during insert: " << e.what() << '\n';
    }

    return 0;
}

