
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
	pSystem flameParticleSystem;
	
	// Position -------------------------------------------------------- Position
	flameParticleSystem.position.x = 0;
	flameParticleSystem.position.y = 0;
	flameParticleSystem.position.z = 0;

	// Velocity --------------------------------------------------------- Velocity
	flameParticleSystem.velocity.x = 0;
	flameParticleSystem.velocity.y = 0;
	flameParticleSystem.velocity.z = 0;

	// Acceleration ----------------------------------------------------- Acceleration
	flameParticleSystem.acceleration.x = 0;
	flameParticleSystem.acceleration.y = 0;
	flameParticleSystem.acceleration.z = 0;

	flameParticleSystem.velocityMultiplier.x = 0;
	flameParticleSystem.velocityMultiplier.y = 0;
	flameParticleSystem.velocityMultiplier.z = 0;


	flameParticleSystem.pointAtCam = true;

	// Rotation -------------------------------------------------------- Rotation
	flameParticleSystem.rotation.x = 0;
	flameParticleSystem.rotation.y = 0;
	flameParticleSystem.rotation.z = 0;

	// rotationVelocity --------------------------------------------------------- rotationVelocity
	flameParticleSystem.rotationVelocity.x = 0;
	flameParticleSystem.rotationVelocity.y = 0;
	flameParticleSystem.rotationVelocity.z = 0;

	// rotationAcceleration ----------------------------------------------------- rotationAcceleration
	flameParticleSystem.rotationAcceleration.x = 0;
	flameParticleSystem.rotationAcceleration.y = 0;
	flameParticleSystem.rotationAcceleration.z = 0;


	flameParticleSystem.rotationMultiplier.x = 0;
	flameParticleSystem.rotationMultiplier.y = 0;
	flameParticleSystem.rotationMultiplier.z = 0;


	// Scale -------------------------------------------------------- Scale
	flameParticleSystem.scale.x = 0;
	flameParticleSystem.scale.y = 0;
	flameParticleSystem.scale.z = 0;

	// scaleVelocity --------------------------------------------------------- scaleVelocity
	flameParticleSystem.scaleVelocity.x = 0;
	flameParticleSystem.scaleVelocity.y = 0;
	flameParticleSystem.scaleVelocity.z = 0;

	// scaleAcceleration ----------------------------------------------------- scaleAcceleration
	flameParticleSystem.scaleAcceleration.x = 0;
	flameParticleSystem.scaleAcceleration.y = 0;
	flameParticleSystem.scaleAcceleration.z = 0;








	// Colors over time	 ----------------------------------------------------- Colors over time -TODO: Use a linked list system instead to allow multiple colors set at specific times & Separate the Alpha transition
	flameParticleSystem.colors[0].a = 1;
	flameParticleSystem.colors[0].r = 1;
	flameParticleSystem.colors[0].g = 0;
	flameParticleSystem.colors[0].b = 0;

	flameParticleSystem.colors[1].a = 0;
	flameParticleSystem.colors[1].r = 1;
	flameParticleSystem.colors[1].g = 0.8f;
	flameParticleSystem.colors[1].b = 0;








	// Floor Collision
	flameParticleSystem.useFloorCollider = false;
	flameParticleSystem.destroyOnContact; // will destroy the particle when the particle hits the floor
	flameParticleSystem.floorHeight; // determines what y position particles should bounce
	flameParticleSystem.bounceMultiplier; // determines the change of y velocity when in contact with the floor
	flameParticleSystem.floorFriction; // determines the change of x&z velocity when in contact with the floor


	//Perlin Noise - double perlinCustom(float x, float y, double scale, double persistence, double octaves, bool sinus) {...
	flameParticleSystem.useNoise; // if false then ignore noise calculations
	flameParticleSystem.noiseOffset; // the larger the number the farther appart the particles will be placed on the noise plane for calculations
	flameParticleSystem.noiseSpeed; // the larger the number the faster the particles will move on the noise plane
	flameParticleSystem.noiseScale;
	flameParticleSystem.noisePersistece;
	flameParticleSystem.noiseOctaves;
	flameParticleSystem.noiseSinus;
	flameParticleSystem.noiseVelocity.x;
	flameParticleSystem.noiseVelocity.y;
	flameParticleSystem.noiseVelocity.z;


					   //Sub particles will spawn when a particle dies
	flameParticleSystem.subParticleID; // 0 (no sub particles), 1-? particles

	flameParticleSystem.lifeMin = 10; // these determine the lifetime of individual particles
	flameParticleSystem.lifeMax = 10;

	flameParticleSystem.delayTime;	// This is the amount of delay before the particles begin to spawn
	flameParticleSystem.loopParticles = true;
	flameParticleSystem.stopTime;		// If loopParticles = false then this will determine when the particles will stop spawning
	flameParticleSystem.emissionRate = 0;   // The speed the particles are spawned at 0=MaxSpeed		1=DelayOneSecond before spawning more	0.5= delay half a second before spawning more
	flameParticleSystem.emmisionAmount = 1; // The amount of particles spawned at any given time

	flameParticleSystem.displayID = displayParticlePlane; // model to be displayed

	flameParticleSystem.useTrailSubParticles; // trail particles are spawned in the location of the current particle - WARNING: Don't spawn identical particles it will result in an infinite loop and destroy everything
	flameParticleSystem.trailParticleID; // DataType???? int???

	flameParticleSystem.useDestroySubParticles = false; // spawns these particles when a particle is destoyed by timer or other factor
	flameParticleSystem.destroyParticleID; // DataType???? int???








	return flameParticleSystem;
}


