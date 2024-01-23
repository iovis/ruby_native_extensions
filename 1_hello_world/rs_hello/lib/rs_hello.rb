# frozen_string_literal: true

require_relative "rs_hello/version"
require_relative "rs_hello/rs_hello"

module RsHello
  def self.rb_fib(n)
    return n if n < 2

    rb_fib(n - 1) + rb_fib(n - 2)
  end
end
