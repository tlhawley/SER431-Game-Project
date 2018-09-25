struct healthPack {
	bool active;
	float x;
	float y;
	float z;
};

healthPack newHealthPack(float x, float y, float z) ;
void initHealthPacks() ;
void actionHealthPacks() ;
void displayHealthPacks() ;

#define maxHealthPacks 100
healthPack healthPacks[maxHealthPacks];
int healthPackAmount;

healthPack newHealthPack(float x, float y, float z) {
	healthPackAmount++;
	healthPack theHealthPack;
	theHealthPack.active = true;
	theHealthPack.x = x;
	theHealthPack.y = y;
	theHealthPack.z = z;
	return theHealthPack;
}

void initHealthPacks() {
	healthPackAmount = 0;
	// Intro to graphics 332 map
	/*
	healthPacks[0] = newHealthPack(-17.0f, 0.0f, 8.0f);
	healthPacks[1] = newHealthPack(-20.0f, 0.0f, 8.0f);
	healthPacks[2] = newHealthPack(-23.0f, 0.0f, 8.0f);
	healthPacks[3] = newHealthPack(-17.0f, 0.0f, -8.0f);
	healthPacks[4] = newHealthPack(-20.0f, 0.0f, -8.0f);
	healthPacks[5] = newHealthPack(-23.0f, 0.0f, -8.0f);
	*/
	
}

void actionHealthPacks() {
	for (int i = 0; i < healthPackAmount; i++) {
		if (healthPacks[i].active == true) {
				if (fabs(camx - healthPacks[i].x) < 1 && fabs(camz - healthPacks[i].z) < 1 && fabs(camy - healthPacks[i].y) < 2) {
					health = health + 200;
					if (health > 1000) {
						health = 1000;
					}
					healthPacks[i].active = false;
				}
		}
	}
}


void displayHealthPacks() {
	for (int i = 0; i < healthPackAmount; i++) {
		if (healthPacks[i].active == true) {
			if (abs(camx - healthPacks[i].x) < 120 && abs(camz - healthPacks[i].z) < 120) {
				objPlacementTRS(drawHealthPack, healthPacks[i].x, sin(timer * 4)*0.1f + healthPacks[i].y, healthPacks[i].z, 0.0, timer * 100, 0.0, 1.0, 1.0, 1.0);
				objPlacementTRS(drawHealthPack, healthPacks[i].x, -sin(timer * 4)*0.1f + healthPacks[i].y, healthPacks[i].z, 0.0, timer * 100, 0.0, 1.0, -1.0, 1.0);
			}
		}
	}
}