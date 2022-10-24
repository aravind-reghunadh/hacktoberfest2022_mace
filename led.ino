/*
  4x4x4 LED Cube
  Connection Setup: 
  Columns
  [(x,y)-Pin]
  (1,1)-13
  (1,2)-12
  (1,3)-11
  (1,4)-10
  (2,1)-9
  (2,2)-8
  (2,3)-7
  (2,4)-6
  (3,1)-5
  (3,2)-4
  (3,3)-3
  (3,4)-2
  (4,1)-1
  (4,2)-0
  (4,3)-A5
  (4,4)-A4
  Layers
  [layer-Pin]
  a-A0
  b-A1
  c-A2
  d-A3
*/
int pin[4][4]={{13,12,11,10},
              {9,8,7,6},      
              {5,4,3,2},    
              {1,0,A5,A4}};

int layer[4]={A3,A2,A1,A0};
void setup() {
  
  for(int i=0;i<4;i++)
  {
    pinMode(layer[i],OUTPUT);
    for(int j=0;j<4;j++)
      {
      pinMode(pin[i][j],OUTPUT);
      }   
  }

}
void turnon(int,int,int);
void turnoff(int,int,int);
void turnoneverything();
void turnoffeverything();
void turnoncoloum(int,int);
void turnoffcoloum(int,int);
void turnonlayerZ(int);
void turnofflayerZ(int);
void turnonlayerX(int);
void turnofflayerX(int);
void turnonlayerY(int);
void turnofflayerY(int);
void moveupdown(int);
void movefrontback(int);
void moveleftright(int);
void flicker(int);
void coloumnPattern(int);
void wheel(int);

void loop() {
  flicker(100);
  moveupdown(300);
  movefrontback(300);
  moveleftright(300);
  coloumnPattern(250);
  wheel(50);
  delay(2000);
}
void turnon(int x,int y,int z)
{
  digitalWrite(pin[x][y],0);
  digitalWrite(layer[z],1);
}

void turnoff(int x,int y,int z)
{
  digitalWrite(pin[x][y],1);
  digitalWrite(layer[z],0);
}
                
void turnoneverything()
{
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      for(int k=0;k<4;k++)
        turnon(i,j,k);
}

void turnoffeverything()
{
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      for(int k=0;k<4;k++)
        turnon(i,j,k);  
}

void turnoncoloum(int x,int y)
{
  for(int i=0;i<4;i++)
  {
    turnon(x,y,i);
  }
}

void turnoffcoloum(int x,int y)
{
  for(int i=0;i<4;i++)
  {
    turnoff(x,y,i);
  }
}

void turnonlayerZ(int z)
{
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      turnon(i,j,z);// i j k
}

void turnofflayerZ(int z)
{
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      turnoff(i,j,z); // i j k
}

void turnonlayerX(int x)
{
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      turnon(x,i,j);      
}

void turnofflayerX(int x)
{
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      turnoff(x,i,j);  
}

void turnonlayerY(int y)
{
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      turnon(i,y,j);
}

void turnofflayerY(int y)
{
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      turnoff(i,y,j); 
}

void moveupdown(int time)
{
    for(int i=0;i<4;i++)
    {
      turnonlayerZ(i);
      delay(time);
      turnofflayerZ(i);
      delay(time);
    }
    for(int i=3;i>=0;i++)
    {
    turnonlayerY(i);
    delay(time);
    turnofflayerY(i); 
    delay(time);
    }
}

void movefrontback(int time)
{
    for(int i=0;i<4;i++)
    {
      turnonlayerY(i);
      delay(time);
      turnofflayerY(i);
      delay(time);
    }
    for(int i=3;i>=0;i++)
    {
        turnonlayerY(i);
        delay(time);
        turnofflayerY(i);
        delay(time);
    }
}

void moveleftright(int time)
{
  for(int i=0;i<4;i++)
    {
      turnonlayerX(i);
      delay(time);
      turnofflayerX(i);
      delay(time);
    }
    for(int i=3;i>=0;i++) 
    {
    turnonlayerY(i);
    delay(time);
    turnofflayerY(i);
    delay(time);
    }
}

void flicker(int time)
{
  for(int i=0;i<=time;i+=5)
  {
    turnoneverything();
    delay(time);
    turnoffeverything();
    delay(time);
  }
}

void coloumnPattern(int time)
{
  for(int k=0;k<=time;k+=5)
  {
    for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
      {
        turnoncoloum(i,j);
        delay(time);
        turnoffcoloum(i,j);
        delay(time);
      }
    }
  }
}
void wheel(int time)
{
 for(int k=0;k<4;k++)
 {
  for(int t=1;t<=200;t++)
  {
    turnon(0,0,k);
    turnon(1,1,k);
    turnon(2,2,k);
    
    delay(time);
    
    turnoff(0,0,k);
    turnoff(2,2,k);

    turnon(0,1,k);
    turnon(2,1,k);

    delay(time);
    
    turnoff(0,1,k);
    turnoff(2,1,k);

    turnon(0,2,k);
    turnon(2,0,k);

    delay(time);
    
    turnoff(0,2,k);
    turnoff(2,0,k);

    turnon(1,0,k);
    turnon(1,2,k);

    delay(time);

    turnoff(1,0,k);
    turnoff(1,2,k);
    turnoff(1,1,k);
  }
 }
}
