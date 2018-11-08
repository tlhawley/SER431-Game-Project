
#define PI 3.14159265358979323846

float lx = 0.0f, ly = 0.0f, lz = -1.0f;
float ratio = 1.0;
float timer = 0;
float spikeAngY = 0.0;
float camAngY = -PI/2.0;
float camAngX = 0.0;
bool sprint = false;
bool displayMenu = true;
int score = 0;
int inventoryKeys = 0;
bool levelComplete = false;
int currentLevel = 0; // -2 = title screen, -1 = intro level,  0 = hub world, 1 = level 1, 2 = level 2....

int SmoothingSetting = 1;

float pxv = 0.0f, pzv = 0.0f;
float camxv = 0.0f, camyv = 0.0f, camzv = 0.0f; // x,y,z velocity
float camx = 0.0f, camy = 1.75f, camz = 0.0f;
float ox, oy, oz; // old x,y,z
float gravity = 0.0;
float playerAngle = 0;

int health = 20;
int takingDamage = 0;
int itemTimer = 0;
int itemTimerID = 0;

int mouseX, mouseY, mouseOX, mouseOY;
int mouseMoveX = 0, mouseMoveY = 0;

int width, height;
int screenWidth = 800;
int screenHeight = 800;
char msg[100] = "Message";

int creativeMode = 0;

clock_t current_ticks, delta_ticks;
clock_t fps = 0;
clock_t clockOffset = clock();
clock_t clockTime;
int clockSeconds;

int furnitureModel = 0;

bool upPressed = false;
bool downPressed = false;
bool rightPressed = false;
bool leftPressed = false;
bool f11Pressed = false;
bool aKey = false;
bool sKey = false;
bool dKey = false;
bool wKey = false;
bool spaceKey = false;
bool canJump = false;
bool lockMouse = false;
bool mouseDown = false;
bool mouseRDown = false;
bool mouseRWait = false;
bool mouseWait = false;
bool windowed = true;

int refectOn = 0;

void globalVariables();

