import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.Condition;

class Process extends Thread {
    final Condition cond;
    final int duration = 2;
    int relative_duration = 0;
    final int id;
    
    public void run() {
		for(int i=1; i<=duration;i++) {
			relative_duration = i;
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
		    if (duration != relative_duration)
		    	Main.lock.unlock();
		}
		Sched.n += 1;
		Main.lock.unlock();
	}

    public Process(int i, Condition c) {
		cond=c;
		id=i;
    }
}


    
