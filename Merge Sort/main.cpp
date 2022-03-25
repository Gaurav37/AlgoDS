//
//  main.cpp
//  Assignment2
//
//  Created by Gaurav Singh on 2/4/20.
//  Copyright © 2020 Gaurav Singh. All rights reserved.
//

#include <iostream>
#include<random>
#include<array>
using namespace std;

void Merge(int *,int,int,int);
void Merge_Sort(int *arr, int p, int r) {
    if (p < r) {
        //int q = (p + r) / 2;
        int q= p + (r-p)/2;
        Merge_Sort(arr, p, q);
        Merge_Sort(arr, q + 1, r);
        Merge(arr, p, q, r);
    }

}void Merge(int *arr, int p, int q, int r) {
    int n1 = q - p +1;
    int n2 = r - q;
    std::cout<<"N1N2="<<n1<<std::endl<<n2;
    int L[n1+1];
    int R[n2+1];
    for (int i = 0; i <= n1-1; i++) {
        L[i] = arr[p + i ];
        std::cout << "inside L loop L value" << L[i]<<std::endl;
        std::cout << "inside L loop Array to be sorted value" << arr[i] << std::endl;
    }
    for (int j = 0; j <= n2-1; j++) {
        R[j] = arr[q+j+1];
    }

    L[n1] = 101;
    R[n2] = 101;

    int i=0,j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i += 1;
        }
        else {
            arr[k] = R[j];
            j += 1;

        }
        std::cout << "in merge loop" << arr[k] << std::endl;
    }

}

int main()
{
    //int Array_to_be_sorted[51],i,n;
    int n;
    std::cout << "Hello User!\n";
    std::cout << "Please type size of array between 1 and 51 exclusively"<< std::endl;
    std::cin >> n;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 100);

    std::cout << "initial array"<<std::endl;

    int arr[n];
    int array_size=n;
    for (int i = 0; i < n; i++) {
        arr[i] = distribution(generator);
        std::cout << arr[i]<<std::endl;
    }

    Merge_Sort(arr, 0, array_size - 1);

    std::cout << "After sort"<<std::endl;
    for (int i = 0; i < array_size; i++){
        cout<<arr[i]<<"\t";
    }

}
