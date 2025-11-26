#ifndef ROOM_H
#define ROOM_H

#include <stdbool.h>

typedef struct{
	Enemy* enemy;
	bool trap;	
} Room;

typedef struct{
	char* name;
	int health_points;
	int damage;
} Enemy;

Room generate_room();
Enemy generate_enemy();
#endif