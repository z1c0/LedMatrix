int xadd (int i, int a)
{
  i += a;
  while (i < 0) i += DIM;
  while (i >= DIM) i -= DIM;
  return i;
}

/* add to a height index, wrapping around */

int yadd (int i, int a)
{
  i += a;
  while (i < 0) i += DIM;
  while (i >= DIM) i -= DIM;
  return i;
}


unsigned long Life::getInterval()
{
  return 700;
}
  
void Life::onInit()
{
  mLastChanged = 0;
  mCountDown = 0;

  uint16_t color = getColor(true);

  // init world
  for (int r = 0; r < DIM; r++)
  {
    for (int c = 0;  c < DIM; c++)
    {
      copyWorld[r][c] = 0;
      world[r][c] = random(1000) > 700 ? getColor(false) : 0;
    }
  }
  // init world
  if (false)
  {
    // Blinker
    world[4][4] = 1;
    world[4][5] = 1;
    world[4][6] = 1;
  }
  if (false)
  {
    // Block
    world[1][1] = color;
    world[1][2] = color;
    world[2][1] = color;
    world[2][2] = color;
  }
  /*
  // Beehive
  world[5][3] = 1;
  world[4][4] = 1;
  world[4][5] = 1;
  world[6][4] = 1;
  world[6][5] = 1;
  world[5][6] = 1;
  */
  if (false)
  {
    // Beacon
    world[12][12] = color;
    world[12][13] = color;
    world[13][12] = color;
    world[13][13] = color;
    world[14][14] = color;
    world[14][15] = color;
    world[15][14] = color;
    world[15][15] = color;
  }
}

void Life::simulate()
{
  // Store new states in temporary matrix.
  for (byte r = 0; r < DIM; r++)
  {
    for (byte c = 0;  c < DIM; c++)
    {
      int cells = getNumberOfAdjacentCells(r, c);
      if (cells == 2)
      {
        // stasis
        copyWorld[r][c] = world[r][c];
      }
      else if (cells == 3)
      {
        // growth
        copyWorld[r][c] = getColor(false);
      }
      else
      {
        // death
        copyWorld[r][c] = 0;
      }
    }
  }
  //
  // Copy back to world matrix.
  //
  int changed = 0;
  for (byte r = 0; r < DIM; r++)
  {
    for (byte c = 0;  c < DIM; c++)
    {
      bool b1(world[r][c] != 0);
      bool b2(copyWorld[r][c] != 0);
      if (b1 != b2)
      {
        world[r][c] = copyWorld[r][c];
        changed++;
      }
    }
  }
  if (abs(changed - mLastChanged) < 2)
  {
    mCountDown--;
  }
  else
  {
    mCountDown = 10;    
  }
  mLastChanged = changed;
  //
  // Re-populate the world?
  //
  Serial.print("changed: ");
  Serial.println(changed);
  Serial.print("mCountDown: ");
  Serial.println(mCountDown);
  
  if (changed == 0 || mCountDown <= 0)
  {
    _isOver = true;
  }
}

int getNumberOfAdjacentCells(byte r, byte c)
{
  int count = 0;
  for (int k = -1; k <= 1; k++)
  {
    for (int l = -1; l <= 1; l++)
    {
      if (k || l)
      {
        if (world[yadd(r, l)][xadd(c, k)] != 0)
        {
          count++;
        }
      }
    }
  }
  return count;
}


