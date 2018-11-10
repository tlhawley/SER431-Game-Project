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
	/* // Intro to graphics 332 map
	portals[0] = newPortal(0.0f, 0.0f, -220.0f);
	*/
	if (currentLevel == -1) {
		portals[0] = newPortal(-192.5f, 1.0f, -20.0f, 0);
	}

	if (currentLevel == 0) {
		portals[0] = newPortal(-18.5f, -2.0f, 10.0f, -1);
	}

}

void actionPortals() {
	for (int i = 0; i < portalAmount; i++) {
		//objPlacementTRS(drawPortal, portals[i].x, 0.0, portals[i].z, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
		if (portals[i].active == true) {
			
			//objPlacementTRS(drawportal, portals[i].x, -sin(timer * 4)*0.1f + portals[i].y - 0.8f, portals[i].z, 0.0, timer * 100, 0.0, 1.0, -1.0, 1.0);
			if (camx < portals[i].x + 1.0 && camx > portals[i].x - 1.0 && camz < portals[i].z + 1.0 && camz > portals[i].z - 1.0 && camy < portals[i].y + 3 && camy > portals[i].y - 3) {
				portals[i].active = false;
				clearParticles = 1;
				loadLevel(portals[i].levelID);


				//score = score + 1000;
				//levelComplete = true;
				//inventoryportals = inventoryportals + 1;
			}
		}
	}
}