import java.util.concurrent.locks.Condition;

class Process extends Thread {
	final int id;
	final Condition cond;
    final int periodicity;
    final int duration;
    int relativeDuration = 0;

    public void run() {
        while (true) {
			for (int i = 0; i < duration; i++) {
				Main.lock.lock();
				relativeDuration = i + 1;
				if (Main.process != id | Main.sched) {
					try {
						cond.await();
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
				Main.sched = true;
				Main.csched.signal();
				if (duration != relativeDuration)
					Main.lock.unlock();
			}
			Sched.n++;
			Main.lock.unlock();
		}
	}

    public Process(int i, Condition c, int p, int d) {
		id = i;
		cond = c;
		periodicity = p;
		duration = d;
	}
}


    
