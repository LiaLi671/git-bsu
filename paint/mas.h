#pragma once
#include <vector>
#include <QTextStream>
#include <QString>
#include"oval.h"
#include"square.h"
#include"romb.h"
using namespace std;

template <typename T>
class Array {
public:
    vector<T> data;
    vector<int> codes;
    int size;
    Array() : size(0) {}
    Array(int size) : size(size), data(size) {}
    Array(const Array& other) : size(other.size), data(other.data) {}
    Array& operator=(const Array& a) {	//= с копированием
        if (&a != this) {
            delete[] data;
            data = new T[a.size];
            size = a.size;
            memcpy((void*)data, (void*)a.data, sizeof(T) * size);
        }
        return *this;
    }
    T& operator[](int index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
    const T& operator[](int index) const {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
    void resize(int newSize) {
        size = newSize;
        data.resize(newSize);
    }
    friend QTextStream& operator<<(QTextStream& out, Array<T>& array) {
        for (int i = 0; i < array.size; ++i) {
            out << array.data[i] << "\n";
        }
        return out;
    }
    /*friend QTextStream& operator<<(QTextStream& out, Array<T>& array) {
        for (int i = 0; i < array.size; ++i) {
            int code=array.codes[i];
            if(code==0){
                Square* item=static_cast<Square*>(array.data[i]);
                out<<*item;
            }
            else if(code==1){
                Oval* item=static_cast<Oval*>(array.data[i]);
                out<<*item;
            }
            else if(code==2){
                Romb* item=static_cast<Romb*>(array.data[i]);
                out<<*item;
            }

        }
        return out;
    }*/
    friend QTextStream& operator>>(QTextStream& in,Array<T>& obj){
        T temp;
        while(!in.atEnd()){
            in >> temp;
            obj.data.push_back(temp);
        }
        return in;
    }
    void Push(T item,int code){
        size++;
        codes.push_back(code);
        data.push_back(item);
    }
};
