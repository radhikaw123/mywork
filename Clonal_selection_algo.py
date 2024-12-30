import numpy as np
import random

# Define the objective function to optimize (we want f(x) close to target)
def objective_function(x, a, b, target):
    return abs(a * x + b - target)

# Initialize the population of antibodies (solutions)
def initialize_population(pop_size, bounds):
    return [random.uniform(bounds[0], bounds[1]) for _ in range(pop_size)]

# Calculate the affinity of each antibody (fitness)
def calculate_affinity(antibody, a, b, target):
    return objective_function(antibody, a, b, target)

# Select the best antibodies based on their affinity
def select_top_antibodies(population, affinities, num_select):
    selected_indices = np.argsort(affinities)[:num_select]
    return [population[i] for i in selected_indices]

# Clone the selected antibodies
def clone_antibodies(selected_antibodies, num_clones):
    return [antibody for antibody in selected_antibodies for _ in range(num_clones)]

# Mutate the cloned antibodies
def mutate_clones(clones, mutation_rate, bounds):
    mutated_clones = []
    for clone in clones:
        if random.random() < mutation_rate:
            mutation = random.uniform(-1, 1) * (bounds[1] - bounds[0]) * 0.1  # Small mutation
            mutated_clone = clone + mutation
            mutated_clone = np.clip(mutated_clone, bounds[0], bounds[1])  # Keep within bounds
            mutated_clones.append(mutated_clone)
        else:
            mutated_clones.append(clone)
    return mutated_clones

# Replace the worst antibodies in the population
def replace_worst_antibodies(population, affinities, new_antibodies):
    worst_indices = np.argsort(affinities)[-len(new_antibodies):]
    for i, index in enumerate(worst_indices):
        population[index] = new_antibodies[i]
    return population

# Main Clonal Selection Algorithm
def clonal_selection_algorithm(pop_size, num_generations, num_select, num_clones, mutation_rate, bounds, a, b, target):
    # Step 1: Initialization
    population = initialize_population(pop_size, bounds)

    for generation in range(num_generations):
        # Step 2: Calculate affinity
        affinities = [calculate_affinity(antibody, a, b, target) for antibody in population]

        # Step 3: Select top antibodies
        selected_antibodies = select_top_antibodies(population, affinities, num_select)

        # Step 4: Clone selected antibodies
        clones = clone_antibodies(selected_antibodies, num_clones)

        # Step 5: Mutate clones
        mutated_clones = mutate_clones(clones, mutation_rate, bounds)

        # Step 6: Replace worst antibodies
        population = replace_worst_antibodies(population, affinities, mutated_clones)

        # Optionally print progress
        best_affinity = min([calculate_affinity(antibody, a, b, target) for antibody in population])
        print(f"Generation {generation + 1}: Best Affinity = {best_affinity}")

    # Step 7: Return the best solution found
    best_solution = min(population, key=lambda x: calculate_affinity(x, a, b, target))
    return best_solution

# User-defined parameters
pop_size = int(input("Enter population size: "))
num_generations = int(input("Enter number of generations: "))
num_select = int(input("Enter number of antibodies to select: "))
num_clones = int(input("Enter number of clones per antibody: "))
mutation_rate = float(input("Enter mutation rate (0-1): "))
lower_bound = float(input("Enter lower bound of search space: "))
upper_bound = float(input("Enter upper bound of search space: "))
bounds = [lower_bound, upper_bound]
a = float(input("Enter the value of a: "))
b = float(input("Enter the value of b: "))
target = float(input("Enter the target value (e.g., 1 or 10): "))

# Run the Clonal Selection Algorithm
best_solution = clonal_selection_algorithm(pop_size, num_generations, num_select, num_clones, mutation_rate, bounds, a, b, target)
best_value = objective_function(best_solution, a, b, target)

print(f"\nBest Solution: x = {best_solution}")
print(f"Best Value: f(x) = {best_value}")
