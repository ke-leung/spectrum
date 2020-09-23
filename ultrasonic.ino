#define echoPin 7
#define trigPin 8
#define ledRed 9
#define ledGreen 10
#define ledBlue 11

long duration;
long distance;
int prevDist = 0;
unsigned char redWrite = 0;
unsigned char greenWrite = 0;
unsigned char blueWrite = 0;
bool farther;

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  }

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration/58.2000;
  farther = distance > prevDist;

  Serial.println(distance);

  if (distance <= 5){
    redWrite = 170;
    blueWrite = 100;
    greenWrite = 200;
  }
  
  else if (distance == prevDist){}
  
  else if (distance == 15){
    redWrite = 220;
    blueWrite = 80;
    greenWrite = 180;
  }

    else if (distance == 25){
    redWrite = 180;
    blueWrite = 150;
    greenWrite = 80;
  }

  else if (distance == 35){
    redWrite = 100;
    blueWrite = 80;
    greenWrite = 60;
  }

    else if (distance == 45){
    redWrite = 60;
    blueWrite = 70;
    greenWrite = 40;
  }

    else if (distance == 55){
    redWrite = 50;
    blueWrite = 50;
    greenWrite = 50;
  }

//turn blue
  else if (distance <= 15){
    if (farther){
     redWrite += 5;
     blueWrite -= 2;
     greenWrite -= 2;
    }

    else {
     redWrite -= 5;
     blueWrite += 2;
     greenWrite += 2;
    }
  }

//turn green
  else if (distance <= 30){
    if (farther){
     redWrite -= 4;
     blueWrite += 7;
     greenWrite -= 10;
    }
    
    else {
     redWrite += 4;
     blueWrite -= 7;
     greenWrite += 10;
    }
  }

//turn yeller
  else if (distance <= 35){
    if (farther){
     redWrite -= 8;
     blueWrite -= 7;
     greenWrite -= 2;
    }
    
    else {
     redWrite += 8;
     blueWrite += 7;
     greenWrite += 2;
    }
  }
  
//turn organge
  else if (distance <= 45){
    if (farther){
     redWrite -= 4;
     blueWrite--;
     greenWrite -= 2;
    }
    
    else {
     redWrite += 4;
     blueWrite++;
     greenWrite += 2;
    }
  }

//turn red
  else if (distance <= 55){
   if (farther){
     redWrite--;
     blueWrite -= 2;
     greenWrite++;
    }
    
    else {
     redWrite++;
     blueWrite += 2;
     greenWrite--;
    }
  }
Serial.print(redWrite);
Serial.print(blueWrite);
Serial.println(greenWrite);

    analogWrite(ledRed, redWrite);
    analogWrite(ledBlue, blueWrite);
    analogWrite(ledGreen, greenWrite);
  prevDist = distance;
  delay(10);
}
