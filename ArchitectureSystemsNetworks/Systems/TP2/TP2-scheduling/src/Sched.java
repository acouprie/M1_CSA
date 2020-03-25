import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.Condition;

class Sched extends Thread {
    public void run() {
		int n = 0;
		for(int i=0; i<10; i++) {
		    Main.lock.lock();
		    if(!Main.sched)
			try {
			    Main.csched.await();
			} catch (Exception e) {
			    e.printStackTrace();
			}


		    // choose the next process to schedule
			Main.process = n % Main.nbProcess;
		    Main.conds[Main.process].signal();
		    Main.sched = false;
		    Main.lock.unlock();
		    n++;
		    if(n == Main.nbProcess) {
		    	n = 0;
			}
		}
    }
}
		
		
