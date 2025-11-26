#include "room.h"

Room generate_room(){
	int type = dice_rool()%3;
	Room rtnRoom;
	
	
	switch (type){
		case 0:
			rtnRoom.trap = false;
			//rtnRoom.enemy = something;
			break;
		case 1:
			rtnRoom.trap = false;
			rtnRoom.enemy = generate_enemy();
			break;
		case 2:
			rtnRoom.trap = true;
			//rtnRoom.enemy = something else;
			break; 
	};
	
	return rtnRoom;
}

Enemy generate_enemy(){
	Enemy rtnEnemy;
	rtnEnemy.name = "nome mostro";
	rtnEnemy.health_points = 10;
	rtnEnemy.damage = 1;
	
	return rtnEnemy;
}