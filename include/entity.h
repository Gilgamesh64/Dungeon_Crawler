#ifndef ENTITY_H
#define ENTITY_H

typedef struct{
    char* nome;
	int colpo_fatale;
	int danno;
	int monete;
} Entity;

Entity generate_entity(char* nome, int colpo_fatale, int danno, int monete);

#endif