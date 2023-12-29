#include "c_day4.h"

typedef struct Range {
  int start;
  int end;
} Range;

void range_print(Range range) { printf("%d..=%d\n", range.start, range.end); }

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

bool range_full_overlap(Range self, Range other) {
  return (self.start <= other.start && self.end >= other.end) ||
         (other.start <= self.start && other.end >= self.end);
}

long p1_slow(size_t n, const char input[static n]) {
  long count = 0;
  Range ranges[2] = {0};

  char line[32] = {0};
  size_t li = 0;

  for (size_t i = 0; i < n; i++) {
    line[li++] = input[i];

    if (input[i] == '\n') {
      line[li] = '\0';
      li = 0;

      ranges_parse_slow(line, ranges);

      if (range_full_overlap(ranges[0], ranges[1])) {
        count++;
      }
    }
  }

  return count;
}

VALUE run_slow(VALUE self, VALUE input) {
  Check_Type(input, T_STRING);

  size_t length = RSTRING_LEN(input);
  char* cstr_input = StringValuePtr(input);

  long solution = p1_slow(length, cstr_input);

  return LONG2FIX(solution);
}

long p1(size_t n, const char input[static n]) {
  long count = 0;
  Range ranges[2] = {0};

  char line[32] = {0};
  size_t li = 0;

  for (size_t i = 0; i < n; i++) {
    line[li++] = input[i];

    if (input[i] == '\n') {
      line[li] = '\0';
      li = 0;

      // printf("%s", line);
      ranges_parse(line, ranges);
      // range_print(ranges[0]);
      // range_print(ranges[1]);

      if (range_full_overlap(ranges[0], ranges[1])) {
        count++;
      }
    }
  }

  return count;
}

VALUE run(VALUE self, VALUE input) {
  Check_Type(input, T_STRING);

  size_t length = RSTRING_LEN(input);
  char* cstr_input = StringValuePtr(input);

  long solution = p1(length, cstr_input);

  return LONG2FIX(solution);
}

RUBY_FUNC_EXPORTED void Init_c_day4(void) {
  VALUE rb_mCDay4 = rb_define_module("CDay4");
  rb_define_singleton_method(rb_mCDay4, "c_run", run, 1);
  rb_define_singleton_method(rb_mCDay4, "c_run_slow", run_slow, 1);
}
