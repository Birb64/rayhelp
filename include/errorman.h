#include "raylib.h"
#include <cstring>
#include <vector>
#include <string.h>
#include <iostream>
///
//
//      Created by Birb64 2024
//      For use in RLE and 0x216
//
///
using namespace std;

#ifndef ERRORMAN_H
#define ERRORMAN_H

// A simpler way to debug booleans
void DebugBoolean(bool b){
    if(b == true){
        printf("true\n");
    }{
        printf("false\n");
    }
}
void DebugBoolean(bool b, const char* t, const char* f){
    if(b == true){
        printf(t);
    }{
        printf(f);
    }
}

// A simpler way to debug Vectors 2 and 3
void DebugVector3(Vector3 v3){
    std::string usethis;
    usethis = "X: " + std::to_string(v3.x) + " Y: " + std::to_string(v3.x) + " Z: " + std::to_string(v3.z) + "\n";
    printf(usethis.c_str());
}
void DebugVector2(Vector2 v2){
    std::string usethis;
    usethis = "X: " + std::to_string(v2.x) + " Y: " + std::to_string(v2.x) + "\n";
    printf(usethis.c_str());
}

// Don't ask why I have this here, in fact-
/*
void DebugString(std::string str){
    printf(str.c_str());
}
*/
// There we go, fixed
#endif