
#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
#define USE_ARDUINO_INTERRUPTS false
#include <PulseSensorPlayground.h>
#include <DHT.h>

DHT dht;

const char* ssid = "bali";   // Your Network SSID
const char* password = "bali301dada";       // Your Network Password

const int PulseWire = A0;
const int LED2 = 2;
int led = D5;
int buzzer = D6;
int Threshold = 550;


WiFiClient client;

unsigned long myChannelNumber = 1880412; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "ZRJJB5ZFAHALY193"; //Your Write API Key

PulseSensorPlayground pulseSensor;

void setup()
{
  Serial.begin(9600);
  delay(5000);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
  dht.setup(D1);
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED2);
  pulseSensor.setThreshold(Threshold);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  if(pulseSensor.begin()){
    Serial.println("We created a pulseSensor Object!");
  }
  Serial.println("Status\tHumidy\tTemperature(C)\t(F)\tPulse");
}

void bpm(){
  pulseSensor.sawNewSample();
  int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
  if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened".
    Serial.println("♥  A HeartBeat Happened ! ");
    Serial.print("BPM: ");                        
    Serial.println(myBPM);   
    float humidity = dht.getHumidity();
    float temperature = dht.getTemperature();
    Serial.print(dht.getStatusString());
    Serial.print("\t");
    Serial.print(humidity, 1);
    Serial.print("\t\t");
    Serial.print(temperature, 1);
    Serial.print("\t\t");
    float fr = dht.toFahrenheit(temperature);
    Serial.println(fr);
    if (myBPM > 100){
      digitalWrite(led,HIGH);
      tone(buzzer,1000);
    }
    else if(myBPM < 60){
      digitalWrite(led,HIGH);
      tone(buzzer,1000);
    }
    else{
      digitalWrite(led,LOW);
      tone(buzzer,0);
    }
    ThingSpeak.setField(1, fr);
    ThingSpeak.setField(2, myBPM);
    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    
  }
  delay(20);
  
}

void loop() {
bpm();
}
