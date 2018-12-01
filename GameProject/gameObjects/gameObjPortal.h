struct portal {
	bool active;
	float x;
	float y;
	float z;
	int levelID;
};

portal newPortal(float x, float y, float z);
void initPortals();
void actionPortals();

#define maxportals 100
portal portals[maxportals];
int portalAmount;

portal newPortal(float x, float y, float z, int lv) {
	portalAmount++;
	portal theportal;
	theportal.active = true;
	theportal.x = x;
	theportal.y = y;
	theportal.z = z;
	theportal.levelID = lv;
	return theportal;
}

void initPortals() {
	portalAmount = 0;

	if (currentLevel == -1) {
		portals[portalAmount-1] = newPortal(-192.5f, 1.0f, -20.0f, 0);
	}

	if (currentLevel == 0) {
		portals[portalAmount - 1] = newPortal(-18.5f, -2.0f, 10.0f, 1);
		portals[portalAmount - 1] = newPortal(-18.5f, -2.0f, -10.0f, 2);
		portals[portalAmount - 1] = newPortal(-26.5f, -3.0f, 0.0f, 3);
	}

	if (currentLevel == 1) {
		portals[portalAmount - 1] = newPortal(-1.0f, 30.0f, 39.5f, 0);
	}

	if (currentLevel == 2) {
		portals[portalAmount - 1] = newPortal(-12.5f, 5.77f, -75.0f, 0);
	}

	if (currentLevel == 3) {
		portals[portalAmount - 1] = newPortal(-256.0f, 64.0f, -2.5f, 0);
	}

}

void actionPortals() {
	for (int i = 0; i < portalAmount; i++) {
		if (portals[i].active == true) {
			
			if (camx < portals[i].x + 1.0 && camx > portals[i].x - 1.0 && camz < portals[i].z + 1.0 && camz > portals[i].z - 1.0 && camy < portals[i].y + 3 && camy > portals[i].y - 3) {
				portals[i].active = false;
				clearParticles = 1;

				//level unlocks
				if (levelUnlocked < currentLevel) {
					levelUnlocked = currentLevel;
				}
				loadLevel(portals[i].levelID);

			}
		}
	}
}