#ifndef COLLIDE_H
#define COLLIDE_H

// if object 1 is colliding with object 2
bool touching(
  int object1_x, 
  int object1_y, 
  int object1_width, 
  int object1_height, 

  int object2_x,
  int object2_y, 
  int object2_width, 
  int object2_height
);

#endif // COLLIDE_H