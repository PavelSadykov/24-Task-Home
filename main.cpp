//
//  main.cpp
//  C++ ДЗ 24
//
//  Created by Павел on 26.09.2022.
//
#include<cstdlib>
#include<ctime>
#include <iostream>
using namespace std;

template <typename T>
void show_arr (T arr[], const T length){
cout<<"[ ";
for(int i = 0; i<length; i++){
cout<<arr[i]<<" ";
}
    cout<<"]\n";
}


//Задача 1.
template<typename  T> //Заполняем массив случ числами
void fill_arr(T arr[],int length, int beg, int end){
    srand(time(0));
    for(int i=0; i< length; i++)
        arr[i] = rand()% (end-beg)+beg;
   
    
}
//Задача 2.
template<typename  T>
void resize_arr(T arr[],int length, int newlength){
    int *tmp = new int [newlength];
    if(newlength<=0)
        return;
    if(length < newlength){
        int *tmp = new int [newlength]{};
        for(int i=0; i<length;i++)//копируем элементы из arr в tmp
        tmp[i]=arr[i];
        delete [] arr;
        arr = tmp;
        cout<<"Итоговый массив: \n";
        return;
    }else
        for(int i=0; i<newlength;i++)//копируем элементы из arr в tmp
        tmp[i]=arr[i];
    cout<<"Итоговый массив: \n";
    delete [] arr;
        arr = tmp;
}


int main(int argc, const char * argv[]) {
    
   
    cout<<"Задача 1\n";
    int n,m;
    cout<<"Введите длину первого массива : ";
    cin>>n;
    int *A = new int [n];
    cout<<"Введите длину второго массива : ";
    cin>>m;
    int *B = new int [m];
    
    
    fill_arr(A,n,1,50);
    cout<<"Изначальный массив A : ";
    show_arr(A,n);
   
    fill_arr(B,m,1,50);
    cout<<"Изначальный массив B : ";
    show_arr(B,m);
    

    int *C = new int[n + m];
    for (int i = 0; i < n; i++)
        C[i] = A[i];
    for (int i = n; i < n + m; i++)
        C[i] = B[i - n];
    cout<<"Итоговый массив C : ";
    show_arr(C,n+m);
    
    delete[]A;
    A=nullptr;
    delete[]B;
    B=nullptr;

    
    cout<<"\nЗадача 2.\n";
    int size;
    int *arr = new int [5]{1,34,2,-1,0};
    cout <<"Изначальный массив : ";
    show_arr(arr,5);
    cout<<"Введите новую длину массива : \n";
    cin>>size;
    resize_arr(arr, 5, size);
    show_arr(arr,size);
    
    
    return 0;
}
