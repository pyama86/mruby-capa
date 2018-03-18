##
## Capacity Test
##

assert("String#capacity") do
  t = "a" * 1
  assert_equal(23, t.capacity)
  t = "a" * 24
  assert_equal(24, t.capacity)
end

assert("String#capacity=") do
  t = "a" * 1
  assert_equal(23, t.capacity)
  t.capacity = 100
  assert_equal(100, t.capacity)
end

assert("Array#capacity") do
  t = []
  assert_equal(1, t.capacity)
  10.times do |n|
    t << n
  end
  assert_equal(16, t.capacity)
end

assert("Array#capacity=") do
  t = []
  t.capacity = 100
  assert_equal(128, t.capacity)
end
