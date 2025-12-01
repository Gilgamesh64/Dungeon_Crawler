#include "entity.h"

Entity *generate_entity(char* nome, int colpo_fatale, int danno, int monete){
    Entity entity = {nome, colpo_fatale, danno, monete};
    return &entity;
}