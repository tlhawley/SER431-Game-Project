

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
		//glRotatef(180, 0, 1, 0);
		if (refectOn == 0) {
			glCallList(meshTree);
		}
		//glRotatef(-180, 0, 1, 0);
		break;
	case 7:
		//glRotatef(180, 0, 1, 0);
		if (refectOn == 0) {
			glCallList(meshGrassCluster);
		}
		//glRotatef(-180, 0, 1, 0);
		break;
	case 11:
		// Level 1 - Background Rocks
		glCallList(meshLV1BackgroundRocks);
		// Level 1 - Forest Grass
		//glCallList(meshLV1ForestGrass);
		break;
	case 12:
		// Level 1 - Forest Trees
		if (refectOn == 0) {
			glCallList(meshLV1ForestTrees);
		}
		break;
	case 13:
		// Level 1 - Forest Rocks
		if (refectOn == 0) {
			glCallList(meshLV1Rocks);
		}
		break;
	case 14:
		// Level 1 - Structures
		if (refectOn == 0) {
			glCallList(meshLV1Structures);
		}
		break;
	case 15:
		// Level 1 - Floor
		if (refectOn == 0) {
			glCallList(meshLV1Floor);
		}
		break;
	case 16:
		glCallList(meshHubWalls);
		break;
	case 17:
		glCallList(meshPortal);
		break;
	case 18:
		glCallList(meshPortalClosed);
		break;
	case 19:
		glCallList(meshLV1);
		break;
	case 20:
		glCallList(meshLV2);
		break;
	}
	

}