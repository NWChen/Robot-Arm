import processing.serial.*;
//import processing.font.*;

Serial port;

void setup() {
  
  size(300,300);
  
  println("active go ahead");
  
  println(Serial.list());
  
  port = new Serial(this, Serial.list()[0], 9600);
}

void draw()
{
if( keyPressed) {
    if(key == CODED) 
    {
      if (keyCode == LEFT && keyCode != RIGHT) {
        port.write('L');
        println("L");
      }
      
      if (keyCode == RIGHT && keyCode != LEFT) {
        port.write('R');
        println("R");
      }
      
      if (keyCode == UP && keyCode != DOWN){
        port.write('U');
        println("U");
      }
      
      if(keyCode == DOWN && keyCode != UP){
        port.write('D');
        println("D");
      }

    }

    else{
      if(key == 'w' && key != 'q'){
        port.write('W');
        println("W");
      }
      
      if(key == 'q' && key != 'w'){
        port.write('Q');
        println("Q");
      }
      
      if(key == 'a' && key != 's'){
        port.write('A');
        println("A");
      }
      
      if(key == 's' && key != 'a'){
        port.write('S');
        println("S");
      }
    }    
}
else {
        port.write(0);
      }
}
  
