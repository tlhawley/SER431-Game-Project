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

// Similar to the xyz struct, this contains a min and max range for each x,y,z value
struct xyzRng {
	float xMin;
	float yMin;
	float zMin;
	float xMax;
	float yMax;
	float zMax;
};

// Used for color data involving red,green,blue, and alpha values
struct rgba {
	float r;
	float g;
	float b;
	float a;
};

// Used to set transitioning color values at given points in time
struct timeColor {
	rgba colorValues;
	float colorTime;
	timeColor *next; // a linked list struct allowing any number of color points
};

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
	
	rgba colors[2]; // Currently only supports a beginning and ending color transitions - TODO: Add dynamic time based color settings

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
	double noisePersistece;
	double noiseOctaves;
	bool noiseSinus;
	xyz noiseVelocity; // this is used for calculating velocity changes in the particles


	//Sub particles will spawn when a particle dies
	int subParticleID; // 0 (no sub particles), 1-? particles

	float lifeMin; // these determine the lifetime of individual particles
	float lifeMax;
	float lifeLength; // a constant for calculating color changes over time

	float delayTime;	// This is the amount of delay before the particles begin to spawn
	float stopTime;		// If loopParticles = false then this will determine when the particles will stop spawning
	float emissionRate;   // The speed the particles are spawned at 0=MaxSpeed		1=DelayOneSecond before spawning more	0.5= delay half a second before spawning more
	float emmisionAmount; // The amount of particles spawned at any given time
	bool loopParticles; // TODO: This may need to be in a separate data type????

	GLuint displayID; // model to be displayed
	
	bool useTrailSubParticles; // trail particles are spawned in the location of the current particle
	int trailParticleID; // DataType???? int???
	
	bool useDestroySubParticles; // spawns these particles when a particle is destoyed by timer or other factor
	int destroyParticleID; // DataType???? int???
	// Sub Model IDs??? - could be added to create animated particle systems
};


// a structure to hold a particle
class Particle { //TODO: Should take a struct perameter to allow a variety of particle system types
public:			//TODO: Color, Scale, Rotation, Acceleration, Noise, etc...
	
	pSystem pSystemData; // contains a vast amount of information for a particle system
	//xyz position;
	//xyz velocity;
	//float life;
	Particle* next;
	Particle() { // No longer using default particle systems

		pSystemData.useGravity = false;
		pSystemData.position.x = getRnd(-2,2)+0.5;
		pSystemData.position.z = getRnd(-2, 2) + 0.5f;
		pSystemData.position.y = 0.0f;
		pSystemData.velocity.x = (10000 - rand() % 20000) / 10000.0f;
		pSystemData.velocity.y = (10000 - rand() % 20000) / 10000.0f+8.0f;
		pSystemData.velocity.z = 0.00001f; //(10000 - rand() % 20000) / 10000.0f;
		pSystemData.acceleration.x = 1.01f;
		pSystemData.acceleration.y = 0.0f; //-1.81f;
		pSystemData.acceleration.z = 1.01f;
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
		pSystemData.scale.x = 1.01f;
		pSystemData.scale.y = 9.81f;
		pSystemData.scale.z = 1.01f;
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

		pSystemData.useFloorCollider = true;
		pSystemData.destroyOnContact = false;
		pSystemData.floorHeight = 0.0f;
		pSystemData.bounceMultiplier = 0.9f;
		pSystemData.floorFriction = 0.9f;

		pSystemData.lifeMin = 5.0f; //rand() % 10000 / 10000.0f+10.0f;
		pSystemData.lifeLength = pSystemData.lifeMin;
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

			// Floor Collision
			if (p->pSystemData.useFloorCollider) {
				if (p->pSystemData.position.y <= p->pSystemData.floorHeight) {
					if (p->pSystemData.destroyOnContact) {
						p->pSystemData.lifeMin = -1;
					}
					else {
						p->pSystemData.position.y = 0.0f;
						p->pSystemData.velocity.y = abs(p->pSystemData.velocity.y) * p->pSystemData.bounceMultiplier;
						p->pSystemData.velocity.x = p->pSystemData.velocity.x * p->pSystemData.floorFriction;
						p->pSystemData.velocity.z = p->pSystemData.velocity.z * p->pSystemData.floorFriction;
					}
					//p->position[1] -= dt * p->direction[1];
				}
			}
			p->pSystemData.position.z += p->pSystemData.velocity.z * dt;
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
		float red = 1;
		float green = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		float blue = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		float alpha = curr->pSystemData.lifeMin / curr->pSystemData.lifeLength;
		float materialCustom[] = { 0,0,0,0,red,green,blue,alpha,0,0,0,0,red,green,blue,alpha,1 };
		setMaterialAdvanced(materialCustom);

		glPushMatrix();
		glScalef(100.0, 100.0, 100.0); // TODO: Scale
									   // TODO: Color
									   // TODO: Rotation
		glTranslatef(curr->pSystemData.position.x, curr->pSystemData.position.y, curr->pSystemData.position.z);
		
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
		glCallList(displayParticlePlane);
		glPopMatrix();
		curr = curr->next;
	}
	glDepthMask(GL_TRUE);

}

