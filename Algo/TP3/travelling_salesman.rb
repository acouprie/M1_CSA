#!/usr/bin/ruby

require './FIFOList.rb'

MAX_MOVES = 150
K = 150

input_file = ARGV[0]
error_message = "File " + input_file + " does not exist"
raise(error_message) unless File::exists?(input_file)

lines = IO.readlines(input_file)
@n = lines.first.to_i
lines.delete_at(0)
cities = []
lines.each do |line|
    cities << line.split(" ").map(&:to_i)[1..2]
end
p cities

argv_1 = ARGV[1]
solution = argv_1.split(",").map(&:to_i) unless argv_1.nil?
solution ||= [5, 3, 4, 1, 2]
solution = Array.new(@n) { |i| i + 1 }.shuffle if argv_1.nil?
puts "X:" 
p solution
solution.map! { |element| element - 1 }

def compute_distance(cities, solution)
    result = 0
    result += Math.sqrt((0 - cities[solution.first].first)**2 + (0 - cities[solution.first].last)**2)
    for i in 0..cities.size - 2
        j = i+1 > 4 ? 0 : i+1
        result += Math.sqrt((cities[solution[i]].first - cities[solution[j]].first)**2 + (cities[solution[i]].last - cities[solution[j]].last)**2)
    end
    result += Math.sqrt((cities[solution.last].first - 0)**2 + (cities[solution.last].last - 0)**2)
    result
end

def best_neighbour(cities, solution)
    best_solution = solution.dup
    test_sol = solution.dup
    best_distance = compute_distance(cities, solution)
    j = 0
    k = 0
    for x in 0..@n - 1
        for i in k..3
            temp = test_sol[j]
            test_sol[j] = test_sol[i+1]
            test_sol[i+1] = temp
            distance = compute_distance(cities, test_sol)
            if best_distance > distance
                best_distance = distance
                best_solution = test_sol.dup
            end
            #p test_sol.map { |element| element + 1 }
            temp = test_sol[j]
            test_sol[j] = test_sol[i+1]
            test_sol[i+1] = temp
        end
        k += 1
        j += 1
    end
    return best_distance, best_solution
end

def steepest_hill_climbing(cities, solution)
    nb_moves = 0
    stop = false
    s = compute_distance(cities, solution)
    begin
        s_prime, solution = best_neighbour(cities, solution)
        if s_prime < s
            s = s_prime
            best_solution = solution.dup
        else
            stop = true
        end
        nb_moves += 1
    end until nb_moves == MAX_MOVES || stop
    return s, best_solution
end

def non_tabu_neighbour(solution, tabu)
    sol = []
    test_sol = solution.dup
    j = 0
    k = 0
    for x in 0..@n - 1
        for i in k..3
            temp = test_sol[j]
            test_sol[j] = test_sol[i+1]
            test_sol[i+1] = temp
            unless tabu.include?(test_sol)
                sol << test_sol.dup
            end
            #p test_sol.map { |element| element + 1 }
            temp = test_sol[j]
            test_sol[j] = test_sol[i+1]
            test_sol[i+1] = temp
        end
        k += 1
        j += 1
    end
    sol
end

def best_non_tabu_neigbour(cities, solutions)
    s_prime = 0
    solution = []
    solutions.each do |element|
        ubqp = compute_distance(cities, element)
        if s_prime < ubqp
            s_prime = ubqp
            solution = element
        end
    end
    return s_prime, solution
end

def tabu(cities, x)
    nb_moves = 0
    stop = false
    s = compute_distance(cities, x)
    best_ubqp = s.dup
    tabu = FIFOList.new(K)
    solution = x.dup
    best_solution = x.dup
    begin
        solutions = non_tabu_neighbour(solution, tabu)
        unless solutions.empty?
            ubqp, solution = best_non_tabu_neigbour(cities, solutions)
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

puts "Distance of X"
p compute_distance(cities, solution)

puts "Best neighbour"
distance, sol = best_neighbour(cities, solution)
p distance
p sol.map { |element| element + 1 }

puts "SHC"
distance, sol = steepest_hill_climbing(cities, solution)
p distance
p sol.map { |element| element + 1 } unless sol.nil?

puts "Tabu"
distance, sol = tabu(cities, solution)
p distance
p sol.map { |element| element + 1 } unless sol.nil?