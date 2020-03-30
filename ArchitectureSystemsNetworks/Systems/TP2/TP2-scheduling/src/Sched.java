class Sched extends Thread {
	public static int n = 0, timesteps = 0, violations = 0, i = 0;
	public void run() {
		for(i = 0; i < Main.timesteps; i++) {
		    Main.lock.lock();
		    if(!Main.sched) {
				try {
					Main.csched.await();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}

			// loop on the processes
			if(n == Main.nbProcess) {
				n = 0;
			}

			// update the periodicity queue
			click(i);

			// process election
			Main.process = n % Main.nbProcess;
			Process currentProcess = Main.processes[Main.process];

			int duration = 0;
			// if elected process is ready to execute
            if (Main.inQueue[currentProcess.id] == true) {
				duration = fifo(currentProcess);
			} else {
				// else we look for the next process ready
            	for (int process = 0; process < Main.nbProcess; process++) {
            	    if(Main.inQueue[process] == true) {
						duration = fifo(Main.processes[process]);
						break;
					} else {
            	        // if no process ready is found
						System.out.println(i + " -");
					}
				}
			}
            // resynchronise the main loop if process executed more than one time
            if(duration != 0) {
				i += duration - 1;
			}
            n++;
			Main.lock.unlock();
		}

		// print violations and timesteps used
		System.out.print("violation: " + violations + " timesteps: " + timesteps);
    }

	// FIFO implementation
	// if process not finished, call it again
	private int fifo(Process currentProcess) {
		int duration;
		 for (duration = 0; duration < currentProcess.duration; duration++) {
		 	int timestep = i + duration;
			 System.out.println(timestep + " " + currentProcess.id);
			 // update the periodicity queue
			 click(timestep);
			 Main.sched = false;
			 Main.conds[Main.process].signal();
			 timesteps++;
		 }
		 Main.inQueue[currentProcess.id] = false;
		 return duration;
	 }

	 private void click(int timestep) {
		 for (int process = 0; process < Main.nbProcess; process++) {
			 if (timestep % Main.processes[process].periodicity == 0) {
				 Main.inQueue[process] = true;
			 }

		 }
	 }
}
		
		
