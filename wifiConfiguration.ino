void wifiConnect(){
    wifiManager.autoConnect("Pet Feeder App", "petFeederDemo");
    Serial.println("Connected.....");
    delay(3000);
}

void wifiReset(){
    wifiManager.resetSettings();
    Serial.println("Resetting WiFi");
    delay(3000);
}
