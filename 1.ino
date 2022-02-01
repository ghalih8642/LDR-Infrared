 
const int lampu1 =3; // inisialisasi pin LED
const int lampu2 =5 ;
const int lampu3 =6 ;
const int lampu4 =9 ;
const int lampu5 =10 ;
#define IR1 2 //inisialisasi infrared
#define IR2 4 
#define IR3 7 
#define IR4 8 
#define IR5 12 
#define LDR 11 //inisialisasi LDR
 
int lampu[5]; 
bool kondisiSensor[5]; 
bool malam = false; 
bool keadaanLampu[5]; 
int nilaiLampuSekarang[5]; 
int nilaiLampuTujuan[5]; 

void bacaLDR(){ //monitoring LDR
 int nilaiLDR = digitalRead(LDR); 
 Serial.print("ldr =");
 Serial.println(nilaiLDR);
 if(nilaiLDR > 0){malam = true;} // kondisi 1 = malam
 else {malam = false;} } 
 
void setLampu(){ //inisialisasi variabel utk perpindahan kondisi lampu  
 if(nilaiLampuTujuan[0] != nilaiLampuSekarang[0]){ 
 if (nilaiLampuTujuan[0] < nilaiLampuSekarang[0] ) {nilaiLampuSekarang[0]--
;}
 else{nilaiLampuSekarang[0]++;} 
 analogWrite(lampu[0],nilaiLampuSekarang[0]); 
 delay(100); } 
 if(nilaiLampuTujuan[1] != nilaiLampuSekarang[1]){ 
 if (nilaiLampuTujuan[1] < nilaiLampuSekarang[1] ) {nilaiLampuSekarang[1]--
;}
 else{nilaiLampuSekarang[1]++;} 
 analogWrite(lampu[1],nilaiLampuSekarang[1]); 
 delay(100); } 
 if(nilaiLampuTujuan[2] != nilaiLampuSekarang[2]){ 
 if (nilaiLampuTujuan[2] < nilaiLampuSekarang[2] ) {nilaiLampuSekarang[2]--
;}
 else{nilaiLampuSekarang[2]++;} 
 analogWrite(lampu[2],nilaiLampuSekarang[2]); 
 delay(100); } 
 
 if(nilaiLampuTujuan[3] != nilaiLampuSekarang[3]){ 
 if (nilaiLampuTujuan[3] < nilaiLampuSekarang[3] ) {nilaiLampuSekarang[3]--
;}
 else{nilaiLampuSekarang[3]++;} 
 analogWrite(lampu[3],nilaiLampuSekarang[3]); 
 delay(100); } 
 if(nilaiLampuTujuan[4] != nilaiLampuSekarang[4]){ 
 if (nilaiLampuTujuan[4] < nilaiLampuSekarang[4] ) {nilaiLampuSekarang[4]--
;}
 else{nilaiLampuSekarang[4]++;} 
 analogWrite(lampu[4],nilaiLampuSekarang[4]); 
 delay(100); }} 
 
void menentukanCahayaLampu(){ //menentukan nilai pwm jika infrared menteksi objek 
  Serial.print("pwm1= ");Serial.println(nilaiLampuTujuan[0]);
 Serial.print("pwm1= ");Serial.println(nilaiLampuTujuan[0]); 
 Serial.print("pwm2= ");Serial.println(nilaiLampuTujuan[1]);
 Serial.print("pwm3= ");Serial.println(nilaiLampuTujuan[2]);
 Serial.print("pwm4= ");Serial.println(nilaiLampuTujuan[3]);
 Serial.print("pwm5= ");Serial.println(nilaiLampuTujuan[4]);
 if(kondisiSensor[0] == LOW){nilaiLampuTujuan[0] = 255;} 
 else{ 
 nilaiLampuTujuan[0] = 2; } 
 
 if(kondisiSensor[0] == LOW || kondisiSensor[1] == LOW){ 
 nilaiLampuTujuan[1] = 255; } 
 else{ 
 nilaiLampuTujuan[1] = 2; } 
 
 if((kondisiSensor[0] == LOW || kondisiSensor[1] == LOW) || (kondisiSensor[1] 
== LOW || kondisiSensor[2] == LOW)){ 
 nilaiLampuTujuan[2] = 255; } 
 else { 
 nilaiLampuTujuan[2] = 2; } 
 
 if((kondisiSensor[1] == LOW || kondisiSensor[2] == LOW) || (kondisiSensor[2] 
== LOW || kondisiSensor[3] == LOW)){  
 nilaiLampuTujuan[3] = 255; } 
 else{ 
 nilaiLampuTujuan[3] = 2; } 
 
 if((kondisiSensor[2] == LOW || kondisiSensor[3] == LOW) || (kondisiSensor[3] 
== LOW || kondisiSensor[4] == LOW)){ 
 nilaiLampuTujuan[4] = 255; } 
 else{ 
 nilaiLampuTujuan[4] = 2; }} 
 
void deteksiMobil(){ //inisialisasi monitoring sensor infrared, jika 0 atau LOW ada objek jika 1 tidak ada objek
 kondisiSensor[0] = digitalRead(IR1);//membaca IR 1
 Serial.print("IR1= ");Serial.println(kondisiSensor[0]);// menampilkan di serial monitor
 kondisiSensor[1] = digitalRead(IR2);// membaca IR 2
 Serial.print("IR2= ");Serial.println(kondisiSensor[1]);// menampilkan di serial monitor
 kondisiSensor[2] = digitalRead(IR3);// membaca IR 3
 Serial.print("IR3= ");Serial.println(kondisiSensor[2]);// menampilkan di serial monitor
 kondisiSensor[3] = digitalRead(IR4); // membaca IR 4
 Serial.print("IR4= ");Serial.println(kondisiSensor[3]);// menampilkan di serial monitor
 kondisiSensor[4] = digitalRead(IR5); // membaca IR 5
 Serial.print("IR5= ");Serial.println(kondisiSensor[4]);// menampilkan di serial monitor
 Serial.println("");
 menentukanCahayaLampu(); 
 setLampu();} 
void setup() {
 Serial.begin(9600); 
 lampu[0] = lampu1; 
 lampu[1] = lampu2; 
 lampu[2] = lampu3; 
 lampu[3] = lampu4; 
 lampu[4] = lampu5; 
 pinMode(lampu1,OUTPUT); 
 pinMode(lampu2,OUTPUT); 
 pinMode(lampu3,OUTPUT); 
 pinMode(lampu4,OUTPUT); 
 pinMode(lampu5,OUTPUT); 
 pinMode(IR1,INPUT);  
 pinMode(IR2,INPUT); 
 pinMode(IR3,INPUT); 
 pinMode(IR4,INPUT); 
 pinMode(IR5,INPUT); 
 pinMode(LDR,INPUT); 
 for(int o = 0;o<2;o++){ // fungsi incremental jika ldr tidak menangkap cahaya maka led akan menyala dengan pwm 2 
 analogWrite(lampu1,o); // inisialisasi pwm sebagai o
 delay(30); 
 analogWrite(lampu2,o); 
 delay(30); 
 analogWrite(lampu3,o); 
 delay(30); 
 analogWrite(lampu4,o); 
 delay(30); 
 analogWrite(lampu5,o); 
 delay(30); } 
 for(int u = 0;u<5;u++){ 
 nilaiLampuSekarang[u] = 2; }} 
 
void loop() {  
 bacaLDR(); 
 if(malam == true){ // jika waktu malam sensor infrared akan bekerja 
 deteksiMobil(); } 
 else 
 { 
 for(int u = 0;u<5;u++){ 
 analogWrite(lampu[u],0); 
 delay(100); 
 nilaiLampuSekarang[u] = 0; }
 }
} 
// Serial.println("Matikan semua lampu"); } }} 
