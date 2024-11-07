#include "raylib.h"
#include "errorman.h"
#include <iostream>
#include <fstream>
#include <string>


// THE save float data function.
void SaveFloat(const char* fileName, float data, int where);
// More of a shorthand purpose than anything, just made to write many floats at once.
void SaveMultipleFloat(const char* fileName, float *data, int where, int howMany);
// Save Vector3 values(not really, but you see why)
void SaveVector3(const char* fileName, Vector3 data, int where);

// Loads floats like we want it to
float LoadFloat(const char* fileName, int where);
// Load multiple floats. The specific reason for it being a pointer is because I can add
// values just like an array on the whim
float *LoadMultipleFloat(const char* fileName, int where, int howMany);
// The most simple looking code I could have ever come up. It loads the Vector3
Vector3 LoadVector3(const char* fileName, int where);

// Simply read a file from the data drive
std::string ConcatenateFile(const char* fileName);

// Simple save text to a file on the data drive
void SaveFile(const char* fileName, char* dataToSave);

/// COMPLETELY STOLEN CODE : REMAKE/RENEW IF YOU CAN
Vector3 LoadStorageValue(const char *fileName, unsigned int position);
bool SaveStorageValue(const char *fileName, unsigned int position, Vector3 value);