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

			// choose the next process to schedule
			Main.process = n % Main.nbProcess;
			Process currentProcess = Main.processes[Main.process];
			Main.sched = false;
			Main.conds[Main.process].signal();

			// FIFO implementation
		    // if process not finished, call it again
		    if (currentProcess.relativeDuration <= currentProcess.duration) {
		    	timesteps++;
				System.out.println(i + " " + currentProcess.id);
				Main.conds[Main.process].signal();
			} else {
				System.out.println(i + " -");
			}
			Main.lock.unlock();
		}

		// print violations and timesteps used
		System.out.print("violation: " + violations + " timesteps: " + timesteps);
    }
}
		
		
