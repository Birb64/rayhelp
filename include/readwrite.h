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



// Saves a Vector3 to a file. MAINLY ASSEMBLED FOR TEST PURPOSE
bool SavePosition(const char* fileName, unsigned int where, Vector3 pos){
    bool completed;
    // the size of the data on the line we will modify
    int dataSize;
    unsigned int newSize = 0;
    // Loads the file to change and points the size of the data
    unsigned char* fileData = LoadFileData(fileName, &dataSize);
    unsigned char* newData = NULL;
    // If the file exists
    if(fileData != NULL){
        // This is something I ripped straight from the raylib examples. I do not understand
        // the meaning of this if statement yet.
        if(dataSize <= (where*sizeof(Vector3))){
            // The new data size should be able to hold the size of a Vector3 including wherever
            // in the file it is held at and then some.
            newSize = (where + 1)*sizeof(Vector3);
            
            // this is increasing the size of newData to fit all that was in the old data
            // and include new space for the new data to be held.
            newData = (unsigned char *)RL_REALLOC(fileData, newSize);

            // Whether or not the datasize can be stored
            if(newData != NULL){

                // This grabs the spot of newData where the Vector3 can be stored
                Vector3 *dataPoint = (Vector3 *)newData;
                
                // This takes that spot from the line above and changes it to equal pos
                dataPoint[where] = pos;
            }
            else{
                
                TraceLog(2, "The file [%s] is unable to be given the data.\nThe size (%u) at position (%u) is simply too large.", fileName, dataSize, where*sizeof(Vector3));
                
                // Because the data is too large to store, we bring back the old data to replace the new data
                newData = fileData;
                newSize = dataSize;
            }
        }
        else{
            // I still do not understand the meaning of the if statement to include the dataSize
            // when it is clearly initialized as 0. 
            newData = fileData;
            newSize = dataSize;

            Vector3 *dataPoint = (Vector3 *)newData;
            dataPoint[where] = pos;
        }
        completed = SaveFileData(fileName, newData, newSize);
        // Because newData is a pointer, this will free the data it points to from RAM.
        RL_FREE(newData);
    }
    // If the file does not exist, create a new one with the data we want saved.
    else{
        TraceLog(7, "Created new file [%s]", fileName);

        /// Adds the new line for where to store our data
        dataSize = (where + 1)*sizeof(Vector3);
        // Allocate size bytes of memory into fileData
        // In other words, expand fileData to include our new data
        fileData = (unsigned char *)RL_MALLOC(dataSize);

        // Initialize a pointer to point to the file we are saving to
        Vector3 *dataPoint = (Vector3 *)fileData;

        // Add the position to where the data pointer is pointing to on the fileData
        dataPoint[where] = pos;

        // Finally, save the data to the file we wanted it to be
        completed = SaveFileData(fileName, fileData, dataSize);
        UnloadFileData(fileData);
        TraceLog(7, "Stored value [%s] to [$d]", pos, fileName);

    }
    return completed;

}
///     THEORY TIME:
//          If you want to make a new kind of saving data, replace Vector3 with whatever
//          type you want to save. 

// The inverse of the save up there. Instead of saving, we are loading the data back from
// the file.
Vector3 LoadPosition(const char* fileName, unsigned int where){

    // The value we will return by the end of this function.
    Vector3 returner = {0, 0, 0};
    int dataSize = 0;
    // Loads file pointing to dataSize
    unsigned char *fileData = LoadFileData(fileName, &dataSize);

    if(fileData != NULL){
        // Point to the data within fileData
        Vector3 *dataPoint = (Vector3 *)fileData;

        // Set the returner to a place the dataPointer can point
        returner = dataPoint[where];

        UnloadFileData(fileData);
        TraceLog(7, "File [%s] loaded position [%u]", fileName, returner);
    }
    // What did I tell ya?
    return returner;
}

// Simply read a file from the data drive
std::string ConcatenateFile(const char* fileName){
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