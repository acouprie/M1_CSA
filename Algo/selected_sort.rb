A = [4, 6, 2, 1, 3, 5]
B = []

while !A.empty?
    key = A.min
    B << key
    A.delete(A.min)
end

puts B
