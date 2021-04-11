//  Copyright 2021 Golovanov

#include "train.h"
Train::Train() {
    this->first = nullptr;
    this->last = nullptr;
}
void Train::addCageInTrain() {
    Cage* new_cage = new Cage();
    if (!first) {
        first = new_cage;
        last = new_cage;
        first->next = last;
        first->prev = last;
    }
    new_cage->prev = last;
    new_cage->next = first;
    last->next = new_cage;
    last = new_cage;
}
void Train::printTrain() {
    Cage* cage = first;
    int i = 1;
    while (cage != last) {
        std::cout << i << cage->get() << '\n';
        cage = cage->next;
        i++;
    }
    std::cout << i << last->get() << '\n';
}
unsigned int Train::sumCage() {
    int sum = 1;
    Cage* cage = first;
    first->off();
    while (true) {
        for (int i = 0; i < sum; i++) {
            cage = cage->next;
            cage->on();
        }
        for (int i = 0; i < sum; i++) {
            cage = cage->prev;
        }
        if (cage->get()) return sum;
        sum = sum+1;
    }
}
