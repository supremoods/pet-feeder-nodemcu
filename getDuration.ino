int getDuration() {
  const char* path = "/configurations/api/getDuration";
  const String duration = callAPI(path);
  return duration.toInt();
}
