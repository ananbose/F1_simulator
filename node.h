#ifndef HEADER_FILE_NAME_H
#define HEADER_FILE_NAME_H
// Include any necessary libraries
#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <memory>
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
struct Track
{
    // Assuming currently that it is a circle and the cars are moving points on the circle
    int radius;
};
struct Car_sensor
{
    int car_num;
    float speed;
    float acc;
    vector<float> position;
    int position;
    int time;
    Car_sensor(int _time , int _car_num, float _speed , float _acc): time(_time), car_num(_car_num), speed(_speed), acc(_acc) {}
};

struct Car
{
    int car_num;
}

struct Node {
    int position;
    int lap_num;
    float delta_ahead;
    float delta_behind;
    shared_ptr<Car> car;
};
#endif