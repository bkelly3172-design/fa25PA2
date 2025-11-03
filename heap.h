//
// Created by Manju Muralidharan on 10/19/25.
//
//Brett Kelly
//RedID: 1312844745
//10/21/25
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
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        int root = data[0];
        data[0] = data[size-1];
        size--;
        downheap(0,weightArr);
        return root;
        //return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) {
            if (weightArr[pos] >= weightArr[(pos-1)/2]) {
                return;
            }
            int tmp = data[(pos-1)/2];
            data[(pos-1)/2] = data[pos];
            data[pos] = tmp;
            pos = (pos-1)/2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // // TODO: swap parent downward while larger than any child
        int right;
        int left;
        int smallest;
        while ((left = 2 * pos + 1)< size) {
            right = left + 1;
            smallest = pos;
            if (weightArr[left] < weightArr[smallest]) {
                smallest = left;
            }
            if (weightArr[right] < weightArr[smallest]) {
                smallest = right;
            }
            if (smallest == pos) {
                return;
            }
            int tmp = data[pos];
            data[pos] = data[smallest];
            data[smallest] = tmp;
            pos = smallest;
        }
    }
};

#endif