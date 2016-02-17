#define VOID 0
#define GRID 1
#define CIRCLE 2
#define CIRCLE_WIN 12
#define CROSS 3
#define CROSS_WIN 13

#define STATE_PLAYING 1
#define STATE_WINNER  2
#define STATE_OVER    3


Game::Point* prepareLine(byte x1, byte y1, byte x2, byte y2, byte x3, byte y3)
{
  static Game::Point line[3];
  line[0].x = x1;
  line[0].y = y1;
  line[1].x = x2;
  line[1].y = y2;
  line[2].x = x3;
  line[2].y = y3;
  return line;
}

void shuffle(Game::Point* cells, byte nrOfCells)
{
  for (byte i = 0; i < nrOfCells; i++) 
  {
    auto r = random(nrOfCells);
    Game::Point tmp(cells[i]);
    cells[i] = cells[r];
    cells[r] = tmp;    
  }
}

bool TicTacToe::isOver() const
{
  return mRoundsToPlay == 0;
}

unsigned long TicTacToe::getInterval()
{
  return 500;
}

void TicTacToe::onInit()
{
  mRoundsToPlay = 3;
  reset();
};

void TicTacToe::reset()
{
  mState = STATE_PLAYING;
  mPlaySmart = getRandomBool();
  mPlayerOne = getRandomBool();

  for (byte i = 0; i < 3; i++)
  {
    for (byte j = 0; j < 3; j++)
    {
      copyWorld[i][j] = VOID;
    }
  }

  for (byte i = 0; i < DIM; i++)
  {
    for (byte j = 0; j < DIM; j++)
    {
      byte col = VOID;
      if (i != 0 && j != 0 && i != DIM - 1 && j != DIM - 1)
      {
        if (i == 10 || i == 21 || j == 10 || j == 21)
        {
          col = GRID;
        }
      }
      world[i][j] = col;
    }
  }
}

Game::Point TicTacToe::getNextPos(byte what)
{
  // create array of empty fields
  byte pos = 0;
  Game::Point candidates[9];
  byte nrOfCandidates = 0;
  for (byte y = 0; y < 3; y++)
  {
    for (byte x = 0; x < 3; x++)
    {
      if (copyWorld[x][y] == VOID)
      {
        candidates[nrOfCandidates].x = x;
        candidates[nrOfCandidates].y = y;
        nrOfCandidates++;
      }
    }
  }
  
  shuffle(candidates, nrOfCandidates);

  if (mPlaySmart)
  {
    // evaluate fields
    int highScore = -1;
    for (byte i = 0; i < nrOfCandidates; i++)
    {
      auto& c = candidates[i];
      byte score = 0;
      score += evaluateLine(what, prepareLine(0, c.y, 1, c.y, 2, c.y));
      score += evaluateLine(what, prepareLine(c.x, 0, c.x, 1, c.x, 2));
      if (c.x == c.y)
      {
        score += evaluateLine(what, prepareLine(0, 0, 1, 1, 2, 2));
      }
      else if (c.x + c.y == 2)
      {
        score += evaluateLine(what, prepareLine(2, 0, 1, 1, 2, 0));
      }
      if (score > highScore)
      {
        highScore = score;
        pos = i;
      }
    }
  }
  else
  {
    // random empty field
    pos = random(0, nrOfCandidates);
  }
  return candidates[pos];
}

byte TicTacToe::evaluateLine(byte what, Game::Point* cells)
{
  byte score = 1;
  auto result = checkLine(cells, false);
  if (result.x == 2 || result.y == 2)
  {
    score += 2;
  }
  return score;
}

Game::Point TicTacToe::checkLine(Game::Point* cells, bool mark)
{
  byte x = 0;
  byte o = 0;
  for (byte i = 0; i < 3; i++)
  {
    byte v = copyWorld[cells[i].x][cells[i].y];
    if (v == CIRCLE)
    {
      o++;
    }
    else if (v == CROSS)
    {
      x++;
    }
  }
  if (mState != STATE_WINNER)
  {
    if (mark && (x == 3 || o == 3))
    {
      mState = STATE_WINNER;
      for (byte i = 0; i < 3; i++)
      {
        draw(cells[i].x, cells[i].y, copyWorld[cells[i].x][cells[i].y] + 10);
      }
    }
  }
  return Game::Point(x, o);
}

void TicTacToe::checkIfOver()
{
  checkLine(prepareLine(0, 0, 1, 1, 2, 2), true);
  checkLine(prepareLine(2, 0, 1, 1, 0, 2), true);
  for (byte i = 0; i < 3; i++)
  {
    checkLine(prepareLine(i, 0, i, 1, i, 2), true);
    checkLine(prepareLine(0, i, 1, i, 2, i), true);
  }

  if (mState == STATE_PLAYING)
  {
    byte voids = 0;
    for (byte i = 0; i < 3; i++)
    {
      for (byte j = 0; j < 3; j++)
      {
        if (copyWorld[i][j] == VOID)
        {
          voids++;
        }
      }
    }
    if (voids == 0)
    {
      mState = STATE_OVER;
    }
  }
}

void TicTacToe::simulate()
{
  if (mState == STATE_PLAYING)
  {
    checkIfOver();
  }

  if (mState == STATE_OVER)
  {
    reset();
    mRoundsToPlay--;
  }
  else if (mState == STATE_WINNER)
  {
    mState = STATE_OVER;
  }
  else
  {
    byte what = mPlayerOne ? CIRCLE : CROSS;
    auto pos = getNextPos(what);
    draw(pos.x, pos.y, what);
    copyWorld[pos.x][pos.y] = what;
    mPlayerOne = !mPlayerOne;
  }
}

void TicTacToe::draw(byte col, byte row, byte what)
{
  byte offX = col * 11 + 1;
  byte offY = row * 11 + 1;
  if (what == CIRCLE || what == CIRCLE_WIN)
  {
    world[offX + 3][offY + 0] = what;
    world[offX + 2][offY + 1] = what;
    world[offX + 1][offY + 1] = what;
    world[offX + 1][offY + 2] = what;
    world[offX + 0][offY + 3] = what;
  }
  else
  {
    world[offX + 0][offY + 0] = what;
    world[offX + 1][offY + 1] = what;
    world[offX + 2][offY + 2] = what;
    world[offX + 3][offY + 3] = what;
  }
  for (byte i = 0; i < 4; i++)
  {
    for (byte j = 0; j < 4; j++)
    {
      byte x = offX + j;
      byte y = offY + i;
      byte v = world[x][y];
      world[x][offY + 7 - i] = v;
      world[offX + 7 - j][y] = v;
      world[offX + 7 - j][offY + 7 - i] = v;
    }
  }
}

uint16_t TicTacToe::mapColor(byte x, byte y)
{
  switch (world[x][y]) {
    case GRID:
      return matrix.Color333(7, 7, 7);

    case CIRCLE:
      return mPlaySmart ? matrix.Color333(0, 6, 0) : matrix.Color333(0, 7, 7);

    case CROSS:
      return mPlaySmart ? matrix.Color333(0, 0, 6) : matrix.Color333(7, 0, 4);

    case CIRCLE_WIN:
    case CROSS_WIN:
      return matrix.Color333(6, 6, 0);

    default:
      return 0;
  }
}
