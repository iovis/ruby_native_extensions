# frozen_string_literal: true

require_relative "c_day4/version"
require_relative "c_day4/c_day4"

# shut up
module RangeExt
  refine Range do
    def full_overlap?(other)
      (first <= other.first && last >= other.last) || (other.first <= first && other.last >= last)
    end
  end
end

# Shut up rubocop
module CDay4
  using RangeExt

  def self.run(input)
    input
      .lines
      .map { _1.split(",") }
      .map { |ranges| ranges.map { parse _1 } }
      .filter { |a, b| a.full_overlap? b }
      .count
  end

  # @param range [String]
  # @return [Range]
  def self.parse(range)
    range.scan(/(\d+)-(\d+)/) do |s, e|
      return s.to_i..e.to_i
    end
  end
end
