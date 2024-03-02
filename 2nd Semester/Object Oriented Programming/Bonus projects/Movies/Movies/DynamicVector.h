#include <stdexcept>

template <typename T>
class DynamicVector {
private:
    T* elements;
    int size;
    int capacity;

    /*
     * Private resize method to increase capacity of vector
     * to newCapacity
     * @param newCapacity The new capacity of the dynmaic vector.
     */
    void resize(int newCapacity) {
        T* newElements = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }

public:
    /*
     * Default constructor for DynamicVector
     */
    DynamicVector() {
        size = 0;
        capacity = 1;
        elements = new T[capacity];
    }

    /*
     * Copy constructor for DynamicVector
     */
    DynamicVector(const DynamicVector<T>& v) {
        size = v.size;
        capacity = v.capacity;
        elements = new T[capacity];
        for (int i = 0; i < size; i++) {
            elements[i] = v.elements[i];
        }
    }

    /*
     * Destructor for DynamicVector
     */
    ~DynamicVector() {
        delete[] elements;
    }

    /*
     * Adds an element to the back of the vector.
     * If the size of the vector is equal to its capacity,
     * the capacity of the vector is doubled.
     * @param element The element to be added.
     */
    void push_back(T element) {
        if (size == capacity) {
            resize(2 * capacity);
        }
        elements[size] = element;
        size++;
    }

    /*
     * Overloads the subscript operator to access elements
     * in the vector.
     * @param index The index of the element we are trying to access.
     */
    T& operator[](int index) {
        return elements[index];
    }

    /*
     * Removes an element from the vector at the specified index.
     * Throws an out_of_range exception if index is out of range.
     * @param The index of the element we want to remove.
     */
    void remove(int index) {
        /*if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }*/
        for (int i = index; i < size - 1; i++) {
            elements[i] = elements[i + 1];
        }
        size--;
    }

    /*
     * Updates the value of an element at the specified index.
     * Throws an out_of_range exception if index is out of range.
     * @param index The index of the element we want to update.
     * @param newValue The value we want to update with.
     */
    void update(int index, const T& newValue) {
        /*if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }*/
        elements[index] = newValue;
    }

    /*
     * Returns the size of the vector.
     */
    int getSize() const {
        return size;
    }

    /*
     * Returns the capacity of the vector.
     */
    int getCapacity() const {
        return capacity;
    }

    /*
     * Returns a pointer to the first element in the vector.
     */
    T* getAllElements() const
    {
        return elements;
    }
};
