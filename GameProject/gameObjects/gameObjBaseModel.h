
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


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			baseModels[baseModelAmount - 1] = newBaseModel(-8 + i * 4.0, 0.0f, -20.0f + j * 4.0, 0.0f, 180.0f, 0.0f, 400.0, 6);
		}
	}

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
		//if (abs(camx - baseModels[i].x) < baseModels[i].cullRange && abs(camz - baseModels[i].z) < baseModels[i].cullRange) { // only render models if they are within the cull range
			baseModelID = baseModels[i].model;
			//if (baseModels[i].model == 3) {
			objPlacementTRS(drawBaseModel, baseModels[i].x, baseModels[i].y, baseModels[i].z, baseModels[i].ax , baseModels[i].ay, baseModels[i].az, 1.0, 1.0, 1.0);
		//}
	}
}