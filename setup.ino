
void setup(){
    Serial.begin(115200);
    
    wifiConnect();
    while (WiFi.status() != WL_CONNECTED){
        delay(100);
    }

    Serial.println("WiFi connected");
    myservo.attach(2); //
    timeClient.begin();
    timeClient.setTimeOffset(28800); // Set the time offset to GMT+8 (28800 seconds)
}
