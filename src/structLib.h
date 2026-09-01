//Header file for comman structs that will be used across the program.
#ifndef STRUCTLIB_H
#define STRUCTLIB_H

//Enums
typedef enum {
	PLAYER,
	TERRAIN,
	SPIKE,
	PLATFORM,
	BOUND_BOX,
	CHECKPOINT,
	FLAG,
	CAMERA
} ObjectType;

typedef enum {
	GROUND,
	ON_WALL,
	AIR,
	AIR_DASH_DJUMP,
	AIR_DASH,
	AIR_DJUMP
} PlayerState;

typedef enum {
	SOLID,
	BORDER
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
	int jump;
	int dash;
	int escape;
} Input;

//Key
typedef struct {
	char name[16];
	int  value;
} Key;

//Collision struct to contain collsion information for the physics engine
typedef struct{
	I2Vect dimesion;
	F2Vect offset;
} Collision;
//Context struct to contain context information for the renderer
typedef struct{
	I2Vect dimesion;
	F2Vect offset;
	int colour;
	int alpha;
	Style style;
} Context;

//Represents a singular object
typedef struct {
	int id;
	ObjectType objType;
	Collision coll;
	Context ctx;
	F2Vect loc;
} Object;

//Contains the scene of a game level
typedef struct{
	Object* objArr;
	int size;
} Scene;


typedef struct {
	int objId; //Its id number in the Scene struct
	F2Vect velocity;
	PlayerState state;
	Key* key;
} Player;

#endif
