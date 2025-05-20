#pragma once

/*
*   벡터(가변배열)의 특징
*    - 길이가 변할 수 있다. 동적 크기 변환이 가능하다.
*    - 자동으로 크기가 변경된다. 
*    - 


    int arr[15]; // 해석하기전에 바꾸는거
*/

/*
*  int 크기;
*  int capacity 수용량
* 
*  int arr = new int[5];  size0. capacity 5.
*  size 6 int[6];
*  arr = new int[10];
* 
*  resize();
*  int size, capacity;
*/

//auto R = vector<int> 추론할수 있는 힌트가 있어야함.
// std::vecotr<int>::iterator<int> aa <<- auto aa

template<typename T>
class MyVector
{
  private:
    int size; // size는 갯수이기 때문에 굳이 1.1개 표현 ? 못함 
    int capacity; // 얘도 최대 갯수가 4.4? 굳이? 못함
    T* vec; // 배열의 주소 가리킴 // double* int* std::string*

public:
    // 생성자
    MyVector() = default;
    MyVector(int startSize)
    {
        vec = new T[startSize];
        size = 0;
        capacity = startSize;
    }
    // 소멸자
    ~MyVector()
    {
       delete[] vec;

    }

    T& operator[](int idx) // vec[0] 접근하라?
    {
        return vec[idx];
    }
    void resize(int nsize)
    {
        // size : 현재 배열에 들어있는 원소의 숫자
        // nsize : 변경하려는 사이즈의 크기 

        //원소의 갯수를 재정의
        if (size < nsize)
        {
            size = size;
        }
        else
        {
            size = nsize;
        }
        // capacity는?
        capacity = nsize;

        T* arr = new T[nsize];
        
        // vec[0] , vec[1] ... size 
        for (int i = 0; i < size; i++)
        {
            arr[i] = vec[i];
        }
        delete[] vec; // 기존에 vec 가리키고 있는 공간을 메모리 해제한다.
        vec = arr; // vec 새로운 공간을 다시 가리켜라. (arr의 주소를 가리켜라)


    }
    void push_back(const T& element)
    {
        // capacity <= size 

        if (capacity <= size)
        {
            capacity = capacity * 2; // 
            resize(capacity);
        }
        vec[size] = element;
        size++;
    }


    void pop_back()
    {
        size = size > 0 ? size -1 : 0;
        
    }
    int Size() { return size; }

};


void test1()
{
    while (true)
    {
        MyVector<int>* myvec = new MyVector<int> (10);
        delete myvec;
    }
}

#include <iostream>
// int size() (return size;)
void test2()
{
    MyVector<int> vec(5);

    for (int i = 0; i < 5; i++)
    {
        vec.push_back(i + 1);
        std::cout << vec[i] << " "; 
    }

    vec.push_back(6);
    for (int i = 0; i < vec.Size(); i++)
    {
        std::cout << vec[i] << " "; 
    }

    MyVector<double> vec2(5);

    for (int i = 0; i < 5; i++)
    {
        vec2.push_back(i + 1.5);
        std::cout << vec2[i] << " ";
    }

    vec2.push_back(6);
    for (int i = 0; i < vec2.Size(); i++)
    {
        std::cout << vec2[i] << " ";
    }
}