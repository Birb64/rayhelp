#include "raylib.h"


///
//
//      Created by Birb64 2024
//      I can do what I want, that includes making my own math logic
//
///
#ifndef MATHLOGIC_H
#define MATHLOGIC_H

// Return a sign of your int
int SignOf(int sign){
    if(sign > 0){
        return 1;
    }
    else
    {
        return -1;
    }
};
// Return a sign of your float
float SignOf(float sign){
    if(sign > 0){
        return 1;
    }
    else
    {
        return -1;
    }
};
// Return a sign of your double
double SignOf(double sign){
    if(sign > 0){
        return 1;
    }
    else
    {
        return -1;
    }
};


// Return the maximum int
int MaxOf(int valueA, int valueB){
    if(valueA > valueB){
        return valueA;
    }
    else{
        return valueB;
    }
};
// Return the maximum float
float MaxOf(float valueA, float valueB){
    if(valueA > valueB){
        return valueA;
    }
    else{
        return valueB;
    }
};
// Return the maximum double
double MaxOf(double valueA, double valueB){
    if(valueA > valueB){
        return valueA;
    }
    else{
        return valueB;
    }
};


// Return the minimum int
int MinOf(int valueA, int valueB){
    if(valueA < valueB){
        return valueA;
    }
    else{
        return valueB;
    }
};
// Return the minimum float
float MinOf(float valueA, float valueB){
    if(valueA < valueB){
        return valueA;
    }
    else{
        return valueB;
    }
};
// Return the minimum double
double MinOf(double valueA, double valueB){
    if(valueA < valueB){
        return valueA;
    }
    else{
        return valueB;
    }
};


// Return the absoulte of an int
int Abs(int value){
    if(value < 0){
        return value * -1;
    }
    else{
        return value;
    }
};
// Return the absoulte of a float
float Abs(float value){
    if(value < 0){
        return value * -1;
    }
    else{
        return value;
    }
};
// Return the absoulte of a double
double Abs(double value){
    if(value < 0){
        return value * -1;
    }
    else{
        return value;
    }
};




#endif