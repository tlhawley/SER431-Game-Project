struct doorway {
	float x;
	float y;
	float z;
	float angle;
	int locked;
	int lockCollision;
	float doorAnimate;
	bool mirror;
};

doorway newDoorway(float x, float y, float z, float ang, int locked, bool mirror) ;
void initDoorway() ;
void actionDoorway() ;
void displayDoorway() ;

#define maxDoorway 20
doorway doorways[maxHealthPacks];
int doorwayAmount;

doorway newDoorway(float x, float y, float z, float ang, int locked, bool mirror) {
	doorwayAmount++;
	doorway theDoorway;
	theDoorway.doorAnimate = 0;
	theDoorway.locked = locked;
	theDoorway.angle = ang;
	theDoorway.x = x;
	theDoorway.y = y;
	theDoorway.z = z;
	theDoorway.lockCollision = CboxAmount;
	theDoorway.mirror = mirror;

	if (ang == 90) {

		Cboxes[CboxAmount - 1] = newCBox(x, y + 5, z, 1.0, 10.0, 6.0); // Door

		//Cboxes[CboxAmount - 1] = newCBox(x, y + 1.5, z, 2.0, 4.0, 4.0); // Door
		//Cboxes[CboxAmount - 1] = newCBox(x, y + 1, z + 2.5, 2.5, 4.0, 2.0); // Door Frame Left
		//Cboxes[CboxAmount - 1] = newCBox(x, y + 1, z - 2.5, 2.5, 4.0, 2.0); // Door Frame Right Again?
		//Cboxes[CboxAmount - 1] = newCBox(x, y + 1, z - 2.5, 2.5, 4.0, 2.0); // Door Frame Right
		//Cboxes[CboxAmount - 1] = newCBox(x, y + 4, z, 2.5, 2.0, 7.0); // Door Frame Top
		
		/*
		Cboxes[CboxAmount - 1] = newCBox(x, y + 2, z, 1.25, 4, 3.0); // Door Frame
		Cboxes[CboxAmount - 1] = newCBox(x, y + 2, z + 2.625, 1.5, 4, 2.2); // Door Frame
		Cboxes[CboxAmount - 1] = newCBox(x, y + 2, z - 2.625, 1.5, 4, 2.2); // Door Frame
		Cboxes[CboxAmount - 1] = newCBox(x, y + 3.8, z, 1.5, 1.6, 7.25); // Door Frame
		*/
	}
	else {

		Cboxes[CboxAmount - 1] = newCBox(x, y + 5, z, 6.0, 10.0, 1.0); // Door


		//Cboxes[CboxAmount - 1] = newCBox(x, y + 1.5, z, 4.0, 4.0, 2.0); // Door
		//Cboxes[CboxAmount - 1] = newCBox(x + 2.5, y + 1, z, 2.0, 4.0, 2.5); // Door Frame Left
		//Cboxes[CboxAmount - 1] = newCBox(x - 2.5, y + 1, z, 2.0, 4.0, 2.5); // Door Frame Right
		//Cboxes[CboxAmount - 1] = newCBox(x, y + 4, z, 7.0, 2.0, 2.5); // Door Frame Top

		/*
		Cboxes[CboxAmount - 1] = newCBox(x, y + 2, z, 3.0, 4, 1.25); // Door Frame
		Cboxes[CboxAmount - 1] = newCBox(x + 2.625, y + 2, z, 2.2, 4, 1.5); // Door Frame
		Cboxes[CboxAmount - 1] = newCBox(x - 2.625, y + 2, z, 2.2, 4, 1.5); // Door Frame
		Cboxes[CboxAmount - 1] = newCBox(x, y + 3.8, z, 7.25, 1.6, 1.5); // Door Frame
		*/
	}

	return theDoorway;
}

void initDoorway() {
	doorwayAmount = 0;

	if (currentLevel == 2) {
		doorways[doorwayAmount - 1] = newDoorway(-17.0, 0, 0, 90, 1, false);
		doorways[doorwayAmount - 1] = newDoorway(-34.0, 0, 0, 90, 1, false);
	}

	 // Intro to graphics 332 map
	/*
	doorways[doorwayAmount-1] = newDoorway(-30,0,0,90,1,false);
	doorways[doorwayAmount - 1] = newDoorway(0, 0, -30, 0, 1, false);
	doorways[doorwayAmount - 1] = newDoorway(-70.0, 0, 0, 90, 0, false);
	doorways[doorwayAmount - 1] = newDoorway(-90.0, 0, -20.0, 0, 0, false);
	doorways[doorwayAmount - 1] = newDoorway(-90.0, 0, -100.0, 0, 0, false);
	doorways[doorwayAmount - 1] = newDoorway(-70.0, 0, -120, 90, 0, false);
	doorways[doorwayAmount - 1] = newDoorway(-30.0, 0, -120, 90, 0, false);
	doorways[doorwayAmount - 1] = newDoorway(0, 0, -90.0, 0, 0, false);
	doorways[doorwayAmount - 1] = newDoorway(0, 0, -150.0, 0, 1, false);
	doorways[doorwayAmount - 1] = newDoorway(0, 0, -190.0, 0, 1, false);
	*/
	
}





void actionDoorway() {

	for (int i = 0; i < doorwayAmount; i++) {

		if (abs(camx - doorways[i].x) < 3 && abs(camz - doorways[i].z) < 3 && doorways[i].locked == 1 && inventoryKeys > 0) {
			inventoryKeys = inventoryKeys - 1;
			doorways[i].locked = 0;
		}
		if (doorways[i].locked == 0 && doorways[i].doorAnimate < 3.0) {
			doorways[i].doorAnimate = doorways[i].doorAnimate + 0.05f;
			Cboxes[doorways[i].lockCollision].y = Cboxes[doorways[i].lockCollision].y + 0.05f;
		}


	}

}





void actionDoorwayzzzzzzzzzz() {
	for (int i = 0; i < doorwayAmount; i++) {
		
		if (abs(camx - doorways[i].x) < 120 && abs(camz - doorways[i].z) < 120) {

			if (doorways[i].locked == 0) {

				if (Cboxes[doorways[i].lockCollision].y == doorways[i].y + 1.5) {
					Cboxes[doorways[i].lockCollision].y = -10000;
				}

				if (doorways[i].angle == 90) {
					if (camx > doorways[i].x - 5 && camx < doorways[i].x + 5 && camz > doorways[i].z - 5 && camz < doorways[i].z + 5
						&& camy > doorways[i].y - 5 && camy < doorways[i].y + 5) {
						if (doorways[i].doorAnimate < 1.25) doorways[i].doorAnimate = doorways[i].doorAnimate + 0.05f;
					}
					else {
						if (doorways[i].doorAnimate > 0) doorways[i].doorAnimate = doorways[i].doorAnimate - 0.05f;
					}



				}
				else {
					if (camx > doorways[i].x - 5 && camx < doorways[i].x + 5 && camz > doorways[i].z - 5 && camz < doorways[i].z + 5
						&& camy > doorways[i].y - 5 && camy < doorways[i].y + 5) {
						if (doorways[i].doorAnimate < 1.25) doorways[i].doorAnimate = doorways[i].doorAnimate + 0.05f;
					}
					else {
						if (doorways[i].doorAnimate > 0) doorways[i].doorAnimate = doorways[i].doorAnimate - 0.05f;
					}


				}
			}
			else { // The Door is locked


				/*
				if (Cboxes[doorways[i].lockCollision].y == doorways[i].y + 2) {
					Cboxes[doorways[i].lockCollision].y = -10000;
				}
				*/

				if (doorways[i].angle == 90) {
					if (camx > doorways[i].x - 5 && camx < doorways[i].x + 5 && camz > doorways[i].z - 5 && camz < doorways[i].z + 5
						&& camy > doorways[i].y - 5 && camy < doorways[i].y + 5) {
						if (inventoryKeys > 0) {
							inventoryKeys = inventoryKeys - 1;
							doorways[i].locked = 0;
						}
						//if (doorways[i].doorAnimate < 1.05) doorways[i].doorAnimate = doorways[i].doorAnimate + 0.05f;
					}
					else {
						if (doorways[i].doorAnimate > 0) doorways[i].doorAnimate = doorways[i].doorAnimate - 0.05f;
					}



				}
				else {
					if (camx > doorways[i].x - 5 && camx < doorways[i].x + 5 && camz > doorways[i].z - 5 && camz < doorways[i].z + 5
						&& camy > doorways[i].y - 5 && camy < doorways[i].y + 5) {
						if (inventoryKeys > 0) {
							inventoryKeys = inventoryKeys - 1;
							doorways[i].locked = 0;
						}
						//if (doorways[i].doorAnimate < 1.05) doorways[i].doorAnimate = doorways[i].doorAnimate + 0.05f;
					}
					else {
						if (doorways[i].doorAnimate > 0) doorways[i].doorAnimate = doorways[i].doorAnimate - 0.05f;
					}

				}


			}
		}
	}
}




















/*
void displayDoorway() {
	for (int i = 0; i < doorwayAmount; i++) {

		if (abs(camx - doorways[i].x) < 120 && abs(camz - doorways[i].z) < 120) {

			if (doorways[i].locked == 0) {

				if (doorways[i].angle == 90) {

					objPlacementTRS(drawDoor, doorways[i].x, doorways[i].y, doorways[i].z, 0, 90.0f, 0, 1, 1, 1);
					objPlacementTRS(drawDoorLeft, doorways[i].x, doorways[i].y, doorways[i].z + doorways[i].doorAnimate, 0, 90.0f, 0, 1, 1, 1);
					objPlacementTRS(drawDoorRight, doorways[i].x, doorways[i].y, doorways[i].z - doorways[i].doorAnimate, 0, 90.0f, 0, 1, 1, 1);

				}
				else {

					objPlacementTRS(drawDoor, doorways[i].x, doorways[i].y, doorways[i].z, 0, 0, 0, 1, 1, 1);
					objPlacementTRS(drawDoorLeft, doorways[i].x - doorways[i].doorAnimate, doorways[i].y, doorways[i].z, 0, 0, 0, 1, 1, 1);
					objPlacementTRS(drawDoorRight, doorways[i].x + doorways[i].doorAnimate, doorways[i].y, doorways[i].z, 0, 0, 0, 1, 1, 1);
				}
			}
			else { // The Door is locked

				if (doorways[i].angle == 90) {

					objPlacementTRS(drawDoor, doorways[i].x, doorways[i].y, doorways[i].z, 0, 90.0f, 0, 1, 1, 1);
					objPlacementTRS(drawDoorLeft, doorways[i].x, doorways[i].y, doorways[i].z, 0, 90.0f, 0, 1, 1, 1);
					objPlacementTRS(drawDoorRight, doorways[i].x, doorways[i].y, doorways[i].z, 0, 90.0f, 0, 1, 1, 1);
					objPlacementTRS(drawDoorLock, doorways[i].x, doorways[i].y, doorways[i].z, 0, 90.0f, 0, 1, 1, 1);

				}
				else {

					objPlacementTRS(drawDoor, doorways[i].x, doorways[i].y, doorways[i].z, 0, 0, 0, 1, 1, 1);
					objPlacementTRS(drawDoorLeft, doorways[i].x, doorways[i].y, doorways[i].z, 0, 0, 0, 1, 1, 1);
					objPlacementTRS(drawDoorRight, doorways[i].x, doorways[i].y, doorways[i].z, 0, 0, 0, 1, 1, 1);
					objPlacementTRS(drawDoorLock, doorways[i].x, doorways[i].y, doorways[i].z, 0, 0, 0, 1, 1, 1);

				}

			}
		}
	}
}
*/












void displayDoorway() {
	for (int i = 0; i < doorwayAmount; i++) {


		objPlacementTRS(drawDoor, doorways[i].x, doorways[i].y + doorways[i].doorAnimate, doorways[i].z, 0, doorways[i].angle, 0, 1, 1, 1);

		//if (doorways[i].active == true) {
			//if (abs(camx - doorways[i].x) < 60 && abs(camz - doorways[i].z) < 60) {
				//objPlacementTRS(drawGem, doorways[i].x, sin(timer * 4)*0.1f + gems[i].y + 0.2f, gems[i].z, 0.0, timer * 100, 0.0, 1.0, 1.0, 1.0);
			//}
		//}
	}
}











