import processing.serial.*;
//import processing.font.*;

Serial port;

void setup() {
  
  size(300,300);
  
  println("Hey There!");
  println("Hit Left or Right Key to Move your motor!g");
  
  println(Serial.list());
  
  port = new Serial(this, Serial.list()[0], 9600);
}

void draw()
{
if( keyPressed) {
    if(key == CODED) 
    {
      if (key == LEFT && key != RIGHT) {
        port.write('L');
      }
      
      if (key == RIGHT && key != LEFT) {
        port.write('R');
      }
      
    }    
}
else {
        port.write(0);
        println("CLEAR");
      }
}
  
