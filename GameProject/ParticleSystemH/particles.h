#pragma once

//Notes:
// Added lots of new features...


// Enum used to identify different particle systems
enum ParID { flame, flameWall, flameSparks, flameWallSparks, flameSmoke, smoke, snow, bubbles, waterfall, waterfallSub, frost, frostWall, ash, leaves, fog};
enum ParColorID { flameC, smokeC, smokeDarkC, snowC, waterfallC, waterfallSubC, frostC, leafC, rainbowC, fogC};


// Used for variables involving xyz axis such as - position, velocity, acceleration, scale, rotation...
struct xyz {
	float x;
	float y;
	float z;
};



struct pSystem {

	// A unique id to identify the type of particle system
	int pSystemTypeID;

	// Positioning & Movement
	xyz position;
	xyz velocity;
	xyz acceleration;
	bool useVelocityMultiplier;
	xyz velocityMultiplier; // multiplies the velocity
	bool useGravity;

	// Rotation
	bool pointAtCam; // true (rotates facing the camera), false (free rotation)
	xyz rotation; // the starting rotation - if (pointAtCam) then ignore x&y rotations
	xyz rotationVelocity; // the rotation speed
	xyz rotationAcceleration; // the rotation acceleration
	bool useRotationMultiplier;
	xyz rotationMultiplier; // multiplies the rotationVelocity

							// Scale
	bool noScaleStretching; // This is recomended and will make the xyz scale values to be equivalent. Only using x scale data
	xyz scale; // particle starting size
	xyz scaleVelocity; // the growth rate of the particles
	xyz scaleAcceleration; // the acceleration of growth rate of the particles
	bool useScaleMultiplier;
	xyz scaleMultiplier;

	//rgba colors[2]; // Currently only supports a beginning and ending color transitions - TODO: Add dynamic time based color settings
	int colorFunction;
	int colorSeed;

	// Floor Collision
	bool useFloorCollider; // ignores floor collision if false
	bool destroyOnContact; // will destroy the particle when the particle hits the floor
	float floorHeight; // determines what y position particles should bounce
	float bounceMultiplier; // determines the change of y velocity when in contact with the floor
	float floorFriction; // determines the change of x&z velocity when in contact with the floor


						 //Perlin Noise - double perlinCustom(float x, float y, double scale, double persistence, double octaves, bool sinus) {...
	bool useNoise; // if false then ignore noise calculations
	float noiseOffset; // the larger the number the farther appart the particles will be placed on the noise plane for calculations
	float noiseSpeed; // the larger the number the faster the particles will move on the noise plane
	double noiseScale;
	double noisePersistence;
	double noiseOctaves;
	bool noiseSinus;
	xyz noiseVelocity; // this is used for calculating velocity changes in the particles
	float noiseSeed;

	float lifeMin; // these determine the lifetime of individual particles
	float lifeMax;
	float lifeLength; // a constant for calculating color changes over time

	float delayTime;	// This is the amount of delay before the particles begin to spawn
	float stopTime;		// If loopParticles = false then this will determine when the particles will stop spawning
	int emissionRate;   // The speed the particles are spawned at 0=MaxSpeed		1=DelayOneSecond before spawning more	0.5= delay half a second before spawning more
	float emissionAmount; // The amount of particles spawned at any given time
	bool loopParticles; // TODO: This may need to be in a separate data type????

	GLuint displayID; // model to be displayed

	
	bool useSubParticleSpawn; // spawnSubParticles will spawn at the same time the main particle spawns
	int subParticleSpawnID; // subParticleSpawnID is the particle ID that spawns when the

	bool useTrailSubParticles; // trail particles are spawned in the location of the current particle over time
	int trailParticleID; // DataType???? int??? spawnRate????

	bool useSubParticleExit; //subParticleExit spawns these particles on exit or when a particle is destoyed by timer or other factor
	int subParticleExitID; // subParticleExitID is the particle ID that spawns when the 

};






// Forward declarations for particleData.h & particleColorData.h
pSystem particleData(int p, float x, float y, float z);







// a structure to hold a particle
class Particle {
public:
	
	pSystem pSystemData; // contains a vast amount of information for a particle system - coordinates, velocity, acceleration, scale, color, noise, etc...

	Particle* next;
	Particle() { // default particle
		pSystemData = particleData(1, 0, 0, 0);
	}
	Particle(pSystem pSystemData) {
		this->pSystemData = pSystemData;
		pSystemData.lifeLength = pSystemData.lifeMin;
	}
};

class ParticleSystem {
public:
	Particle * particle_head;

	// add
	void add() {
		Particle* p = new Particle();
		p->next = particle_head;
		particle_head = p;
	}
	void add(int parID) { // creates x amount of particles
		pSystem pSystemData;
		pSystemData = particleData(parID, 0, 0, 0);
		__int64 end_clock;
		QueryPerformanceCounter((LARGE_INTEGER*)&end_clock);
		if ((int)end_clock % pSystemData.emissionRate == 0) {
			
			if (pSystemData.useSubParticleSpawn) { // recrusively spawns sub particle(s) on creation
				add(pSystemData.subParticleSpawnID);
			}

			// Spawns x amount of particles
			for (int i = 0; i < pSystemData.emissionAmount; i++) {
				addAmount(particleData(pSystemData.pSystemTypeID,0,0,0));
			}

		}
	}

	void add(int parID,float x, float y, float z) { // creates x amount of particles with a given offset
		pSystem pSystemData;
		pSystemData = particleData(parID, 0, 0, 0);
		__int64 end_clock;
		QueryPerformanceCounter((LARGE_INTEGER*)&end_clock);
		if ((int)end_clock % pSystemData.emissionRate == 0) {

			if (pSystemData.useSubParticleSpawn) { // recrusively spawns sub particle(s) on creation
				add(pSystemData.subParticleSpawnID, x, y, z);
			}

			// Spawns x amount of particles
			for (int i = 0; i < pSystemData.emissionAmount; i++) {
				addAmount(particleData(pSystemData.pSystemTypeID, x, y, z));
			}

		}
	}

	void addAmount(pSystem pSystemData) { // Creates a single particle - used by the add functions
		Particle* p = new Particle(pSystemData);
		p->next = particle_head;
		particle_head = p;
	}

	// update
	void update(float dt) {
		Particle* p = particle_head;
		while (p) {
			// decrease lifespan
			p->pSystemData.lifeMin -= dt;
			// apply gravity
			//p->pSystemData.velocity.y -= 9.81f * dt;

			// Velocity Multiplier
			if (p->pSystemData.useVelocityMultiplier) {
				p->pSystemData.velocity.x = p->pSystemData.velocity.x*p->pSystemData.velocityMultiplier.x * dt;
				p->pSystemData.velocity.y = p->pSystemData.velocity.y*p->pSystemData.velocityMultiplier.y * dt;
				p->pSystemData.velocity.z = p->pSystemData.velocity.z*p->pSystemData.velocityMultiplier.z * dt;
			}

			
			// Apply Acceleration
			p->pSystemData.velocity.x += p->pSystemData.acceleration.x * dt;
			p->pSystemData.velocity.y += p->pSystemData.acceleration.y * dt;
			p->pSystemData.velocity.z += p->pSystemData.acceleration.z * dt;
			if (p->pSystemData.useGravity == true) {
				p->pSystemData.velocity.y -= 9.81f * dt;
			}



			// Apply Rotation Multiplier
			if (p->pSystemData.useRotationMultiplier) {
				if (p->pSystemData.pointAtCam == false) {
					p->pSystemData.rotationVelocity.x = p->pSystemData.rotationVelocity.x * p->pSystemData.rotationMultiplier.x * dt;
					p->pSystemData.rotationVelocity.y = p->pSystemData.rotationVelocity.y * p->pSystemData.rotationMultiplier.y * dt;
				}
				p->pSystemData.rotationVelocity.z = p->pSystemData.rotationVelocity.z * p->pSystemData.rotationMultiplier.z * dt;
			}

			// Apply Rotation Acceleration
			if (p->pSystemData.pointAtCam == false) {
				p->pSystemData.rotationVelocity.x += p->pSystemData.rotationAcceleration.x * dt;
				p->pSystemData.rotationVelocity.y += p->pSystemData.rotationAcceleration.y  * dt;
			}
			p->pSystemData.rotationVelocity.z += p->pSystemData.rotationAcceleration.z  * dt;

			// Apply Rotation Velocity
			if (p->pSystemData.pointAtCam == false) {
				p->pSystemData.rotation.x += p->pSystemData.rotationVelocity.x * dt;
				p->pSystemData.rotation.y += p->pSystemData.rotationVelocity.y * dt;
			}
			p->pSystemData.rotation.z += p->pSystemData.rotationVelocity.z * dt;







			// Apply Scale Multiplier
			if (p->pSystemData.useScaleMultiplier) {
				p->pSystemData.scale.x = p->pSystemData.scale.x * p->pSystemData.scaleMultiplier.x * dt;
				if (p->pSystemData.noScaleStretching) {
					p->pSystemData.scale.y = p->pSystemData.scale.y * p->pSystemData.scale.y * dt;
					p->pSystemData.scale.z = p->pSystemData.scale.z * p->pSystemData.scale.z * dt;
				}
			}

			// Apply Scale Acceleration
			p->pSystemData.scaleVelocity.x += p->pSystemData.scaleAcceleration.x * dt;
			if (p->pSystemData.noScaleStretching) {
				p->pSystemData.scaleVelocity.y += p->pSystemData.scaleAcceleration.y  * dt;
				p->pSystemData.scaleVelocity.z += p->pSystemData.scaleAcceleration.z  * dt;
			}

			// Apply Scale Velocity
			p->pSystemData.scale.x += p->pSystemData.scaleVelocity.x * dt;
			if (p->pSystemData.noScaleStretching) {
				p->pSystemData.scale.y += p->pSystemData.scaleVelocity.y * dt;
				p->pSystemData.scale.z += p->pSystemData.scaleVelocity.z * dt;
			}



			
			// modify position
			p->pSystemData.position.x += p->pSystemData.velocity.x * dt;
			p->pSystemData.position.y += p->pSystemData.velocity.y * dt;
			p->pSystemData.position.z += p->pSystemData.velocity.z * dt;

			// Floor Collision
			if (p->pSystemData.useFloorCollider) {
				if (p->pSystemData.position.y < p->pSystemData.floorHeight) {
					if (p->pSystemData.destroyOnContact) {
						p->pSystemData.lifeMin = -1;
					}
					else {
						p->pSystemData.position.y = p->pSystemData.floorHeight;
						p->pSystemData.velocity.y = abs(p->pSystemData.velocity.y) * p->pSystemData.bounceMultiplier;
						p->pSystemData.velocity.x = p->pSystemData.velocity.x * p->pSystemData.floorFriction;
						p->pSystemData.velocity.z = p->pSystemData.velocity.z * p->pSystemData.floorFriction;
					}
					//p->position[1] -= dt * p->direction[1];
				}
			}
			
			// goto next particle
			p = p->next;
		}
	}
	// remove
	void remove() {
		Particle* curr = particle_head;
		Particle* prev = 0;
		while (curr) {
			if (curr->pSystemData.lifeMin<0) {
				if (curr->pSystemData.useSubParticleExit) {
					add(curr->pSystemData.subParticleExitID, curr->pSystemData.position.x, curr->pSystemData.position.y, curr->pSystemData.position.z);
					//addParticleAt(particleData(curr->pSystemData.destroyParticleID, 0, 0, 0), curr->pSystemData.position);
				}

				if (prev) {
					prev->next = curr->next;
				}
				else {
					particle_head = curr->next;
				}
				Particle* temp = curr;
				curr = curr->next;
				delete temp;
			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
	}
};


ParticleSystem ps;
void setParticleColor(Particle* curr); // forward declares color gradient function


// draw particles
void drawParticles() {

	glDepthMask(GL_FALSE); // Fixes Transparency glitch
	glEnable(GL_BLEND);
	Particle* curr = ps.particle_head;

	while (curr) {

		// Sets the color based on the particle system parameters
		setParticleColor(curr);

		glPushMatrix();
		glScalef(100.0, 100.0, 100.0); // scale rotation and color complete

		// Positioning
		// Offsets the position with perlin noise
		if (curr->pSystemData.useNoise) {
			ImprovedNoise noise;
			float xnoise = curr->pSystemData.position.x + curr->pSystemData.position.y + curr->pSystemData.lifeMin*curr->pSystemData.noiseSpeed;
			float ynoise = curr->pSystemData.position.x + curr->pSystemData.position.y + curr->pSystemData.lifeMin*curr->pSystemData.noiseSpeed;
			glTranslatef(noise.perlinCustom(xnoise, ynoise, curr->pSystemData.noiseScale,
				curr->pSystemData.noisePersistence, curr->pSystemData.noiseOctaves, curr->pSystemData.noiseSinus) * curr->pSystemData.noiseVelocity.x + curr->pSystemData.position.x
						,
						noise.perlinCustom(xnoise + 12700, ynoise + 12700, curr->pSystemData.noiseScale,
							curr->pSystemData.noisePersistence, curr->pSystemData.noiseOctaves, curr->pSystemData.noiseSinus) * curr->pSystemData.noiseVelocity.y + curr->pSystemData.position.y
						,
						noise.perlinCustom(xnoise + 31600, ynoise + 31600, curr->pSystemData.noiseScale,
							curr->pSystemData.noisePersistence, curr->pSystemData.noiseOctaves, curr->pSystemData.noiseSinus) * curr->pSystemData.noiseVelocity.z + curr->pSystemData.position.z);
		}
		else {
			glTranslatef(curr->pSystemData.position.x, curr->pSystemData.position.y, curr->pSystemData.position.z);
		}
		
		// Scale only using the x scale value for all xyz
		if (curr->pSystemData.noScaleStretching){
			glScalef(curr->pSystemData.scale.x, curr->pSystemData.scale.x, curr->pSystemData.scale.x);
		}
		else { // scale using the given xyz scale values
			glScalef(curr->pSystemData.scale.x, curr->pSystemData.scale.y, curr->pSystemData.scale.z);
		}

		// TODO: Add a velocity based rotation option
		// Makes particles rotate to face the same angle as the camera
		if (curr->pSystemData.pointAtCam) {
			glRotatef(-y_angle, 0.0f, 1.0f, 0.0f);
			glRotatef(-x_angle, 1.0f, 0.0f, 0.0f);
			glRotatef(curr->pSystemData.rotation.z, 0.0f, 0.0f, 1.0f);
			glRotatef(-90, 1.0f, 0.0f, 0.0f);
		}
		else { // rotates the particles using the given angle
			glRotatef(curr->pSystemData.rotation.x, 1.0f, 0.0f, 0.0f);
			glRotatef(curr->pSystemData.rotation.y, 0.0f, 1.0f, 0.0f);
			glRotatef(curr->pSystemData.rotation.z, 0.0f, 0.0f, 1.0f);
		}

		glCallList(curr->pSystemData.displayID);
		glPopMatrix();
		curr = curr->next;
	}
	glDepthMask(GL_TRUE);

}

