
struct Cbox {
	float x;
	float y;
	float z;
	float sx;
	float sy;
	float sz;
};

Cbox newCBox(float x, float y, float z, float sx, float sy, float sz);
void initCBoxes();
void actionCBoxes();

#define maxCBoxes 1000
Cbox Cboxes[maxCBoxes];
int CboxAmount;

#define playerSize 0.5f
#define playerHeight 1.0f

Cbox newCBox(float x, float y, float z, float sx, float sy, float sz) {
	CboxAmount++;
	Cbox theBox;
	theBox.x = x;
	theBox.y = y;
	theBox.z = z;
	theBox.sx = sx;
	theBox.sy = sy;
	theBox.sz = sz;
	return theBox;
}

void initCBoxes() {

	CboxAmount = 0;
	Cboxes[CboxAmount - 1] = newCBox(0, 5, 31, 20, 10, 2); // white back wall
	
	
	//Cboxes[CboxAmount - 1] = newCBox(0, 5, -31, 20, 10, 2); // yellow back wall
	Cboxes[CboxAmount - 1] = newCBox(6, 5, -30.25, 0.5, 10, 8); // green back wall
	Cboxes[CboxAmount - 1] = newCBox(-6, 5, -30.25, 0.5, 10, 8); // green back wall
	Cboxes[CboxAmount - 1] = newCBox(0, 7, -30.25, 0.5, 6, 4); // green back wall


	Cboxes[CboxAmount - 1] = newCBox(31, 5, 0, 2, 10, 20); // red back wall

	//Cboxes[CboxAmount - 1] = newCBox(-31, 5, 0, 2, 10, 20); // blue back wall solid
	Cboxes[CboxAmount - 1] = newCBox(-30.25, 5, 6, 0.5, 10, 8); // blue back wall
	Cboxes[CboxAmount - 1] = newCBox(-30.25, 5, -6, 0.5, 10, 8); // blue back wall
	Cboxes[CboxAmount - 1] = newCBox(-30.25, 7, 0, 0.5, 6, 4); // blue back wall

	//Cboxes[CboxAmount - 1] = newCBox(-30, 2, 2.4, 1.5, 4, 2.7); // Door Frame
	//Cboxes[CboxAmount - 1] = newCBox(-30, 2, 2.625, 1.5, 4, 2.2); // Door Frame
	//Cboxes[CboxAmount - 1] = newCBox(-30, 2, -2.625, 1.5, 4, 2.2); // Door Frame
	//Cboxes[CboxAmount - 1] = newCBox(-30, 3.8, 0, 1.5, 1.6, 7.25); // Door Frame

	//Cboxes[CboxAmount - 1] = newCBox(-30, 2, 2.625, 1.5, 4, 2.2); // Door Frame
	//Cboxes[CboxAmount - 1] = newCBox(-30, 2, -2.625, 1.5, 4, 2.2); // Door Frame

	Cboxes[CboxAmount - 1] = newCBox(-20, 5, -20, 20, 10, 20); // Corner 1
	Cboxes[CboxAmount - 1] = newCBox(20, 5, -20, 20, 10, 20); // Corner 2
	Cboxes[CboxAmount - 1] = newCBox(20, 5, 20, 20, 10, 20); // Corner 3
	Cboxes[CboxAmount - 1] = newCBox(-20, 5, 20, 20, 10, 20); // Corner 4

	//Cboxes[CboxAmount - 1] = newCBox(0, -1, 0, 60, 2, 60); // Floor
	//Cboxes[CboxAmount - 1] = newCBox(0, 11, 0, 60, 2, 60); // Ceiling



	// New Environment Floor
	// Floor/Platform Collision
	Cboxes[CboxAmount - 1] = newCBox(0, -2.0, 0, 20.0, 4.0, 20.0);
	Cboxes[CboxAmount - 1] = newCBox(20, -2.0, 0, 20.0, 4.0, 20.0);
	Cboxes[CboxAmount - 1] = newCBox(-20, -2.0, 0, 20.0, 4.0, 20.0);
	Cboxes[CboxAmount - 1] = newCBox(0, -2.0, 20, 20.0, 4.0, 20.0);
	Cboxes[CboxAmount - 1] = newCBox(0, -2.0, -20, 20.0, 4.0, 20.0);


	Cboxes[CboxAmount - 1] = newCBox(-50.0, -2.0, 0, 40.0, 4.0, 9.0);
	Cboxes[CboxAmount - 1] = newCBox(-90.0, -2.0, 0, 40.0, 4.0, 40.0);

	Cboxes[CboxAmount - 1] = newCBox(-90.0, -2.0, -38.0, 12.0, 4.0, 36.0);

	Cboxes[CboxAmount - 1] = newCBox(-90.0, -2.0, -60.0, 4.0, 4.0, 2.0);

	// Platforms Semetric
	Cboxes[CboxAmount - 1] = newCBox(-95.0, -3.0, -60.0, 2.0, 4.0, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(-85.0, -3.0, -60.0, 2.0, 4.0, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(-99.0, -4.0, -60.0, 2.0, 4.0, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(-81.0, -4.0, -60.0, 2.0, 4.0, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(-103.0, -5.0, -60.0, 2.0, 4.0, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(-77.0, -5.0, -60.0, 2.0, 4.0, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(-108.0, -6.0, -60.0, 4.0, 4.0, 4.0);
	Cboxes[CboxAmount - 1] = newCBox(-72.0, -6.0, -60.0, 4.0, 4.0, 4.0);

	Cboxes[CboxAmount - 1] = newCBox(-90.0, -2.0, -82.0, 12.0, 4.0, 36.0);
	Cboxes[CboxAmount - 1] = newCBox(-90.0, -2.0, -120.0, 40.0, 4.0, 40.0); // Room
	Cboxes[CboxAmount - 1] = newCBox(-50.0, -2.0, -120.0, 40.0, 4.0, 9.0);

	Cboxes[CboxAmount - 1] = newCBox(0.0, -2.0, -120.0, 60.0, 4.0, 60.0); // Large Room

	Cboxes[CboxAmount - 1] = newCBox(0.0, -2.0, -170.0, 40.0, 4.0, 40.0); // Back1 Room
	Cboxes[CboxAmount - 1] = newCBox(0.0, -2.0, -210.0, 40.0, 4.0, 40.0); // Back2 Room

	// more platforms
	Cboxes[CboxAmount - 1] = newCBox(0.0, -2.0, -84.0, 12.0, 4.0, 12.0);
	Cboxes[CboxAmount - 1] = newCBox(0.0, -2.0, -72.0, 8.0, 4.0, 8.0);
	Cboxes[CboxAmount - 1] = newCBox(0.0, -2.0, -62.0, 8.0, 4.0, 8.0);
	Cboxes[CboxAmount - 1] = newCBox(0.0, -2.0, -52.0, 8.0, 4.0, 8.0);
	Cboxes[CboxAmount - 1] = newCBox(0.0, -2.0, -38.0, 8.0, 4.0, 16.0);






	// Walls
	// Hall 1
	Cboxes[CboxAmount - 1] = newCBox(-50.0, 2.0, 6.5, 40.0, 12.0, 4.0);
	Cboxes[CboxAmount - 1] = newCBox(-50.0, 2.0, -6.5, 40.0, 12.0, 4.0);

	// Room 1
	Cboxes[CboxAmount - 1] = newCBox(-70.0, 5.75, 0.0, 2.0, 4.5, 4.0);
	Cboxes[CboxAmount - 1] = newCBox(-70.0, 2.0, -11.0, 2.0, 12.0, 18.0);
	Cboxes[CboxAmount - 1] = newCBox(-70.0, 2.0, 11.0, 2.0, 12.0, 18.0);

	Cboxes[CboxAmount - 1] = newCBox(-110.0, 2.0, 0.0, 2.0, 12.0, 40.0);

	Cboxes[CboxAmount - 1] = newCBox(-90.0, 2.0, 20.0, 40.0, 12.0, 2.0);

	Cboxes[CboxAmount - 1] = newCBox(-90.0, 5.75, 20.0, 4.0, 4.5, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(-101.0, 2.0, -20.0, 18.0, 12.0, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(-79.0, 2.0, -20.0, 18.0, 12.0, 2.0);

	// Room 2
	Cboxes[CboxAmount - 1] = newCBox(-70.0, 5.75, -120.0, 2.0, 4.5, 4.0);
	Cboxes[CboxAmount - 1] = newCBox(-70.0, 2.0, -131.0, 2.0, 12.0, 18.0);
	Cboxes[CboxAmount - 1] = newCBox(-70.0, 2.0, -109.0, 2.0, 12.0, 18.0);

	Cboxes[CboxAmount - 1] = newCBox(-110.0, 2.0, -120.0, 2.0, 12.0, 40.0);

	Cboxes[CboxAmount - 1] = newCBox(-90.0, 2.0, -140.0, 40.0, 12.0, 2.0);

	Cboxes[CboxAmount - 1] = newCBox(-90.0, 5.75, -100.0, 4.0, 4.5, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(-101.0, 2.0, -100.0, 18.0, 12.0, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(-79.0, 2.0, -100.0, 18.0, 12.0, 2.0);

	// Hall 2
	Cboxes[CboxAmount - 1] = newCBox(-50.0, 2.0, -113.5, 40.0, 12.0, 4.0);
	Cboxes[CboxAmount - 1] = newCBox(-50.0, 2.0, -126.5, 40.0, 12.0, 4.0);

	// Room 3
	Cboxes[CboxAmount - 1] = newCBox(-30.0, 5.75, -120.0, 2.0, 4.5, 4.0);
	Cboxes[CboxAmount - 1] = newCBox(-30.0, 2.0, -103.0, 2.0, 12.0, 30.0);
	Cboxes[CboxAmount - 1] = newCBox(-30.0, 2.0, -137.0, 2.0, 12.0, 30.0);

	Cboxes[CboxAmount - 1] = newCBox(30.0, 2.0, -120.0, 2.0, 12.0, 64.0);

	Cboxes[CboxAmount - 1] = newCBox(0.0, 5.75, -90.0, 4.0, 4.5, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(-17.0, 2.0, -90.0, 30.0, 12.0, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(17.0, 2.0, -90.0, 30.0, 12.0, 2.0);

	Cboxes[CboxAmount - 1] = newCBox(0.0, 5.75, -150.0, 4.0, 4.5, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(-17.0, 2.0, -150.0, 30.0, 12.0, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(17.0, 2.0, -150.0, 30.0, 12.0, 2.0);
	
	// Room 4&5
	Cboxes[CboxAmount - 1] = newCBox(0.0, 5.75, -190.0, 4.0, 4.5, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(-11.0, 2.0, -190.0, 18.0, 12.0, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(11.0, 2.0, -190.0, 18.0, 12.0, 2.0);

	Cboxes[CboxAmount - 1] = newCBox(0.0, 2.0, -230.0, 40.0, 12.0, 2.0);

	Cboxes[CboxAmount - 1] = newCBox(20.0, 2.0, -190.0, 2.0, 12.0, 80.0);
	Cboxes[CboxAmount - 1] = newCBox(-20.0, 2.0, -190.0, 2.0, 12.0, 80.0);


	// platforms south west
	Cboxes[CboxAmount - 1] = newCBox(26.0, -6.0, -62.0, 4.0, 4.0, 4.0);
	Cboxes[CboxAmount - 1] = newCBox(21.0, -5.0, -62.0, 2.0, 4.0, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(17.0, -4.0, -62.0, 2.0, 4.0, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(13.0, -3.0, -62.0, 2.0, 4.0, 2.0);
	Cboxes[CboxAmount - 1] = newCBox(8.0, -2.0, -62.0, 4.0, 4.0, 2.0);


	/*
	// Bridge
	Cboxes[CboxAmount - 1] = newCBox(-65, -0.5, 0.0, 70, 1, 9);
	Cboxes[CboxAmount - 1] = newCBox(-65, 0, 4.5, 70, 1.8, 0.5);
	Cboxes[CboxAmount - 1] = newCBox(-65, 0, -4.5, 70, 1.8, 0.5);


	// Bridge End
	Cboxes[CboxAmount - 1] = newCBox(-110, -0.5, 0.0, 20, 1, 20);
	Cboxes[CboxAmount - 1] = newCBox(-118.75, -0.5, 8.75, 2.5, 20, 2.5);
	Cboxes[CboxAmount - 1] = newCBox(-101.25, -0.5, 8.75, 2.5, 20, 2.5);
	Cboxes[CboxAmount - 1] = newCBox(-101.25, -0.5, -8.75, 2.5, 20, 2.5);
	Cboxes[CboxAmount - 1] = newCBox(-118.75, -0.5, -8.75, 2.5, 20, 2.5);
	*/

	/*
	Cboxes[CboxAmount - 1] = newCBox(-35, 0, 0.0, 10, 0.1, 10);

	for (int i = 1; i < 50; i++) {
		Cboxes[CboxAmount - 1] = newCBox(-35 - i * 10, 0, 0.0, 10, 0.1, 10);
	}
	*/



	//Cboxes[CboxAmount-1] = newCBox(0, 0.5, -4, 1, 1, 1);
	
	/*
	CboxAmount = 0;
	for (int i = 0; i < 19; i++) {
		Cboxes[i] = newCBox(0, i*0.1-1.9, i*0.2+2.3, 8, 4, 0.2);
	}
	*/
	/*
	Cboxes[19] = newCBox(22, 1, 8.0, 8, 2, 4);
	for (int i = 20; i < 40; i++) {
		Cboxes[i] = newCBox(22, (i-20)*0.1 - 1.9, -(i-20)*0.2 - 2.3, 8, 4, 0.2);
	}
	Cboxes[40] = newCBox(22, 1, -8.0, 8, 2, 4);
	Cboxes[41] = newCBox(0, 0.5, -4, 1, 1, 1);
	*/
	/*
	Cboxes[0] = newCBox(22, 2, 3, 6, 4, 4);
	Cboxes[1] = newCBox(22, 1, -3, 6, 2, 4);
	Cboxes[2] = newCBox(22, 0.5f, -5, 6, 1, 2);
	*/

}

void actionCBoxes() {

	if (creativeMode == 2) {
		Cboxes[CboxAmount - 1].x = (int)((camx + sin(camAngY) * 3) * 4) / 4.0;
		Cboxes[CboxAmount - 1].y = (int)((camy + sin(camAngX) * 3) * 8) / 8.0;
		Cboxes[CboxAmount - 1].z = (int)((camz - cos(camAngY) * 3) * 4) / 4.0;

		if (mouseRDown == true && mouseRWait == false) {
			Cboxes[CboxAmount - 1] = newCBox((int)((camx + sin(camAngY) * 3) * 4) / 4.0, (int)((camy + sin(camAngX) * 3) * 8) / 8.0, (int)((camz - cos(camAngY) * 3) * 4) / 4.0, 1, 1, 1);
			mouseRWait = true;
		}
		if (mouseRDown == false) {
			mouseRWait = false;
		}
	}
	else {
		Cboxes[CboxAmount - 1].x = 0.0;
		Cboxes[CboxAmount - 1].y = -10000.0;
		Cboxes[CboxAmount - 1].z = 0.0;
	}
	
	for (int i = 0; i < CboxAmount; i++) {
		// Do not render collision boxes
		//objPlacementTRS(drawBox, Cboxes[i].x, Cboxes[i].y, Cboxes[i].z, 0.0, 0.0, 0.0, Cboxes[i].sx, Cboxes[i].sy, Cboxes[i].sz);
		if (camx > Cboxes[i].x - playerSize - Cboxes[i].sx / 2 && camx < Cboxes[i].x + playerSize + Cboxes[i].sx / 2) {
			if (camy > Cboxes[i].y - playerSize - Cboxes[i].sy / 2 && camy < Cboxes[i].y + playerHeight + Cboxes[i].sy / 2) {
				if (camz > Cboxes[i].z - playerSize - Cboxes[i].sz / 2 && camz < Cboxes[i].z + playerSize + Cboxes[i].sz / 2) {
					
					if (camx > Cboxes[i].x - playerSize - Cboxes[i].sx / 2 && ox < Cboxes[i].x + playerSize + Cboxes[i].sx / 2) {
						if (camz > Cboxes[i].z - playerSize - Cboxes[i].sz / 2 && oz < Cboxes[i].z + playerSize + Cboxes[i].sz / 2) {
							if (oy <= Cboxes[i].y - playerSize + 0.2 - Cboxes[i].sy / 2) {
								camy = Cboxes[i].y - playerSize - Cboxes[i].sy / 2;
								//oy = y;
							}
							if (oy >= Cboxes[i].y + playerHeight - 0.2 + Cboxes[i].sy / 2) {
								camy = Cboxes[i].y + playerHeight + Cboxes[i].sy / 2;
								//oy = y;
								camyv = 0.0f;
								canJump = true;
							}
						}
					}

					if (ox >= Cboxes[i].x - playerSize - Cboxes[i].sx / 2 && ox <= Cboxes[i].x + playerSize + Cboxes[i].sx / 2) {
						if (oy >= Cboxes[i].y - playerSize - Cboxes[i].sy / 2 && oy <= Cboxes[i].y + playerHeight - 0.2 + Cboxes[i].sy / 2) {
							if (oz <= Cboxes[i].z - playerSize - Cboxes[i].sz / 2) {
								camz = Cboxes[i].z - playerSize - Cboxes[i].sz / 2;
								//oz = z;
							}
							if (oz >= Cboxes[i].z + playerSize + Cboxes[i].sz / 2) {
								camz = Cboxes[i].z + playerSize + Cboxes[i].sz / 2;
								//oz = z;
							}
						}
					}


					if (oz >= Cboxes[i].z - playerSize - Cboxes[i].sz / 2 && oz <= Cboxes[i].z + playerSize + Cboxes[i].sz / 2) {
						if (oy >= Cboxes[i].y - playerSize - Cboxes[i].sy / 2 && oy <= Cboxes[i].y + playerHeight - 0.2 + Cboxes[i].sy / 2) {
							if (ox <= Cboxes[i].x - playerSize - Cboxes[i].sx / 2) {
								camx = Cboxes[i].x - playerSize - Cboxes[i].sx / 2;
								//ox = x;
							}
							if (ox >= Cboxes[i].x + playerSize + Cboxes[i].sx / 2) {
								camx = Cboxes[i].x + playerSize + Cboxes[i].sx / 2;
								//ox = x;
							}
						}
					}



				}
			}
		}
	}
}