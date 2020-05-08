//
//  main.cpp
//  Algorithms
//
//  Created by cxz on 2020/5/8.
//  Copyright © 2020 cxz. All rights reserved.
//

#include <iostream>
#include "Sort.hpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::vector<int> num{5,4,3,2,1,6};
    mySort<int> Sort;
//    Sort.MergeSort(num,0,5);
//    Sort.MergeSortBU(num);
    Sort.QuickSort(num);
    Sort.print(num);
    
    
    return 0;
}
