
// This file is used for defining different particle systems
// Flame Particles
// Flame Smoke Sub Particles

// Smoke Particles

// Snow Particles

// Rain Particles
// Rain Splash Sub Particles

// Waterfall Particles

// Bubble Particles



pSystem flameParticles() {
	pSystem pSystemData;

	pSystemData.useGravity = false;
	pSystemData.position.x = 0.5;
	pSystemData.position.z = 0.5f;
	pSystemData.position.y = getRnd(0, 5);
	//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
	pSystemData.velocity.x = getRnd(-0.5, 0.5);
	pSystemData.velocity.y = getRnd(-10, -8);
	pSystemData.velocity.z = getRnd(-0.5, 0.5); //(10000 - rand() % 20000) / 10000.0f;
	pSystemData.acceleration.x = getRnd(-2.5, 2.5);
	pSystemData.acceleration.y = 0.0f; //-1.81f;
	pSystemData.acceleration.z = getRnd(-2.5, 2.5);
	pSystemData.useVelocityMultiplier = true;
	pSystemData.velocityMultiplier.x = 60.0f;
	pSystemData.velocityMultiplier.y = 59.0f;
	pSystemData.velocityMultiplier.z = 60.0f;

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
	pSystemData.scale.x = 0.8f;
	pSystemData.scale.y = 0.8f;
	pSystemData.scale.z = 0.8f;
	pSystemData.scaleVelocity.x = 2.0f;
	pSystemData.scaleVelocity.y = 0.0f;
	pSystemData.scaleVelocity.z = 0.0f;
	pSystemData.scaleAcceleration.x = 0.0f;
	pSystemData.scaleAcceleration.y = 0.0f;
	pSystemData.scaleAcceleration.z = 0.0f;
	pSystemData.useScaleMultiplier = true;
	pSystemData.scaleMultiplier.x = 59.f;
	pSystemData.scaleMultiplier.y = 60.0f;
	pSystemData.scaleMultiplier.z = 60.0f;

	pSystemData.colorFunction = flameColors;

	pSystemData.useFloorCollider = true;
	pSystemData.destroyOnContact = false;
	pSystemData.floorHeight = 0.0f;
	pSystemData.bounceMultiplier = 0.9f;
	pSystemData.floorFriction = 0.9f;

	pSystemData.lifeMin = 1.0f; //rand() % 10000 / 10000.0f+10.0f;
	pSystemData.lifeLength = pSystemData.lifeMin;

	pSystemData.emissionRate = 1; // bigger number less particles
	pSystemData.emissionAmount = 2;

	pSystemData.useDestroySubParticles = true;
	pSystemData.destroyParticleID = 3; // flame smoke sub particles
	//pSystemData.subParticleID = 3;

	pSystemData.displayID = displayParticlePlaneFlames;

	return pSystemData;
}








pSystem flameSmokeSubParticles() {
	pSystem pSystemData;

	pSystemData.useGravity = false;
	pSystemData.position.x = getRnd(-0.5, 0.5) + 0.5;
	pSystemData.position.z = getRnd(-0.5, 0.5) + 0.5f;
	pSystemData.position.y = 0.0f;
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

	pSystemData.colorFunction = smokeDarkColors;

	pSystemData.useFloorCollider = true;
	pSystemData.destroyOnContact = false;
	pSystemData.floorHeight = 0.0f;
	pSystemData.bounceMultiplier = 0.9f;
	pSystemData.floorFriction = 0.9f;

	pSystemData.lifeMin = rand() % 10000 / 10000.0f + 1.0f; //rand() % 10000 / 10000.0f+10.0f;
	pSystemData.lifeLength = pSystemData.lifeMin;

	pSystemData.emissionRate = 1;
	pSystemData.emissionAmount = 1;

	pSystemData.displayID = displayParticlePlane;

	return pSystemData;
}













pSystem smokeParticles() {
	pSystem pSystemData;

	pSystemData.useGravity = false;
	pSystemData.position.x = getRnd(-0.5, 0.5) + 0.5;
	pSystemData.position.z = getRnd(-0.5, 0.5) + 0.5f;
	pSystemData.position.y = 0.0f;
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

	pSystemData.colorFunction = smokeColors;

	pSystemData.useFloorCollider = true;
	pSystemData.destroyOnContact = false;
	pSystemData.floorHeight = 0.0f;
	pSystemData.bounceMultiplier = 0.9f;
	pSystemData.floorFriction = 0.9f;

	pSystemData.lifeMin = 5.0f; //rand() % 10000 / 10000.0f+10.0f;
	pSystemData.lifeLength = pSystemData.lifeMin;

	pSystemData.emissionRate = 1;
	pSystemData.emissionAmount = 1;

	pSystemData.displayID = displayParticlePlane;

	return pSystemData;
}



























pSystem snowParticles() {
	pSystem pSystemData;

	pSystemData.useGravity = false;
	pSystemData.position.x = getRnd(-10.0, 10.0);
	pSystemData.position.z = getRnd(-10.0, 10.0);
	pSystemData.position.y = 12.0f;
	//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
	pSystemData.velocity.x = 0.01f;
	pSystemData.velocity.y = -1;
	pSystemData.velocity.z = 0; //(10000 - rand() % 20000) / 10000.0f;
	pSystemData.acceleration.x = 0.0f;
	pSystemData.acceleration.y = 0.0f; //-1.81f;
	pSystemData.acceleration.z = 0.0f;
	pSystemData.useVelocityMultiplier = false;
	pSystemData.velocityMultiplier.x = 60.0f;
	pSystemData.velocityMultiplier.y = 59.0f;
	pSystemData.velocityMultiplier.z = 60.0f;

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
	pSystemData.scale.x = getRnd(0.05,0.1);
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

	pSystemData.colorFunction = snowColors;

	pSystemData.useFloorCollider = true;
	pSystemData.destroyOnContact = true;
	pSystemData.floorHeight = 0.0f;
	pSystemData.bounceMultiplier = 0.9f;
	pSystemData.floorFriction = 0.9f;

	pSystemData.lifeMin = 14.0f; //rand() % 10000 / 10000.0f+10.0f;
	pSystemData.lifeLength = pSystemData.lifeMin;

	pSystemData.emissionRate = 1; // bigger number less particles
	pSystemData.emissionAmount = 10;

	pSystemData.useDestroySubParticles = false;
	pSystemData.destroyParticleID = 0;

	pSystemData.displayID = displayParticlePlaneSnow;

	return pSystemData;
}






pSystem bubbleParticles() {
	pSystem pSystemData;

	pSystemData.useGravity = true;
	pSystemData.position.x = 0.5;
	pSystemData.position.z = 0.5f;
	pSystemData.position.y = 0.0f;
	//pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f + 3.0f;
	pSystemData.velocity.x = getRnd(-2.5, 2.5);
	pSystemData.velocity.y = getRnd(-10, -8);
	pSystemData.velocity.z = getRnd(-2.5, 2.5); //(10000 - rand() % 20000) / 10000.0f;
	pSystemData.acceleration.x = 0.0f;
	pSystemData.acceleration.y = 0.0f; //-1.81f;
	pSystemData.acceleration.z = 0.0f;
	pSystemData.useVelocityMultiplier = false;
	pSystemData.velocityMultiplier.x = 60.0f;
	pSystemData.velocityMultiplier.y = 59.0f;
	pSystemData.velocityMultiplier.z = 60.0f;

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

	pSystemData.colorFunction = snowColors; // uses white for bubbles

	pSystemData.useFloorCollider = true;
	pSystemData.destroyOnContact = false;
	pSystemData.floorHeight = 0.0f;
	pSystemData.bounceMultiplier = 0.9f;
	pSystemData.floorFriction = 0.9f;

	pSystemData.lifeMin = 8.0f; //rand() % 10000 / 10000.0f+10.0f;
	pSystemData.lifeLength = pSystemData.lifeMin;

	pSystemData.emissionRate = 4; // bigger number less particles
	pSystemData.emissionAmount = 1;

	pSystemData.useDestroySubParticles = false;
	pSystemData.destroyParticleID = 3; // flame smoke sub particles
									   //pSystemData.subParticleID = 3;

	pSystemData.displayID = displayParticlePlaneBubbles;

	return pSystemData;
}