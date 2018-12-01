struct key {
	bool active;
	float x;
	float y;
	float z;
};

key newKey(float x, float y, float z);
void initKeys();
void actionKeys();
void displayKeys();

#define maxKeys 20
key keys[maxKeys];
int keyAmount;

key newKey(float x, float y, float z) {
	keyAmount++;
	key theKey;
	theKey.active = true;
	theKey.x = x;
	theKey.y = y;
	theKey.z = z;
	return theKey;
}

void initKeys() {
	keyAmount = 0;
	// Intro to graphics 332 map


	if (currentLevel == 2){
		keys[keyAmount - 1] = newKey(-0.102766f, 4.32769f, -49.8305f);
		keys[keyAmount - 1] = newKey(81.0096f , -0.26221f, -0.561697f);
	}

	if (currentLevel == 3) {
		keys[keyAmount - 1] = newKey(-192.0f, 48.0f, 0.0f);
	}
	
}

void actionKeys() {
	if (itemTimer > 0) {
		itemTimer = itemTimer - 1;

	}
	for (int i = 0; i < keyAmount; i++) {
		if (keys[i].active == true) {
				if (fabs(camx - keys[i].x) < 1.2 && fabs(camz - keys[i].z) < 1.2 && fabs(camy - keys[i].y) < 2) {
					SoundEngine->play2D("./src/audio/ItemPickup.wav", GL_FALSE);
					itemTimer = 40;
					keyPickUp = true;
					keys[i].active = false;
					inventoryKeys = inventoryKeys + 1;
				}
		}
	}
	if (itemTimer == 0)
	{
		keyPickUp = false;
	}
}


void displayKeys() {
	for (int i = 0; i < keyAmount; i++) {
		if (keys[i].active == true) {
			if (abs(camx - keys[i].x) < 120 && abs(camz - keys[i].z) < 120) {
				objPlacementTRS(drawKey, keys[i].x, sin(timer * 4)*0.1f + keys[i].y + 0.8f, keys[i].z, 0.0, timer * 100, 0.0, 1.0, 1.0, 1.0);
			}
		}
	}
}