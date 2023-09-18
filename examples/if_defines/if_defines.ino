void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
#if defined(ARDUINO)  
  Serial.println("Your company is defined as ARDUINO");
#endif

#if defined(YOUR_BOARD1)    
  Serial.println("Your company is defined as YOUR_BOARD1");
#endif

  Serial.println("Companies Done!");
  Serial.println("");


#if defined(ARDUINO_ARDUINO_NANO33BLE)   ||  defined (YOUR_BOARD1) 
  Serial.println("Your board is defined as ARDUINO_ARDUINO_NANO33BLE");
#endif

#if defined(ARDUINO_PORTENTA_H7_M7)   ||  defined (YOUR_BOARD1) 
  Serial.println("Your board is defined as ARDUINO_PORTENTA_H7_M7");
#endif

#if defined(CORE_CM7)   ||  defined (YOUR_BOARD1) 
  Serial.println("Your board is defined as CORE_CM7");
#endif

#if defined(ARDUINO_NICLA_VISION)   ||  defined (YOUR_BOARD1) 
  Serial.println("Your board is defined as ARDUINO_NICLA_VISION");
#endif

#if defined(SEEED_XIAO_M0)   ||  defined (YOUR_BOARD1) 
  Serial.println("Your board is defined as SEEED_XIAO_M0");
#endif

#if defined(YOUR_BOARD1)  
  Serial.println("Your board is defined as YOUR_BOARD1");
#endif

  Serial.println("Boards Done");
  Serial.println("---------------------");
  delay(1000);

}
