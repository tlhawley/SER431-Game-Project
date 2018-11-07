struct gem {
	bool active;
	float x;
	float y;
	float z;
};

gem newGem(float x, float y, float z);
void initGems();
void actionGems();
void displayGems();

#define maxGems 100
gem gems[maxGems];
int gemAmount;

gem newGem(float x, float y, float z) {
	gemAmount++;
	gem theGem;
	theGem.active = true;
	theGem.x = x;
	theGem.y = y;
	theGem.z = z;
	return theGem;
}

void initGems() {
	gemAmount = 0;

	gems[gemAmount - 1] = newGem(27.2f, 0.0f, 1.8f);
	gems[gemAmount - 1] = newGem(27.9f, 0.0f, -3.5f);
	gems[gemAmount - 1] = newGem(29.0f, 0.0f, -7.5f);

	gems[gemAmount - 1] = newGem(-11.0f, 0.0f, -5.0f);
	gems[gemAmount - 1] = newGem(-19.2f, 0.0f, -9.5f);
	gems[gemAmount - 1] = newGem(-28.0f, 0.0f, -14.7f);
	gems[gemAmount - 1] = newGem(-37.9f, 0.0f, -20.2f);
	gems[gemAmount - 1] = newGem(-47.4f, 0.0f, -22.7f);
	gems[gemAmount - 1] = newGem(-57.5f, 0.0f, -24.0f);
	gems[gemAmount - 1] = newGem(-68.0f, 0.0f, -24.2f);
	gems[gemAmount - 1] = newGem(-78.6f, 0.0f, -24.4f);
	gems[gemAmount - 1] = newGem(-89.5f, 0.0f, -24.5f);
	gems[gemAmount - 1] = newGem(-101.2f, 0.0f, -24.3f);
	gems[gemAmount - 1] = newGem(-113.5f, 0.0f, -24.0f);
	gems[gemAmount - 1] = newGem(-125.0f, 0.0f, -23.5f);
	gems[gemAmount - 1] = newGem(-136.0f, 0.0f, -23.0f);
	gems[gemAmount - 1] = newGem(-151.0f, 0.0f, -22.2f);
	gems[gemAmount - 1] = newGem(-161.0f, 0.0f, -21.7f);
	gems[gemAmount - 1] = newGem(-172.9f, 0.0f, -21.2f);
	gems[gemAmount - 1] = newGem(-182.5f, 0.0f, -20.7f);


	// Intro to graphics 332 map
	/*
	gems[gemAmount - 1] = newGem(0.0f, 0.0f, -20.0f);
	gems[gemAmount - 1] = newGem(-109.0, -4.0, -61.0f);
	gems[gemAmount - 1] = newGem(-109.0, -4.0, -59.0f);
	gems[gemAmount - 1] = newGem(-107.0, -4.0, -61.0f);
	gems[gemAmount - 1] = newGem(-107.0, -4.0, -59.0f);

	gems[gemAmount - 1] = newGem(2.0f, 0.0f, -172.0f);
	gems[gemAmount - 1] = newGem(2.0f, 0.0f, -168.0f);
	gems[gemAmount - 1] = newGem(-2.0f, 0.0f, -172.0f);
	gems[gemAmount - 1] = newGem(-2.0f, 0.0f, -168.0f);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			gems[gemAmount - 1] = newGem(-9+i*3, 0.0f, -215.0f+j*3);
		}
	}
	*/
	
}

void actionGems() {
	for (int i = 0; i < gemAmount; i++) {
		if (gems[i].active == true) {
			if (abs(camx - gems[i].x) < 120 && abs(camz - gems[i].z) < 120) {
				if (fabs(camx - gems[i].x) < 1.2 && fabs(camz - gems[i].z) < 1.2 && fabs(camy - gems[i].y) < 2) {
					gems[i].active = false;
					SoundEngine->play2D("./src/audio/ItemPickup.wav", GL_FALSE);
					score = score + 1000;
					//inventoryGems = inventoryGems + 1;
				}
			}
		}
	}
}


void displayGems() {
	for (int i = 0; i < gemAmount; i++) {
		if (gems[i].active == true) {
			if (abs(camx - gems[i].x) < 60 && abs(camz - gems[i].z) < 60) {
				objPlacementTRS(drawGem, gems[i].x, sin(timer * 4)*0.1f + gems[i].y + 0.2f, gems[i].z, 0.0, timer * 100, 0.0, 0.9, 0.9, 0.9);
			}
		}
	}
}