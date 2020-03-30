import javax.swing.text.StyledEditorKit;
import java.util.*;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.Condition;

import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors


class Main {
	//public static String pathname = "inputsFiles/input1";
	public static String pathname = "inputsFiles/input_test";

	public static int nbProcess, timesteps;
	public static String algo;

    public static Lock lock = new ReentrantLock();
	public static Condition csched = lock.newCondition();

	public static Boolean inQueue[];
	public static Process processes[];
	public static Condition conds[];

    public static int process = 0;
    public static boolean sched = true;
    
    public static void main(String[] args) throws InterruptedException {
    	// Get data from the file
		String[] raw_data = readFile(pathname).split(" ");
		List<String> data = Arrays.asList(raw_data);
		// Get main information
		timesteps = Integer.parseInt(data.get(0));
		algo = data.get(1);
		nbProcess = Integer.parseInt(data.get(2));
		// Get processes information
		List<String> tasksDetails = new LinkedList<>(data.subList(3, data.size()));
		// Create array to store the processes
		processes = new Process[nbProcess];
		// Create array of conditions
		conds = new Condition[nbProcess];

		inQueue = new Boolean[nbProcess];
		// Create processes
		try {
			for (int i = 0; i < nbProcess; i++) {
				conds[i] = lock.newCondition();
				inQueue[i] = true;
				processes[i] = new Process(
						i,
						conds[i],
						Integer.parseInt(tasksDetails.get(1)),
						Integer.parseInt(tasksDetails.get(0))
				);
				tasksDetails.remove(1);
				tasksDetails.remove(0);
				processes[i].start();
			}

			Sched sc = new Sched();
		    sc.start();

		} catch (Exception e) {
		    e.printStackTrace();
		}
    }

    private static String readFile(String pathname) {
        String data = "";
		try {
			File myObj = new File(pathname);
			Scanner myReader = new Scanner(myObj);
			while (myReader.hasNextLine()) {
				data += myReader.nextLine() + " ";
			}
			myReader.close();
		} catch (FileNotFoundException e) {
			System.out.println("An error occurred.");
			e.printStackTrace();
		}
		return data;
	}
}
