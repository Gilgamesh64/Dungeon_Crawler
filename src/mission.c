#include "utils.h"
#include <stdlib.h>/*

Mission* generate_missions(){
	static Mission allMissions[] = {
		{"quest 1", "target 1"},
		{"quest 2", "target 2"},
		{"quest 3", "target 3"},
		{"quest 4", "target 4"},
		{"quest 5", "target 5"},
		{"quest 6", "target 6"},
	};
	Mission temp;
	int n1, n2;
	for(int i = 0; i < 15; i++){
		n1 = roll_dice();
		n2 = roll_dice();
		temp = allMissions[n1];
		allMissions[n1] = allMissions[n2];
		allMissions[n2] = temp;
	}
	
	Mission* rtnMissions = &allMissions;
	
	return realloc(rtnMissions, 3 * sizeof(Mission));
}*/