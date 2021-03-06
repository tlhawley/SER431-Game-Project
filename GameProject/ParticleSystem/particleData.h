
// This file is used for defining different particle systems
// It contains all the variable data for each particle system.

// Flame particles
// Flame smoke sub sarticles
// Flame spark/ash sub particles
// Smoke particles
// Snow particles
// Fog particles
// Waterfall particles
// Bubble particles
// etc...








// Instead of having a separate function for each particle system...
pSystem particleData(int p, float x, float y, float z) {

	pSystem pSystemData;

	switch (p) {
	case ParID::flame:
		pSystemData.pSystemTypeID = ParID::flame; // A uniqe value to identify the type of particle

		pSystemData.useGravity = false;
		pSystemData.position.x = getRnd(-0.125, 0.125)+x;
		pSystemData.position.y = getRnd(-0.125, 0.125) + y;
		pSystemData.position.z = getRnd(-0.125, 0.125) + z;

		pSystemData.velocity.x = getRnd(-0.25, 0.25);
		pSystemData.velocity.y = getRnd(2.5, 2.0);
		pSystemData.velocity.z = getRnd(-0.25, 0.25); //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = getRnd(-1.5, 1.5);
		pSystemData.acceleration.y = 2.0f; //-1.81f;
		pSystemData.acceleration.z = getRnd(-1.5, 1.5);
		pSystemData.useVelocityMultiplier = false;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = true;
		pSystemData.rotation.x = 0.0f;
		pSystemData.rotation.y = 0.0f;
		pSystemData.rotation.z = getRnd(0, 5);
		pSystemData.rotationVelocity.x = 0.0f;
		pSystemData.rotationVelocity.y = 0.0f;
		pSystemData.rotationVelocity.z = getRnd(-400, 400);
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = false;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 61.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = 1.0f;
		pSystemData.scale.y = 1.0f;
		pSystemData.scale.z = 1.0f;
		pSystemData.scaleVelocity.x = 2.0f;
		pSystemData.scaleVelocity.y = 2.0f;
		pSystemData.scaleVelocity.z = 2.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = true;
		pSystemData.scaleMultiplier.x = 57.0f;
		pSystemData.scaleMultiplier.y = 59.0f;
		pSystemData.scaleMultiplier.z = 57.0f;

		pSystemData.colorFunction = ParColorID::flameC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = true;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.useNoise = false;

		pSystemData.life = getRnd(0.5f, 1.0f); //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1; // bigger number less particles
		pSystemData.emissionAmount = 1; // the amount of particles spawned at a time


		pSystemData.useSubParticleSpawn = true;
		pSystemData.subParticleSpawnID = ParID::flameSparks;

		pSystemData.useSubParticleExit = true;
		pSystemData.subParticleExitID = ParID::flameSmoke; // flame smoke sub particles
														   //pSystemData.subParticleID = 3;

		pSystemData.displayID = displayParticlePlaneFlames;

		break;
	case ParID::flameWall:
		pSystemData.pSystemTypeID = ParID::flameWall; // A uniqe value to identify the type of particle

		pSystemData.useGravity = false;
		pSystemData.position.x = getRnd(-5, 5) + x;
		pSystemData.position.y = y;
		pSystemData.position.z = z;

		pSystemData.velocity.x = getRnd(-0.5, 0.5);
		pSystemData.velocity.y = getRnd(5, 4);
		pSystemData.velocity.z = getRnd(-0.5, 0.5); //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = getRnd(-2.5, 2.5);
		pSystemData.acceleration.y = 2.0f; //-1.81f;
		pSystemData.acceleration.z = getRnd(-2.5, 2.5);
		pSystemData.useVelocityMultiplier = false;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = true;
		pSystemData.rotation.x = 0.0f;
		pSystemData.rotation.y = 0.0f;
		pSystemData.rotation.z = getRnd(0, 5);
		pSystemData.rotationVelocity.x = 0.0f;
		pSystemData.rotationVelocity.y = 0.0f;
		pSystemData.rotationVelocity.z = getRnd(-400, 400);
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = true;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 61.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = 2.0f;
		pSystemData.scale.y = 2.0f;
		pSystemData.scale.z = 2.0f;
		pSystemData.scaleVelocity.x = 4.0f;
		pSystemData.scaleVelocity.y = 4.0f;
		pSystemData.scaleVelocity.z = 4.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = true;
		pSystemData.scaleMultiplier.x = 57.0f;
		pSystemData.scaleMultiplier.y = 59.0f;
		pSystemData.scaleMultiplier.z = 57.0f;

		pSystemData.colorFunction = ParColorID::flameC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = true;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.useNoise = false;

		pSystemData.life = getRnd(0.5f, 1.0f); //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1; // bigger number less particles
		pSystemData.emissionAmount = 8; // the amount of particles spawned at a time


		pSystemData.useSubParticleSpawn = true;
		pSystemData.subParticleSpawnID = ParID::flameWallSparks;

		pSystemData.useSubParticleExit = true;
		pSystemData.subParticleExitID = ParID::flameSmoke; // flame smoke sub particles
														   //pSystemData.subParticleID = 3;

		pSystemData.displayID = displayParticlePlaneFlames;

		break;
	case ParID::flameSmoke:

		pSystemData.pSystemTypeID = ParID::flameSmoke;

		pSystemData.useGravity = false;
		pSystemData.position.x = getRnd(-0.5, 0.5)+ x;
		pSystemData.position.y = y;
		pSystemData.position.z = getRnd(-0.5, 0.5)+ z;
		//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
		pSystemData.velocity.x = getRnd(0, 2) + 3.0f;
		pSystemData.velocity.y = getRnd(-2, 2) + 8.0f;
		pSystemData.velocity.z = getRnd(-1, 1); //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = 0.5f;
		pSystemData.acceleration.y = 0.0f; //-1.81f;
		pSystemData.acceleration.z = 0.0f;
		pSystemData.useVelocityMultiplier = true;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = true;
		pSystemData.rotation.x = 0.0f;
		pSystemData.rotation.y = 0.0f;
		pSystemData.rotation.z = 0.0f;
		pSystemData.rotationVelocity.x = 0.0f;
		pSystemData.rotationVelocity.y = 0.0f;
		pSystemData.rotationVelocity.z = 400.0f;
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = true;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 57.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = 1.0f;
		pSystemData.scale.y = 1.0f;
		pSystemData.scale.z = 1.0f;
		pSystemData.scaleVelocity.x = 1.0f;
		pSystemData.scaleVelocity.y = 0.0f;
		pSystemData.scaleVelocity.z = 0.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = false;
		pSystemData.scaleMultiplier.x = 59.f;
		pSystemData.scaleMultiplier.y = 60.0f;
		pSystemData.scaleMultiplier.z = 60.0f;

		pSystemData.colorFunction = ParColorID::smokeDarkC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = false;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.useNoise = false;

		pSystemData.life = getRnd(0, 1); //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1;
		pSystemData.emissionAmount = 1;

		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = false;

		pSystemData.displayID = displayParticlePlane;

		break;

	case ParID::flameSparks:

		pSystemData.pSystemTypeID = ParID::flameSparks;

		pSystemData.useGravity = false;
		pSystemData.position.x = getRnd(-0.25, 0.25) + x;
		pSystemData.position.y = 1.0f + y;
		pSystemData.position.z = getRnd(-0.25, 0.25) + z;
		//pSystemData.position.x = 0;
		//pSystemData.position.y = 0;
		//pSystemData.position.z = 0;


		//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
		pSystemData.velocity.x = getRnd(-1.5, 1.5);
		pSystemData.velocity.y = getRnd(2, 4);
		pSystemData.velocity.z = getRnd(-1.5, 1.5); //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = 0.5f;
		pSystemData.acceleration.y = 0.0f; //-1.81f;
		pSystemData.acceleration.z = 0.0f;
		pSystemData.useVelocityMultiplier = true;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = false;
		pSystemData.rotation.x = getRnd(-200.0f, 200.0f);
		pSystemData.rotation.y = getRnd(-200.0f, 200.0f);
		pSystemData.rotation.z = getRnd(-200.0f, 200.0f);
		pSystemData.rotationVelocity.x = getRnd(-200.0f, 200.0f);
		pSystemData.rotationVelocity.y = getRnd(-200.0f, 200.0f);
		pSystemData.rotationVelocity.z = getRnd(-200.0f,200.0f);
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = true;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 57.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = getRnd(0.15f,0.3f);
		pSystemData.scale.y = 0.2f;
		pSystemData.scale.z = 0.2f;
		pSystemData.scaleVelocity.x = 0.0f;
		pSystemData.scaleVelocity.y = 0.0f;
		pSystemData.scaleVelocity.z = 0.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = false;
		pSystemData.scaleMultiplier.x = 59.f;
		pSystemData.scaleMultiplier.y = 60.0f;
		pSystemData.scaleMultiplier.z = 60.0f;

		pSystemData.colorFunction = ParColorID::flameC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = false;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.useNoise = false;
		pSystemData.noiseOctaves = 2;
		pSystemData.noisePersistence = 2;
		pSystemData.noiseScale = 0.05;
		pSystemData.noiseSinus = true;
		pSystemData.noiseVelocity.x = 2.1f;
		pSystemData.noiseVelocity.y = 0.0f;
		pSystemData.noiseVelocity.z = 2.1f;
		pSystemData.noiseSpeed = 1.5;

		pSystemData.life = getRnd(0, 1); //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1;
		pSystemData.emissionAmount = 1;

		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = false;

		pSystemData.displayID = displayParticlePlaneFlameSparks;

		break;

	case ParID::flameWallSparks:

		pSystemData.pSystemTypeID = ParID::flameWallSparks;

		pSystemData.useGravity = false;
		pSystemData.position.x = getRnd(-4.0f, 6.0f) + x;
		pSystemData.position.y = 2.0f + y;
		pSystemData.position.z = getRnd(-0.5, 0.5) + z;
		//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
		pSystemData.velocity.x = getRnd(-3, 3);
		pSystemData.velocity.y = getRnd(4, 8);
		pSystemData.velocity.z = getRnd(-3, 3); //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = 0.5f;
		pSystemData.acceleration.y = 0.0f; //-1.81f;
		pSystemData.acceleration.z = 0.0f;
		pSystemData.useVelocityMultiplier = true;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = false;
		pSystemData.rotation.x = getRnd(-200.0f, 200.0f);
		pSystemData.rotation.y = getRnd(-200.0f, 200.0f);
		pSystemData.rotation.z = getRnd(-200.0f, 200.0f);
		pSystemData.rotationVelocity.x = getRnd(-200.0f, 200.0f);
		pSystemData.rotationVelocity.y = getRnd(-200.0f, 200.0f);
		pSystemData.rotationVelocity.z = getRnd(-200.0f, 200.0f);
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = true;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 57.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = getRnd(0.2f, 0.4f);
		pSystemData.scale.y = 0.2f;
		pSystemData.scale.z = 0.2f;
		pSystemData.scaleVelocity.x = 0.0f;
		pSystemData.scaleVelocity.y = 0.0f;
		pSystemData.scaleVelocity.z = 0.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = false;
		pSystemData.scaleMultiplier.x = 59.f;
		pSystemData.scaleMultiplier.y = 60.0f;
		pSystemData.scaleMultiplier.z = 60.0f;

		pSystemData.colorFunction = ParColorID::flameC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = false;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.useNoise = true;
		pSystemData.noiseOctaves = 2;
		pSystemData.noisePersistence = 2;
		pSystemData.noiseScale = 0.025;
		pSystemData.noiseSinus = true;
		pSystemData.noiseVelocity.x = 2.1f;
		pSystemData.noiseVelocity.y = 2.1f;
		pSystemData.noiseVelocity.z = 2.1f;
		pSystemData.noiseSpeed = 0.5;

		pSystemData.life = getRnd(0, 1); //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1;
		pSystemData.emissionAmount = 4;

		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = false;

		pSystemData.displayID = displayParticlePlaneFlameSparks;

		break;


	case ParID::smoke:

		pSystemData.pSystemTypeID = ParID::smoke;

		pSystemData.useGravity = false;
		pSystemData.position.x = getRnd(-0.5, 0.5) + x;
		pSystemData.position.y = 0.0f + y;
		pSystemData.position.z = getRnd(-0.5, 0.5) + z;
		//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
		pSystemData.velocity.x = getRnd(0, 2) + 1.0f;
		pSystemData.velocity.y = getRnd(-2, 2) + 8.0f;
		pSystemData.velocity.z = getRnd(-1, 1); //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = 0.0f;
		pSystemData.acceleration.y = 0.0f; //-1.81f;
		pSystemData.acceleration.z = 0.0f;
		pSystemData.useVelocityMultiplier = true;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.5f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = true;
		pSystemData.rotation.x = 0.0f;
		pSystemData.rotation.y = 0.0f;
		pSystemData.rotation.z = 0.0f;
		pSystemData.rotationVelocity.x = 0.0f;
		pSystemData.rotationVelocity.y = 0.0f;
		pSystemData.rotationVelocity.z = 400.0f;
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = true;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 57.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = 1.0f;
		pSystemData.scale.y = 1.0f;
		pSystemData.scale.z = 1.0f;
		pSystemData.scaleVelocity.x = 1.0f;
		pSystemData.scaleVelocity.y = 0.0f;
		pSystemData.scaleVelocity.z = 0.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = false;
		pSystemData.scaleMultiplier.x = 59.f;
		pSystemData.scaleMultiplier.y = 60.0f;
		pSystemData.scaleMultiplier.z = 60.0f;

		pSystemData.colorFunction = ParColorID::smokeC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = false;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.useNoise = false;

		pSystemData.life = 5.0f; //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1;
		pSystemData.emissionAmount = 1;


		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = false;

		pSystemData.displayID = displayParticlePlane;

		break;
	case ParID::snow:

		pSystemData.pSystemTypeID = ParID::snow;

		pSystemData.useGravity = false;
		pSystemData.position.x = getRnd(-10.0, 10.0) + x;
		pSystemData.position.y = 12.0f + y;
		pSystemData.position.z = getRnd(-10.0, 10.0) + z;

		//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
		pSystemData.velocity.x = 0.01f;
		pSystemData.velocity.y = -2;
		pSystemData.velocity.z = 0; //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = 0.0f;
		pSystemData.acceleration.y = 0.0f; //-1.81f;
		pSystemData.acceleration.z = 0.0f;
		pSystemData.useVelocityMultiplier = false;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = false;
		pSystemData.rotation.x = getRnd(0, 5000);
		pSystemData.rotation.y = getRnd(0, 5000);
		pSystemData.rotation.z = getRnd(0, 5000);
		pSystemData.rotationVelocity.x = getRnd(-200, 200);
		pSystemData.rotationVelocity.y = getRnd(-200, 200);
		pSystemData.rotationVelocity.z = getRnd(-200, 200);
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = false;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 61.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = 0.1f;
		pSystemData.scale.y = 0.2f;
		pSystemData.scale.z = 0.2f;
		pSystemData.scaleVelocity.x = 0.0f;
		pSystemData.scaleVelocity.y = 0.0f;
		pSystemData.scaleVelocity.z = 0.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = false;
		pSystemData.scaleMultiplier.x = 59.f;
		pSystemData.scaleMultiplier.y = 60.0f;
		pSystemData.scaleMultiplier.z = 60.0f;

		pSystemData.colorFunction = ParColorID::snowC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = true;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;


		pSystemData.useNoise = true;
		pSystemData.noiseOctaves = 2;
		pSystemData.noisePersistence = 2;
		pSystemData.noiseScale = 0.05;
		pSystemData.noiseSinus = true;
		pSystemData.noiseVelocity.x = 2.1f;
		pSystemData.noiseVelocity.y = 0.0f;
		pSystemData.noiseVelocity.z = 2.1f;
		pSystemData.noiseSpeed = 0.5;
		//pSystemData.noiseSeed = getRnd(-100000, 100000);

		pSystemData.life = 14.0f; //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1; // bigger number less particles
		pSystemData.emissionAmount = 1;

		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = false;
		pSystemData.subParticleExitID = 0;

		pSystemData.displayID = displayParticlePlaneSnow;

		break;

	case ParID::rain:

		pSystemData.pSystemTypeID = ParID::rain;

		pSystemData.useGravity = false;
		pSystemData.position.x = getRnd(-15.0, 15.0) + x;
		pSystemData.position.y = 24.0f + y;
		pSystemData.position.z = getRnd(-15.0, 15.0) + z;

		//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
		pSystemData.velocity.x = getRnd(0.1f,5.0f);
		pSystemData.velocity.y = -40;
		pSystemData.velocity.z = getRnd(0.1f, 5.0f); //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = 0.0f;
		pSystemData.acceleration.y = 0.0f; //-1.81f;
		pSystemData.acceleration.z = 0.0f;
		pSystemData.useVelocityMultiplier = false;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = true;
		pSystemData.pointAtCam = false;
		pSystemData.rotation.x = 0.0f;
		pSystemData.rotation.y = 0.0f;
		pSystemData.rotation.z = 0.0f;
		pSystemData.rotationVelocity.x = 0.0f;
		pSystemData.rotationVelocity.y = 0.0f;
		pSystemData.rotationVelocity.z = 0.0f;
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = false;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 60.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = 0.5f;
		pSystemData.scale.y = 4.0f;
		pSystemData.scale.z = 0.5f;
		pSystemData.scaleVelocity.x = 0.0f;
		pSystemData.scaleVelocity.y = 0.0f;
		pSystemData.scaleVelocity.z = 0.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = false;
		pSystemData.scaleMultiplier.x = 59.f;
		pSystemData.scaleMultiplier.y = 60.0f;
		pSystemData.scaleMultiplier.z = 60.0f;

		pSystemData.colorFunction = ParColorID::rainC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = true;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;


		pSystemData.useNoise = false;
		pSystemData.noiseOctaves = 2;
		pSystemData.noisePersistence = 2;
		pSystemData.noiseScale = 0.05;
		pSystemData.noiseSinus = true;
		pSystemData.noiseVelocity.x = 2.1f;
		pSystemData.noiseVelocity.y = 0.0f;
		pSystemData.noiseVelocity.z = 2.1f;
		pSystemData.noiseSpeed = 0.5;
		//pSystemData.noiseSeed = getRnd(-100000, 100000);

		pSystemData.life = 14.0f; //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1; // bigger number less particles
		pSystemData.emissionAmount = 10;

		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::rainSplash;

		pSystemData.useSubParticleExit = true;
		pSystemData.subParticleExitID = ParID::rainSplash;

		pSystemData.displayID = displayParticleRain;

		break;


	case ParID::rainSplash:

		pSystemData.pSystemTypeID = ParID::rainSplash;

		pSystemData.useGravity = false;
		pSystemData.position.x = 0.0f + x;
		pSystemData.position.y = 0.1f + y;
		pSystemData.position.z = 0.0f + z;
		//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
		pSystemData.velocity.x = 0.0f;
		pSystemData.velocity.y = 0.0f;
		pSystemData.velocity.z = 0.0f; //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = 0.0f;
		pSystemData.acceleration.y = 0.0f;
		pSystemData.acceleration.z = 0.0f;
		pSystemData.useVelocityMultiplier = false;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = false;
		pSystemData.rotation.x = 0.0f;
		pSystemData.rotation.y = 0.0f;
		pSystemData.rotation.z = 0.0f;
		pSystemData.rotationVelocity.x = 0.0f;
		pSystemData.rotationVelocity.y = 0.0f;
		pSystemData.rotationVelocity.z = 0.0f;
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = false;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 57.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = 0.1f;
		pSystemData.scale.y = 0.1f;
		pSystemData.scale.z = 0.1f;
		pSystemData.scaleVelocity.x = 8.0f;
		pSystemData.scaleVelocity.y = 0.0f;
		pSystemData.scaleVelocity.z = 0.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = false;
		pSystemData.scaleMultiplier.x = 59.f;
		pSystemData.scaleMultiplier.y = 60.0f;
		pSystemData.scaleMultiplier.z = 60.0f;

		pSystemData.colorFunction = ParColorID::whiteFadeC;

		pSystemData.useFloorCollider = false;
		pSystemData.destroyOnContact = false;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.useNoise = false;

		pSystemData.life = 0.1f; //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1;
		pSystemData.emissionAmount = 1;

		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = false;

		pSystemData.displayID = displayParticlePlaneRing;

		break;


	case ParID::bubbles:

		pSystemData.pSystemTypeID = ParID::bubbles;

		pSystemData.useGravity = false;
		pSystemData.position.x = x;
		pSystemData.position.y = 0.75f + y;
		pSystemData.position.z = z;
		//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
		pSystemData.velocity.x = getRnd(-2.5, 2.5);
		pSystemData.velocity.y = getRnd(6, 4);
		pSystemData.velocity.z = getRnd(-2.5, 2.5); //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = 0.0f;
		pSystemData.acceleration.y = -1.0f; //-1.81f;
		pSystemData.acceleration.z = 0.0f;
		pSystemData.useVelocityMultiplier = false;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = true;
		pSystemData.rotation.x = 0.0f;
		pSystemData.rotation.y = 0.0f;
		pSystemData.rotation.z = 0.0f;
		pSystemData.rotationVelocity.x = 0.0f;
		pSystemData.rotationVelocity.y = 0.0f;
		pSystemData.rotationVelocity.z = 0.0f;
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = false;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 61.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = getRnd(0.8, 1.5);
		pSystemData.scale.y = 0.8f;
		pSystemData.scale.z = 0.8f;
		pSystemData.scaleVelocity.x = 0.0f;
		pSystemData.scaleVelocity.y = 0.0f;
		pSystemData.scaleVelocity.z = 0.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = false;
		pSystemData.scaleMultiplier.x = 59.f;
		pSystemData.scaleMultiplier.y = 60.0f;
		pSystemData.scaleMultiplier.z = 60.0f;

		pSystemData.colorFunction = ParColorID::rainbowC; // rainbow bubbles

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = false;
		pSystemData.floorHeight = pSystemData.scale.x / 2.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.useNoise = true;
		pSystemData.noiseOctaves = 2;
		pSystemData.noisePersistence = 2;
		pSystemData.noiseScale = 0.05;
		pSystemData.noiseSinus = true;
		pSystemData.noiseVelocity.x = 4.1f;
		pSystemData.noiseVelocity.y = 0.0f;
		pSystemData.noiseVelocity.z = 4.1f;
		pSystemData.noiseSpeed = 0.5;

		pSystemData.life = 8.0f; //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 4; // bigger number less particles
		pSystemData.emissionAmount = 1;

		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = false;
		//pSystemData.subParticleExitID = ParID::???;

		pSystemData.displayID = displayParticlePlaneBubbles;

		break;

	case ParID::waterfall:

		pSystemData.pSystemTypeID = ParID::waterfall;

		pSystemData.useGravity = true;
		pSystemData.position.x = getRnd(-0.5, 0.5) + x;
		pSystemData.position.y = 12.0f + y;
		pSystemData.position.z = getRnd(-0.5, 0.5) + z;

		pSystemData.velocity.x = getRnd(1, 2);
		pSystemData.velocity.y = 0.0f;
		pSystemData.velocity.z = getRnd(-1, 1);
		pSystemData.acceleration.x = 0.0f;
		pSystemData.acceleration.y = 0.0f;
		pSystemData.acceleration.z = 0.0f;
		pSystemData.useVelocityMultiplier = true;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = true;
		pSystemData.rotation.x = 0.0f;
		pSystemData.rotation.y = 0.0f;
		pSystemData.rotation.z = 0.0f;
		pSystemData.rotationVelocity.x = 0.0f;
		pSystemData.rotationVelocity.y = 0.0f;
		pSystemData.rotationVelocity.z = 400.0f;
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = true;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 57.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = 1.0f;
		pSystemData.scale.y = 1.0f;
		pSystemData.scale.z = 1.0f;
		pSystemData.scaleVelocity.x = 1.0f;
		pSystemData.scaleVelocity.y = 0.0f;
		pSystemData.scaleVelocity.z = 0.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = false;
		pSystemData.scaleMultiplier.x = 59.f;
		pSystemData.scaleMultiplier.y = 60.0f;
		pSystemData.scaleMultiplier.z = 60.0f;

		pSystemData.colorFunction = ParColorID::waterfallC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = false;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.useNoise = false;

		pSystemData.life = 5.0f; //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1;
		pSystemData.emissionAmount = 1;

		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = true;
		pSystemData.subParticleExitID = ParID::waterfallSub;

		pSystemData.displayID = displayParticlePlane;

		break;

	case ParID::waterfallSub:

		pSystemData.pSystemTypeID = ParID::waterfallSub;

		pSystemData.useGravity = true;
		pSystemData.position.x = x - 2.5;
		pSystemData.position.y = y;
		pSystemData.position.z = z;

		pSystemData.velocity.x = getRnd(1, 2);
		pSystemData.velocity.y = 0.0f;
		pSystemData.velocity.z = getRnd(-1, 1);
		pSystemData.acceleration.x = 0.0f;
		pSystemData.acceleration.y = 0.0f;
		pSystemData.acceleration.z = 0.0f;
		pSystemData.useVelocityMultiplier = true;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = false;
		pSystemData.rotation.x = 0.0f;
		pSystemData.rotation.y = 0.0f;
		pSystemData.rotation.z = 0.0f;
		pSystemData.rotationVelocity.x = 0.0f;
		pSystemData.rotationVelocity.y = 0.0f;
		pSystemData.rotationVelocity.z = 0.0f;
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = false;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 57.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = 1.0f;
		pSystemData.scale.y = 1.0f;
		pSystemData.scale.z = 1.0f;
		pSystemData.scaleVelocity.x = 15.0f;
		pSystemData.scaleVelocity.y = 0.0f;
		pSystemData.scaleVelocity.z = 0.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = false;
		pSystemData.scaleMultiplier.x = 59.f;
		pSystemData.scaleMultiplier.y = 60.0f;
		pSystemData.scaleMultiplier.z = 60.0f;

		pSystemData.colorFunction = ParColorID::waterfallSubC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = false;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.useNoise = false;

		pSystemData.life = 1.0f; //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1;
		pSystemData.emissionAmount = 1;

		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = false;

		pSystemData.displayID = displayParticlePlaneWaterfallSub;

		break;
	case ParID::frost:
		pSystemData.pSystemTypeID = ParID::frost; // A uniqe value to identify the type of particle

		pSystemData.useGravity = false;
		pSystemData.position.x = x;
		pSystemData.position.y = y;
		pSystemData.position.z = z;

		pSystemData.velocity.x = getRnd(-0.5, 0.5);
		pSystemData.velocity.y = getRnd(5, 4);
		pSystemData.velocity.z = getRnd(-0.5, 0.5); //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = getRnd(-2.5, 2.5);
		pSystemData.acceleration.y = 2.0f; //-1.81f;
		pSystemData.acceleration.z = getRnd(-2.5, 2.5);
		pSystemData.useVelocityMultiplier = false;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = true;
		pSystemData.rotation.x = 0.0f;
		pSystemData.rotation.y = 0.0f;
		pSystemData.rotation.z = getRnd(0, 5);
		pSystemData.rotationVelocity.x = 0.0f;
		pSystemData.rotationVelocity.y = 0.0f;
		pSystemData.rotationVelocity.z = getRnd(-400, 400);
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = true;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 61.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = 2.0f;
		pSystemData.scale.y = 2.0f;
		pSystemData.scale.z = 2.0f;
		pSystemData.scaleVelocity.x = 4.0f;
		pSystemData.scaleVelocity.y = 4.0f;
		pSystemData.scaleVelocity.z = 4.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = true;
		pSystemData.scaleMultiplier.x = 57.0f;
		pSystemData.scaleMultiplier.y = 59.0f;
		pSystemData.scaleMultiplier.z = 57.0f;

		pSystemData.colorFunction = ParColorID::frostC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = true;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.useNoise = false;

		pSystemData.life = getRnd(0.5f, 1.0f); //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1; // bigger number less particles
		pSystemData.emissionAmount = 1; // the amount of particles spawned at a time

		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = true;
		pSystemData.subParticleExitID = ParID::flameSmoke; // flame smoke sub particles
														   //pSystemData.subParticleID = 3;

		pSystemData.displayID = displayParticlePlaneFlames;

		break;
	case ParID::frostWall:
		pSystemData.pSystemTypeID = ParID::frostWall; // A uniqe value to identify the type of particle

		pSystemData.useGravity = false;
		pSystemData.position.x = getRnd(-5, 5) + x;
		pSystemData.position.y = y;
		pSystemData.position.z = z;

		pSystemData.velocity.x = getRnd(-0.5, 0.5);
		pSystemData.velocity.y = getRnd(5, 4);
		pSystemData.velocity.z = getRnd(-0.5, 0.5); //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = getRnd(-2.5, 2.5);
		pSystemData.acceleration.y = 2.0f; //-1.81f;
		pSystemData.acceleration.z = getRnd(-2.5, 2.5);
		pSystemData.useVelocityMultiplier = false;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = true;
		pSystemData.rotation.x = 0.0f;
		pSystemData.rotation.y = 0.0f;
		pSystemData.rotation.z = getRnd(0, 5);
		pSystemData.rotationVelocity.x = 0.0f;
		pSystemData.rotationVelocity.y = 0.0f;
		pSystemData.rotationVelocity.z = getRnd(-400, 400);
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = true;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 61.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = 2.0f;
		pSystemData.scale.y = 2.0f;
		pSystemData.scale.z = 2.0f;
		pSystemData.scaleVelocity.x = 4.0f;
		pSystemData.scaleVelocity.y = 4.0f;
		pSystemData.scaleVelocity.z = 4.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = true;
		pSystemData.scaleMultiplier.x = 57.0f;
		pSystemData.scaleMultiplier.y = 59.0f;
		pSystemData.scaleMultiplier.z = 57.0f; 

		pSystemData.colorFunction = ParColorID::frostC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = true;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.useNoise = false;

		pSystemData.life = getRnd(0.5f, 1.0f); //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1; // bigger number less particles
		pSystemData.emissionAmount = 8; // the amount of particles spawned at a time

		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = false;
		//pSystemData.destroyParticleID = ParID::flameSmoke; // flame smoke sub particles

		pSystemData.displayID = displayParticlePlaneFlames;

		break;
	case ParID::ash:

		pSystemData.pSystemTypeID = ParID::ash;

		pSystemData.useGravity = false;
		pSystemData.position.x = getRnd(-10.0, 10.0) + x;
		pSystemData.position.y = 12.0f + y;
		pSystemData.position.z = getRnd(-10.0, 10.0) + z;

		//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
		pSystemData.velocity.x = 0.01f;
		pSystemData.velocity.y = -2;
		pSystemData.velocity.z = 0; //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = 0.0f;
		pSystemData.acceleration.y = 0.0f; //-1.81f;
		pSystemData.acceleration.z = 0.0f;
		pSystemData.useVelocityMultiplier = false;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = false;
		pSystemData.rotation.x = getRnd(0, 5000);
		pSystemData.rotation.y = getRnd(0, 5000);
		pSystemData.rotation.z = getRnd(0, 5000);
		pSystemData.rotationVelocity.x = getRnd(-200, 200);
		pSystemData.rotationVelocity.y = getRnd(-200, 200);
		pSystemData.rotationVelocity.z = getRnd(-200, 200);
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = false;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 61.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = 0.1f;
		pSystemData.scale.y = 0.2f;
		pSystemData.scale.z = 0.2f;
		pSystemData.scaleVelocity.x = 0.0f;
		pSystemData.scaleVelocity.y = 0.0f;
		pSystemData.scaleVelocity.z = 0.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = false;
		pSystemData.scaleMultiplier.x = 59.f;
		pSystemData.scaleMultiplier.y = 60.0f;
		pSystemData.scaleMultiplier.z = 60.0f;

		pSystemData.colorFunction = ParColorID::smokeC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = true;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;


		pSystemData.useNoise = true;
		pSystemData.noiseOctaves = 2;
		pSystemData.noisePersistence = 2;
		pSystemData.noiseScale = 0.05;
		pSystemData.noiseSinus = true;
		pSystemData.noiseVelocity.x = 2.1f;
		pSystemData.noiseVelocity.y = 0.0f;
		pSystemData.noiseVelocity.z = 2.1f;
		pSystemData.noiseSpeed = 0.5;
		//pSystemData.noiseSeed = getRnd(-100000, 100000);

		pSystemData.life = 14.0f; //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1; // bigger number less particles
		pSystemData.emissionAmount = 1;

		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = false;
		pSystemData.subParticleExitID = 0;

		pSystemData.displayID = displayParticlePlaneAsh;

		break;

	case ParID::leaves:

		pSystemData.pSystemTypeID = ParID::leaves;

		pSystemData.useGravity = false;
		pSystemData.position.x = -12.0f + x;
		pSystemData.position.y = getRnd(-5.0, 10.0) + y;
		pSystemData.position.z = getRnd(-10.0, 10.0) + z;

		//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
		pSystemData.velocity.x = 20.01f;
		pSystemData.velocity.y = 0.0f;
		pSystemData.velocity.z = 0.0f; //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = 0.0f;
		pSystemData.acceleration.y = 0.0f; //-1.81f;
		pSystemData.acceleration.z = 0.0f;
		pSystemData.useVelocityMultiplier = false;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = false;
		pSystemData.rotation.x = getRnd(0, 5000);
		pSystemData.rotation.y = getRnd(0, 5000);
		pSystemData.rotation.z = getRnd(0, 5000);
		pSystemData.rotationVelocity.x = getRnd(-200, 200)*4.0f;
		pSystemData.rotationVelocity.y = getRnd(-200, 200)*4.0f;
		pSystemData.rotationVelocity.z = getRnd(-200, 200)*4.0f;
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = false;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 61.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = getRnd(0.6f,0.8f);
		pSystemData.scale.y = 0.2f;
		pSystemData.scale.z = 0.2f;
		pSystemData.scaleVelocity.x = 0.0f;
		pSystemData.scaleVelocity.y = 0.0f;
		pSystemData.scaleVelocity.z = 0.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = false;
		pSystemData.scaleMultiplier.x = 59.f;
		pSystemData.scaleMultiplier.y = 60.0f;
		pSystemData.scaleMultiplier.z = 60.0f;

		pSystemData.colorFunction = ParColorID::leafC;
		pSystemData.colorSeed = getRnd(1, 1000);

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = true;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;


		pSystemData.useNoise = true;
		pSystemData.noiseOctaves = 2;
		pSystemData.noisePersistence = 2;
		pSystemData.noiseScale = 0.05;
		pSystemData.noiseSinus = true;
		pSystemData.noiseVelocity.x = 3.1f;
		pSystemData.noiseVelocity.y = 3.0f;
		pSystemData.noiseVelocity.z = 3.1f;
		pSystemData.noiseSpeed = 0.5;
		//pSystemData.noiseSeed = getRnd(-100000, 100000);

		pSystemData.life = 14.0f; //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1; // bigger number less particles
		pSystemData.emissionAmount = 1;

		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = false;
		pSystemData.subParticleExitID = 0;

		pSystemData.displayID = displayParticlePlaneLeaves;

		break;

	case ParID::fog:

		pSystemData.pSystemTypeID = ParID::fog;

		pSystemData.useGravity = false;
		pSystemData.position.x = getRnd(-60, 60) + x;
		pSystemData.position.y = y;
		pSystemData.position.z = getRnd(-60, 60) + z;
		//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
		pSystemData.velocity.x = getRnd(0, 2) + 4.0f;
		pSystemData.velocity.y = getRnd(-0.2, 0.2);
		pSystemData.velocity.z = 0.0f; //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = 0.0f;
		pSystemData.acceleration.y = 0.0f; //-1.81f;
		pSystemData.acceleration.z = 0.0f;
		pSystemData.useVelocityMultiplier = false;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.5f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = true;
		pSystemData.rotation.x = 0.0f;
		pSystemData.rotation.y = 0.0f;
		pSystemData.rotation.z = 0.0f;
		pSystemData.rotationVelocity.x = 0.0f;
		pSystemData.rotationVelocity.y = 0.0f;
		pSystemData.rotationVelocity.z = 15.0f;
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = false;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 57.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = 20.0f;
		pSystemData.scale.y = 20.0f;
		pSystemData.scale.z = 20.0f;
		pSystemData.scaleVelocity.x = 0.0f;
		pSystemData.scaleVelocity.y = 0.0f;
		pSystemData.scaleVelocity.z = 0.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = false;
		pSystemData.scaleMultiplier.x = 59.f;
		pSystemData.scaleMultiplier.y = 60.0f;
		pSystemData.scaleMultiplier.z = 60.0f;

		pSystemData.colorFunction = ParColorID::fogC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = false;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.useNoise = false;

		pSystemData.life = 5.0f; //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1;
		pSystemData.emissionAmount = 1;

		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = false;

		pSystemData.displayID = displayParticlePlane;

		break;

	default:
		pSystemData.pSystemTypeID = ParID::smoke;

		pSystemData.useGravity = false;
		pSystemData.position.x = getRnd(-0.5, 0.5) + x;
		pSystemData.position.y = y;
		pSystemData.position.z = getRnd(-0.5, 0.5) + z;
		//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
		pSystemData.velocity.x = getRnd(0, 2) + 3.0f;
		pSystemData.velocity.y = getRnd(-2, 2) + 8.0f;
		pSystemData.velocity.z = getRnd(-1, 1); //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = 0.5f;
		pSystemData.acceleration.y = 0.0f; //-1.81f;
		pSystemData.acceleration.z = 0.0f;
		pSystemData.useVelocityMultiplier = true;
		pSystemData.velocityMultiplier.x = 60.0f;
		pSystemData.velocityMultiplier.y = 59.0f;
		pSystemData.velocityMultiplier.z = 60.0f;

		pSystemData.useRotationByVelocity = false;
		pSystemData.pointAtCam = true;
		pSystemData.rotation.x = 0.0f;
		pSystemData.rotation.y = 0.0f;
		pSystemData.rotation.z = 0.0f;
		pSystemData.rotationVelocity.x = 0.0f;
		pSystemData.rotationVelocity.y = 0.0f;
		pSystemData.rotationVelocity.z = 400.0f;
		pSystemData.rotationAcceleration.x = 0.0f;
		pSystemData.rotationAcceleration.y = 0.0f;
		pSystemData.rotationAcceleration.z = 0.0f;
		pSystemData.useRotationMultiplier = true;
		pSystemData.rotationMultiplier.x = 60.0f;
		pSystemData.rotationMultiplier.y = 60.0f;
		pSystemData.rotationMultiplier.z = 57.0f;

		pSystemData.noScaleStretching = true;
		pSystemData.scale.x = 1.0f;
		pSystemData.scale.y = 1.0f;
		pSystemData.scale.z = 1.0f;
		pSystemData.scaleVelocity.x = 1.0f;
		pSystemData.scaleVelocity.y = 0.0f;
		pSystemData.scaleVelocity.z = 0.0f;
		pSystemData.scaleAcceleration.x = 0.0f;
		pSystemData.scaleAcceleration.y = 0.0f;
		pSystemData.scaleAcceleration.z = 0.0f;
		pSystemData.useScaleMultiplier = false;
		pSystemData.scaleMultiplier.x = 59.f;
		pSystemData.scaleMultiplier.y = 60.0f;
		pSystemData.scaleMultiplier.z = 60.0f;

		pSystemData.colorFunction = ParColorID::smokeC;

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = false;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.useNoise = false;

		pSystemData.life = 5.0f; //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.life;

		pSystemData.emissionRate = 1;
		pSystemData.emissionAmount = 1;


		pSystemData.useSubParticleSpawn = false;
		//pSystemData.subParticleSpawnID = ParID::??

		pSystemData.useSubParticleExit = false;

		pSystemData.displayID = displayParticlePlane;

		break;







	}

	return pSystemData;
}




