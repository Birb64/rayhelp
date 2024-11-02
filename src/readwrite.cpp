#include "raylib.h"
#include "errorman.h"
#include <iostream>
#include <fstream>
#include <string>


// Saves a Vector3 to a file. MAINLY ASSEMBLED FOR TEST PURPOSE
bool SavePosition(const char* fileName, unsigned int where, Vector3 pos);

// The inverse of the save up there. Instead of saving, we are loading the data back from
// the file.
Vector3 LoadPosition(const char* fileName, unsigned int where);

// Saves a Vector3 to a file. MAINLY ASSEMBLED FOR TEST PURPOSE
bool SavePositionINT(const char* fileName, unsigned int where, Vector3 pos);

// The inverse of the save up there. Instead of saving, we are loading the data back from
// the file.
Vector3 LoadPositionINT(const char* fileName, unsigned int where);

// Simply read a file from the data drive
std::string ConcatenateFile(const char* fileName);

// Simple save text to a file on the data drive
void SaveFile(const char* fileName, char* dataToSave);

