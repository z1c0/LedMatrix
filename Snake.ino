#define VOID 0
#define SNAKE_UP 10
#define SNAKE_DOWN 11
#define SNAKE_LEFT 12
#define SNAKE_RIGHT 13
#define FOOD 20
#define WALL 30
#define GROWBY 4

Game::Point shuffle(byte value1, byte value2)
{
  if (random(100) > 50)
  {
    auto tmp = value1;
    value1 = value2;
    value2 = tmp;
  }
  Game::Point pt;
  pt.x = value1;
  pt.y = value2;
  return pt;
}

unsigned long Snake::getInterval()
{
  return 300;
}

void Snake::onInit()
{
  // walls;
  for (byte i = 0; i < DIM; i++)
  {
    for (byte j = 0; j < DIM; j++)
    {
      byte cell = VOID;
      if (i == 0 || j == 0 || i == DIM - 1 || j == DIM - 1)
      {
        cell = WALL;
      }
      world[i][j] = cell;
    }
  }
  // snake
  byte x = random(5, DIM - 10);
  byte y = random(2, DIM - 2);
  mTail.x = x;
  mTail.y = y;
  world[x][y] = SNAKE_RIGHT;
  x++;
  world[x][y] = SNAKE_RIGHT;
  x++;
  world[x][y] = SNAKE_RIGHT;
  mHead.x = x;
  mHead.y = y;
  // food
  mFood = getRandomPos();
  world[mFood.x][mFood.y] = FOOD;
}

uint16_t Snake::mapColor(byte x, byte y)
{
  uint16_t value = world[x][y];
  switch (value)
  {
    case SNAKE_UP:
    case SNAKE_DOWN:
    case SNAKE_LEFT:
    case SNAKE_RIGHT:
      return matrix.Color333(0, 6, 0);

    case FOOD:
      return matrix.Color333(6, 0, 0);

    case WALL:
      return matrix.Color333(0, 0, 6);
  }
  return 0;
}

bool Snake::checkMove(Point cell, uint16_t dir)
{
  world[cell.x][cell.y] = dir;
  moveCell(cell);
  uint16_t v = world[cell.x][cell.y];
  return (v == VOID || v == FOOD);
}

void Snake::simulate()
{
  auto dir = world[mHead.x][mHead.y];
  // steer to food
  auto dx = mFood.x - mHead.x;
  auto dy = mFood.y - mHead.y;
  if (dx != 0) 
  {
    if (dir == SNAKE_UP || dir == SNAKE_DOWN)
    {
      dir = (dx < 0) ? SNAKE_LEFT : SNAKE_RIGHT;
    }
  }
  if (dy != 0)
  {
    if (dir == SNAKE_LEFT || dir == SNAKE_RIGHT) 
    {
      dir = (dy < 0) ? SNAKE_UP : SNAKE_DOWN;
    }
  }
  world[mHead.x][mHead.y] = dir;

  // check
  if (!checkMove(mHead, dir))
  {
    Point o;
    if (dir == SNAKE_UP || dir == SNAKE_DOWN)
    {
      o = shuffle(SNAKE_LEFT, SNAKE_RIGHT);
    }
    else
    {
      o = shuffle(SNAKE_UP, SNAKE_DOWN);
    }
    if (!checkMove(mHead, o.x))
    {
      checkMove(mHead, o.y);
    }
  }
  // move
  move();
}

void Snake::moveCell(Snake::Point& cell)
{
  uint16_t value = world[cell.x][cell.y];
  switch (value)
  {
    case SNAKE_UP:
      cell.y--;
      break;

    case SNAKE_DOWN:
      cell.y++;
      break;

    case SNAKE_LEFT:
      cell.x--;
      break;

    case SNAKE_RIGHT:
      cell.x++;
      break;
  }
}

void Snake::move()
{
  if (mGrow == 0) 
  {
    // move tail
    auto oldTail = mTail;
    moveCell(mTail);
    world[oldTail.x][oldTail.y] = VOID;
  }
  else 
  {
    mGrow--;
  }
  // move head
  uint16_t vOld = world[mHead.x][mHead.y];
  moveCell(mHead);
  uint16_t v = world[mHead.x][mHead.y];
  switch(v)
  {
    case FOOD:
      mFood = getRandomPos();
      world[mFood.x][mFood.y] = FOOD;
      mGrow = GROWBY;
      // fall through
      
    case VOID:     
      world[mHead.x][mHead.y] = vOld;
      break;
  
    default:
      _isOver = true;
  }
}

