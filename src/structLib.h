//Header file for comman structs that will be used across the program.
#ifndef STRUCTLIB_H
#define STRUCTLIB_H
#include <SDL3/SDL_rect.h>
//Enums
typedef enum {
	BACKGROUND,
	BOUND_BOX,
	CAMERA,
	CHECKPOINT,
	FLAG,
	FOREGROUND,
	ITEM,
	PLATFORM,
	PLAYER,
	SPIKE,
	TERRAIN
} ObjectType;

typedef enum {
	AIR,
	AIR_DASH,
	AIR_DJUMP,
	AIR_DASH_DJUMP,
	GROUND,
	ON_WALL
} PlayerState;

typedef enum {
	BORDER,
	SOLID
} Style;

//Structs

//Float 2D Vector
typedef struct {
	float x;
	float y;
} F2Vect;

//Integer 2D Vector
typedef struct {
	int x;
	int y;
} I2Vect;

//User input frame
typedef struct {
	I2Vect dir;
	int dash;
	int escape;
	int jump;
} Input;

//Key
typedef struct {
	char name[16];
	int  value;
} Key;

//Context struct to contain context information for the renderer
typedef struct{
	int alpha;
	int colour;
	SDL_FRect shape;
	Style style;
} Context;

//Represents a singular object
typedef struct {
	int id;
	SDL_FRect collShape;
	Context ctx;
	F2Vect loc;
	ObjectType objType;
} Object;

//Contains the scene of a game level
typedef struct{
	int size;
	Object* objArr;
} Scene;


typedef struct {
	int objId; //Its id number in the Scene struct
	Key* keys;
	PlayerState pState;
	F2Vect velocity;
} Player;

#endif
