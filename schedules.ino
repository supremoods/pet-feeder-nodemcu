bool checkIsSched() {
  const char* path = "/schedules/api/isSched";
  const String isSched = callAPI(path);
  return isSched == "true";
}
