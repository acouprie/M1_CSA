#!/usr/bin/ruby
require './FIFOList.rb'

MAX_MOVES = 200
K = 200

input_file = ARGV[0]
error_message = "File " + input_file + " does not exist"
raise(error_message) unless File::exists?(input_file)

partition = IO.readlines(input_file)[0].split(" ").map(&:to_i)
n = partition.first
partition.delete_at(0)
@number_p = partition.first
partition.delete_at(0)

argv_1 = ARGV[1]
x = argv_1.split(",").map(&:to_i) unless argv_1.nil?
x ||= Array.new(n) { rand(2) }
puts "X:" 
p x

def compute_ubqp(partition, x, n)
    result = 0
    row = -1
    partition.each_with_index do |number, i|
        modulo_i = i % x.size
        row += 1 if modulo_i == 0
        # safety check
        row = n if row > n
        result += number * x[row] * x[modulo_i]
    end
    result
end

def best_neighbour(partition, x, n)
    ubqp = 0
    solution = []
    x.each_with_index { |digit, index|
        new_digit = digit == 1 ? 0 : 1
        x[index] = new_digit
        if ubqp > compute_ubqp(partition, x, n)
        #if x.inject(:+) > @number_p && ubqp > compute_ubqp(partition, x, n)
            ubqp = compute_ubqp(partition, x, n)
            solution = x.dup
        end
        x[index] = digit
    }
    #puts "no best_neighbour" if ubqp == 0 && solution.empty?
    return ubqp, solution
end

def steepest_hill_climbing(partition, x, n)
    nb_moves = 0
    stop = false
    best_ubqp = compute_ubqp(partition, x, n)
    begin
        s_prime, solution = best_neighbour(partition, x, n)
        if s_prime < best_ubqp
            best_ubqp = s_prime
            best_solution = solution
        else
            stop = true
        end
        nb_moves += 1
    end until nb_moves == MAX_MOVES || stop
    return best_ubqp, best_solution
end

def random_start_steepest_hill_climbing(partition, n)
    best_ubqp = 0
    best_solution = []
    for i in 0..MAX_MOVES
        x_bis = Array.new(n) { rand(2) }
        ubqp, solution = steepest_hill_climbing(partition, x_bis, n)
        if ubqp < best_ubqp
            best_ubqp = ubqp
            best_solution = solution.dup
        end
    end
    return best_ubqp, best_solution
end

def non_tabu_neighbour(x, tabu)
    solution = []
    x.each_with_index { |digit, index|
        new_digit = digit == 1 ? 0 : 1
        x[index] = new_digit
        unless tabu.include?(x)
            solution << x.dup
        end
        x[index] = digit
    }
    solution
end

def best_non_tabu_neigbour(partition, solutions, n)
    s_prime = 0
    solution = []
    solutions.each do |element|
        ubqp = compute_ubqp(partition, element, n)
        if s_prime > ubqp
            s_prime = ubqp 
            solution = element
        end
    end
    return s_prime, solution
end

def tabu(partition, x, n)
    nb_moves = 0
    stop = false
    s = compute_ubqp(partition, x, n)
    best_ubqp = s.dup
    tabu = FIFOList.new(K)
    solution = x.dup
    best_solution = x.dup
    begin
        solutions = non_tabu_neighbour(solution, tabu)
        unless solutions.empty?
            ubqp, solution = best_non_tabu_neigbour(partition, solutions, n)
        else
            stop = true
        end
        tabu.push(solution.dup)
        if ubqp < best_ubqp
            best_ubqp = ubqp
            best_solution = solution.dup
        end
        s = ubqp
        nb_moves += 1
    end until nb_moves == MAX_MOVES || stop
    return best_ubqp, best_solution
end

puts "Solution with X:"
p compute_ubqp(partition, x, n)

puts "Best neighbour of X:"
ubqp, solution = best_neighbour(partition, x, n)
p ubqp
p solution

puts "Steepest hill climbing"
ubqp, solution = steepest_hill_climbing(partition, x, n)
p ubqp
p solution

puts "Random SHC"
ubqp, solution = random_start_steepest_hill_climbing(partition, n)
p ubqp
p solution

puts "Tabu:"
ubqp, solution = tabu(partition, x, n)
p ubqp
p solution