#ifndef MISSIONS_H
#define MISSIONS_H

typedef struct {
	
	char* location;
	char* target;
	
} Mission;

char** generate_missions();

#endif