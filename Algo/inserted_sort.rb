A = [4, 6, 2, 1, 3, 5]

for j in 1..A.length
    key = A[j]
    i = j - 1
    
    while i >= 0 && i + 1 < A.length && A[i] > key
        A[i + 1] = A[i]
        i = i - 1
    end
    A[i + 1] = key
end

puts A