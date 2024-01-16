#include "c_hello.h"

#include "ruby/internal/eval.h"
#include "ruby/internal/symbol.h"

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

RUBY_FUNC_EXPORTED void Init_c_hello(void) {
  VALUE rb_mCHello = rb_define_module("CHello");
  rb_define_singleton_method(rb_mCHello, "hello", hello, -1);
  rb_define_singleton_method(rb_mCHello, "hello!", excited_hello, -1);
}
