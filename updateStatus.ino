void updateStatus() {
  const char* path = "/deviceStatus/api/updateStatus";
  const String status = callAPI(path);
  Serial.println(status); 
}
