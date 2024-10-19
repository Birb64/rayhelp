#include "raylib.h"
#include <cstring>
#include <vector>
#include <string.h>
#include <iostream>
// Where the tech sounds are
#define TECHSOUNDS_PATH     "audio/sounds/technical/"

using namespace std;

#ifndef ERRORMAN_H
#define ERRORMAN_H

// GO BACK AND CHANGE THIS TO std::vector<const char*> FOR BETTER FLEXABILITY
int maxTechSounds = 19;

const char* techsoundnames[19] = {
"boot.wav", 
"delete.wav", 
"error1.wav", 
"loaderror.wav", 
"newfile.wav", 
"oldfile.wav", 
"openfile.wav", 
"place.wav", 
"question.wav", 
"redo.wav", 
"rotateFAST.wav", 
"rotateSIDE.wav", 
"rotateUP.wav", 
"savesuccess.wav", 
"snap.wav", 
"technicalerror.wav", 
"undo.wav", 
"updatedenied.wav", 
"updatesuccessful.wav"
};

// I wanted to make a "public" variable for LoadAllTechWaves, but I don't know how to yet, so here's this
// ALSO: from now on after, I'll be using std::vector because it's an array but WAY more flexible
std::vector<Wave> Standin;

// Function to load all of the techy-type sound files like error1 and undo
std::vector<Wave> LoadAllTechWaves(){

    // Resets the Standin because it does not originate from this function
    Standin = {};

    // A for loop adding the path of TECHSOUNDS_PATH and the sound names together to add to Standin
    for(int i = 0; i < maxTechSounds; i++){

        // Combine the techsounds path and techsoundnames
        std::string fullPath = std::string(TECHSOUNDS_PATH) + techsoundnames[i];
        Wave trywave = LoadWave(fullPath.c_str());
        if(trywave.sampleSize > 0){
            Standin.push_back(trywave);
        }
        else{
            printf("ERRORMAN_H COULD NOT LOAD %d", fullPath);
        }
    }

    // Standin gets returned, the end
    return Standin;
}

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

void DebugString(std::string str){
    printf(str.c_str());
}

#endif