// This contains mathematical case functions for setting the particle colors and alpha values


void setParticleColor(Particle* curr) {

	float red = 0;
	float green = 0;
	float blue = 0;
	float alpha = 0;

	switch (curr->pSystemData.colorFunction) {
	case ParColorID::smokeC:
		red = curr->pSystemData.life / curr->pSystemData.lifeLength / 1.5f;
		green = curr->pSystemData.life / curr->pSystemData.lifeLength / 1.5f;
		blue = curr->pSystemData.life / curr->pSystemData.lifeLength / 1.5f;
		alpha = curr->pSystemData.life / curr->pSystemData.lifeLength;
		break;
	case ParColorID::flameC:
		red = 1.0f;
		green = curr->pSystemData.life / curr->pSystemData.lifeLength*1.0 + 0.4f;
		if (curr->pSystemData.life > curr->pSystemData.lifeLength / 2.0) {
			blue = curr->pSystemData.life / curr->pSystemData.lifeLength;
			alpha = 1.0f;
		}
		else {
			alpha = 2 * curr->pSystemData.life / curr->pSystemData.lifeLength;

			blue = 0.0f;
		}
		//alpha = 2*curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		break;
	case ParColorID::flame2C:
		red = 1.0f;
		green = curr->pSystemData.life / curr->pSystemData.lifeLength*1.0 + 0.4f;
		if (curr->pSystemData.life > curr->pSystemData.lifeLength / 2.0) {
			blue = curr->pSystemData.life / curr->pSystemData.lifeLength /2.0;
			alpha = 1.0f;
		}
		else {
			alpha = 2 * curr->pSystemData.life / curr->pSystemData.lifeLength;

			blue = 0.0f;
		}
		//alpha = 2*curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		break;
	case ParColorID::smokeDarkC:
		red = 0.1f;
		green = 0.1f;
		blue = 0.1f;
		alpha = curr->pSystemData.life / curr->pSystemData.lifeLength / 8.0f;
		break;
	case ParColorID::snowC:
		red = 1.0f;
		green = 1.0f;
		blue = 1.0f;
		alpha = curr->pSystemData.life / curr->pSystemData.lifeLength / 4.0f + 0.75f;
		break;
	case ParColorID::waterfallC:
		red = 1.0f - curr->pSystemData.life / curr->pSystemData.lifeLength / 7.0f;
		green = 1.0f - curr->pSystemData.life / curr->pSystemData.lifeLength / 15.0f;
		blue = 1.0f;
		alpha = 0.8f*curr->pSystemData.life / curr->pSystemData.lifeLength;
		break;
	case ParColorID::waterfallSubC:
		red = 1.0f - curr->pSystemData.life / curr->pSystemData.lifeLength / 7.0f;
		green = 1.0f - curr->pSystemData.life / curr->pSystemData.lifeLength / 15.0f;
		blue = 1.0f;
		alpha = curr->pSystemData.life / curr->pSystemData.lifeLength / 6.0f;
		break;
	case ParColorID::frostC:
		if (curr->pSystemData.life > curr->pSystemData.lifeLength / 2.0) {
			red = curr->pSystemData.life / curr->pSystemData.lifeLength;
			//alpha = 1.0f;
		}
		else {
			//alpha = 2 * curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
			red = 0.0f;
		}
		green = curr->pSystemData.life / curr->pSystemData.lifeLength*1.0 + 0.5f;
		blue = 1.0f;
		alpha = curr->pSystemData.life / curr->pSystemData.lifeLength;
		//alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength / 4.0f + 0.75f;
		break;
	case ParColorID::leafC:
		red = .9f;
		green = 0.3f+curr->pSystemData.colorSeed/3000.0f;
		blue = 0.1f;
		alpha = curr->pSystemData.life / curr->pSystemData.lifeLength / 4.0f + 0.75f;
		break;
	case ParColorID::rainbowC:
		if (curr->pSystemData.life / curr->pSystemData.lifeLength > 0.8333333333333333) {
			red = 1.0f;
			green = (0.8333333333333333 -curr->pSystemData.life / curr->pSystemData.lifeLength) * 6.0 + 1;
			blue = 0.0f;
			alpha = 1.0f;
		}
		else {
			if (curr->pSystemData.life / curr->pSystemData.lifeLength > 0.66666666666666666666) {
				red = (-0.666666666666666666 + curr->pSystemData.life / curr->pSystemData.lifeLength) * 6.0;
				green = 1.0;
				blue = 0.0f;
				alpha = 1.0f;
			}
			else {
				if (curr->pSystemData.life / curr->pSystemData.lifeLength > 0.5) {
					red = 0.0f;
					green = 1.0f;
					blue = (0.5 - curr->pSystemData.life / curr->pSystemData.lifeLength) * 6.0 + 1;
					alpha = 1.0f;
				}
				else {
					if (curr->pSystemData.life / curr->pSystemData.lifeLength > 0.333333333333333333333) {
						red = 0.0f;
						green = (-0.3333333333333333333 + curr->pSystemData.life / curr->pSystemData.lifeLength) * 6.0;
						blue = 1.0f;
						alpha = 1.0f;
					}
					else {
						if (curr->pSystemData.life / curr->pSystemData.lifeLength > 0.16666666666666666666666666) {
							red = (0.16666666666666666666666 - curr->pSystemData.life / curr->pSystemData.lifeLength) * 6.0 + 1;
							green = 0.0f;
							blue = 1.0f;
							alpha = 1.0f;
						}
						else {
							red = 1.0f;
							green = 0.0f;
							blue = 1.0f;
							alpha = (curr->pSystemData.life / curr->pSystemData.lifeLength) * 6.0;
						}
					}
				}
			}
		}
		//alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		break;
	case ParColorID::fogC:
		/*
		red = 0.4f;
		green = 0.4f;
		blue = 0.4f;
		*/
		red = 1.0f;
		green = 1.0f;
		blue = 1.0f;

		if (curr->pSystemData.life / curr->pSystemData.lifeLength > 0.8333333333333333) { // alpha fade in
			alpha = (0.8333333333333333 - curr->pSystemData.life / curr->pSystemData.lifeLength) * 1.0 + 0.1666666666666666;
		}
		else { // alpha fade out
			if (curr->pSystemData.life / curr->pSystemData.lifeLength < 0.16666666666666666666666666) {
				alpha = (curr->pSystemData.life / curr->pSystemData.lifeLength) * 1.0;
			}
			else { // alpha solid
				alpha = 0.1666666666666666666666f;
			}
		}
		break;

	case ParColorID::whiteFadeC:
		red = 1.0f;
		green = 1.0f;
		blue = 1.0f;
		alpha = curr->pSystemData.life / curr->pSystemData.lifeLength;
		break;
	case ParColorID::rainC:
		red = 1.0f;
		green = 1.0f;
		blue = 1.0f;
		alpha = 0.1f;
		break;

	default:
		red = curr->pSystemData.life / curr->pSystemData.lifeLength / 1.5f;
		green = curr->pSystemData.life / curr->pSystemData.lifeLength / 1.5f;
		blue = curr->pSystemData.life / curr->pSystemData.lifeLength / 1.5f;
		alpha = curr->pSystemData.life / curr->pSystemData.lifeLength;
		break;
	}

	float materialCustom[] = { 0,0,0,0,red,green,blue,alpha,0,0,0,0,red,green,blue,alpha,1 };
	setMaterialAdvanced(materialCustom);

}