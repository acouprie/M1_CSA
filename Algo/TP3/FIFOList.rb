#!/usr/bin/ruby

class FIFOList
  attr_reader :size, :arr

  def self.[](*values)
    obj = self.new(values.size)
    obj.arr = values
    obj
  end

  def initialize(size)
    @size = size
    @arr  = Array.new
  end

  def push(element)
    arr.push(element)
    arr.shift if arr.length > size
    arr
  end

  def include?(element)
    arr.include?(element)
  end
end