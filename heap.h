//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        weightArr[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        int root = weightArr[0];
        weightArr[0] = weightArr[size-1];
        size--;
        return root;
        //return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        if (weightArr[pos] < weightArr[(pos-1)/2]) {
            int tmp = weightArr[(pos-1)/2];
            weightArr[(pos-1)/2] = weightArr[pos];
            weightArr[pos] = tmp;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        if (weightArr[pos] > weightArr[(2 * pos) + 1]) {
            int tmp = weightArr[pos];
            weightArr[pos] = weightArr[2 * pos + 1];
            weightArr[2 * pos + 1] = tmp;
        }
        else if (weightArr[pos] < weightArr[(2 * pos) + 2]) {
            int tmp = weightArr[pos];
            weightArr[pos] = weightArr[2 * pos + 2];
            weightArr[2 * pos + 2] = tmp;
        }
    }
};

#endif