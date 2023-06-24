#include "Splash.h"
#include "Object.h"

int Object::act_water(Direction fromwhere, Actor fromwho) {
	int score = 0;
	if(fromwho == TOXIC)
	{
		if(size == 1)
		{
			set2void(x,y,splash);
		}
		else
			size--;
	}
	else
	{
		if(size == 3)
		{
			score++;
			set2void(x,y,splash);
			if(x < splash->size - 1) score += splash->map[x+1][y]->act(UP,WATER);
			if(x > 0) score += splash->map[x-1][y]->act(DOWN,WATER);
			if(y > 0) score += splash->map[x][y-1]->act(RIGHT,WATER);
			if(y < splash->size - 1) score += splash->map[x][y+1]->act(LEFT,WATER);
		}
		else size++;
	}
	return score;
}

int Object::act_void(Direction fromwhere, Actor fromwho) {
	int score = 0;
	if(fromwhere == NONE)
	{
		cout << "Error: Cannot act a Void." << endl;
	}
	else
	{
		switch(fromwhere)
		{
			case UP:
				if(x < splash->size - 1)
					score += splash->map[x+1][y]->act(UP,fromwho);
				break;
			case DOWN:
				if(x > 0)
					score += splash->map[x-1][y]->act(DOWN,fromwho);
				break;
			case RIGHT:
				if(y > 0)
					score += splash->map[x][y-1]->act(RIGHT,fromwho);
				break;
			case LEFT:
				if(y < splash->size - 1)
					score += splash->map[x][y+1]->act(LEFT,fromwho);
				break;
			default:
				break;
		}
	}
	return score;
}

int Object::act_barrier(Direction fromwhere, Actor fromwho) {
	if(fromwhere == NONE)
	{
		cout << "Error: Cannot act a Barrier." << endl;
	}
	return 0;
}

int Object::act_toxic(Direction fromwhere, Actor fromwho) {
	int score = 0;
	if(fromwho == WATER)
	{
		if(size == 1)
		{
			set2void(x,y,splash);
		}
		else
			size--;
	}
	else
	{
		if(size == 3)
		{
			score--;
			set2void(x,y,splash);
			if(x < splash->size - 1) score += splash->map[x+1][y]->act(UP,TOXIC);
			if(x > 0) score += splash->map[x-1][y]->act(DOWN,TOXIC);
			if(y > 0) score += splash->map[x][y-1]->act(RIGHT,TOXIC);
			if(y < splash->size - 1) score += splash->map[x][y+1]->act(LEFT,TOXIC);
		}
		else size++;
	}
	return score;
}