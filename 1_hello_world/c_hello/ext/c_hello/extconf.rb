# frozen_string_literal: true

require "mkmf"

# Makes all symbols private by default to avoid unintended conflict
# with other gems. To explicitly export symbols you can use RUBY_FUNC_EXPORTED
# selectively, or entirely remove this flag.
append_cflags("-fvisibility=hidden")
append_cflags("-std=c2x")
append_cflags("-Wall")
append_cflags("-Wextra")

create_makefile("c_hello/c_hello")
