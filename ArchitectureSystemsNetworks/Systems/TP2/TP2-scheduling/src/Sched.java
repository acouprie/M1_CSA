class Sched extends Thread {
	public static int n = 0;
	public void run() {
		for(int i=0; i<10; i++) {
		    Main.lock.lock();
		    if(!Main.sched) {
				try {
					Main.csched.await();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}

		    // choose the next process to schedule
			Main.process = n % Main.nbProcess;
		    Main.conds[Main.process].signal();
			Main.sched = false;
		    Process currentProcess = Main.processes[Main.process];
		    if(n == Main.nbProcess) {
				n = 0;
			}
		    if (currentProcess.relativeDuration != currentProcess.duration) {
				Main.conds[Main.process].signal();
			}
			Main.lock.unlock();
		}
    }
}
		
		
