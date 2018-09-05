struct key {
	bool active;
	float x;
	float y;
	float z;
};

key newKey(float x, float y, float z);
void initKeys();
void actionKeys();

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
	/* // Intro to graphics 332 map
	keys[keyAmount-1] = newKey(-20.0f, 0.0f, 0.0f);
	keys[keyAmount-1] = newKey(26.0f, -4.0, -62.0f);
	keys[keyAmount - 1] = newKey(-72.0, -4.0, -60.0f);
	keys[keyAmount - 1] = newKey(-90.0, 0.0, -120.0f);
	*/
}

void actionKeys() {
	for (int i = 0; i < keyAmount; i++) {
		if (keys[i].active == true) {
			if (abs(camx - keys[i].x) < 60 && abs(camz - keys[i].z) < 60) {
				objPlacementTRS(drawKey, keys[i].x, sin(timer * 4)*0.1f + keys[i].y + 0.8f, keys[i].z, 0.0, timer * 100, 0.0, 1.0, 1.0, 1.0);
				objPlacementTRS(drawKey, keys[i].x, -sin(timer * 4)*0.1f + keys[i].y - 0.8f, keys[i].z, 0.0, timer * 100, 0.0, 1.0, -1.0, 1.0);
				if (fabs(camx - keys[i].x) < 1.2 && fabs(camz - keys[i].z) < 1.2 && fabs(camy - keys[i].y) < 2) {
					keys[i].active = false;
					inventoryKeys = inventoryKeys + 1;
				}
			}
		}
	}
}