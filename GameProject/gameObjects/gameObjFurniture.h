struct furniture {
	int model;
	float x;
	float y;
	float z;
	float ax;
	float ay;
	float az;
};

furniture newfurniture(float x, float y, float z);
void initfurnitures();
void actionfurnitures();

#define maxfurnitures 200
furniture furnitures[maxfurnitures];
int furnitureAmount;

furniture newfurniture(float x, float y, float z, float ax, float ay, float az, int model) {
	furnitureAmount++;
	furniture thefurniture;
	thefurniture.model = model;
	thefurniture.x = x;
	thefurniture.y = y;
	thefurniture.z = z;
	thefurniture.ax = ax;
	thefurniture.ay = ay;
	thefurniture.az = az;
	return thefurniture;
}

void initfurnitures() {

	
	furnitureAmount = 0;
	/* // Intro to graphics 332 map
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			furnitures[furnitureAmount - 1] = newfurniture(-8 + i * 4.0, 0.0f, -128.0f + j * 4.0, 0.0f, 180.0f, 0.0f, 1);
		}
	}
	furnitures[furnitureAmount-1] = newfurniture(20.0f, 0.0f, 8.0f, 0.0f, 180.0f, 0.0f, 4);
	furnitures[furnitureAmount - 1] = newfurniture(-90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 2);
	furnitures[furnitureAmount - 1] = newfurniture(-90.0f, 35.0f, 0.0f, 0.0f, 0.0f, 0.0f, 3);

	for (int i = 0; i < 5; i++) {
		furnitures[furnitureAmount - 1] = newfurniture(-110.0 +i*4.0f, 0.0f, -130.0f, 0.0f, 180.0f, 0.0f, 5);
	}
	*/

}

void actionfurnitures() {
	for (int i = 0; i < furnitureAmount; i++) {
		//if (furnitures[i].active == true) {

		if (abs(camx - furnitures[i].x) < 80 && abs(camz - furnitures[i].z) < 80) { // only render models if they are close to the camera

			furnitureModel = furnitures[i].model;

			if (furnitures[i].model == 3) {
				objPlacementTRS(drawfurniture, furnitures[i].x, furnitures[i].y, furnitures[i].z, furnitures[i].ax + sin(timer*3.0)*10.0f, furnitures[i].ay, furnitures[i].az, 1.0, 1.0, 1.0);
			}
			else {
				objPlacementTRS(drawfurniture, furnitures[i].x, furnitures[i].y, furnitures[i].z, furnitures[i].ax, furnitures[i].ay, furnitures[i].az, 1.0, 1.0, 1.0);
			}
		}
			
			//if (fabs(camx - furnitures[i].x) < 1.2 && fabs(camz - furnitures[i].z) < 1.2 && fabs(camy - furnitures[i].y) < 2) {
				//furnitures[i].active = false;
				//inventoryfurnitures = inventoryfurnitures + 1;
			//}
		//}
	}
}