struct portal {
	bool active;
	float x;
	float y;
	float z;
};

portal newPortal(float x, float y, float z);
void initPortals();
void actionPortals();

#define maxportals 100
portal portals[maxportals];
int portalAmount;

portal newPortal(float x, float y, float z) {
	portalAmount++;
	portal theportal;
	theportal.active = true;
	theportal.x = x;
	theportal.y = y;
	theportal.z = z;
	return theportal;
}

void initPortals() {
	portalAmount = 0;
	/* // Intro to graphics 332 map
	portals[0] = newPortal(0.0f, 0.0f, -220.0f);
	*/
}

void actionPortals() {
	for (int i = 0; i < portalAmount; i++) {
		objPlacementTRS(drawPortal, portals[i].x, 0.0, portals[i].z, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
		if (portals[i].active == true) {
			
			//objPlacementTRS(drawportal, portals[i].x, -sin(timer * 4)*0.1f + portals[i].y - 0.8f, portals[i].z, 0.0, timer * 100, 0.0, 1.0, -1.0, 1.0);
			if (fabs(camx - portals[i].x) < 1.5 && fabs(camz - portals[i].z) < 1.5 && fabs(camy - portals[i].y) < 2) {
				portals[i].active = false;
				score = score + 1000;
				levelComplete = true;
				//inventoryportals = inventoryportals + 1;
			}
		}
	}
}