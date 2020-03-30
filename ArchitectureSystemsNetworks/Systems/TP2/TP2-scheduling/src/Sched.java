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

			for (int process = 0; process < Main.nbProcess; process++) {
				if(i % Main.processes[process].periodicity == 0) {
					Main.inQueue[process] = true;
				}
			}

			// process election
			Main.process = n % Main.nbProcess;
			Process currentProcess = Main.processes[Main.process];

			// FIFO implementation
		    // if process not finished, call it again
			Boolean gap = true;
			int duration = 0;
            if (Main.inQueue[currentProcess.id] == true) {
				duration = fifo(currentProcess);
			} else {
            	for (int process = 0; process < Main.nbProcess; process++) {
            	    if(Main.inQueue[process] == true) {
            	    	gap = false;
						duration = fifo(Main.processes[process]);
						break;
					} else {
            	    	gap = true;
					}
				}
            	if (gap) {
					System.out.println(i + " -");
				}
			}
            n++;
			Main.lock.unlock();
			if (duration != 0) {
				i += duration - 1;
			}
		}

		// print violations and timesteps used
		System.out.print("violation: " + violations + " timesteps: " + timesteps);
    }

     private int fifo(Process currentProcess) {
		int duration = 0;
		 for (duration = 0; duration < currentProcess.duration; duration++) {
			 System.out.println(i + duration + " " + currentProcess.id);
			 Main.sched = false;
			 Main.conds[Main.process].signal();
			 timesteps++;
		 }
		 Main.inQueue[currentProcess.id] = false;
		 return duration;
	 }
}
		
		
