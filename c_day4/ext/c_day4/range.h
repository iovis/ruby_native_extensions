#include <stdbool.h>

typedef struct {
  int start;
  int end;
} Range;

void range_print(Range range);
bool range_full_overlap(Range self, Range other);
void ranges_parse_slow(const char* line, Range ranges[static 2]);
void ranges_parse(const char* line, Range ranges[static 2]);
