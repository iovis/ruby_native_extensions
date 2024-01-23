#include "c_hello.h"

static VALUE hello(int argc, VALUE* argv, VALUE self) {
  VALUE name;
  rb_scan_args(argc, argv, "01", &name);
  if (NIL_P(name)) name = rb_str_new_cstr("World");

  return rb_sprintf("Hello, %" PRIsVALUE, name);
}

static VALUE excited_hello(int argc, VALUE* argv, VALUE self) {
  VALUE string = hello(argc, argv, self);
  rb_funcall(string, rb_intern("upcase!"), 0);

  return rb_sprintf("%" PRIsVALUE "!", string);
}

static uint64_t fib(uint64_t n) {
  if (n < 2) return n;

  return fib(n - 1) + fib(n - 2);
}

static VALUE rb_fFib(VALUE self, VALUE n) {
  uint64_t num = FIX2LONG(n);
  uint64_t result = fib(num);

  return LONG2FIX(result);
}

RUBY_FUNC_EXPORTED void Init_c_hello(void) {
  VALUE rb_mCHello = rb_define_module("CHello");
  rb_define_singleton_method(rb_mCHello, "hello", hello, -1);
  rb_define_singleton_method(rb_mCHello, "hello!", excited_hello, -1);
  rb_define_singleton_method(rb_mCHello, "fib", rb_fFib, 1);
}
