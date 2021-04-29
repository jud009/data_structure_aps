#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#include <iostream>
using namespace std;

template <class T> class ArrayList{
	
	private:
		int size;
		int capacity;
		T* array;
		
	public:
		ArrayList(){
			this->capacity = 10;
			this->size = 0;
			this->array = new T[capacity];
		}
		
		void add(T elem) {
	        if (isArrayFull()) {
	            increaseSize();
	        }
	        array[size] = elem;
	        size++;
		}
		
		bool add(T elem, int index) {
	        if (isOutOfIndex(index)) {
	            return false;
	        }
	        if (isArrayFull()) {
	            increaseSize();
	        }
	
	        for (int i = size; i > index; i--) {
	            array[i] = array[i - 1];
	        }
	        array[index] = elem;
	        size++;
	
	        return true;
    	}
    	
    	bool remove(T elem) {
	        for (int x = 0; x < size; x++) {
	            if (array[x] == elem) {
	                deleteValue(x);
	                return true;
	            }
	        }
	
	        return false;
    	}
    	
    	bool removeAt(int index) {
	        if (isOutOfIndex(index)) {
	            return false;
	        }
	        deleteValue(index);
	        return true;
    	}
    	
    	void clear() {
	        size = 0;
	        capacity = 10;
	        array = new T[capacity];
    	}
    	
        T get(int index) {
	        if (isOutOfIndex(index)) {
	            throw "OBJECT NOT FOUND";
	        }
	        return array[index];
    	}
    	
    	int indexOf(T elem) {
	        for (int x = 0; x < size; x++) {
	            if (array[x] == elem) {
	                return x;
	            }
	        }
	        
	        return -1;
    	}
    	
    	void print() {
    		cout << "[";
	        for (int x = 0; x < size; x++) {
	        	if (x == size - 1){
					cout << array[x];
					continue;	
				}
	        	cout << array[x] << ", ";
	        }
	        cout << "]";
    	}
    	
    	bool isEmpty() {
        	return size == 0;
    	}
    	
    	int getSize() {
        	return size;
    	}
    	
	private:	
		bool isOutOfIndex(int index) {
        	return index < 0 || index >= size;
		}
		
		bool isArrayFull() {
        	return size == capacity;
		}
		
		void deleteValue(int index) {
	        T* tempArray;
	        tempArray = new T[capacity];
	        
			int position = 0;
	        for (int i = 0; i < size; i++) {
	            if (i == index){
					continue;
				}
	                
	            tempArray[position] = array[i];
	            position++;
	        }
			
	        array = tempArray;
	        size--;
    	}
    	
    	void increaseSize() {
	        capacity = capacity * 2;
	        
	        T* tempArray;
	        tempArray = new T[capacity];
	        
	        for (int x = 0; x < size; x++) {
	            tempArray[x] = array[x];
	        }
	        array = tempArray;
    	}
};

#endif