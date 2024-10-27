#include "raylib.h"
#include <string>
#include <iostream>

///
//
//      Created by Birb64 2024
//      Adds multiple functions for ease of use in raylib
//
///

#ifndef DATALOGIC_H
#define DATALOGIC_H



using namespace std;
// Delta time
int dT(){
    return GetFrameTime();
};

#pragma region Structs
// Structure for a level
typedef struct Level{
    // Worldspace
    Vector3 pos;

    // Model
    Model m;

    // Rotation
    Vector4 rotation;

} Level;


// Structure for animation data
typedef struct AnimDat{
    // Y is the animation and X is the frame it is on
    Vector2 frame;

    // MaxFrame(what goes into the area is the Y)
    int maxFrame[255];
    
    // How the animation is drawn
    Rectangle drawRec;

    // when to update the animation(the area gets the Y)
    int updateTime[255];

    // how long the frame has stayed
    int runningTime;
} AnimDat;


// Structure for sprite
typedef struct Sprite{
    // Sprite Texture
    Texture2D tex;

    // Animation protocol
    AnimDat data;

    // Position
    Vector2 pos;

    // Origin
    Vector2 origin;

    // Width
    int width;

    // Height
    int height;

    // Rotation
    int rot;

    // Scale
    float scale;

} Sprite;

typedef struct Entity{

    // Rendered sprite
    Sprite spr;

    // Entity Scale
    Vector3 scale;

    // Entity type
    int type;

    // Variation
    int Variation;
    
    // Velocity
    Vector3 vel;

    // Rotation
    Vector3 rot;

    // Position
    Vector3 pos;


} Entity;

typedef struct Entity3D{

    // Entity model
    Model m;

    // Entity Scale
    Vector3 scale;

    // Entity type
    int type;

    // Variation
    int Variation;
    
    // Velocity
    Vector3 vel;

    // Rotation
    Vector3 rot;

    // Position
    Vector3 pos;


} Entity3D;


typedef struct Button{

    // Texture
    Texture2D tex;

    // Text
    std::string text;

    // Font
    Font fnt;

    // Button Position
    Vector2 pos;

    // Text offset
    Vector2 offset;

    // Button sound
    Sound snd;

    // Mouseclick region
    Rectangle mclick;

    // Scale
    Vector2 scale;

    // Text Scale
    float tscale;

    // Is it pressed down?
    int isPressed;

    // Has the button been pressed down?
    int beenPressed;

} Button;
#pragma endregion

// Returns the current animation frame
Vector2 AnimFrame(AnimDat data){
    Vector2 translate{data.drawRec.width*data.frame.x, data.drawRec.height*data.frame.y};
    return translate;
};

// Returns current animation
int AnimCurrent(AnimDat data){
    return (int)data.frame.y;
};

// Returns the next animation frame
Vector2 AnimNextFrameVEC(AnimDat data, int howFar){
    // if the frame + how many frames afterwards is out of bounds of the maxFrame
    if(data.frame.x+howFar >= data.maxFrame[AnimCurrent(data)]){
        // change animation to the last frame of the current animation
        Vector2 translate{data.drawRec.width*data.maxFrame[AnimCurrent(data)], data.drawRec.height*data.frame.y};
        return translate;
    }
    else{
        // else you change the animation to be the animation plus how far
        Vector2 translate{data.drawRec.width*(data.frame.x+howFar), data.drawRec.height*data.frame.y};
        return translate;
    }
    
};

int AnimNextFrame(AnimDat data, int howFar){
    if(data.frame.x+howFar >= data.maxFrame[AnimCurrent(data)]){
        data.frame.x = data.drawRec.width*data.maxFrame[AnimCurrent(data)];
    }
    else{
        data.frame.x = data.drawRec.width*howFar;
    }
    return data.frame.x;
}

// Animate a character, include a new update time if you want
#pragma region AnimThis
AnimDat AnimThis(AnimDat data, float newUpdateTime){

    data.runningTime += dT();
    data.updateTime[AnimCurrent(data)] = newUpdateTime;
    if(data.runningTime >= data.updateTime[AnimCurrent(data)]){
        data.drawRec.x += AnimNextFrameVEC(data, 1).x;

        data.frame.x++;
        if(data.frame.x >= data.maxFrame[AnimCurrent(data)]){
            data.frame.x = 0;
        }
        data.runningTime = 0.0;
    }
    return data;
};
AnimDat AnimThis(AnimDat data){

    data.runningTime += dT();
    if(data.runningTime >= data.updateTime[AnimCurrent(data)]){
        data.drawRec.x += data.frame.x * data.drawRec.width;

        data.frame.x++;
        if(data.frame.x >= data.maxFrame[AnimCurrent(data)]){
            data.frame.x = 0;
        }
        data.runningTime = 0.0;
    }
    return data;
};
#pragma endregion

// Create a new sprite including animation
Sprite CreateSprite(Texture2D texture, AnimDat animdata, Vector2 position){
    Sprite returner{texture, animdata, position};
    return returner;
};
// Create a new sprite excluding animation
Sprite CreateSprite(Texture2D texture, Vector2 position){
    Sprite returner{texture};
    returner.pos = position;
    return returner;
};

// Add a new animation to a currently existing AnimDat including its ID
AnimDat AddAnimation(AnimDat data, int frameMax, int timeUpdate, int ID){
    data.maxFrame[ID] = frameMax;
    data.updateTime[ID] = timeUpdate;
    return data;
};

// Also draws a sprite to the screen
void DrawSprite(Sprite spr, Vector2 origin){
    DrawTexturePro(spr.tex, 
    {origin.x*spr.data.frame.x, origin.x*spr.data.frame.y, spr.data.drawRec.width, spr.data.drawRec.height}, // Source / Start
    {spr.pos.x,spr.pos.y,spr.scale,spr.scale}, // Destination / End
    {origin.x * spr.scale/100, origin.y * spr.scale/100}, // Origin
    spr.rot, // Rotation
    WHITE);
    
}

// Draws a Sprite to the screen
void DrawSprite(Sprite spr, Vector2 origin, int width, int height){
    DrawTexturePro(spr.tex, 
    {width*spr.data.frame.x, height*spr.data.frame.y, spr.data.drawRec.width, spr.data.drawRec.height}, // Source / Start
    {spr.pos.x,spr.pos.y,spr.scale,spr.scale}, // Destination / End
    {origin.x * spr.scale/100, origin.y * spr.scale/100}, // Origin
    spr.rot, // Rotation
    WHITE);
}



// Draws a 3D sprite to the screen
void DrawSprite3D(Camera3D cam3D, Sprite spr, Vector3 pos){
    DrawBillboardPro(cam3D, spr.tex,
    {spr.origin.x*spr.data.frame.x, spr.origin.x*spr.data.frame.y, spr.data.drawRec.width, spr.data.drawRec.height},
    pos,
    {0,1,0},
    {spr.scale,spr.scale},
    {spr.origin.x * spr.scale/100, spr.origin.y * spr.scale/100},
    spr.rot,
    WHITE
    );
}

// A prototype player physics for a different game entirely
Vector3 ProcessBasicPhysics(Entity et){
    et.pos.x += et.vel.x;
    et.pos.y += et.vel.y;
    et.pos.z += et.vel.z;
    return et.pos;
};

// A prototype player input for a different game entirely
Vector2 PlayerInput(){
    Vector2 returner{((IsKeyDown(KEY_RIGHT))-(IsKeyDown(KEY_LEFT)))*2, ((IsKeyDown(KEY_DOWN))-(IsKeyDown(KEY_UP)))*2};
    //Vector2 returner{(GAMEPAD_AXIS_LEFT_X), (GAMEPAD_AXIS_LEFT_Y)};
    return returner;
}



Button CreateButton(Texture2D tex, Rectangle mclick, Sound snd, std::string text){
    Button newButton{tex, text};
    newButton.mclick = mclick;
    newButton.snd = snd;
    return newButton;
    
}


// Draws a button for the player to see
void DrawButton(Button* btn, float size, std::string *text, Color color){
    //DrawTexturePro(btn->tex, 
    //{0, 0, (float)btn->tex.width, (float)btn->tex.height}, // source x, source y, source width, source height
    //{btn->pos.x*100,btn->pos.y*100,btn->mclick.width,btn->mclick.height}, // Destination / End
    //{btn->pos.x, btn->pos.y}, // Origin
    //0, // Rotation
    //WHITE);
    DrawTextureEx(btn->tex, btn->pos, 0, size, WHITE);
    DrawText(text->c_str(), btn->pos.x+btn->offset.x, btn->pos.y+btn->offset.y, btn->tscale, color);
    
    btn->mclick.x = btn->pos.x;
    btn->mclick.y = btn->pos.y;
}


// Draws a button for the player to see
void DrawButton(Button* btn, float size, std::string text, Color color, bool outline){
    //DrawTexturePro(btn->tex, 
    //{0, 0, (float)btn->tex.width, (float)btn->tex.height}, // source x, source y, source width, source height
    //{btn->pos.x*100,btn->pos.y*100,btn->mclick.width,btn->mclick.height}, // Destination / End
    //{btn->pos.x, btn->pos.y}, // Origin
    //0, // Rotation
    //WHITE);
    DrawTextureEx(btn->tex, btn->pos, 0, size, color);
    if(outline){
        DrawText(text.c_str(), btn->pos.x+btn->offset.x, btn->pos.y+btn->offset.y, btn->tscale, color);
        DrawText(text.c_str(), btn->pos.x+btn->offset.x-btn->scale.x/2, btn->pos.y+btn->offset.y-btn->scale.x/2, btn->scale.x*1.5, BLACK);
        
    }
    else{
        DrawText(text.c_str(), btn->pos.x+btn->offset.x, btn->pos.y+btn->offset.y, btn->tscale, color);
    }
    btn->mclick.x = btn->pos.x;
    btn->mclick.y = btn->pos.y;
}



// Activates a button, including leighway for how far away the mouse is.
void ButtonActivity(Button *btn, float leighway){
  
    if(CheckCollisionRecs(btn->mclick, {GetMousePosition().x - leighway/2, GetMousePosition().y - leighway/2, leighway, leighway}) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        btn->isPressed = true;
        PlaySound(btn->snd);
    }
    else{
        btn->isPressed = false;
    }
}
// Activates a button, including leighway for how far away the mouse is.
void ButtonActivity(Button *btn, float leighway, bool toggleable){
    
    if(toggleable){
        if(CheckCollisionRecs(btn->mclick, {GetMousePosition().x - leighway/2, GetMousePosition().y - leighway/2, leighway, leighway}) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(btn->isPressed == true){
                btn->isPressed = false;
            }
            else{
                btn->isPressed = true;
            }
            PlaySound(btn->snd);
        }

    }
    else{
        if(CheckCollisionRecs(btn->mclick, {GetMousePosition().x - leighway/2, GetMousePosition().y - leighway/2, leighway, leighway}) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            btn->isPressed = true;
            PlaySound(btn->snd);
        }
        else{
            btn->isPressed = false;
        }

    }
}

// Activates a button through a cam2D, including leighway for how far away the mouse is.
void ButtonActivityCam(Button *btn, float leighway, Camera2D cam2D){
    Vector2 cameraloc = GetScreenToWorld2D(GetMousePosition(), cam2D);
    if(CheckCollisionRecs(btn->mclick, {cameraloc.x - leighway/2, cameraloc.y - leighway/2, leighway, leighway}) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        btn->isPressed = true;
        PlaySound(btn->snd);
    }
    else{
        btn->isPressed = false;
    }
}


// Draws an entity
void DrawEntity(Camera3D cam3D, Entity et, Vector3 pos){
    DrawBillboardPro(cam3D, // Camera
    et.spr.tex, // Entity Texture
    {et.spr.width*et.spr.data.frame.x, et.spr.height*et.spr.data.frame.y, et.spr.data.drawRec.width, et.spr.data.drawRec.height}, // Source Rect
    pos,
    {0,1,0}, // Up direction
    {et.scale.x,et.scale.y}, // Scale
    {et.spr.origin.x * et.scale.x/100, et.spr.origin.y * et.scale.y/100}, // Origin
    et.rot.y, // Rotation
    WHITE // Color
    );
}


// Draws an entity
void DrawEntity3D(Entity3D et, Vector3 pos){
    DrawModelEx(et.m, pos, et.rot, 0, et.scale, WHITE);
}

void DrawAlphaEntity(Entity3D et, Vector3 pos, int modeltype, Color c){
    switch(modeltype){
        case 0:
        DrawCircle3D(pos,et.scale.x,et.rot,0,c);
        break;
        case 1:
        DrawCube(pos,et.scale.x,et.scale.y,et.scale.z,c);
        break;
        case 2:
        DrawCylinder(pos,et.scale.y/2,-(et.scale.y/2),et.scale.y,16,c);
        break;
        default:
        DrawCircle3D(pos,et.scale.x,et.rot,0,c);
        break;
    }
}

#endif