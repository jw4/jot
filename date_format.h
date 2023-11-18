#pragma once

#include <sys/types.h>

int format_date(time_t asOf, char *buf, size_t buf_len);
int format_time(time_t asOf, char *buf, size_t buf_len);
int format_time_iso8601(time_t asOf, char *buf, size_t buf_len);
