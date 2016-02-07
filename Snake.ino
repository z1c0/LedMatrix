#define VOID 0
#define SNAKE_UP 10
#define SNAKE_DOWN 11
#define SNAKE_LEFT 12
#define SNAKE_RIGHT 13
#define FOOD 20
#define WALL 30

/*  
 function shuffle(o) {
 for(var j, x, i = o.length; i; j = Math.floor(Math.random() * i), x = o[--i], o[i] = o[j], o[j] = x);
 return o;
 }*/

Snake::Point Snake::getRandomPos()
{
  Snake::Point pt;
  while (true) {
    pt.x = random(0, DIM);
    pt.y = random(0, DIM);
    if (world[pt.x][pt.y] == VOID)
    {
      break;
    }
  }
  return pt;
}

unsigned long Snake::getInterval()
{
  return 300;
}    

void Snake::init()
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
      return matrix.Color333(6, 6, 0);
 
    case WALL:
      return matrix.Color333(0, 0, 6);
  }
  return 0;
}
 
/*
 checkMove : function(cell, dir) {
 var tmp = cell.slice();
 this.setCellValue(tmp, dir);
 var v = this.getCellValue(this.moveCell(tmp));
 return (v == VOID || v == FOOD);
 },
 
 
 simulate : function() {
 var dir = this.getCellValue(this.head);
 // steer to food
 var dx = this.food[0] - this.head[0];
 var dy = this.food[1] - this.head[1];
 if (dx != 0) {
 if (dir == SNAKE_UP || dir == SNAKE_DOWN) {
 dir = (dx < 0) ? SNAKE_LEFT : SNAKE_RIGHT;
 } 
 }
 if (dy != 0) {
 if (dir == SNAKE_LEFT || dir == SNAKE_RIGHT) {
 dir = (dy < 0) ? SNAKE_UP : SNAKE_DOWN;
 }
 }
 this.setCellValue(this.head, dir);
 
 // check
 dir = this.getCellValue(this.head);
 if (!this.checkMove(this.head, dir)) {
 var o = [];
 if (dir == SNAKE_UP || dir == SNAKE_DOWN) {
 o = shuffle([SNAKE_LEFT, SNAKE_RIGHT]);
 } 
 else {
 o = shuffle([SNAKE_UP, SNAKE_DOWN]);
 }
 if (!this.checkMove(this.head, o[0])) {
 this.checkMove(this.head, o[1]);
 }
 }
 
 // move
 this.move();
 },
 */
 
void Snake::moveCell(Snake::Point& cell)
{
 uint16_t value = world[cell.x][cell.y];
 switch (dir)
 {
   case SNAKE_UP:
   cell[1]--;
   break;
   case SNAKE_DOWN:
   cell[1]++;
   break;
   case SNAKE_LEFT:
   cell[0]--;
   break;
   case SNAKE_RIGHT:
   cell[0]++;
   break;
 }
 //return cell;
}

/*
 
 /*
 move : function() {
 debugger;
 if (this.grow == 0) {
 // move tail
 var oldTail = this.tail.slice();
 this.moveCell(this.tail);
 this.setCellValue(oldTail, VOID);
 }
 else {
 this.grow--;
 }
 // move head
 var vOld = this.getCellValue(this.head);
 var newHead = this.moveCell(this.head);
 var v = this.getCellValue(newHead);
 switch(v) {
 case FOOD:
 this.food = this.getRandomPos();
 this.setCellValue(this.food, FOOD);
 this.grow = 3;
 // fall through
 
 case VOID:
 this.head = newHead;
 this.setCellValue(this.head, vOld);
 break;
 
 default:
 this.reset();
 }
 }
 };
 }
 */

