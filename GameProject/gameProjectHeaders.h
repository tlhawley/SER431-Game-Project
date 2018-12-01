
// graphics functions.h forward declare
void setUp3DView();
void renderBitmapString(float x, float y, float z, void *font, char *string);
void myReshape(int w, int h);
void myInit();



#include "globalVariables.h"
#include "materials.h"
#include "lighting.h"
#include "GUI/buttonUI.h"
#include "sync.h"
#include "input.h"
#include "camera.h"
#include "controls.h"
#include "graphicsFunctions.h"



#include "meshObjConverter.h"
#include "modelLoading.h"

#include "noise.h"
#include "noiseGenerator.h"




#include "ParticleSystem/particles.h"
#include "ParticleSystem/particleColorData.h"
#include "ParticleSystem/particleData.h"



#include "GUI/map2D.h"
#include "GUI/healthBar2D.h"

#include "objPlacement.h"

#include "draw/drawProject1Images.h"
#include "draw/drawSpinSpikes.h"
#include "draw/drawHealthPack.h"
#include "draw/drawDoor.h"
#include "draw/drawKey.h"
#include "draw/drawGem.h"
#include "draw/drawPortal.h"
#include "draw/drawSkyBox.h"
#include "draw/drawMirror1.h"
#include "draw/drawBaseModel.h"
#include "flagCreator.h"
#include "fractalsCreator.h"

#include "gameObjects/gameObjHealthPack.h"
#include "gameObjects/gameObjSpinSpike.h"
#include "gameObjects/gameObjCollisionBox.h"
#include "gameObjects/gameObjMovingPlatform.h"
#include "gameObjects/gameObjDoorway.h"
#include "gameObjects/gameObjKey.h"
#include "gameObjects/gameObjGem.h"
#include "gameObjects/gameObjPortal.h"
#include "gameObjects/gameObjBoundingBox.h"
#include "gameObjects/gameObjBaseModel.h"
#include "gameObjects/gameObjPointLight.h"

#include "displayAll.h"
#include "reflection.h"

#include "mapInitialize.h"

