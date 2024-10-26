#include "raylib.h"
#include "errorman.h"
#include <iostream>
#include <fstream>
#include <string>

// Simply read a file from the data drive
std::string readFile(const char* fileName);

// Simple save text to a file on the data drive
void SaveFile(const char* fileName, char* dataToSave);