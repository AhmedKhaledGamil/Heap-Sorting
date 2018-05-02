#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

template <class T>
class Heap
{
    vector<T> array;
    vector<T> sortedArray;
    int getParent(int child);
    void heapifyArray(int size, int i);
    int getLeftChild(int parent);
    int getRightChild(int parent);
    void heapPrint();
    int swapCounter;
public:
    Heap();
    Heap(initializer_list<T> list);
    void insertNode(T value);
    void heapSort();

};

template<class T>
Heap<T>::Heap() {swapCounter = 0;}

template<class T>
Heap<T>::Heap(initializer_list<T> list)
{
    for (T i : list)
    {
        this->array.push_back(i);
    }
    swapCounter = 0;
}

template <class T>
void Heap<T>::insertNode(T value)
{
    this->array.push_back(value);
}

template<class T>
void Heap<T>::heapSort()
{
    int n = this->array.size();
    for (int i = getParent(n); i >= 0 ; i--)
    {
        heapifyArray(n, i);
    }
    for (int i = 0; i < n; i++)
    {
        swap(this->array[0],this->array[this->array.size() -1]);
        this->sortedArray.push_back(this->array[this->array.size() - 1]);
        this->array.pop_back();
        heapifyArray(this->array.size(),0);
    }
    heapPrint();
}

template<class T>
int Heap<T>::getParent(int child)
{
    return ((child / 2) - 1);
}

template<class T>
void Heap<T>::heapifyArray(int size, int i)
{
    int maximum = i;
    int leftChild = getLeftChild(i);
    int rightChild = getRightChild(i);
    if (leftChild < rightChild && this->array[leftChild] > this->array[maximum] && leftChild < size)
        maximum = leftChild;
    if (rightChild < size && this->array[rightChild] > this->array[maximum])
        maximum = rightChild;
    if (maximum != i)
    {
        swap(this->array[i], this->array[maximum]);
        swapCounter++;
        heapifyArray(this->array.size(),maximum);
    }
}

template <class T>
int Heap<T> :: getLeftChild(int parent) { return 2 * parent + 1; }

template <class T>
int Heap<T> :: getRightChild(int parent) { return 2 * parent + 2; }

template<class T>
void Heap<T>::heapPrint()
{
    reverse(this->sortedArray.begin(),this->sortedArray.end());
    ofstream outFile("C://Users//ahmed_nqedrw9//CLionProjects//MaxHeap//33706_AhmedKhaledGamil.csv");
    for (T i : this->sortedArray)
    {
        outFile << i << "\n";
    }
    outFile << swapCounter << "\n";
}

int main()
{
    ifstream inFile;
    inFile.open("C://Users//ahmed_nqedrw9//CLionProjects//MaxHeap//unsorted.txt");

    Heap<int> heap;
    int x;
    // Don't leave an empty line at End Of File
    while(!inFile.eof())
    {
        inFile >> x;
        heap.insertNode(x);
    }
    heap.heapSort();

    inFile.close();
    return 0;
}