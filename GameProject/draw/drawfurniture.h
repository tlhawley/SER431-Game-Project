

void drawfurniture();

void drawfurniture() {

	switch (furnitureModel) {
	case 1:
		setMaterialAdvanced(materialWood);
		glCallList(meshBench);
		break;
	case 2:
		setMaterialAdvanced(materialWood);
		glCallList(meshChair);
		break;
	case 3:
		setMaterialAdvanced(materialBronze);
		glCallList(hangingLamp);
		setMaterialAdvanced(materialLamp);
		glCallList(hangingLampE);
		break;
	case 4:
		setMaterialAdvanced(materialRubberRed);
		glCallList(meshCouch);
		break;
	case 5:
		setMaterialAdvanced(materialWood);
		glCallList(meshDesk);
		break;
	}

}