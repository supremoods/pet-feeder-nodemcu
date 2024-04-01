void loop(){
  updateStatus();
  if(checkIsSched()){
   Serial.println("Dispensing...."); 
   myservo.write(150); 
   delay(getDuration());
   myservo.write(92); 
  }
  delay(500);
}
