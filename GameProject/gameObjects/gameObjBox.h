
// Visible Collision Boxes - No longer in use
// Use gameObjCollisionBox instead

struct box {
	float x;
	float y;
	float z;
	float sx;
	float sy;
	float sz;
};

box newBox(float x, float y, float z, float sx, float sy, float sz);
void initBoxes();
void actionBoxes();

#define maxBoxes 1000
box boxes[maxBoxes];
int boxAmount;

#define playerSize 0.5f
#define playerHeight 1.0f

box newBox(float x, float y, float z, float sx, float sy, float sz) {
	boxAmount++;
	box theBox;
	theBox.x = x;
	theBox.y = y;
	theBox.z = z;
	theBox.sx = sx;
	theBox.sy = sy;
	theBox.sz = sz;
	return theBox;
}

void initBoxes() {

	boxAmount = 0;
	/* // old stairs
	for (int i = 0; i < 19; i++) {
		boxes[i] = newBox(22, i*0.1-1.9, i*0.2+2.3, 8, 4, 0.2);
	}
	boxes[19] = newBox(22, 1, 8.0, 8, 2, 4);
	for (int i = 20; i < 40; i++) {
		boxes[i] = newBox(22, (i-20)*0.1 - 1.9, -(i-20)*0.2 - 2.3, 8, 4, 0.2);
	}
	*/

	/*
	// Stairs
	for (int i = 0; i < 19; i++) {
		//boxes[boxAmount - 1] = newBox(22, i*0.1, i*0.2 + 2.3, 8, 0.2, 0.2);
		
		boxes[boxAmount - 1] = newBox(22, 0, i*0.2 + 2.3, 8, 0.2+i*0.2, 0.2);

		boxes[boxAmount - 1] = newBox(22, 0, i*-0.2 - 2.3, 8, 0.2 + i * 0.2, 0.2);

		//boxes[boxAmount - 1] = newBox(22, i*-0.1, i*0.2 + 2.3, 8, 0.2, 0.2);
	}
	boxes[boxAmount - 1] = newBox(22, 0, 8.0, 8, 4, 4);
	*/



	/*
	for (int i = 20; i < 40; i++) {
		boxes[boxAmount - 1] = newBox(22, (i - 20)*0.1, -(i - 20)*0.2 - 2.3, 8, 0.2, 0.2);
		//boxes[boxAmount - 1] = newBox(22, (i - 20)*-0.1, -(i - 20)*0.2 - 2.3, 8, 0.2, 0.2);
	}
	*/

	
	//boxes[boxAmount-1] = newBox(22, 0, -8.0, 8, 4, 4);

	/*
	boxes[boxAmount - 1] = newBox(-35, 0, 0.0, 10, 0.1, 10);

	for (int i = 1; i < 50; i++) {
		boxes[boxAmount - 1] = newBox(-35-i*10, 0, 0.0, 10, 0.1, 10);
	}
	*/
	//boxes[boxAmount - 1] = newBox(-350, 0, 0.0, 620, 0.1, 10);


	//boxes[boxAmount - 1] = newBox(0, 0.5, -4, 1, 1, 1); //NULL BOX
	

	/*
	boxes[0] = newBox(22, 2, 3, 6, 4, 4);
	boxes[1] = newBox(22, 1, -3, 6, 2, 4);
	boxes[2] = newBox(22, 0.5f, -5, 6, 1, 2);
	*/

}

void actionBoxes() {
	//canJump = true;

	if (creativeMode == 1) {
		boxes[boxAmount - 1].x = (int)((camx + sin(camAngY) * 3) * 4) / 4.0;
		boxes[boxAmount - 1].y = (int)((camy + sin(camAngX) * 3) * 8) / 8.0;
		boxes[boxAmount - 1].z = (int)((camz - cos(camAngY) * 3) * 4) / 4.0;

		if (mouseRDown == true && mouseRWait == false) {
			boxes[boxAmount - 1] = newBox((int)((camx + sin(camAngY) * 3) * 4) / 4.0, (int)((camy + sin(camAngX) * 3) * 8) / 8.0, (int)((camz - cos(camAngY) * 3) * 4) / 4.0, 1, 1, 1);
			mouseRWait = true;
		}
		if (mouseRDown == false) {
			mouseRWait = false;
		}
	}
	else {
		boxes[boxAmount - 1].x = 0.0;
		boxes[boxAmount - 1].y = -10000.0;
		boxes[boxAmount - 1].z = 0.0;
	}
	
	for (int i = 0; i < boxAmount; i++) {
		objPlacementTRS(drawBox, boxes[i].x, boxes[i].y, boxes[i].z, 0.0, 0.0, 0.0, boxes[i].sx, boxes[i].sy, boxes[i].sz);
		if (camx > boxes[i].x - playerSize - boxes[i].sx / 2 && camx < boxes[i].x + playerSize + boxes[i].sx / 2) {
			if (camy > boxes[i].y - playerSize - boxes[i].sy / 2 && camy < boxes[i].y + playerHeight + boxes[i].sy / 2) {
				if (camz > boxes[i].z - playerSize - boxes[i].sz / 2 && camz < boxes[i].z + playerSize + boxes[i].sz / 2) {
					
					if (camx > boxes[i].x - playerSize - boxes[i].sx / 2 && ox < boxes[i].x + playerSize + boxes[i].sx / 2) {
						if (camz > boxes[i].z - playerSize - boxes[i].sz / 2 && oz < boxes[i].z + playerSize + boxes[i].sz / 2) {
							if (oy <= boxes[i].y - playerSize - boxes[i].sy / 2) {
								camy = boxes[i].y - playerSize - boxes[i].sy / 2;
							}
							if (oy >= boxes[i].y + playerHeight - 0.2 + boxes[i].sy / 2) {
								camy = boxes[i].y + playerHeight + boxes[i].sy / 2;
								camyv = 0.0f;
								canJump = true;
							}
						}
					}

					if (ox > boxes[i].x - playerSize - boxes[i].sx / 2 && ox < boxes[i].x + playerSize + boxes[i].sx / 2) {
						if (oy > boxes[i].y - playerSize - boxes[i].sy / 2 && oy < boxes[i].y + playerHeight - 0.2 + boxes[i].sy / 2) {
							if (oz <= boxes[i].z - playerSize - boxes[i].sz / 2) {
								camz = boxes[i].z - playerSize - boxes[i].sz / 2;
							}
							if (oz >= boxes[i].z + playerSize + boxes[i].sz / 2) {
								camz = boxes[i].z + playerSize + boxes[i].sz / 2;
							}
						}
					}

					if (oz > boxes[i].z - playerSize - boxes[i].sz / 2 && oz < boxes[i].z + playerSize + boxes[i].sz / 2) {
						if (oy > boxes[i].y - playerSize - boxes[i].sy / 2 && oy < boxes[i].y + playerHeight - 0.2 + boxes[i].sy / 2) {
							if (ox <= boxes[i].x - playerSize - boxes[i].sx / 2) {
								camx = boxes[i].x - playerSize - boxes[i].sx / 2;
							}
							if (ox >= boxes[i].x + playerSize + boxes[i].sx / 2) {
								camx = boxes[i].x + playerSize + boxes[i].sx / 2;
							}
						}
					}

				}
			}
		}
	}
}