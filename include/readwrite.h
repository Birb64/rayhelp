#include "raylib.h"
#include "errorman.h"
#include <iostream>
#include <fstream>
#include <string>


///
//
//      Created by Birb64 2024
//      Reading and writing functionalities here
//
///

#ifndef READWRITE_H
#define READWRITE_H


// Simply read a file from the data drive
std::string ReadFile(const char* fileName){
    return LoadFileText(fileName);
}

// Simple save text to a file on the data drive
void SaveFile(const char* fileName, char* dataToSave){
    SaveFileText(fileName, dataToSave);
}

//void SaveDataFile(const char* fileName){
//    SaveFileData();
//}

#endif