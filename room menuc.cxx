/*void room_menu(Room* room){
	switch (room->state){
		case 1:
			//stanza vuota	
			printf("La stanza e' vuota\n");
			room++;
			break;
		case 2:
			//trappola
			trap_message(room);
			room++;
			break;
		case 3:
			//combattimento
			combat_menu(room);
			room++;
			break;
			
		default:
			break;
	}
	printf("Premi INVIO per tornare al menu del dungeon...\n");
	getchar();
	
}

void combat_menu(Room* room){
	int roll = -1;
	while(roll < room->target->health){
		clear_screen();
		printf("L'eroe incontra un %s e inizia il combattimento:\n", room->target->name)
		printf("Premi INVIO per tirare il dado...\n");
		roll = dice_roll();
		getchar();
		printf("Il risultato: %d.\n", roll);
		
		if(roll < room->target->health){
			printf("Attacco non sufficiente per sconfiggere lo %s (%d < Colpo Fatale=%d).\n", room->target->name, roll, room->enemy->health)
		}else{
			printf("Lo %s viene sconfitto (%d > %d). L'eroe rimane con %d punti vita, e riceve %d monete.\n", room->target->name, roll, room->target->healt, get_game_data()->health_points, room->target->reward);
		}
		
		get_game_data()->health_points -= room->target->damage;
		printf("Lo %s infligge %d danni all'eroe, l'eroe rimane con %d punti vita.\n", room->enemy->name, room->enemy->damage, get_game_data()->health_points);
		
	}
	
}

void trap_message(){
	int damage = dice_roll();
	get_game_data()->health_points -= damage;
	printf("L'eroe cade in una trappola e riceve %d danni. L'eroe rimane con %d punti vita", damage, get_game_data()->health_points);
}*/