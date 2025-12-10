#include "mission.h"
#include "utils.h"
#include "entity.h"
#include <stdlib.h>
#include <stdio.h>

void generate_dungeon(int current_level){

	dungeon.rooms = malloc(sizeof(Entity*)*MAX_DIM);

	int n_stanze;
    int id_entity;


    switch (current_level) {
    case 0:
        n_stanze = 3;
        id_entity = 5;

        break;
    case 1:
        n_stanze = 1;
        id_entity = 4;
        break;

    case 2:
        n_stanze = 1;
        id_entity = 5;

        break;

    default:
        break;
    }

    printf("%d %d %d\n", current_level, n_stanze, id_entity);

	for(dungeon.dim = 0; dungeon.dim < MAX_DIM && n_stanze > 0; dungeon.dim++){
		if(dungeon.dim+n_stanze < MAX_DIM) {
			Entity t = spawn_entity(current_level);
            dungeon.rooms = &t;
        }
        else{
            dungeon.rooms = &LEVEL_TABLE[current_level][id_entity];
            printf("forced dio can\n");
        }


        //check non funziona
        if(dungeon.rooms == &LEVEL_TABLE[current_level][id_entity]){
            printf("generato missione\n");
            n_stanze--;
            //hey cristian ;3
        }
        printf("%s\n", dungeon.rooms->name);
		dungeon.rooms++;
	}

	realloc(dungeon.rooms, dungeon.dim);
    dungeon.current_room = 0;
}

Dungeon* get_dungeon(){
    return &dungeon;
}

