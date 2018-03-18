//
// Created by Alex on 3/12/2018.
//

#ifndef COADACUPRIORITATI_PQUEUE_H
#define COADACUPRIORITATI_PQUEUE_H


#include <iostream>
using namespace std;
//#include <ostream>



class PQueue {

    int queue_size;//folosesc max heap pentru a retine coada
    int val_maxi;

      struct  Heap{

        int priority;
        int val;//max heap ul o sa fie creat in functie de prioritate ,radacina va avea cea mai mare prioritate

      };
Heap *array;


public:
    PQueue();

    explicit PQueue(int p);
    PQueue(const PQueue&q);
    ~PQueue();
    void insert_queue(int priority,int val);
    void delete_queue();
    int priority_max();
    int val_max();
    int nr_elemente();
    PQueue &operator++();
    PQueue &operator+(const PQueue&);
    PQueue &operator-(const PQueue&q);
    PQueue &operator=(const PQueue &q);
    friend istream& operator>>(istream&x,PQueue&q);
    friend ostream& operator<<(ostream&x, PQueue&q);



};


#endif //COADACUPRIORITATI_PQUEUE_H
