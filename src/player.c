//Code for player
//Imports

//Structs
typedef struct float2dVector {
	float x;
	float y;
} f2Vect;

typedef struct int2dVector {
	int x;
	int y;
} i2Vect;

typedef struct key {
	char* name;
	int value;
} key;

typedef struct player {
	f2Vect location;
	f2Vect velocity;
	i2Vect size;
	int health;
	key* keys;
} player;


//Globals

//Function definitions
void intiPlayer(int, player*);


