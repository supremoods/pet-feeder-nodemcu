String callAPI(const char* path) {
  std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);
  client->setFingerprint(fingerprint_onrender_com);

  HTTPClient https;
  Serial.print("[HTTPS] begin...\n");

  String response; // Variable to hold the response

  if (https.begin(*client, pet_feeder_host, pet_feeder_port, path, true)) {  // HTTPS
    Serial.print("[HTTPS] GET...\n");
    int httpCode = https.GET();

    if (httpCode > 0) {
      Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        response = https.getString(); // Store the response
        Serial.println(response);
      }
    } else {
      Serial.printf("[HTTPS] GET... code: %d\n", httpCode);
      String error = https.errorToString(httpCode);
      Serial.printf("[HTTPS] GET... failed, error: %s\n", error.c_str());
      response = "[HTTPS]" + String(httpCode) + " GET... failed, error: " + error ;
    }
    https.end();
  } else {
    Serial.printf("[HTTPS] Unable to connect\n");
    response = "[HTTPS] Unable to connect";
  }

  return response; // Return the response
}
