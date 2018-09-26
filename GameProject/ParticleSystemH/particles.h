#pragma once

// a structure to hold a particle
class Particle { //TODO: Should take a struct perameter to allow a variety of particle system types
public:			//TODO: Color, Scale, Rotation, Acceleration, Noise, etc...
	float position[3];
	float direction[3];
	float life;
	Particle* next;
	Particle() {
		position[0] = 0.5f;
		position[2] = 0.5f;
		position[1] = 0.0f;
		direction[0] = (10000 - rand() % 20000) / 10000.0f;
		direction[1] = (10000 - rand() % 20000) / 10000.0f+8.0f;
		direction[2] = (10000 - rand() % 20000) / 10000.0f;
		life = rand() % 10000 / 10000.0f+10.0f;
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
			p->life -= dt;
			// apply gravity
			p->direction[1] -= 9.81f * dt;
			// modify position
			p->position[0] += dt * p->direction[0];
			p->position[1] += dt * p->direction[1];
			if (p->position[1] <= 0.0f) {
				p->position[1] = 0.0f;
				p->direction[1] = abs(p->direction[1]) * 0.9f;
				p->direction[0] = p->direction[0] * 0.9f;
				p->direction[2] = p->direction[2] * 0.9f;
				//p->position[1] -= dt * p->direction[1];
			}
			p->position[2] += dt * p->direction[2];
			// goto next particle
			p = p->next;
		}
	}
	// remove
	void remove() {
		Particle* curr = particle_head;
		Particle* prev = 0;
		while (curr) {
			if (curr->life<0) {
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
		float green = curr->life / 10.0f;
		float blue = curr->life / 10.0f;
		float alpha = curr->life/10.0f;
		float materialCustom[] = { 0,0,0,0,red,green,blue,alpha,0,0,0,0,red,green,blue,alpha,1 };
		setMaterialAdvanced(materialCustom);

		glPushMatrix();
		glScalef(100.0, 100.0, 100.0); // TODO: Scale
									   // TODO: Color
									   // TODO: Rotation
		glTranslatef(curr->position[0], curr->position[1], curr->position[2]);
		glScalef(0.4, 0.4, 0.4);
		//glRotatef(90, 1, 0, 0);
		// Makes particles rotate to face the same angle as the camera
		glRotatef(-y_angle, 0.0f, 1.0f, 0.0f);
		//glRotatef(curr->life*400.0f + x_angle - 90.0f, 0.0f, 0.0f, 1.0f);
		glRotatef(-x_angle, 1.0f, 0.0f, 0.0f);
		glRotatef(curr->life*400.0f, 0.0f, 0.0f, 1.0f);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);

		//glRotatef(curr->life*400.0f, 0.0f, 0.0f, 1.0f);
		//glRotatef(curr->position[2], 0.0f, 0.0f, 1.0f);

		//glCallList(display3);
		glCallList(displayParticlePlane);
		glPopMatrix();
		curr = curr->next;
	}
	glDepthMask(GL_TRUE);

}

