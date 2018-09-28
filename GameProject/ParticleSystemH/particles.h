#pragma once

//Notes:
// Modified position and direction(velocity) to use an xyz struct instead of an array [0],[1],[2]
// The direction varible has been refactored to velocity

// Used for variables involving xyz axis such as - position, velocity, acceleration, scale, rotation...
struct xyz {
	float x;
	float y;
	float z;
};

/*
// Similar to the xyz struct, this contains a min and max range for each x,y,z value
struct xyzRng {
	float xMin;
	float yMin;
	float zMin;
	float xMax;
	float yMax;
	float zMax;
};
*/

/*
// Used for color data involving red,green,blue, and alpha values
struct rgba {
	float r;
	float g;
	float b;
	float a;
};
*/

/*
// Used to set transitioning color values at given points in time
struct timeColor {
	rgba colorValues;
	float colorTime;
	timeColor *next; // a linked list struct allowing any number of color points
};
*/

// An advansed structure containing all date within a particle system
/*
struct pSystem {
	xyz position;
	xyz velocity;
	xyz acceleration;
	xyz rotation;
	xyz rotationVelocity;
	xyz rotationAcceleration;
	xyz scale;
	xyz scaleVelocity;
	xyz scaleAcceleration;
	rgba colors;
	float life;
	GLuint displayID; // model to be displayed
};*/

struct pSystem {

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

	//Sub particles will spawn when a particle dies
	int subParticleID; // 0 (no sub particles), 1-? particles

	float lifeMin; // these determine the lifetime of individual particles
	float lifeMax;
	float lifeLength; // a constant for calculating color changes over time

	float delayTime;	// This is the amount of delay before the particles begin to spawn
	float stopTime;		// If loopParticles = false then this will determine when the particles will stop spawning
	int emissionRate;   // The speed the particles are spawned at 0=MaxSpeed		1=DelayOneSecond before spawning more	0.5= delay half a second before spawning more
	float emissionAmount; // The amount of particles spawned at any given time
	bool loopParticles; // TODO: This may need to be in a separate data type????

	GLuint displayID; // model to be displayed
	
	bool useTrailSubParticles; // trail particles are spawned in the location of the current particle
	int trailParticleID; // DataType???? int???
	
	bool useDestroySubParticles; // spawns these particles when a particle is destoyed by timer or other factor
	int destroyParticleID; // DataType???? int???
	// Sub Model IDs??? - could be added to create animated particle systems
};

// Forward declarations for particleData.h & particleColorData.h
pSystem flameParticles();
const int flameColors = 1;
pSystem smokeParticles();
const int smokeColors = 2;
pSystem flameSmokeSubParticles();
const int smokeDarkColors = 3;
pSystem snowParticles();
const int snowColors = 4;
pSystem bubbleParticles();

// a structure to hold a particle
class Particle { //TODO: Should take a struct perameter to allow a variety of particle system types
public:			//TODO: Color, Scale, Rotation, Acceleration, Noise, etc...
	
	pSystem pSystemData; // contains a vast amount of information for a particle system
	//xyz position;
	//xyz velocity;
	//float life;
	Particle* next;
	Particle() { // No longer using default particle systems
		pSystemData = smokeParticles();
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
	void add(pSystem pSystemData) { // creates x amount of particles
		__int64 end_clock;
		QueryPerformanceCounter((LARGE_INTEGER*)&end_clock);
		if ((int)end_clock % pSystemData.emissionRate == 0) {
			for (int i = 0; i < pSystemData.emissionAmount; i++) {
				addAmount(pSystemData);
			}
		}
	}
	void addAmount(pSystem pSystemData) { // Creates a single particle
		Particle* p = new Particle(pSystemData);
		p->next = particle_head;
		particle_head = p;
	}
	void addParticleAt(pSystem pSystemData, xyz position) { // creates a single particle at a specified starting location
		pSystemData.position.x = position.x;
		pSystemData.position.y = position.y;
		pSystemData.position.z = position.z;
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
				if (curr->pSystemData.useDestroySubParticles) {
					if (curr->pSystemData.destroyParticleID == 3) {
						addParticleAt(flameSmokeSubParticles(), curr->pSystemData.position);
					}
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






void setParticleColor(Particle* curr);



// draw particles
void drawParticles() {
	//setMaterialAdvanced(materialEmissive); //NOTE: Sets an emissive material for the particles

	glDepthMask(GL_FALSE); // Fixes Transparency glitch
	glEnable(GL_BLEND);
	Particle* curr = ps.particle_head;


	// glPointSize(2);
	// glBegin(GL_POINTS);
	// while (curr) {
	//   glVertex3fv(curr->position);
	//	 curr = curr->next;
	// }
	// glEnd();
	while (curr) {

		// Creates random color values - Warning: may cause seizures
		/*
		float red = ((rand() + (int)(curr->life * 200)) % 255) / 255.0f;
		float green = ((rand() + (int)(curr->life * 200)) % 255) / 255.0f;
		float blue = ((rand() + (int)(curr->life * 200)) % 255) / 255.0f;
		float materialCustom[] = { 0,0,0,0,red,green,blue,1.0f,0,0,0,0,red,green,blue,1.0f,1 };
		*/
		/*
		float red = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		float green = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		float blue = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		float alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		*/

		setParticleColor(curr);

		glPushMatrix();
		glScalef(100.0, 100.0, 100.0); // TODO: Scale
									   // TODO: Color
									   // TODO: Rotation


		/*
		if (p->pSystemData.useNoise) {
			ImprovedNoise noise;
			p->pSystemData.position.x += noise.perlinCustom(p->pSystemData.position.x, p->pSystemData.position.z, p->pSystemData.noiseScale,
				p->pSystemData.noisePersistence, p->pSystemData.noiseOctaves, p->pSystemData.noiseSinus) * p->pSystemData.noiseVelocity.x * dt;
			p->pSystemData.position.y += noise.perlinCustom(p->pSystemData.position.x, p->pSystemData.position.z, p->pSystemData.noiseScale,
				p->pSystemData.noisePersistence, p->pSystemData.noiseOctaves, p->pSystemData.noiseSinus) * p->pSystemData.noiseVelocity.y * dt;
			p->pSystemData.position.z += noise.perlinCustom(p->pSystemData.position.x, p->pSystemData.position.z, p->pSystemData.noiseScale,
				p->pSystemData.noisePersistence, p->pSystemData.noiseOctaves, p->pSystemData.noiseSinus) * p->pSystemData.noiseVelocity.z * dt;
		}
		*/
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
		
		if (curr->pSystemData.noScaleStretching){
			glScalef(curr->pSystemData.scale.x, curr->pSystemData.scale.x, curr->pSystemData.scale.x);
		}
		else {
			glScalef(curr->pSystemData.scale.x, curr->pSystemData.scale.y, curr->pSystemData.scale.z);
		}
		//glRotatef(90, 1, 0, 0);
		// Makes particles rotate to face the same angle as the camera
		if (curr->pSystemData.pointAtCam) {
			glRotatef(-y_angle, 0.0f, 1.0f, 0.0f);
			//glRotatef(curr->life*400.0f + x_angle - 90.0f, 0.0f, 0.0f, 1.0f);
			glRotatef(-x_angle, 1.0f, 0.0f, 0.0f);
			//glRotatef(curr->pSystemData.lifeMin*400.0f, 0.0f, 0.0f, 1.0f);
			glRotatef(curr->pSystemData.rotation.z, 0.0f, 0.0f, 1.0f);
			glRotatef(-90, 1.0f, 0.0f, 0.0f);
		}
		else {
			glRotatef(curr->pSystemData.rotation.x, 1.0f, 0.0f, 0.0f);
			glRotatef(curr->pSystemData.rotation.y, 0.0f, 1.0f, 0.0f);
			glRotatef(curr->pSystemData.rotation.z, 0.0f, 0.0f, 1.0f);
		}

		//glScalef(curr->pSystemData.scale.x, curr->pSystemData.scale.y, curr->pSystemData.scale.z);

		//glRotatef(curr->life*400.0f, 0.0f, 0.0f, 1.0f);
		//glRotatef(curr->position[2], 0.0f, 0.0f, 1.0f);

		//glCallList(display3);
		glCallList(curr->pSystemData.displayID);
		glPopMatrix();
		curr = curr->next;
	}
	glDepthMask(GL_TRUE);

}

