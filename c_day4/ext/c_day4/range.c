#include "range.h"

#include <stdio.h>

void range_print(Range range) { printf("%d..=%d\n", range.start, range.end); }

bool range_full_overlap(Range self, Range other) {
  return (self.start <= other.start && self.end >= other.end) ||
         (other.start <= self.start && other.end >= self.end);
}

void ranges_parse_slow(const char* line, Range ranges[static 2]) {
  sscanf(line, "%d-%d,%d-%d", &ranges[0].start, &ranges[0].end,
         &ranges[1].start, &ranges[1].end);
}

void ranges_parse(const char* line, Range ranges[static 2]) {
  int i = 0;
  int digit = 0;
  int start = 0;
  int end = 0;

  while (*line != '\0') {
    while (*line >= '0' && *line <= '9') {
      digit = digit * 10 + (*line - '0');
      line++;
    }

    if (*line == '-') {
      start = digit;
    } else if (*line == ',' || *line == '\n') {
      end = digit;

      ranges[i++] = (Range){
          .start = start,
          .end = end,
      };
    }

    digit = 0;
    line++;
  }
}
