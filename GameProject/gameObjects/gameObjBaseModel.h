
// Used to display various .obj files
// These objects are only for display and do not have any collision movement, or interaction applied to them.

struct baseModel {
	int model;
	float x;
	float y;
	float z;
	float ax;
	float ay;
	float az;
	float cullRange;
};

baseModel newBaseModel(float x, float y, float z);
void initBaseModels();
void actionBaseModels();
void displayBaseModels();

#define maxBaseModels 200
baseModel baseModels[maxBaseModels];
int baseModelAmount;

baseModel newBaseModel(float x, float y, float z, float ax, float ay, float az, float cullRange, int model) {
	baseModelAmount++;
	baseModel theBaseModel;
	theBaseModel.model = model;
	theBaseModel.x = x;
	theBaseModel.y = y;
	theBaseModel.z = z;
	theBaseModel.ax = ax;
	theBaseModel.ay = ay;
	theBaseModel.az = az;
	theBaseModel.cullRange = cullRange;

	return theBaseModel;
}

void initBaseModels() {


	baseModelAmount = 0;

	if (currentLevel == -1) { //intro level
		baseModels[baseModelAmount - 1] = newBaseModel(5.87292, 0.000015, 13.4375, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(0.016002, 0.000015, 14.8966, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-4.25544, 0.000015, 11.3592, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-2.74412, 0.000015, 19.1562, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-9.71325, 0.000015, 11.0473, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-13.0989, 0.000015, 18.6313, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-14.7305, 0.000015, 12.1364, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-17.9581, 0.000015, 7.7457, 0, 0, 0, 70.0, 7); // LV1 Grass

		baseModels[baseModelAmount - 1] = newBaseModel(-25.0648, 0.000015, 5.37347, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-27.979, 0.000015, 0.102108, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-30.5226, 0.000015, 5.06159, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-35.5399, 0.000015, 6.15073, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-33.3537, 0.000015, -2.48115, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-38.7675, 0.000015, 1.75999, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-40.237, 0.000015, -5.2776, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-42.304, 0.000015, -10.0842, 0, 0, 0, 70.0, 7); // LV1 Grass

		baseModels[baseModelAmount - 1] = newBaseModel(-46.5005, 0.000015, -13.448, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-47.3437, 0.000015, -7.64982, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-52.8015, 0.000015, -13.448, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-52.8015, 0.000015, -7.96171, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-59.6039, 0.000015, -13.4144, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-65.8431, 0.000015, -14.1284, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-70.5335, 0.000015, -5.04331, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-76.068, 0.000015, -13.1809, 0, 0, 0, 70.0, 7); // LV1 Grass

		baseModels[baseModelAmount - 1] = newBaseModel(-81.5258, 0.000015, -13.4928, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-86.5431, 0.000015, -12.4037, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-86.5431, 0.000015, -5.04331, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-95.4288, 0.000015, -14.7783, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-96.7133, 0.000015, -5.04331, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-102.597, 0.000015, -11.4861, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-112.592, 0.000015, -15.5867, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-118.81, 0.000015, -5.04331, 0, 0, 0, 70.0, 7); // LV1 Grass

		baseModels[baseModelAmount - 1] = newBaseModel(-120.049, 0.000015, -15.5867, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-126.731, 0.000015, -15.5867, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-133.573, 0.000015, -5.04331, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-138.49, 0.000015, -15.5867, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-145.209, 0.000015, -12.947, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-151.329, 0.000015, -11.0272, 0, 0, 0, 70.0, 7); // LV1 Grass
		//baseModels[baseModelAmount - 1] = newBaseModel(-112.592, 0.000015, -15.5867, 0, 0, 0, 70.0, 7); // LV1 Grass
		//baseModels[baseModelAmount - 1] = newBaseModel(-118.81, 0.000015, -5.04331, 0, 0, 0, 70.0, 7); // LV1 Grass

		baseModels[baseModelAmount - 1] = newBaseModel(20.286, 0.000015, 1.30327, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(23.9635, 0.000015, -13.1652, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(13.3694, 0.000015, -13.1652, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(13.3694, 0.000015, -31.756, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(8.2022, 0.000015, -20.5679, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(6.6419, 0.000015, -14.569, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(1.1968, 0.000015, -11.1906, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(3.35359, 0.000015, -39.7768, 0, 0, 0, 70.0, 7); // LV1 Grass

		baseModels[baseModelAmount - 1] = newBaseModel(3.88156, 0.000015, -30.3523, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(2.77671, 0.000015, -24.7065, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(1.26785, 0.000015, -19.0094, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-2.99975, 0.000015, -14.5544, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-5.74161, 0.000015, -10.2801, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-9.30072, 0.000015, -14.5544, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-3.87473, 0.000015, -23.5758, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-2.41044, 0.000015, -29.3398, 0, 0, 0, 70.0, 7); // LV1 Grass

		baseModels[baseModelAmount - 1] = newBaseModel(-9.31954, 0.000015, -20.8797, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-14.3592, 0.000015, -18.4454, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-13.5161, 0.000015, -24.2435, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-8.58846, 0.000015, -28.31, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-8.09985, 0.000015, -34.9616, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-19.8171, 0.000015, -24.2435, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-15.1826, 0.000015, -30.7875, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-20.8209, 0.000015, -30.4269, 0, 0, 0, 70.0, 7); // LV1 Grass

		baseModels[baseModelAmount - 1] = newBaseModel(-25.8606, 0.000015, -27.9926, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-25.0175, 0.000015, -33.7907, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-31.3184, 0.000015, -33.7907, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-37.9513, 0.000015, -37.8747, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-47.6737, 0.000015, -39.334, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-54.2843, 0.000015, -39.334, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-63.435, 0.000015, -39.334, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-69.3051, 0.000015, -38.1365, 0, 0, 0, 70.0, 7); // LV1 Grass

		baseModels[baseModelAmount - 1] = newBaseModel(-75.2034, 0.000015, -36.8129, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-80.9755, 0.000015, -35.7336, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-86.9484, 0.000015, -36.8129, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-86.4561, 0.000015, -46.2136, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-93.3982, 0.000015, -36.8129, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-99.4104, 0.000015, -36.8129, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-106.007, 0.000015, -37.3569, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-111.163, 0.000015, -48.0046, 0, 0, 0, 70.0, 7); // LV1 Grass

		baseModels[baseModelAmount - 1] = newBaseModel(-129.678, 0.000015, -38.7391, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-138.49, 0.000015, -35.2836, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-145.209, 0.000015, -34.3717, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-151.329, 0.000015, -32.4519, 0, 0, 0, 70.0, 7); // LV1 Grass
		baseModels[baseModelAmount - 1] = newBaseModel(-159.051, 0.000015, -35.2836, 0, 0, 0, 70.0, 7); // LV1 Grass
		//baseModels[baseModelAmount - 1] = newBaseModel(-99.4104, 0.000015, -36.8129, 0, 0, 0, 70.0, 7); // LV1 Grass
		//baseModels[baseModelAmount - 1] = newBaseModel(-106.007, 0.000015, -37.3569, 0, 0, 0, 70.0, 7); // LV1 Grass
		//baseModels[baseModelAmount - 1] = newBaseModel(-111.163, 0.000015, -48.0046, 0, 0, 0, 70.0, 7); // LV1 Grass



		baseModels[baseModelAmount - 1] = newBaseModel(0, 0, 0, 0, 0, 0, 4000.0, 11); // LV1 - background rocks
		baseModels[baseModelAmount - 1] = newBaseModel(0, 0, 0, 0, 0, 0, 4000.0, 12); // LV1
		baseModels[baseModelAmount - 1] = newBaseModel(0, 0, 0, 0, 0, 0, 4000.0, 13); // LV1
		baseModels[baseModelAmount - 1] = newBaseModel(0, 0, 0, 0, 0, 0, 4000.0, 14); // LV1
		baseModels[baseModelAmount - 1] = newBaseModel(0, 0, 0, 0, 0, 0, 4000.0, 15); // LV1

	}

	if (currentLevel == 0) { // hub world
		baseModels[baseModelAmount - 1] = newBaseModel(0, 0, 0, 0, 0, 0, 4000.0, 16); // hub walls

		// TODO: Add conditions for the portals to open, close, or mark complete based on what levels are unlocked
		baseModels[baseModelAmount - 1] = newBaseModel(-20, -3.2, 10, 0, 90, 0, 4000.0, 17); // hub portal LV 1
		//Cboxes[CboxAmount - 1] = newCBox(-20, -3.2, 10, 1.9829, 20, 6.42671);
		baseModels[baseModelAmount - 1] = newBaseModel(-20, -3.2, -10, 0, 90, 0, 4000.0, 17); // hub portal LV 2 open
		//baseModels[baseModelAmount - 1] = newBaseModel(-20, -3.2, -10, 0, 90, 0, 4000.0, 18); // hub portal LV 2 closed
	}

	if (currentLevel == 1) { // level 1
		baseModels[baseModelAmount - 1] = newBaseModel(0, 0, 0, 0, 0, 0, 4000.0, 19); // level 1 walls

		baseModels[baseModelAmount - 1] = newBaseModel(-1.0f, 30.0f, 41.0f, 0, 180, 0, 4000.0, 17); // portal

																					  // TODO: Add conditions for the portals to open, close, or mark complete based on what levels are unlocked
		//baseModels[baseModelAmount - 1] = newBaseModel(-20, -3.2, 10, 0, 90, 0, 4000.0, 17); // hub portal LV 1
		//baseModels[baseModelAmount - 1] = newBaseModel(-20, -3.2, -10, 0, 90, 0, 4000.0, 18); // hub portal LV 2
	}

	if (currentLevel == 2) { // level 2
		baseModels[baseModelAmount - 1] = newBaseModel(0, 0, 0, 0, 0, 0, 4000.0, 20); // level 2 walls

		baseModels[baseModelAmount - 1] = newBaseModel(-11.0f, 5.77f, -75.0f, 0, -90, 0, 4000.0, 17); // portal

																									// TODO: Add conditions for the portals to open, close, or mark complete based on what levels are unlocked
																									//baseModels[baseModelAmount - 1] = newBaseModel(-20, -3.2, 10, 0, 90, 0, 4000.0, 17); // hub portal LV 1
																									//baseModels[baseModelAmount - 1] = newBaseModel(-20, -3.2, -10, 0, 90, 0, 4000.0, 18); // hub portal LV 2
	}

	/*
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (j % 2 == 0 && i % 2 == 0) {
				baseModels[baseModelAmount - 1] = newBaseModel(8 + i * 4.0, 0.0f, 20.0f + j * 4.0, 0.0f, 180.0f, 0.0f, 400.0, 6); // Tree Models
			}
			baseModels[baseModelAmount - 1] = newBaseModel(8 + i * 4.0, 0.0f, 20.0f + j * 4.0, 0.0f, 180.0f, 0.0f, 400.0, 7); // Grass Models
		}
	}
	*/

	/*
	// Intro to graphics 332 map
	for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 4; j++) {
		baseModels[baseModelAmount - 1] = newBaseModel(-8 + i * 4.0, 0.0f, -128.0f + j * 4.0, 0.0f, 180.0f, 0.0f, 400.0, 1);
	}
	}
	baseModels[baseModelAmount -1] = newBaseModel(20.0f, 0.0f, 8.0f, 0.0f, 180.0f, 0.0f, 400.0, 4);
	baseModels[baseModelAmount - 1] = newBaseModel(-90.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 400.0, 2);
	baseModels[baseModelAmount - 1] = newBaseModel(-90.0f, 35.0f, 0.0f, 0.0f, 0.0f, 0.0f, 400.0, 3);

	for (int i = 0; i < 5; i++) {
		baseModels[baseModelAmount - 1] = newBaseModel(-110.0 +i*4.0f, 0.0f, -130.0f, 0.0f, 180.0f, 0.0f, 400.0, 5);
	}

	*/


	

}

void displayBaseModels() {
	for (int i = 0; i < baseModelAmount; i++) {
		if (abs(camx - baseModels[i].x) < baseModels[i].cullRange && abs(camz - baseModels[i].z) < baseModels[i].cullRange) { // only render models if they are within the cull range
			baseModelID = baseModels[i].model;
			//if (baseModels[i].model == 3) {
			objPlacementTRS(drawBaseModel, baseModels[i].x, baseModels[i].y, baseModels[i].z, baseModels[i].ax , baseModels[i].ay, baseModels[i].az, 1.0, 1.0, 1.0);
		}
	}
}