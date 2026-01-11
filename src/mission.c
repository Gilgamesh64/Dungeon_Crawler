#include "mission.h"


void generate_dungeon(int current_level) {
    int n_stanze;
    int id_entity;

    dungeon.dim = 10;
    dungeon.current_room = 0;

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

    /*for(dungeon.dim = 0; dungeon.dim < MAX_DIM && n_stanze > 0; dungeon.dim++){
            if(dungeon.dim+n_stanze < MAX_DIM) {
                    Entity t = spawn_entity(current_level);
        dungeon.rooms = &t;
    }
    else{
        dungeon.rooms = &LEVEL_TABLE[current_level][id_entity];
    }

    if(dungeon.rooms == &LEVEL_TABLE[current_level][id_entity]){
        n_stanze--;
    }
    printf("%s\n", dungeon.rooms->name);
            dungeon.rooms++;
    }*/

    for (size_t i = 0; i < 10; i++) {
        dungeon.rooms[i] = spawn_entity(current_level); // assign struct to struct
        printf("%s\n", dungeon.rooms[i]->name);
    }

    // dungeon.rooms = realloc(dungeon.rooms, sizeof (Entity*) * dungeon.dim); //TODO
    dungeon.current_room = 0;
}

Dungeon *get_dungeon() {
    return &dungeon;
}
