

void setParticleColor(Particle* curr) {

	float red = 0;
	float green = 0;
	float blue = 0;
	float alpha = 0;

	switch (curr->pSystemData.colorFunction) {
	case smokeColors :
		red = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 1.5f;
		green = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 1.5f;
		blue = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 1.5f;
		alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		break;
	case flameColors:
		red = 1.0f;
		green = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength*1.0+0.4f;
		if (curr->pSystemData.lifeMin > curr->pSystemData.lifeLength / 2.0) {
			blue = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		}
		else {
			blue = 0.0f;
		}
		alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		break;
	case smokeDarkColors:
		red = 0.1f;
		green = 0.1f;
		blue = 0.1f;
		alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength/4.0f;
		break;
	case snowColors:
		red = 1.0f;
		green = 1.0f;
		blue = 1.0f;
		alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 4.0f+0.75f;
		break;
	default:
		red = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 1.5f;
		green = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 1.5f;
		blue = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 1.5f;
		alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		break;
	}

	float materialCustom[] = { 0,0,0,0,red,green,blue,alpha,0,0,0,0,red,green,blue,alpha,1 };
	setMaterialAdvanced(materialCustom);

}