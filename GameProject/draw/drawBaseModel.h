

// Unlike other draw.h files this one uses a global variable baseModelID to display a variety of different .obj models

int baseModelID;

void drawBaseModel();

void drawBaseModel() {

	switch (baseModelID) {
	case 1:
		//setMaterialAdvanced(materialWood);
		glCallList(meshBench);
		break;
	case 2:
		//setMaterialAdvanced(materialWood);
		glCallList(meshChair);
		break;
	case 3:
		//setMaterialAdvanced(materialBronze);
		glCallList(hangingLamp);
		//setMaterialAdvanced(materialLamp);
		//glCallList(hangingLampE);
		break;
	case 4:
		//setMaterialAdvanced(materialRubberRed);
		glCallList(meshCouch);
		break;
	case 5:
		//setMaterialAdvanced(materialWood);
		glCallList(meshDesk);
		break;
	case 6:
		//setMaterialAdvanced(materialWood);
		glRotatef(180, 0, 1, 0);
		glCallList(meshTree);
		glRotatef(-180, 0, 1, 0);
		break;
	}

}