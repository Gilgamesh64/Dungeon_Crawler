#ifndef MISSIONS_H
#define MISSIONS_H

typedef struct {
	
	char* location;
	char* target;
	
} Mission;

Mission* generate_missions();

#endif