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


	// intro level
	if (currentLevel == -1) {
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
	}

	// level 1
	if (currentLevel == 1) {
		gems[gemAmount - 1] = newGem(-12.0f, 0.0f, 0.0f);
		gems[gemAmount - 1] = newGem(-18.0f, 0.0f, 0.0f);
		gems[gemAmount - 1] = newGem(-24.0f, 0.0f, 0.0f);
		gems[gemAmount - 1] = newGem(-30.0f, 0.0f, 0.0f);
		gems[gemAmount - 1] = newGem(-36.0f, 0.0f, 0.0f);
		gems[gemAmount - 1] = newGem(-42.0f, 0.0f, 0.0f);
		gems[gemAmount - 1] = newGem(-48.0f, 0.0f, 0.0f);

		gems[gemAmount - 1] = newGem(2.0f, 30.0f, -26.0f);
		gems[gemAmount - 1] = newGem(6.0f, 30.0f, -20.0f);
		gems[gemAmount - 1] = newGem(9.0f, 30.0f, -14.0f);
		gems[gemAmount - 1] = newGem(10.0f, 30.0f, -8.0f);
		gems[gemAmount - 1] = newGem(10.0f, 30.0f, 8.0f);
		gems[gemAmount - 1] = newGem(9.0f, 30.0f, 14.0f);
		gems[gemAmount - 1] = newGem(6.0f, 30.0f, 20.0f);
		gems[gemAmount - 1] = newGem(2.0f, 30.0f, 26.0f);

		gems[gemAmount - 1] = newGem(10.0f, 30.0f, 0.0f);
	}


	// level 2
	if (currentLevel == 2) {
		gems[gemAmount - 1] = newGem(51.0f, 1.0f, 0.0f);
		gems[gemAmount - 1] = newGem(55.0f, 1.0f, 0.0f);
		gems[gemAmount - 1] = newGem(59.0f, 1.0f, 0.0f);
		gems[gemAmount - 1] = newGem(63.0f, 1.0f, 0.0f);
		gems[gemAmount - 1] = newGem(67.0f, 1.0f, 0.0f);
		gems[gemAmount - 1] = newGem(71.0f, 1.0f, 0.0f);

		gems[gemAmount - 1] = newGem(-50.0f, 0.0f, 0.0f);
		gems[gemAmount - 1] = newGem(-54.0f, 0.0f, 0.0f);
		gems[gemAmount - 1] = newGem(-58.0f, 0.0f, 0.0f);
		gems[gemAmount - 1] = newGem(-62.0f, 0.0f, 0.0f);
		gems[gemAmount - 1] = newGem(-66.0f, 0.0f, 0.0f);
		gems[gemAmount - 1] = newGem(-70.0f, 0.0f, 0.0f);

		gems[gemAmount - 1] = newGem(-78.0f, 6.0f, -27.0f);
		gems[gemAmount - 1] = newGem(-78.0f, 6.0f, -31.0f);
		gems[gemAmount - 1] = newGem(-78.0f, 6.0f, -35.0f);
		gems[gemAmount - 1] = newGem(-78.0f, 6.0f, -39.0f);
		gems[gemAmount - 1] = newGem(-78.0f, 6.0f, -43.0f);
		gems[gemAmount - 1] = newGem(-78.0f, 6.0f, -47.0f);

		gems[gemAmount - 1] = newGem(-64.9117, 5.78911f, -57.4967f);
		gems[gemAmount - 1] = newGem(-60.6421f, 5.78911f, -60.368f);
		gems[gemAmount - 1] = newGem(-58.2516f, 5.78911f, -64.7682f);
		gems[gemAmount - 1] = newGem(-56.5603f, 5.78911f, -69.3403f);
		gems[gemAmount - 1] = newGem(-51.9296f, 5.78911f, -70.4354f);
		gems[gemAmount - 1] = newGem(-47.0403f, 5.78911f, -72.9285f);
		gems[gemAmount - 1] = newGem(-42.0339f, 5.78912f, -74.1757f);

	}

	// level 3
	if (currentLevel == 3) {
		gems[gemAmount - 1] = newGem(-256.0f, 64.0f, 39.0f);
		gems[gemAmount - 1] = newGem(-256.0f, 64.0f, 35.0f);
		gems[gemAmount - 1] = newGem(-256.0f, 64.0f, 31.0f);
		gems[gemAmount - 1] = newGem(-256.0f, 64.0f, 27.0f);
		gems[gemAmount - 1] = newGem(-256.0f, 64.0f, 23.0f);
		gems[gemAmount - 1] = newGem(-256.0f, 64.0f, 19.0f);
		gems[gemAmount - 1] = newGem(-256.0f, 64.0f, 15.0f);
		gems[gemAmount - 1] = newGem(-256.0f, 64.0f, 11.0f);

	}

}

void actionGems() {
	if (itemTimer > 0) {
		itemTimer = itemTimer - 1;

	}
	for (int i = 0; i < gemAmount; i++) {
		if (gems[i].active == true) {
			if (abs(camx - gems[i].x) < 120 && abs(camz - gems[i].z) < 120) {
				if (fabs(camx - gems[i].x) < 1.2 && fabs(camz - gems[i].z) < 1.2 && fabs(camy - gems[i].y) < 2) {
					gems[i].active = false;
					SoundEngine->play2D("./src/audio/ItemPickup.wav", GL_FALSE);
					itemTimer = 40;
					gemPickUp = true;
					score = score + 1000;
					//inventoryGems = inventoryGems + 1;
				}
			}
		}
	}
	if (itemTimer == 0)
	{
		gemPickUp = false;
	}
}




void displayGems() {
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	for (int i = 0; i < gemAmount; i++) {
		if (gems[i].active == true) {
			if (abs(camx - gems[i].x) < 60 && abs(camz - gems[i].z) < 60) {
				setMaterialAdvanced(materialRuby);
				objPlacementTRS(drawGem, gems[i].x, sin(timer * 4)*0.1f + gems[i].y + 0.2f, gems[i].z, 0.0, timer * 100, 0.0, 1.0, 1.0, 1.0);
				if (buttons[7].toggle == true) {
					setMaterialAdvanced(materialShadow);
					glEnable(GL_BLEND);
					objPlacementTRS(drawGem, gems[i].x, gems[i].y + 0.01f, gems[i].z - sin(timer * 4)*0.1f -0.2f, 0.0, timer * 100, 0.0, 1.0, 0.001f, 1.0f);
					glDisable(GL_BLEND);
				}
			}
		}
	}
}