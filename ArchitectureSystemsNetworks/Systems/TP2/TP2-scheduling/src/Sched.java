class Sched extends Thread {
	public static int n = 0, timesteps = 0, violations = 0;
	public void run() {
		for(int i = 0; i < Main.timesteps; i++) {
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

			// process election
			Main.process = n % Main.nbProcess;
			Process currentProcess;
			currentProcess = Main.processes[Main.process];

			int nbProcessChecked = 0;
			Boolean gap = false;
			while(timesteps % currentProcess.periodicity != 0
			&& currentProcess.relativeDuration != currentProcess.duration) {
				if(nbProcessChecked == Main.nbProcess) {
				    gap = true;
					break;
				}
				if(n == Main.nbProcess) {
					n = 0;
				}
				Main.process = n % Main.nbProcess;
				currentProcess = Main.processes[Main.process];
				nbProcessChecked++;
			}

			Main.sched = false;
			Main.conds[Main.process].signal();

			// FIFO implementation
		    // if process not finished, call it again
		    if (gap || currentProcess.relativeDuration > currentProcess.duration) {
				System.out.println(i + " -");
			} else {
		    	System.out.println(i + " " + currentProcess.id);
				Main.conds[Main.process].signal();
			}

			timesteps++;
			Main.lock.unlock();
		}

		// print violations and timesteps used
		System.out.print("violation: " + violations + " timesteps: " + timesteps);
    }
}
		
		
