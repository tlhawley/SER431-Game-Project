

void setParticleColor(Particle* curr) {

	float red = 0;
	float green = 0;
	float blue = 0;
	float alpha = 0;

	switch (curr->pSystemData.colorFunction) {
	case ParColorID::smokeC:
		red = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 1.5f;
		green = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 1.5f;
		blue = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 1.5f;
		alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		break;
	case ParColorID::flameC:
		red = 1.0f;
		green = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength*1.0 + 0.4f;
		if (curr->pSystemData.lifeMin > curr->pSystemData.lifeLength / 2.0) {
			blue = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
			alpha = 1.0f;
		}
		else {
			alpha = 2 * curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;

			blue = 0.0f;
		}
		//alpha = 2*curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		break;
	case ParColorID::smokeDarkC:
		red = 0.1f;
		green = 0.1f;
		blue = 0.1f;
		alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 8.0f;
		break;
	case ParColorID::snowC:
		red = 1.0f;
		green = 1.0f;
		blue = 1.0f;
		alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 4.0f + 0.75f;
		break;
	case ParColorID::waterfallC:
		red = 1.0f - curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 7.0f;
		green = 1.0f - curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 15.0f;
		blue = 1.0f;
		alpha = 0.8f*curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		break;
	case ParColorID::waterfallSubC:
		red = 1.0f - curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 7.0f;
		green = 1.0f - curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 15.0f;
		blue = 1.0f;
		alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 6.0f;
		break;
	case ParColorID::frostC:
		if (curr->pSystemData.lifeMin > curr->pSystemData.lifeLength / 2.0) {
			red = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		}
		else {
			red = 0.0f;
		}
		green = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength*1.0 + 0.4f;
		blue = 1.0f;
		alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 4.0f + 0.75f;
		break;
	case ParColorID::leafC:
		
		red = .9f;
		green = 0.3f+curr->pSystemData.colorSeed/3000.0f;
		blue = 0.1f;
		alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 4.0f + 0.75f;
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