#pragma once

// Include any necessary libraries
#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;
/*
Welcome ! I am writing a simple multithreaded program that does the following
1. Thread one reads inputs from a file that has certain car specs that is currently static but will be dynamic once the car starts moving
2. Thread two computes the speed and order of the car in a linked list of cars every 30 seconds
3. Thread three is computing the speed and order of other nodes ( static now , will be dynamic later) every 30 seconds
4. Thread 4 prints the order of the cars when prompted by the user

*/

//Global variables
int LAPS = 5;
int CARS = 5;

struct Node {
    int car_num;
    //vector<float> position;// depending on position, we will insert or delete
    int position;
    int lap_num;
    int delta_prev;
    int delta_next;
};
