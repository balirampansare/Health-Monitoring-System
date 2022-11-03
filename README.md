<h1 align="center">Health Monitoring System</h1>

<h5 align="center"><b>ARDUINO IDE | NODE MCU | THINGSPEAK | MATLAB ANALYSIS |</b></h5>
<br>
<p align="center">
<img src="https://img.shields.io/badge/Arduino_IDE-00979D?style=for-the-badge&logo=arduino&logoColor=white" />
</p>

<p  align="justify">
Health Monitoring System will record the patient’s heart beat rate and body temperature and the data is send to Thingspeak channel. With the help of MATLAB analysis and TimeControl email is send after every 5 min, mentioning the BPM condition of the patient. If the BPM of the patient goes below or abobe certain threshold then LED glows and buzzer also start to buzz.
</p>

---

### **HARDWARE & SOFTWARE REQUIREMENTS** ###

Hardware                     | Software
---------------------------- | -------------
Node MCU & Power Cable       | Arduino Software IDE
Pulse rate sensor            | Thingspeak 
DHT11 Temperature Sensor     | MATLAB Analysis
420 ohm resistor             | TimeControl
Jumper wires                 |
Breadboard                   |
LED                          |
Buzzer                       |

---
### **BLOCK DIAGRAM** ###

![block diagram](/images/blockdiagram.png)

---

### **CIRCUIT DIAGRAM AND CONNECTIONS** ###
![cirucit diagram](/images/circuitdiagram.png)

- Signal pin of pulse sensor -> A0 of  Node MCU
- Vcc pin of pulse sensor -> 3.3V
- GND pin of pulse sensor -> GND

- Signal pin of DHT11 -> D1 of Node MCU
- Vcc pin of pulse sensor -> 3.3V 
- GND pin DTH11 sensor -> GND

- +ve pin of LED -> D5 of Node MCU
- +ve pin of Buzzer -> D6 of Node MCU

- ve pin of  LED & Buzzer -> GND

---
### **Working** ###

1. Setting up all the connections code uploading / Configuring Thingspeak channel
2. Pulse rate and temperature sensor will continously monitor the patients pulse rate and temperature
3. The monitored vlaues will be sent to thingspeak , where it will continously analysed
4. MATLAB analysis will analysed the channel reading, for sending email as alert
5. Timecontrol will send email after every 5 minutes in collaboration with MATLAB analysis
6. LED will glow and buzzer will buzz if the Pulse rate goes below/above threshold value
---
### **CODE** ###


**Arduino IDE File**
1. [Code file](https://github.com/balirampansare/Health-Monitoring-System/blob/main/patientmonitoring.ino)

2. Matlab analysis and time control is in thingspeak 
![MATLAB Analysis](/images/matlabanalysis.PNG)
    [MATLAB Code](https://github.com/balirampansare/Health-Monitoring-System/blob/main/matlabanalysis.txt)

3. OUTPUT
    ![output](/images/output.PNG)