/*  ____  __  _  _  ____  __    ____     ___   __   __    ____
   / ___)(  )( \/ )(  _ \(  )  (  __)   / __) /  \ (  )  (  __)
   \___ \ )( / \/ \ ) __// (_/\ ) _)   ( (_ \(  O )/ (_/\ ) _)
   (____/(__)\_)(_/(__)  \____/(____)   \___/ \__/ \____/(__)   */
//A virtual toy for your personal unix system
//Julian Triveri for CS 173 @ Denison
//Sept 18th, 2018
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
using namespace std;

////////////////CONFIG////////////////

//Width and height of the display area
const int w = 120;
const int h = 40;
//Length in nanoseconds between each frame refresh
const int refreshRate = 16000;

//////////////////////////////////////

//Matrix representing display area.
//Integers represent different characters to be drawn on screen
int scene[h][w];
//1D array representing terrain height across the width of the scene
float terrain[w];
//Used when generating terrain height
int terrainLevel = 0;

//Strength of the player's golf stroke
float strokeStrength;

/* Function: setPixel
 * Usage: setPixel(<x position>, <y position>, <pixel id>)
 * ---------------------------------------------------------------------------
 * Assigns value of scene[<y position>][<x position>] to <pixel id> */
void setPixel(int x, int y, int id){
  if(-1 < x && x < w - 1 && -1 < y && y < h - 1)
    scene[y][x] = id;
}


/* Function: getPixel
 * Usage: int p = getPixel(<x position>, <y position>)
 * ---------------------------------------------------------------------------
 * Returns pixel id from scene[<y position>][<x position>]  */
int getPixel(int x, int y){
  return (-1 < x && x < w - 1 && -1 < y && y < h - 1)? scene[y][x] : 0;
}

/* Function: pixelIdToString
 * Usage: string c = pixelIdToString(<pixel id>)
 * ---------------------------------------------------------------------------
 * Returns string of a single character corrosponding to <pixel id> */
string pixelIdToString(int id){
  switch(id){
    case 0: return " "; break;
    case 1: return "▓"; break;
    case 2: return "●"; break;
  }
  return " ";
}

/* Function: drawScene
 * Usage: drawScene()
 * ---------------------------------------------------------------------------
 * Clears previous terminal lines and prints scene matrix as a grid of
 * characters. Pauses program for 'refreshRate' nanoseconds */
void drawScene(){
  //Clear display (works on Linux + MacOS, but not Windows & etc)
  cout << "\033c" << endl;

  for(int y = 0; y < h; y++){
    for(int x = 0; x < w; x++)
      cout << pixelIdToString(getPixel(x, y));
    cout << endl;
  }
  //Delay for refreshRate time.
  usleep(refreshRate);
}

/* Function: generateTerrain
 * Usage: generateTerrain()
 * ---------------------------------------------------------------------------
 * Fills terrain array with integers that either are the same or have a
 * difference of 1 to the previous value in the array. The first item in the
 * array is always the same as the last value of the array prior to calling
 * generateTerrain(). Applies terrain array to scene matrix  */
void generateTerrain(){

  for(int i = 0; i < w; i++){
    if(rand() % 5 < 1)
      //If terrain is between 0 and 10, raise or lower the
      //terrain level by 1.
      terrainLevel += (terrainLevel > 10 || (terrainLevel > 0 && rand() % 2 < 1))? -1 : 1;

    terrain[i] = terrainLevel;
  }

  //Show terrain on-screen
  for(int y = 0; y < h; y++)
    for(int x = 0; x < w; x++)
      if(y >= h - 3 - terrain[x])
        setPixel(x, y, 1);
      else
        setPixel(x, y, 0);

}

/* Class: Ball
 * ---------------------------------------------------------------------------
 * Represents the player's golf ball object */
class Ball{
public:
  float x;
  float y;
  float velocityX;
  float velocityY;

  //Set to whatever pixel value the ball is replacing
  //at position x,y
  int lastPixelValue;

  /* Function: Ball
   * Usage: Ball b = Ball(<x position>, <y position>)
   * ---------------------------------------------------------------------------
   * Initializes a new Ball class object with the ball initially displayed
   * at scene[<y position>][<x position>] */
  Ball(float xPos, float yPos){
    x = xPos;
    y = yPos;
  }

  /* Function: setVelocity
   * Usage: b.setVelocity(<x velocity>, <y velocity>)
   * ---------------------------------------------------------------------------
   * Sets velocityX and velocityY to <x velocity> and <y velocity> */
  void setVelocity(float vX, float vY){
    velocityX = vX;
    velocityY = vY;
  }

  /* Function: update
   * Usage: b.update()
   * ---------------------------------------------------------------------------
   * Calculates the next position of the ball based on position, velocity, and
   * if/how the ball is colliding with the ground. Then sets scene[y][x] to
   * ball pixel id. */
  void update(){

    //Limit velocity to prevent clipping through the ground
    if(velocityX > 3)
      velocityX = 3;

    if(velocityY > -3)
      velocityY -= 0.01;

    //  Replace last ball pixel with whatever was there before it to avoid
    //trail of "ghost balls" onscreen
    setPixel(x, y, lastPixelValue);

    //Apply velocity
    y -= velocityY;
    x += velocityX;

    //Get the ball out of the ground if it ends up in there
    while(getPixel(x, y) == 1){
      y--;
      //  Ball can 'roll off' an incline like a ramp
      //based on velocityX
      velocityY += velocityX / 4;
      //Reduce speed more if 'rolling' up a hill
      velocityX -= 0.2;
    }

    //Store pixel value ball is replacing at x,y
    lastPixelValue = getPixel(x, y);

    //  If the pixel bellow the ball is ground,
    //handle collisions
    if(getPixel(x, y + 1) == 1 && velocityY <= 0){
      //The ball can bounce back up if its falling quick enough
      velocityY = (velocityY < -0.3)? -velocityY / 2 : 0;
      //The ground and the Ball have friction! Decrease speed
      velocityX *= 0.98;
    }

    //  When the ball reaches the edge of the display,
    //generate the next segment of the scene
    if(x > w - 1){
      generateTerrain();
      x = 0;
    }

    //Display the ball onscreen
    setPixel(x, y, 2);
  }
};

/* Main program */
int main(){

  //Fancy title screen
  //Generated from http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20
  cout << "\033c" <<
          " ___  ____  __  __  ____  __    ____     ___  _____  __    ____\n" <<
          "/ __)(_  _)(  \\/  )(  _ \\(  )  ( ___)   / __)(  _  )(  )  ( ___)\n" <<
          "\\__ \\ _)(_  )    (  )___/ )(__  )__)   ( (_-. )(_)(  )(__  )__)\n" <<
          "(___/(____)(_/\\/\\_)(__)  (____)(____)   \\___/(_____)(____)(__)  \n\n\n" <<
          "                        By Julian Triveri\n" <<
          "                            For CS173\n\n\n\n";

  //Create ball object
  Ball ball = Ball(0, 10);
  //Generate inital terrain
  generateTerrain();
  //Loop!
  while(true){
    //Get user input
    //if input is 0, exit the program
    if(ball.velocityX < 0.01){
      cout << "Enter stroke\n40-100 is a good range\n0 will exit the program\n>";
      cin >> strokeStrength;

      //Exit if user enters anything less than 1
      if(strokeStrength < 1){
        cout << "Goodbye golfer!" << endl;
        break;
      }

      //No unreasonable values!
      if(strokeStrength > 150)
        strokeStrength = 150;

      //Apply strike force
      ball.setVelocity(strokeStrength * 0.01, strokeStrength * 0.006);
    }

    //Update the ball for this frame
    ball.update();

    //Draw the whole scene and wait refreshRate nanoseconds until next
    drawScene();
  }

  return 0;
}
