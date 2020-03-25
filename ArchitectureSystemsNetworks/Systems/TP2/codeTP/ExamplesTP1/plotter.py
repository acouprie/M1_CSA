import argparse
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import colorsys as cs
import numpy

def get_new_color(feed=None):
    color = "#"
    if feed:

        r, g, b = cs.hls_to_rgb(((feed * 3.34876) % 16)/16, 0.7, 0.4)

        color += str(hex(int(r*256)))[2:]
        color += str(hex(int(g*256)))[2:]
        color += str(hex(int(b*256)))[2:]

    else:
        import random
        for i in range(0, 6):
            color += str(hex(random.randint(5, 15)))[2:]
    return color


# Create the argument parser
parser = argparse.ArgumentParser(description='Display a schedule.')

# Add input file argument
parser.add_argument('file', metavar='file', type=str,
                   help='the path of the results file')

# Parse the arguments
args = parser.parse_args()

# Check whether file exists
file = None
try:
    file = open(args.file)
    file.close()
except FileNotFoundError:
    print('Error : File ' + args.file + ' not found.')
    exit(1)


# Start parsing the file
print("Parsing file...")

# Create the Job list
tasks = []
# Open the file
file = open(args.file)
# For each line
for line in file:
    # If not a comment
    if not line.startswith('#'):
        # Split words
        values = line.split(' ')
        try:
            # Convert the words to integers
            info = [int(v) for v in values]
            tasks.append(info[1])
        except:
            print(values)
            if values[len(values)-1] == '-\n':
                 tasks.append(-1)
            else:
                print("Error : Wrong file format", values)
                exit(1)
# Close the file
missed = info[0]
file.close()
print("Done parsing file.")

# Create Matplotlib figure
fig1 = plt.figure()

print("Creating plots...")

# Create subplot
ax1 = fig1.add_subplot(111)

# Set labels
ax1.set_ylabel("Task ID")
ax1.set_xlabel("Timestep")
ax1.set_xticks(numpy.arange(0, len(tasks), step=1))
#ax1.set_yticks(numpy.arange(0, 1, step=1))
ax1.set_yticks([])

color = [-1 for i in range(len(tasks))]

i = 0
prevt = -1
# For all tasks
for t in tasks:
    i = i + 1
    if t == -1:
           continue
    if i == len(tasks)-1:
           break
    if (t != prevt and color[t]==-1):
        color[t] = get_new_color(t)
    ax1.add_patch(
        # As a rectangle
        patches.Rectangle(
            # X is the start time, Y is the Server ID
            (i, 0),  # (x,y)
            # Width is the difference between end time and start time
            1,  # width
            # Height is always 1
            1,  # height
            # We assign it a random color
            facecolor=color[t]
        )
    )
    print(i, " ", t, " ", color[t])
    # Add text for the ID of the job at (almost) the same position
    if (t != prevt):
       ax1.text(i+0.2, 0.1, str(t))
    prevt = t

violations = "Number of missed deadlines="+str(missed)
ax1.text(0.5, 1.1, violations)
print("Done...")
plt.plot()
plt.show()
