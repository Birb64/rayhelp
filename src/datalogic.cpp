#include "../include/raylib.h"
#include <string>

typedef struct Level;
typedef struct AnimDat;
typedef struct Sprite;
typedef struct Entity;
typedef struct Entity3D;
typedef struct Button;


Vector2 AnimFrame(AnimDat data);

// Returns current animation
int AnimCurrent(AnimDat data);

// Returns the next animation frame
Vector2 AnimNextFrameVEC(AnimDat data, int howFar);

int AnimNextFrame(AnimDat data, int howFar);

// Animate a character, include a new update time if you want
#pragma region AnimThis
AnimDat AnimThis(AnimDat data, float newUpdateTime);
AnimDat AnimThis(AnimDat data);
#pragma endregion

// Create a new sprite including animation
Sprite CreateSprite(Texture2D texture, AnimDat animdata, Vector2 position);

// Create a new sprite excluding animation
Sprite CreateSprite(Texture2D texture, Vector2 position);

// Add a new animation to a currently existing AnimDat including its ID
AnimDat AddAnimation(AnimDat data, int frameMax, int timeUpdate, int ID);

// Also draws a sprite to the screen
void DrawSprite(Sprite spr, Vector2 origin);

// Draws a Sprite to the screen
void DrawSprite(Sprite spr, Vector2 origin, int width, int height);

// Draws a 3D sprite to the screen
void DrawSprite3D(Camera3D cam3D, Sprite spr, Vector3 origin);

// A prototype player physics for a different game entirely
Vector2 ProcessBasicPhysics(Sprite spr);

// A prototype player input for a different game entirely
Vector2 PlayerInput();

// A test function for saving data to an outside file
void SaveFuncTest(const char* Filename, char* dataToSave);

Button CreateButton(Texture2D tex, Rectangle mclick, Sound snd, std::string text);


// Draws a button for the player to see
void DrawButton(Button* btn, float size, std::string text, Color color);


// Draws a button for the player to see
void DrawButton(Button* btn, float size, std::string text, Color color, bool outline);


// Activates a button, including leighway for how far away the mouse is.
void ButtonActivity(Button btn, float leighway);
void ButtonActivity(Button btn, float leighway, bool toggleable);
void ButtonActivityCam(Button *btn, float leighway, Camera2D cam2D);

// Draws an entity
void DrawEntity(Camera3D cam3D, Entity et, Vector3 pos);

// Draws 3D entity
void DrawEntity3D(Entity3D et, Vector3 pos);

// Draws 3D alpha entity
void DrawAlphaEntity(Entity3D et, Vector3 pos, int modeltype, Color c);
