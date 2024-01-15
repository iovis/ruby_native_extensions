#include "c_day4.h"

static long p1_slow(size_t n, const char input[static n]) {
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

static VALUE run_slow(VALUE self, VALUE input) {
  Check_Type(input, T_STRING);

  size_t length = RSTRING_LEN(input);
  char* cstr_input = StringValuePtr(input);

  long solution = p1_slow(length, cstr_input);

  return LONG2FIX(solution);
}

static long p1(size_t n, const char input[static n]) {
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

static VALUE run(VALUE self, VALUE input) {
  Check_Type(input, T_STRING);

  size_t length = RSTRING_LEN(input);
  char* cstr_input = RSTRING_PTR(input);

  long solution = p1(length, cstr_input);

  return LONG2FIX(solution);
}

RUBY_FUNC_EXPORTED void Init_c_day4(void) {
  VALUE rb_mCDay4 = rb_define_module("CDay4");
  rb_define_singleton_method(rb_mCDay4, "c_run", run, 1);
  rb_define_singleton_method(rb_mCDay4, "c_run_slow", run_slow, 1);
}
