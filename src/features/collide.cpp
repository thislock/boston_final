
#include "collide.h"

// dont mind old var names, didnt bother to change them
bool touching(
  int heart_x, 
  int heart_y, 
  int heart_width, 
  int heart_height, 

  int your_x,
  int your_y, 
  int your_width, 
  int your_height
) {
  bool final_num = false;

  // math for un-centering the middle rendered point
  heart_x -= heart_width/2;
  heart_y -= heart_height/2;

  your_x -= your_width/2;
  your_y -= your_height/2;

  if (
    // pos of the heart x is greater than your objects x
    heart_x > your_x && 
    // pos of heart x and your object's, is less than both with their widths added
    heart_x + heart_width < your_x + your_width &&

    // pos of the heart y is greater than your objects y
    heart_y > your_y && 
    // pos of heart x and your object's, is less than both with their heights added
    heart_y + heart_height < your_y + your_height
  ) {
    final_num = true;
  }

  return final_num;
}
