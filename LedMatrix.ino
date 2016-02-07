#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK 11
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

#define WAIT_SWIPE 70
#define DIM 32

uint16_t world[DIM][DIM];
uint16_t copyWorld[DIM][DIM];

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true);

uint16_t currentColor = 0;


class Game
{
public:
  virtual void init() = 0;
  virtual void simulate() = 0;
  virtual unsigned long getInterval() = 0;
  virtual uint16_t mapColor(byte x, byte y) { return world[x][y]; };
};

class Life : public Game
{
public:
  Life() : mCountDown(0), mLastChanged(0) {}
  virtual void init() override;
  virtual void simulate() override;
  virtual unsigned long getInterval() override;
private:
  uint16_t mCountDown;
  uint16_t mLastChanged;
};

class Snake : public Game
{
  struct Point
  {
    Point() : x(0), y(0) {}
    byte x;
    byte y;  
  };
public:
  Snake() : mGrow(0) {}
  virtual void init() override;
  virtual void simulate() override;
  virtual unsigned long getInterval() override;
  virtual uint16_t mapColor(byte x, byte y) override;

private:
  Point getRandomPos();
  void moveCell(Point& cell);
  
  Point mHead;
  Point mTail;
  Point mFood;
  byte mGrow;
};


Game* game = new Life();

uint8_t getColorVal()
{
  //return 7;
  return random(4, 8);
}

uint16_t getColor(bool newColor)
{
  uint8_t r = 0;
  uint8_t g = 0;
  uint8_t b = 0;
  if (newColor)
  {
    currentColor = random() % 7;
  }
  switch (currentColor)
  {
    case 0: // green
      g = getColorVal();
      break;
      
    case 1: // red    
      r = getColorVal();
      break;
      
    case 2:  // blue
      b = getColorVal();
      break;
      
    case 3:  // yellow
      r = getColorVal();
      g = getColorVal();
      break;
      
    case 4:  // cyan
      g = getColorVal();
      b = getColorVal();
      break;
      
    case 5:  // magenta
      r = getColorVal();
      b = getColorVal();      
      break;
      
    default:  // white
      r = getColorVal();
      b = getColorVal();
      g = getColorVal();
      break;
  }
  return matrix.Color333(r, g, b);
}

void initWorld()
{
  uint16_t color = getColor(true);
  // swipe left to right
  for (int c = 0;  c < DIM; c++)
  {
    for (int r = 0; r < DIM; r++)
    {
      matrix.drawPixel(max(0, c - 1), r, 0);
      matrix.drawPixel(c, r, color);
    }
    matrix.swapBuffers(true);
    delay(WAIT_SWIPE);
  }
  
  game->init();
    
  // swipe right to left
  for (int c = DIM - 1;  c >= 0; c--)
  {
    for (int r = 0; r < DIM; r++)
    {
      matrix.drawPixel(max(0, c - 1), r, color);
      matrix.drawPixel(c, r, world[r][c]);
    }
    matrix.swapBuffers(true);
    delay(WAIT_SWIPE);
  }
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello LedLife");
  int seed = analogRead(11);
  delay(seed % 9);
  seed = seed * millis();
  Serial.println(seed);
  randomSeed(seed);
  matrix.begin();
  initWorld();
}

void render()
{  
  for (byte r = 0; r < DIM; r++)
  {
    for (byte c = 0;  c < DIM; c++)
    {
      if (world[r][c] != 0)
      {
        //matrix.drawPixel(c, r, color);        
      }
    }
  }
  matrix.swapBuffers(true);
}

void loop()
{
  render();
  delay(game->getInterval());
  game->simulate();
}
