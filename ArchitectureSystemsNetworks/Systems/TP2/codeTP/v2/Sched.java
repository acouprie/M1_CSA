import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.Condition;

class Sched extends Thread {
    public void run() {
	for(int i=0; i<10; i++) {
	    Main.lock.lock();
	    if(!Main.sched)
		try {
		    Main.csched.await();
		} catch (Exception e) {
		    e.printStackTrace();
		}
	    
	    // choose the next process to schedule
	    Main.process = 1-Main.process;
	    Main.conds[Main.process].signal();
	    Main.sched = false;
	    Main.lock.unlock();
	}
    }
}
		
		
