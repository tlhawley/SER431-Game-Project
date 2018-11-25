

void drawfurniture();

void drawfurniture() {

	switch (furnitureModel) {
	case 1:
		setMaterialAdvanced(materialWood);
		glCallList(meshBench.l1);
		break;
	case 2:
		setMaterialAdvanced(materialWood);
		glCallList(meshChair.l1);
		break;
	case 3:
		setMaterialAdvanced(materialBronze);
		glCallList(hangingLamp.l1);
		setMaterialAdvanced(materialLamp);
		glCallList(hangingLampE.l1);
		break;
	case 4:
		setMaterialAdvanced(materialRubberRed);
		glCallList(meshCouch.l1);
		break;
	case 5:
		setMaterialAdvanced(materialWood);
		glCallList(meshDesk.l1);
		break;
	}

}