//  Copyright 2021 Golovanov

#pragma once
#define TRAIN_H
#ifdef TRAIN_H
#include <iostream>
class Cage {
    bool light;  
 public:
    Cage* next;  
    Cage* prev;  
    Cage() : light(false), next(nullptr), prev(nullptr) {}
    void on() { light = true; }
    void off() { light = false; }
    bool get() const { return light; }
};
class Train {
    Cage* first;  
    Cage* last;   
 public:
    Train();
    void addCageInTrain();
    void printTrain();
    unsigned int sumCage();
};
#endif  // TRAIN_H
