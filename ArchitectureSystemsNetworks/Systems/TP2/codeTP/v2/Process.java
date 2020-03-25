import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.Condition;

class Process extends Thread {
    final Condition cond;
    final int id;
    
    public void run() {
	for(int i=0; i<4;i++) {
	    Main.lock.lock();
	    if(Main.process != id | Main.sched) {
		try {
		    cond.await();
		} catch (Exception e) {
		    e.printStackTrace();
		}
	    }
	    System.out.println("Process "+id);
	    Main.sched=true;
	    Main.csched.signal();
	    Main.lock.unlock();
	}
    }
    public Process(int i, Condition c) {
	cond=c;
	id=i;
    }
}


    
