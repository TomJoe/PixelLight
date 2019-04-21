#define CMND_PLAY 0
#define CMND_RENDER 1
#define CMND_WIPE 2
#define CMND_ROTATE 3
#define CMND_BLOOB 4
#define CMND_TUNNEL 5
#define CMND_ANSCHISS 6 
#define CMND_STARS 7
#define CMND_ANIM 8
#define CMND_END 0xff

struct animStep {
  byte command;
  byte ID;
  int xPos;
  int yPos;
  bool clear;
  int delay;
};

static const animStep StartupAnim[] PROGMEM = {
  animStep{CMND_PLAY, 0, 0, 0, true, 250},
  animStep{CMND_RENDER, 0, 0, 0, false, 2000},
  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep InvaderAnim[] PROGMEM = {
  animStep{CMND_RENDER, 1, 0, 5, true, 500},
  animStep{CMND_RENDER, 1, 1, 6, true, 500},
  animStep{CMND_RENDER, 1, 2, 5, true, 500},
  animStep{CMND_RENDER, 1, 3, 6, true, 500},
  animStep{CMND_RENDER, 1, 4, 5, true, 500},
  animStep{CMND_RENDER, 1, 5, 6, true, 500},
  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep PacManAnim[] PROGMEM = {
  animStep{CMND_RENDER, 6, -12, 0, true , 250},
  animStep{CMND_RENDER, 6, -10, 1, true , 250},
  animStep{CMND_RENDER, 6, -8, 1, true , 250},
  animStep{CMND_RENDER, 6, -6, 0, true , 250},
  animStep{CMND_RENDER, 6, -4, 0, true , 250},
  animStep{CMND_RENDER, 6, -2, -1, true , 250},
  animStep{CMND_RENDER, 6,  0, -1, false, 250},
  animStep{CMND_RENDER, 6,  2, 0, true,     0},
  animStep{CMND_RENDER, 7, -12, 1, false, 250},
  animStep{CMND_RENDER, 6,  4, 0, true,     0},
  animStep{CMND_RENDER, 7, -10, 1, false, 250},
  animStep{CMND_RENDER, 6,  6, 1, true,     0},
  animStep{CMND_RENDER, 7, -8, 2, false, 250},
  animStep{CMND_RENDER, 6,  8, 1, true,     0},
  animStep{CMND_RENDER, 7, -6, 2, false, 250},
  animStep{CMND_RENDER, 6, 10, 0, true,     0},
  animStep{CMND_RENDER, 7, -4, 1, false, 250},
  animStep{CMND_RENDER, 6, 12, 0, true,     0},
  animStep{CMND_RENDER, 7, -2, 1, false, 250},
  animStep{CMND_RENDER, 6, 14, -1, true,     0},
  animStep{CMND_RENDER, 7,  0, 2, false, 250},
  animStep{CMND_RENDER, 7,  2, 2, true , 250},
  animStep{CMND_RENDER, 7,  4, 1, true , 250},
  animStep{CMND_RENDER, 7,  6, 1, true , 250},
  animStep{CMND_RENDER, 7,  8, 0, true , 250},
  animStep{CMND_RENDER, 7, 10, 0, true , 250},
  animStep{CMND_RENDER, 7, 12, 1, true , 250},

  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep wipeLR[] PROGMEM = {
  animStep{CMND_WIPE, 0, 10, 0, true, 10},
  animStep{CMND_WIPE, 1, 10, 0, true, 10},
  animStep{CMND_WIPE, 0, 10, 0, true, 10},

  animStep{CMND_END, 0, 0, 0, false, 10}
};

static const animStep wipeUD[] PROGMEM = {
  animStep{CMND_WIPE, 3, 10, 0, true, 10},
  animStep{CMND_WIPE, 2, 10, 0, true, 10},
  animStep{CMND_WIPE, 3, 10, 0, true, 10},

  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep rotate[] PROGMEM = {
  animStep{CMND_ROTATE, 2, 100, 0, true, 10},
  animStep{CMND_ROTATE, 5, 100, 0, true, 10},
  animStep{CMND_ROTATE, 10, 100, 0, true, 10},

  animStep{CMND_END, 0, 0, 0, false, 0}
};


static const animStep DeathAnim[] PROGMEM = {
  animStep{CMND_RENDER, 2, 0, 13, true, 100},
  animStep{CMND_RENDER, 2, 0, 7, true, 100},
  animStep{CMND_RENDER, 2, 0, 3, true, 100},
  animStep{CMND_RENDER, 2, 0, 1, true, 100},
  animStep{CMND_RENDER, 2, 0, 0, true, 1500},

  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep fruits[] PROGMEM = {
  animStep{CMND_RENDER, 4, 0, 0, true , 1000},
  animStep{CMND_RENDER, 4, 2, 2, true , 1000},
  animStep{CMND_RENDER, 5, 4, 4, true , 1000},
  animStep{CMND_RENDER, 5, 6, 5, true , 1000},
  animStep{CMND_RENDER, 7, 0, 0, true , 1000},
  animStep{CMND_RENDER, 7, 1, 2, true , 1000},

  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep MarioAnim[] PROGMEM = {
  animStep{CMND_RENDER, 3, -12, 0, true , 250},
  animStep{CMND_RENDER, 3, -10, 1, true , 250},
  animStep{CMND_RENDER, 3, -8, 1, true , 250},
  animStep{CMND_RENDER, 3, -6, 0, true , 250},
  animStep{CMND_RENDER, 3, -4, 0, true , 250},
  animStep{CMND_RENDER, 3, -2, -1, true , 250},
  animStep{CMND_RENDER, 3,  0, -1, true,  250},
  animStep{CMND_RENDER, 3,  2, 0, true,  250},
  animStep{CMND_RENDER, 3,  4, 0, true,     0},
  animStep{CMND_RENDER, 4, -12, 1, false, 250},
  animStep{CMND_RENDER, 3,  6, 1, true,     0},
  animStep{CMND_RENDER, 4, -10, 2, false, 250},
  animStep{CMND_RENDER, 3,  8, 1, true,     0},
  animStep{CMND_RENDER, 4, -8, 2, false, 250},
  animStep{CMND_RENDER, 3, 10, 0, true,     0},
  animStep{CMND_RENDER, 4, -6, 1, false, 250},
  animStep{CMND_RENDER, 3, 12, 0, true,     0},
  animStep{CMND_RENDER, 4, -4, 1, false, 250},
  animStep{CMND_RENDER, 3, 14, -1, true,     0},
  animStep{CMND_RENDER, 4, -2, 2, false, 250},
  animStep{CMND_RENDER, 4,  0, 2, true , 250},
  animStep{CMND_RENDER, 4,  2, 1, true , 250},
  animStep{CMND_RENDER, 4,  4, 1, true , 250},
  animStep{CMND_RENDER, 4,  5, 0, true , 250},
  animStep{CMND_RENDER, 4,  8, 0, true , 250},
  animStep{CMND_RENDER, 4, 10, 1, true , 250},
  animStep{CMND_RENDER, 4, 12, 1, true , 250},

  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep Bloob[] PROGMEM = {
  animStep{CMND_BLOOB, 0, 0, 0, false , 25},

  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep Tunnel[] PROGMEM = {
  animStep{CMND_TUNNEL, 0, 0, 0, true , 100},

  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep Anschiss[] PROGMEM = {
  animStep{CMND_ANSCHISS, 0, 0, 0, true , 20},
  
  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep richtigerAnschiss[] PROGMEM = {
  animStep{CMND_ANSCHISS, 1, 0, 0, true , 20},
  
  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep krassserAnschiss[] PROGMEM = {
  animStep{CMND_ANSCHISS, 2, 0, 0, true , 20},
  
  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep StarField[] PROGMEM = {
  animStep{CMND_STARS, 0, 0, 0, true , 10},
  
  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep pokeBall[] PROGMEM = {
  animStep{CMND_RENDER, 11, 0, 0, true , 3000},  

  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep laser[] PROGMEM = {
  animStep{CMND_RENDER, 12, 0, 0, true , 1000},  

  animStep{CMND_END, 0, 0, 0, false, 0}
};

static const animStep herzlich[] PROGMEM = {
  animStep{CMND_RENDER, 13, 0, 0, true , 1000},  
  animStep{CMND_RENDER, 13, 0, 0, true , 1000},
  animStep{CMND_RENDER, 13, 0, 0, true , 1000}, 

  animStep{CMND_END, 0, 0, 0, false, 0}
};




static animStep* const animationSteps[] PROGMEM = {
  wipeLR,       // 0
  wipeUD,       // 1
  rotate,       // 2
  StartupAnim,  // 3
  Bloob,        // 4
  Tunnel,        //5
  InvaderAnim,  // 6
  PacManAnim,   // 7
  MarioAnim,    // 8
  fruits,       // 9
  DeathAnim,    //10
  Anschiss,     //11
  richtigerAnschiss, //12
  krassserAnschiss, //13
  StarField,     //14
  pokeBall,      //15
  laser,         //16
  herzlich       //17
};

void playScript(int scriptID) {

  Serial.print("Script"); Serial.println(scriptID);

  int i = 0;
  animStep aStep;
  memcpy_P(&aStep, pgm_read_word(&(animationSteps[scriptID])) + sizeof(struct animStep) * i++, sizeof(struct animStep));

  while (aStep.command != CMND_END) {
    switch (aStep.command) {
      case CMND_PLAY:
        playAnimation(aStep.ID, aStep.xPos, aStep.yPos, aStep.clear);
        delay(aStep.delay);
        break;
      case CMND_RENDER:
        renderSprite(aStep.ID, aStep.xPos, aStep.yPos, aStep.clear, true, aStep.delay);
        break;
      case CMND_WIPE:
        effectWipe(aStep.ID, aStep.xPos, aStep.yPos, aStep.clear, aStep.delay);
        break;
      case CMND_ROTATE:
        ratator(aStep.delay, aStep.xPos, aStep.yPos);
        break;
      case CMND_TUNNEL:
        tunnel(aStep.delay);
        break;
      case CMND_BLOOB:
        bloob(aStep.clear,aStep.delay);
        break;
      case CMND_ANSCHISS:
        scheissAn(aStep.delay, aStep.ID);
        break;
      case CMND_STARS:
        starField(aStep.delay);
        break;
    }
    memcpy_P(&aStep, pgm_read_word(&(animationSteps[scriptID])) + sizeof(struct animStep) * i++, sizeof(struct animStep));

  };
};
