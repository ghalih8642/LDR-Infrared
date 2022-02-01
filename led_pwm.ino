const int lampu1 = 3; 
const int lampu2 = 5 ;
const int lampu3 = 6 ;
const int lampu4 = 9 ;
const int lampu5 = 10 ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lampu1,OUTPUT); 
  pinMode(lampu2,OUTPUT); 
  pinMode(lampu3,OUTPUT); 
  pinMode(lampu4,OUTPUT); 
  pinMode(lampu5,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
 analogWrite(lampu1,2); 
 analogWrite(lampu2,16); 
 analogWrite(lampu3,32); 
 analogWrite(lampu4,64); 
 analogWrite(lampu5,127); 
 delay(2000);
//  analogWrite(lampu1,0); 
// analogWrite(lampu2,0); 
// analogWrite(lampu3,0); 
// analogWrite(lampu4,0); 
// analogWrite(lampu5,0); 

}
