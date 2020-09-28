#ifndef sorter_h
#define sorter_h
#include <stdlib.h>
#include <vector>

using namespace std;

template<typename T>
class MergeSort{
    public:
    MergeSorter(){};
    ~Sorter(){};
    void swap(int i,int j,vector<T>&a){
        T aux=a[i];
        a[i]=a[j];
        a[j]=aux;
    };
     void sort(vector<T> &a){
        mergesort(a, 0, a.size()-1);
    };

    void mergesort(vector<T> &a, int left, int right){
        int middle;
        if (left < right){
            middle = left + (right-left) / 2;
            mergesort(a, left, middle);
            mergesort(a, middle+1, right);
            merge(a, left, middle, right);
        }
    };

    void merge(vector<T> &a, int left, int middle, int right){
        int i, j, k; 
        int n1 = middle - left + 1; 
        int n2 = right - middle;
        int I[n1], D[n2]; 

        for (i = 0; i < n1; i++){
            I[i] = a[left + i]; 
            for (j = 0; j < n2; j++){
                D[j] = a[middle + 1 + j]; 
            }
        } 
        i = 0; 
        j = 0; 
        k = left; 
        while (i < n1 && j < n2){  
            if (I[i] <= D[j]){ 
                a[k] = I[i]; 
                i++; 
            } 
            else{ 
                a[k] = D[j]; 
                j++; 
            } 
            k++; 
        } 
  
        while (i < n1){ 
            a[k] = I[i]; 
            i++; 
            k++; 
        } 
        while (j < n2){ 
            a[k] = D[j]; 
            j++; 
            k++;
        } 
    };
};



#endif