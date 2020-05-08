//
//  Sort.hpp
//  Algorithms
//
//  Created by cxz on 2020/5/8.
//  Copyright © 2020 cxz. All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>
#include "iostream"
#include "vector"

template <typename T>
class mySort{

public:
    void exch(std::vector<T> & num,int a,int b){
        auto c = num[a];
        num[a] = num[b];
        num[b] = c;
    }
    void exch(int &a,int &b){
        T c = a;
        a = b;
        b = c;
    }
    void SelectionSort(std::vector<T> & num){
        int length = num.size();
        for(auto i = 0; i < length; ++i){
            int min = i;
            for(int j = i+1; j <length; ++j){
                if(num[j] < num[min])
                    min = j;
            }
            exch(num,i,min);
        }
    }

    void InsertionSort(std::vector<T> & num){
        int length = num.size();
        for(int i = 1; i < length; ++i){
            for(int j= i; j > 0; --j){
                if(num[j] < num[j-1])
                    exch(num,j,j-1);
                else
                    break;
            }
        }
    }

    void ShellSort(std::vector<T> & num){
        int length = num.size();
        int h = 1;
        while(h < length/3)
            h = 3*h+1;
        while(h >= 1){
            for(int i = h; i <length; i++){
                for(int j = i; j >= h; j-= h){
                    if(num[j] < num[j-h])
                        exch(num,j,j-h);
                    else break;
                }
            }
            h = h/3;
        }
    }
    void subMergeSort(std::vector<T> & num,int lo,int mi,int hi){
        int sublo = 0;
        int submi = mi-lo;
        std::vector<T> temp(mi - lo);
        for(int k = lo; k <mi; k ++){
            temp[k - lo] = num[k];
        }

        for(int i = lo; i <= hi; i ++){
            if(sublo >= submi){
                num[i] = num[mi++];
            }
            else if(mi >= hi){
                num[i] = temp[sublo++];
            }
            else if(num[mi] < temp[sublo]){
                num[i] = num[mi++];
            }
            else {
                num[i] = temp[sublo++];
            }

        }

    }
    void MergeSort(std::vector<T> & num,int lo,int hi){
        if(hi - lo <2)
            return ;
        int mi = (hi - lo)/2 +lo;
        MergeSort(num,lo,mi);
        MergeSort(num,mi,hi);
        subMergeSort(num,lo,mi,hi);
    }

    void MergeSortBU(std::vector<T> num){
        unsigned long length = num.size()-1;

        for(int i = 1; i < length; i = i+i){
            for(int lo = 0; lo <length - i; lo += i+i){
                if(lo+i+i-1<length-1)
                    subMergeSort(num,lo,lo+i-1,lo+i+i-1);
                else
                {
                    subMergeSort(num,lo,lo+i-1,length-1);
                }
                
            }
        }
        
    }
    
    void QuickSort(std::vector<T> & num){
        QuickSort(num,0,num.size()-1);
    }
    void QuickSort(std::vector<T>& num,int lo,int hi){
        if(hi <= lo)
            return ;
        int j = partition(num, lo, hi);
        QuickSort(num,lo,j-1);
        QuickSort(num,j+1,hi);
    }
    int partition(std::vector<T>& num ,int lo,int hi){
        int i = lo;
        int j = hi+1;
        T temp = num[lo];
        while(true){
            while(num[++i] <temp)
                if(i == hi)
                    break;
            while(num[--j] > temp)
                if(j == lo)
                    break;
            if(i>=j)
                break;
            exch(num,lo,j);
        }
        exch(num,lo,j);
        return j;
    }

    void print(std::vector<T> & num)const{
        for(T i :num){
            std::cout << i << "  ";
        }
        std::cout << std::endl;
    }

};


#endif /* Sort_hpp */
