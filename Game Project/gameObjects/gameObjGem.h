struct gem {
	bool active;
	float x;
	float y;
	float z;
};

gem newGem(float x, float y, float z);
void initGems();
void actionGems();

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

}

void actionGems() {
	for (int i = 0; i < gemAmount; i++) {

		if (gems[i].active == true) {
			if (abs(camx - gems[i].x) < 60 && abs(camz - gems[i].z) < 60) {

				objPlacementTRS(drawGem, gems[i].x, sin(timer * 4)*0.1f + gems[i].y + 0.3f, gems[i].z, 0.0, timer * 100, 0.0, 1.0, 1.0, 1.0);
				//objPlacementTRS(drawGem, gems[i].x, -sin(timer * 4)*0.1f + gems[i].y - 0.3f, gems[i].z, 0.0, timer * 100, 0.0, 1.0, -1.0, 1.0);
				if (fabs(camx - gems[i].x) < 1.2 && fabs(camz - gems[i].z) < 1.2 && fabs(camy - gems[i].y) < 2) {
					gems[i].active = false;
					score = score + 1000;
					//inventoryGems = inventoryGems + 1;
				}
			}
		}
	}
}