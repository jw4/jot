#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int format_date(time_t asOf, char *buf, size_t buf_len) {
  struct tm tm = *localtime(&asOf);
  snprintf(buf, 32, "%04d-%02d-%02d", 1900 + tm.tm_year, tm.tm_mon, tm.tm_mday);
  return 0;
}

int format_time(time_t asOf, char *buf, size_t buf_len) {
  struct tm tm = *localtime(&asOf);
  snprintf(buf, 32, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
  return 0;
}

int format_time_iso8601(time_t asOf, char *buf, size_t buf_len) {
  struct tm tm = *localtime(&asOf);

  char sign = tm.tm_gmtoff >= 0 ? '+' : '-';
  int tzhr = abs((int)tm.tm_gmtoff / 3600);
  int tzmin = (tm.tm_gmtoff % 3600) / 60;

  snprintf(buf, 32, "%02d-%02d-%02dT%02d:%02d:%02d%c%02d:%02d",
           1900 + tm.tm_year, tm.tm_mon, tm.tm_mday, tm.tm_hour, tm.tm_min,
           tm.tm_sec, sign, tzhr, tzmin);

  return 0;
}
