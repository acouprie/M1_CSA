def dynamic_time_warping(first_sequence, second_sequence, constraints):
  # add 1 column and 1 row for the infinites
  columns_size = len(first_sequence) + 1
  rows_size = len(second_sequence) + 1
  # Build a matrice full of zeros
  matrix = np.zeros(shape=(rows_size, columns_size))
  # first row = infinite
  matrix[0, 1:] = np.Inf
  # first column = infinite
  for i in range(1, rows_size):
    matrix[i, 0] = np.Inf
  # compute the matrix
  for i in range(1, rows_size):
    for j in range(1, columns_size):
      distance = compute_distance(first_sequence[j-1], second_sequence[i-1])
      left = (matrix[i-1][j] + constraints[0] * distance)
      diagonal = (matrix[i-1][j-1] + constraints[1] * distance)
      top = (matrix[i][j-1] + constraints[2] * distance)
      matrix[i][j] = min(left, diagonal, top)
  # display the matrix
  print(matrix)
  print(determine_best_path(matrix, first_sequence, second_sequence))

def DTW(first_sequence, second_sequence, constraints):
  # add 1 column and 1 row for the infinites
  columns_size = len(first_sequence)
  rows_size = len(second_sequence)
  # Build a matrice full of zeros
  matrix = np.zeros(shape=(rows_size, columns_size))
  # first row = infinite
  matrix[0, 1:] = np.Inf
  # first column = infinite
  for i in range(1, rows_size):
    matrix[i, 0] = np.Inf
  # compute the matrix
  for i in range(1, rows_size):
    for j in range(1, columns_size):
      correspondance = is_same(first_sequence[j-1], second_sequence[i-1])
      left = (matrix[i-1][j] + constraints[0] * correspondance)
      diagonal = (matrix[i-1][j-1] + constraints[1] * correspondance)
      top = (matrix[i][j-1] + constraints[2] * correspondance)
      matrix[i][j] = min(left, diagonal, top)
  # display the matrix
  print(matrix)