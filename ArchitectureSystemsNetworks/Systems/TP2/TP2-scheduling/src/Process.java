import java.util.concurrent.locks.Condition;

class Process extends Thread {
	final int id;
	final Condition cond;
    final int periodicity;
    final int duration;
    int relativeDuration = 0;

    public void run() {
		for(int i=1; i<=duration; i++) {
			relativeDuration = i;
		    Main.lock.lock();
		    if(Main.process != id | Main.sched) {
				try {
				    cond.await();
				} catch (Exception e) {
				    e.printStackTrace();
				}
		    }
		    System.out.println("Process " + id);
		    Main.sched = true;
		    Main.csched.signal();
		    if (duration != relativeDuration)
		    	Main.lock.unlock();
		}
		Sched.n += 1;
		Main.lock.unlock();
	}

    public Process(int i, Condition c, int p, int d) {
		id = i;
		cond = c;
		periodicity = p;
		duration = d;
	}
}


    
