import java.util.concurrent.locks.Condition;

class Process extends Thread {
	final int id;
	final Condition cond;
	final int periodicity;
    final int duration;
    int relativeDuration = 0;

    public void run() {


		while (true) {
        	int i;

			for (i = 0; i < duration; i++) {
				Main.lock.lock();
				if (Main.process != id | Main.sched) {
					try {
						cond.await();
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
				relativeDuration = i + 1;
				Main.sched = true;
				Main.csched.signal();
				Main.lock.unlock();
			}
		}
	}

    public Process(int i, Condition c, int p, int d) {
		id = i;
		cond = c;
		periodicity = p;
		duration = d;
	}
}


    
