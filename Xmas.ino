uint16_t rgb(byte r, byte g, byte b)
{
  //return matrix.Color333(7, 0, 0);
  return matrix.Color333(r / 32, g / 32, b / 32);
}

void Xmas::onInit()
{
world[3][4] = rgb(0,204,0);
world[3][5] = rgb(51,204,0);
world[4][3] = rgb(51,204,0);
world[4][4] = rgb(51,204,0);
world[4][5] = rgb(51,204,0);
world[4][6] = rgb(51,204,0);
world[4][7] = rgb(51,204,0);
world[5][3] = rgb(51,204,0);
world[5][4] = rgb(0,204,0);
world[5][5] = rgb(51,204,0);
world[5][6] = rgb(51,204,0);
world[5][7] = rgb(255,255,0);
world[5][8] = rgb(51,204,0);
world[5][9] = rgb(51,204,0);
world[6][3] = rgb(51,204,0);
world[6][4] = rgb(255,255,0);
world[6][5] = rgb(51,204,0);
world[6][6] = rgb(255,0,255);
world[6][7] = rgb(51,204,0);
world[6][8] = rgb(51,204,0);
world[6][9] = rgb(51,204,0);
world[6][10] = rgb(51,204,0);
world[6][11] = rgb(51,204,0);
world[7][3] = rgb(51,204,0);
world[7][4] = rgb(51,204,0);
world[7][5] = rgb(255,255,0);
world[7][6] = rgb(51,204,0);
world[7][7] = rgb(51,204,0);
world[7][8] = rgb(51,204,0);
world[7][9] = rgb(51,204,0);
world[7][10] = rgb(51,204,0);
world[7][11] = rgb(51,204,0);
world[7][12] = rgb(51,204,0);
world[7][13] = rgb(51,204,0);
world[8][3] = rgb(51,204,0);
world[8][4] = rgb(51,204,0);
world[8][5] = rgb(51,204,0);
world[8][6] = rgb(255,0,255);
world[8][7] = rgb(51,204,0);
world[8][8] = rgb(51,204,0);
world[8][9] = rgb(51,204,0);
world[8][10] = rgb(51,204,0);
world[8][11] = rgb(51,204,0);
world[8][12] = rgb(51,204,0);
world[8][13] = rgb(51,204,0);
world[8][14] = rgb(255,255,0);
world[8][15] = rgb(51,204,0);
world[9][3] = rgb(51,204,0);
world[9][4] = rgb(51,204,0);
world[9][5] = rgb(51,204,0);
world[9][6] = rgb(255,255,0);
world[9][7] = rgb(51,204,0);
world[9][8] = rgb(51,204,0);
world[9][9] = rgb(255,255,0);
world[9][10] = rgb(255,0,255);
world[9][11] = rgb(51,204,0);
world[9][12] = rgb(51,204,0);
world[9][13] = rgb(51,204,0);
world[9][14] = rgb(255,0,255);
world[9][15] = rgb(51,204,0);
world[9][16] = rgb(51,204,0);
world[9][17] = rgb(51,204,0);
world[10][3] = rgb(51,204,0);
world[10][4] = rgb(51,204,0);
world[10][5] = rgb(51,204,0);
world[10][6] = rgb(255,0,255);
world[10][7] = rgb(51,204,0);
world[10][8] = rgb(51,204,0);
world[10][9] = rgb(255,0,255);
world[10][10] = rgb(255,255,0);
world[10][11] = rgb(51,204,0);
world[10][12] = rgb(51,204,0);
world[10][13] = rgb(255,255,0);
world[10][14] = rgb(51,204,0);
world[10][15] = rgb(51,204,0);
world[10][16] = rgb(51,204,0);
world[10][17] = rgb(255,255,0);
world[10][18] = rgb(51,204,0);
world[10][19] = rgb(51,204,0);
world[11][2] = rgb(153,51,0);
world[11][3] = rgb(51,204,0);
world[11][4] = rgb(51,204,0);
world[11][5] = rgb(255,255,0);
world[11][6] = rgb(51,204,0);
world[11][7] = rgb(51,204,0);
world[11][8] = rgb(51,204,0);
world[11][9] = rgb(51,204,0);
world[11][10] = rgb(51,204,0);
world[11][11] = rgb(51,204,0);
world[11][12] = rgb(51,204,0);
world[11][13] = rgb(255,0,255);
world[11][14] = rgb(51,204,0);
world[11][15] = rgb(51,204,0);
world[11][16] = rgb(51,204,0);
world[11][17] = rgb(255,0,255);
world[11][18] = rgb(51,204,0);
world[11][19] = rgb(51,204,0);
world[11][20] = rgb(51,204,0);
world[11][21] = rgb(51,204,0);
world[12][0] = rgb(153,51,0);
world[12][1] = rgb(153,51,0);
world[12][2] = rgb(153,51,0);
world[12][3] = rgb(51,204,0);
world[12][4] = rgb(51,204,0);
world[12][5] = rgb(255,0,255);
world[12][6] = rgb(51,204,0);
world[12][7] = rgb(51,204,0);
world[12][8] = rgb(51,204,0);
world[12][9] = rgb(51,204,0);
world[12][10] = rgb(51,204,0);
world[12][11] = rgb(51,204,0);
world[12][12] = rgb(255,255,0);
world[12][13] = rgb(51,204,0);
world[12][14] = rgb(51,204,0);
world[12][15] = rgb(51,204,0);
world[12][16] = rgb(255,255,0);
world[12][17] = rgb(51,204,0);
world[12][18] = rgb(51,204,0);
world[12][19] = rgb(51,204,0);
world[12][20] = rgb(51,204,0);
world[12][21] = rgb(51,204,0);
world[12][22] = rgb(51,204,0);
world[12][23] = rgb(51,204,0);
world[13][0] = rgb(153,51,0);
world[13][1] = rgb(153,51,0);
world[13][2] = rgb(153,51,0);
world[13][3] = rgb(51,204,0);
world[13][4] = rgb(51,204,0);
world[13][5] = rgb(51,204,0);
world[13][6] = rgb(255,255,0);
world[13][7] = rgb(51,204,0);
world[13][8] = rgb(51,204,0);
world[13][9] = rgb(51,204,0);
world[13][10] = rgb(255,0,255);
world[13][11] = rgb(51,204,0);
world[13][12] = rgb(255,0,255);
world[13][13] = rgb(51,204,0);
world[13][14] = rgb(51,204,0);
world[13][15] = rgb(51,204,0);
world[13][16] = rgb(255,0,255);
world[13][17] = rgb(51,204,0);
world[13][18] = rgb(51,204,0);
world[13][19] = rgb(51,204,0);
world[13][20] = rgb(255,0,255);
world[13][21] = rgb(51,204,0);
world[13][22] = rgb(51,204,0);
world[13][23] = rgb(51,204,0);
world[13][24] = rgb(255,255,0);
world[13][25] = rgb(51,204,0);
world[14][0] = rgb(153,51,0);
world[14][1] = rgb(153,51,0);
world[14][2] = rgb(153,51,0);
world[14][3] = rgb(51,204,0);
world[14][4] = rgb(51,204,0);
world[14][5] = rgb(51,204,0);
world[14][6] = rgb(51,204,0);
world[14][7] = rgb(255,0,255);
world[14][8] = rgb(51,204,0);
world[14][9] = rgb(51,204,0);
world[14][10] = rgb(51,204,0);
world[14][11] = rgb(51,204,0);
world[14][12] = rgb(255,255,0);
world[14][13] = rgb(51,204,0);
world[14][14] = rgb(51,204,0);
world[14][15] = rgb(51,204,0);
world[14][16] = rgb(255,255,0);
world[14][17] = rgb(51,204,0);
world[14][18] = rgb(51,204,0);
world[14][19] = rgb(255,0,255);
world[14][20] = rgb(51,204,0);
world[14][21] = rgb(51,204,0);
world[14][22] = rgb(51,204,0);
world[14][23] = rgb(255,0,255);
world[14][24] = rgb(51,204,0);
world[14][25] = rgb(0,204,0);
world[14][26] = rgb(51,204,0);
world[14][27] = rgb(0,204,0);
world[14][28] = rgb(255,0,255);
world[14][31] = rgb(255,0,255);
world[15][0] = rgb(153,51,0);
world[15][1] = rgb(153,51,0);
world[15][2] = rgb(153,51,0);
world[15][3] = rgb(51,204,0);
world[15][4] = rgb(51,204,0);
world[15][5] = rgb(51,204,0);
world[15][6] = rgb(51,204,0);
world[15][7] = rgb(0,204,0);
world[15][8] = rgb(255,255,0);
world[15][9] = rgb(51,204,0);
world[15][10] = rgb(51,204,0);
world[15][11] = rgb(51,204,0);
world[15][12] = rgb(51,204,0);
world[15][13] = rgb(255,0,255);
world[15][14] = rgb(51,204,0);
world[15][15] = rgb(51,204,0);
world[15][16] = rgb(51,204,0);
world[15][17] = rgb(255,0,255);
world[15][18] = rgb(51,204,0);
world[15][19] = rgb(0,204,0);
world[15][20] = rgb(51,204,0);
world[15][21] = rgb(51,204,0);
world[15][22] = rgb(255,255,0);
world[15][23] = rgb(51,204,0);
world[15][24] = rgb(255,255,0);
world[15][25] = rgb(51,204,0);
world[15][26] = rgb(51,204,0);
world[15][27] = rgb(51,204,0);
world[15][28] = rgb(0,204,0);
world[15][29] = rgb(255,255,51);
world[15][30] = rgb(255,255,51);
world[16][0] = rgb(153,51,0);
world[16][1] = rgb(153,51,0);
world[16][2] = rgb(153,51,0);
world[16][3] = rgb(51,204,0);
world[16][4] = rgb(51,204,0);
world[16][5] = rgb(51,204,0);
world[16][6] = rgb(0,204,0);
world[16][7] = rgb(0,204,0);
world[16][8] = rgb(255,0,255);
world[16][9] = rgb(51,204,0);
world[16][10] = rgb(51,204,0);
world[16][11] = rgb(0,204,0);
world[16][12] = rgb(51,204,0);
world[16][13] = rgb(255,255,0);
world[16][14] = rgb(51,204,0);
world[16][15] = rgb(51,204,0);
world[16][16] = rgb(51,204,0);
world[16][17] = rgb(255,255,0);
world[16][18] = rgb(51,204,0);
world[16][19] = rgb(0,204,0);
world[16][20] = rgb(51,204,0);
world[16][21] = rgb(51,204,0);
world[16][22] = rgb(255,0,255);
world[16][23] = rgb(51,204,0);
world[16][24] = rgb(51,204,0);
world[16][25] = rgb(255,0,255);
world[16][26] = rgb(51,204,0);
world[16][27] = rgb(51,204,0);
world[16][28] = rgb(51,204,0);
world[16][29] = rgb(255,255,51);
world[16][30] = rgb(255,255,51);
world[17][0] = rgb(153,51,0);
world[17][1] = rgb(153,51,0);
world[17][2] = rgb(153,51,0);
world[17][3] = rgb(51,204,0);
world[17][4] = rgb(51,204,0);
world[17][5] = rgb(255,0,255);
world[17][6] = rgb(0,204,0);
world[17][7] = rgb(255,255,0);
world[17][8] = rgb(51,204,0);
world[17][9] = rgb(51,204,0);
world[17][10] = rgb(51,204,0);
world[17][11] = rgb(51,204,0);
world[17][12] = rgb(255,0,255);
world[17][13] = rgb(51,204,0);
world[17][14] = rgb(51,204,0);
world[17][15] = rgb(51,204,0);
world[17][16] = rgb(51,204,0);
world[17][17] = rgb(51,204,0);
world[17][18] = rgb(255,255,0);
world[17][19] = rgb(0,204,0);
world[17][20] = rgb(51,204,0);
world[17][21] = rgb(51,204,0);
world[17][22] = rgb(255,255,0);
world[17][23] = rgb(51,204,0);
world[17][24] = rgb(51,204,0);
world[17][25] = rgb(51,204,0);
world[17][26] = rgb(51,204,0);
world[17][27] = rgb(51,204,0);
world[17][28] = rgb(255,0,255);
world[17][31] = rgb(255,0,255);
world[18][0] = rgb(153,51,0);
world[18][1] = rgb(153,51,0);
world[18][2] = rgb(153,51,0);
world[18][3] = rgb(51,204,0);
world[18][4] = rgb(51,204,0);
world[18][5] = rgb(51,204,0);
world[18][6] = rgb(51,204,0);
world[18][7] = rgb(255,0,255);
world[18][8] = rgb(51,204,0);
world[18][9] = rgb(51,204,0);
world[18][10] = rgb(0,204,0);
world[18][11] = rgb(255,255,0);
world[18][12] = rgb(51,204,0);
world[18][13] = rgb(51,204,0);
world[18][14] = rgb(51,204,0);
world[18][15] = rgb(51,204,0);
world[18][16] = rgb(51,204,0);
world[18][17] = rgb(51,204,0);
world[18][18] = rgb(255,0,255);
world[18][19] = rgb(0,204,0);
world[18][20] = rgb(51,204,0);
world[18][21] = rgb(51,204,0);
world[18][22] = rgb(255,0,255);
world[18][23] = rgb(51,204,0);
world[18][24] = rgb(51,204,0);
world[18][25] = rgb(51,204,0);
world[19][0] = rgb(153,51,0);
world[19][1] = rgb(153,51,0);
world[19][2] = rgb(153,51,0);
world[19][3] = rgb(51,204,0);
world[19][4] = rgb(51,204,0);
world[19][5] = rgb(51,204,0);
world[19][6] = rgb(51,204,0);
world[19][7] = rgb(255,255,0);
world[19][8] = rgb(51,204,0);
world[19][9] = rgb(51,204,0);
world[19][10] = rgb(255,0,255);
world[19][11] = rgb(51,204,0);
world[19][12] = rgb(51,204,0);
world[19][13] = rgb(51,204,0);
world[19][14] = rgb(51,204,0);
world[19][15] = rgb(255,255,0);
world[19][16] = rgb(51,204,0);
world[19][17] = rgb(51,204,0);
world[19][18] = rgb(51,204,0);
world[19][19] = rgb(255,255,0);
world[19][20] = rgb(51,204,0);
world[19][21] = rgb(51,204,0);
world[19][22] = rgb(255,255,0);
world[19][23] = rgb(51,204,0);
world[20][2] = rgb(153,51,0);
world[20][3] = rgb(51,204,0);
world[20][4] = rgb(51,204,0);
world[20][5] = rgb(51,204,0);
world[20][6] = rgb(255,255,0);
world[20][7] = rgb(51,204,0);
world[20][8] = rgb(51,204,0);
world[20][9] = rgb(51,204,0);
world[20][10] = rgb(255,255,0);
world[20][11] = rgb(51,204,0);
world[20][12] = rgb(51,204,0);
world[20][13] = rgb(51,204,0);
world[20][14] = rgb(255,255,0);
world[20][15] = rgb(255,0,255);
world[20][16] = rgb(255,255,0);
world[20][17] = rgb(51,204,0);
world[20][18] = rgb(51,204,0);
world[20][19] = rgb(51,204,0);
world[20][20] = rgb(255,0,255);
world[20][21] = rgb(51,204,0);
world[21][3] = rgb(51,204,0);
world[21][4] = rgb(51,204,0);
world[21][5] = rgb(51,204,0);
world[21][6] = rgb(255,0,255);
world[21][7] = rgb(51,204,0);
world[21][8] = rgb(51,204,0);
world[21][9] = rgb(51,204,0);
world[21][10] = rgb(255,0,255);
world[21][11] = rgb(51,204,0);
world[21][12] = rgb(51,204,0);
world[21][13] = rgb(51,204,0);
world[21][14] = rgb(51,204,0);
world[21][15] = rgb(255,255,0);
world[21][16] = rgb(51,204,0);
world[21][17] = rgb(51,204,0);
world[21][18] = rgb(51,204,0);
world[21][19] = rgb(51,204,0);
world[22][3] = rgb(51,204,0);
world[22][4] = rgb(51,204,0);
world[22][5] = rgb(51,204,0);
world[22][6] = rgb(51,204,0);
world[22][7] = rgb(255,255,0);
world[22][8] = rgb(51,204,0);
world[22][9] = rgb(51,204,0);
world[22][10] = rgb(255,255,0);
world[22][11] = rgb(51,204,0);
world[22][12] = rgb(51,204,0);
world[22][13] = rgb(51,204,0);
world[22][14] = rgb(51,204,0);
world[22][15] = rgb(51,204,0);
world[22][16] = rgb(51,204,0);
world[22][17] = rgb(51,204,0);
world[23][3] = rgb(51,204,0);
world[23][4] = rgb(51,204,0);
world[23][5] = rgb(51,204,0);
world[23][6] = rgb(51,204,0);
world[23][7] = rgb(255,0,255);
world[23][8] = rgb(51,204,0);
world[23][9] = rgb(51,204,0);
world[23][10] = rgb(51,204,0);
world[23][11] = rgb(255,0,255);
world[23][12] = rgb(51,204,0);
world[23][13] = rgb(51,204,0);
world[23][14] = rgb(51,204,0);
world[23][15] = rgb(51,204,0);
world[24][3] = rgb(51,204,0);
world[24][4] = rgb(51,204,0);
world[24][5] = rgb(51,204,0);
world[24][6] = rgb(51,204,0);
world[24][7] = rgb(255,255,0);
world[24][8] = rgb(51,204,0);
world[24][9] = rgb(51,204,0);
world[24][10] = rgb(51,204,0);
world[24][11] = rgb(255,255,0);
world[24][12] = rgb(51,204,0);
world[24][13] = rgb(51,204,0);
world[25][3] = rgb(51,204,0);
world[25][4] = rgb(51,204,0);
world[25][5] = rgb(51,204,0);
world[25][6] = rgb(51,204,0);
world[25][7] = rgb(51,204,0);
world[25][8] = rgb(255,0,255);
world[25][9] = rgb(51,204,0);
world[25][10] = rgb(51,204,0);
world[25][11] = rgb(51,204,0);
world[26][3] = rgb(51,204,0);
world[26][4] = rgb(51,204,0);
world[26][5] = rgb(51,204,0);
world[26][6] = rgb(255,0,255);
world[26][7] = rgb(51,204,0);
world[26][8] = rgb(51,204,0);
world[26][9] = rgb(255,255,0);
world[27][3] = rgb(51,204,0);
world[27][4] = rgb(51,204,0);
world[27][5] = rgb(51,204,0);
world[27][6] = rgb(51,204,0);
world[27][7] = rgb(51,204,0);
world[28][4] = rgb(51,204,0);
world[28][5] = rgb(51,204,0);

  for (byte r = 0; r < DIM; r++)
  {
    for (byte c = 0;  c < DIM; c++)
    {
      // mask matrix
      copyWorld[r][c] = (world[r][c] == rgb(255, 0, 255));
    }
  }
  simulate();
}

void Xmas::simulate()
{
  for (byte r = 0; r < DIM; r++)
  {
    for (byte c = 0;  c < DIM; c++)
    {
      auto col = world[r][c];
      if (copyWorld[r][c] != 0) {
        switch (random(4)) {
          case 0:
            world[r][c] = rgb(255, 50, 0);
            break;

          case 1:
            world[r][c] = rgb(255, 255, 0);
            break;
            
          case 2:
            world[r][c] = rgb(255, 255, 255);
            break;

          case 3:
            world[r][c] = rgb(0, 0, 255);
            break;
        }
      }
    }
  }
}

unsigned long Xmas::getInterval()
{
  return 1000;
}

uint16_t Xmas::mapColor(byte x, byte y)
{
  return world[x][y];
}

bool Xmas::isOver() const
{
  return false;
}

