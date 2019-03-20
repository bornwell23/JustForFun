int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int black[3] = {0, 0, 0};
int red[3] = {100, 0, 0};
int green[3] = {0, 100, 0};
int blue[3] = {0, 0, 100};
int yellow[3] = {40, 95, 0};
int orange[3] = {100, 25, 0};
int purple[3] = {50, 0, 50};

int redVal = black[0];
int greenVal = black[1]; 
int blueVal = black[2];

int wait = 10;

int prevR = redVal;
int prevG = greenVal;
int prevB = blueVal;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);   
  pinMode(bluePin, OUTPUT); 
}

void loop(){
  crossFade(red);
  crossFade(purple);
  crossFade(blue);
  crossFade(green);
  crossFade(yellow);
  crossFade(orange);
}

int calculateStep(int prevValue, int endValue){
  int step = endValue-prevValue;
  if(step){
    step = 1020/step;
  }
  return step;
}

int calculateVal(int step, int val, int i){
  if(step&&i%step==0){
    if(step>0){
      val += 1;           
    } 
    else if(step<0){
      val -= 1;
    } 
  }
  if(val>255){
    val = 255;
  } 
  else if(val<0){
    val = 0;
  }
  return val;
}

void crossFade(int color[3]){
  int R = (color[0]*255)/100;
  int G = (color[1]*255)/100;
  int B = (color[2]*255)/100;
  int stepR = calculateStep(prevR, R);
  int stepG = calculateStep(prevG, G); 
  int stepB = calculateStep(prevB, B);
  for(int i=0;i<=1020;i++){
    redVal = calculateVal(stepR, redVal, i);
    greenVal = calculateVal(stepG, greenVal, i);
    blueVal = calculateVal(stepB, blueVal, i);
    analogWrite(redPin, redVal);
    analogWrite(greenPin, greenVal);
    analogWrite(bluePin, blueVal);
    delay(wait);
  }
  prevR = redVal; 
  prevG = greenVal; 
  prevB = blueVal;
}
