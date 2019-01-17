static const uint16_t MAX_ROUNDS = 200;
static const uint16_t NR_OF_COLS = 8;
static uint16_t rgbs[NR_OF_COLS] = {
  matrix.Color333(0, 0, 0),
  matrix.Color333(2, 0, 0),
  matrix.Color333(4, 0, 0),
  matrix.Color333(6, 2, 0),
  matrix.Color333(7, 2, 0),
  matrix.Color333(7, 5, 0),
  matrix.Color333(7, 7, 0),
  matrix.Color333(6, 6, 6),
};

void Fire::onInit()
{
  setBottomRow(NR_OF_COLS - 1);
}

void Fire::simulate()
{
  doFire();
  
  _rounds++;
  
  if (isGoingOut())
  {
    setBottomRow(0);
  }  
}

unsigned long Fire::getInterval()
{
  return 75;
}

uint16_t Fire::mapColor(byte x, byte y)
{
  y = DIM - 1- y;
  int16_t index = _firePixels[DIM * y + x];
  return rgbs[index];
}

bool Fire::isOver() const
{
  return _rounds == MAX_ROUNDS;
}

void Fire::doFire()
{
  for(uint16_t x = 0 ; x < DIM; x++)
  {
    for (uint16_t y = 1; y < DIM; y++)
    {
      spreadFire(y * DIM + x);
    }
  }
}

void Fire::spreadFire(uint16_t src) {
  uint16_t rand = random() & 3;
  int16_t dst = src - rand + 1;
  _firePixels[max(0, dst - DIM)] = max(0, _firePixels[src] - (rand & 1));
  //_firePixels[src - DIM] = max(0, _firePixels[src] - 1);
}
 
bool Fire::isGoingOut() const {
  return _rounds >= MAX_ROUNDS - 45;
}

void Fire::setBottomRow(uint16_t col)
{
  for (uint16_t i = 0; i < DIM; i++)
  {
      _firePixels[(DIM - 1) * DIM + i] = col;
  }
}




