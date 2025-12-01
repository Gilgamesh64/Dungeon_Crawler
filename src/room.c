#include "room.h"
#include "utils.h"
#include "entity.h"

#include <stdio.h>

void generate_entities(int mission){
	Entity en = generate_entity("gigi", 10, 1000000, -70);
	for (int i = 0; i < MAX_ROOM_COUNT; i++){
		entities[i]->danno = roll_dice();
		printf("Generated: %d", entities[i]->danno);
	}
}