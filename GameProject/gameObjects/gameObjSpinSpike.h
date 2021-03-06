struct spinSpike {
	int motion;
	float offset;
	float x;
	float y;
	float z;
	float range;
};

#define spikeDamage 4

spinSpike newSpinSpike(float x, float y, float z, int motion, float offset, float range);
void initSpinSpikes();
void actionSpinSpikes();
void displaySpinSpikes();

//#define PI 3.1415926535
#define maxSpinSpikes 60
spinSpike spinSpikes[maxSpinSpikes];
int spinSpikeAmount;

spinSpike newSpinSpike(float x, float y, float z, int motion, float offset, float range) {
	spinSpikeAmount++;
	spinSpike theSpinSpike;
	theSpinSpike.motion = motion; // 1 x axis motion, 2 z axis motion, 3 circular motion, 4 circular counter clockwise
	theSpinSpike.offset = offset;
	theSpinSpike.x = x;
	theSpinSpike.y = y;
	theSpinSpike.z = z;
	theSpinSpike.range = range;
	return theSpinSpike;
}

void initSpinSpikes() {
	spinSpikeAmount = 0;

	// intro levels
	if (currentLevel == -1) {
		spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-50, 0.0f, -24.0f, 2, 0.0f, 9.0f);
		spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-70, 0.0f, -26.0f, 2, 30.0f, 8.0f);
		spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-90, 0.0f, -24.0f, 2, 60.0f, 9.0f);
		spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-110, 0.0f, -24.0f, 2, 90.0f, 9.0f);
		spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-130, 0.0f, -24.0f, 2, 120.0f, 9.0f);
		spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-150, 0.0f, -24.0f, 2, 150.0f, 9.0f);
		spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-170, 0.0f, -19.0f, 2, 180.0f, 9.0f);
	}



	// Intro to graphics 332 map
	//spinSpikes[0] = newSpinSpike(0, 0.0f, 14.0f, 1, 0.0f, 8.0f);
	/*
	spinSpikes[0] = newSpinSpike(0, 0.0f, 14.0f, 1, 0.0f, 8.0f);
	spinSpikes[1] = newSpinSpike(0, 0.0f, -14.0f, 1, 0.0f, 8.0f);
	spinSpikes[2] = newSpinSpike(14, 0.0f, 0.0f, 2, 0.0f, 8.0f);
	spinSpikes[3] = newSpinSpike(0.0f, 0.0f, 0.0f, 4, 0.0f, 8.0f);

	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(0.0f, 0.0f, -170.0f, 3, PI / 2.0, 8.0f);
	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(0.0f, 0.0f, -170.0f, 3, PI, 8.0f);
	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(0.0f, 0.0f, -170.0f, 3, PI*2.0, 8.0f);
	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(0.0f, 0.0f, -170.0f, 3, PI / 2.0+PI, 8.0f);

	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(0.0f, 0.0f, -170.0f, 3, PI / 2.0, 12.0f);
	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(0.0f, 0.0f, -170.0f, 3, PI, 12.0f);
	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(0.0f, 0.0f, -170.0f, 3, PI*2.0, 12.0f);
	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(0.0f, 0.0f, -170.0f, 3, PI / 2.0 + PI, 12.0f);


	for (int i = 0; i < 4; i++) {
		spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-40-i*6.0f, 0.0f, 0.0f, 2, i*1.5f, 2.8f);
		spinSpikes[spinSpikeAmount - 1] = newSpinSpike(0.0f, 0.0f, -44 - i * 6.0f, 1, i*1.5f, 2.8f);
		spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-90.0f, 0.0f, -34 - i * 16.0f, 1, i*1.5f, 2.8f);
	}

	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-90, 0.0f, -120, 3, PI, 8.0f);
	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-90, 0.0f, -120, 3, PI/2.0, 8.0f);
	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-90, 0.0f, -120, 3, PI+PI/2.0, 8.0f);
	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-90, 0.0f, -120, 3, 0.0f, 8.0f);
	*/

	/*
	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-90, 0.0f, -120, 4, PI, 8.0f);
	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-90, 0.0f, -120, 4, PI / 2.0, 8.0f);
	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-90, 0.0f, -120, 4, PI + PI / 2.0, 8.0f);
	spinSpikes[spinSpikeAmount - 1] = newSpinSpike(-90, 0.0f, -120, 4, 0.0f, 8.0f);
	*/


}

void actionSpinSpikes() {

	float num1;
	float num2;

	//spikeAngY = spikeAngY - 22.3;
	spikeAngY = spikeAngY - 12.3;

	for (int i = 0; i < spinSpikeAmount; i++) {

		if (abs(camx - spinSpikes[i].x) < 120 && abs(camz - spinSpikes[i].z) < 120) {

			switch (spinSpikes[i].motion)
			{
			case 1:
				num1 = sin(timer * 4 + spinSpikes[i].offset)*spinSpikes[i].range + spinSpikes[i].x;
				if (sqrtf((num1 - camx)*(num1 - camx) + (spinSpikes[i].y - camy)*(spinSpikes[i].y - camy) + (spinSpikes[i].z - camz)*(spinSpikes[i].z - camz)) < 2.8) {
					camxv = -(num1 - camx)*0.4f;
					camzv = -(spinSpikes[i].z - camz)*0.4f;
					if (takingDamage <= 0) {
						//Source: http://soundbible.com/1008-Decapitation.html
						SoundEngine->play2D("./src/audio/Decapitation-SoundBible.com-800292304.mp3");
						health = health - spikeDamage;
						if (health < 0) { health = 0; }
					}
					takingDamage = 10;
				}

				break;
			case 2:
				num2 = cos(timer * 4 + spinSpikes[i].offset)*spinSpikes[i].range + spinSpikes[i].z;
				if (sqrtf((spinSpikes[i].x - camx)*(spinSpikes[i].x - camx) + (spinSpikes[i].y - camy)*(spinSpikes[i].y - camy) + (num2 - camz)*(num2 - camz)) < 2.8) {
					camxv = -(spinSpikes[i].x - camx)*0.4f;
					camzv = -(num2 - camz)*0.4f;
					if (takingDamage <= 0) {
						//Source: http://soundbible.com/1008-Decapitation.html
						SoundEngine->play2D("./src/audio/Decapitation-SoundBible.com-800292304.mp3");
						health = health - spikeDamage;
						if (health < 0) { health = 0; }
					}
					takingDamage = 10;
				}

				break;
			case 3:
				num1 = sin(timer * 4 + spinSpikes[i].offset)*spinSpikes[i].range + spinSpikes[i].x;
				num2 = cos(timer * 4 + spinSpikes[i].offset)*spinSpikes[i].range + spinSpikes[i].z;
				if (sqrtf((num1 - camx)*(num1 - camx) + (spinSpikes[i].y - camy)*(spinSpikes[i].y - camy) + (num2 - camz)*(num2 - camz)) < 2.8) {
					camxv = -(num1 - camx)*0.4f;
					camzv = -(num2 - camz)*0.4f;
					if (takingDamage <= 0) {
						//Source: http://soundbible.com/1008-Decapitation.html
						SoundEngine->play2D("./src/audio/Decapitation-SoundBible.com-800292304.mp3");
						health = health - spikeDamage;
						if (health < 0) { health = 0; }
					}
					takingDamage = 10;
				}

				break;
			case 4:
				num2 = sin(timer * 4 + spinSpikes[i].offset)*spinSpikes[i].range + spinSpikes[i].x;
				num1 = cos(timer * 4 + spinSpikes[i].offset)*spinSpikes[i].range + spinSpikes[i].z;
				if (sqrtf((num1 - camx)*(num1 - camx) + (spinSpikes[i].y - camy)*(spinSpikes[i].y - camy) + (num2 - camz)*(num2 - camz)) < 2.8) {
					camxv = -(num1 - camx)*0.4f;
					camzv = -(num2 - camz)*0.4f;
					if (takingDamage <= 0) {
						//Source: http://soundbible.com/1008-Decapitation.html
						SoundEngine->play2D("./src/audio/Decapitation-SoundBible.com-800292304.mp3");
						health = health - spikeDamage;
						if (health < 0) { health = 0; }
					}
					takingDamage = 10;
				}

				break;
			}

		}

	}
}






void displaySpinSpikes() {

	float num1;
	float num2;

	for (int i = 0; i < spinSpikeAmount; i++) {

		if (abs(camx - spinSpikes[i].x) < 120 && abs(camz - spinSpikes[i].z) < 120) {

			switch (spinSpikes[i].motion)
			{
			case 1:
				num1 = sin(timer * 4 + spinSpikes[i].offset)*spinSpikes[i].range + spinSpikes[i].x;
				objPlacementTRS(drawSpinSpikes, num1, spinSpikes[i].y, spinSpikes[i].z, 0.0, spikeAngY, 0.0, 1.0, 1.0, 1.0);
				break;
			case 2:
				num2 = cos(timer * 4 + spinSpikes[i].offset)*spinSpikes[i].range + spinSpikes[i].z;
				objPlacementTRS(drawSpinSpikes, spinSpikes[i].x, spinSpikes[i].y, num2, 0.0, spikeAngY, 0.0, 1.0, 1.0, 1.0);
				break;
			case 3:
				num1 = sin(timer * 4 + spinSpikes[i].offset)*spinSpikes[i].range + spinSpikes[i].x;
				num2 = cos(timer * 4 + spinSpikes[i].offset)*spinSpikes[i].range + spinSpikes[i].z;
				objPlacementTRS(drawSpinSpikes, num1, spinSpikes[i].y, num2, 0.0, spikeAngY, 0.0, 1.0, 1.0, 1.0);
				break;
			case 4:
				num2 = sin(timer * 4 + spinSpikes[i].offset)*spinSpikes[i].range + spinSpikes[i].x;
				num1 = cos(timer * 4 + spinSpikes[i].offset)*spinSpikes[i].range + spinSpikes[i].z;
				objPlacementTRS(drawSpinSpikes, num1, spinSpikes[i].y, num2, 0.0, spikeAngY, 0.0, 1.0, 1.0, 1.0);
				break;
			}

		}

	}
}