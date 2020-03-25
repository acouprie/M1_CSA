import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.Condition;

class Main {
    public static Lock lock = new ReentrantLock();
    public static Condition conds[] = { lock.newCondition(), lock.newCondition() };

    public static Condition csched = lock.newCondition();

    public static int process = 0;
    public static boolean sched = true;
    
    public static void main(String[] args) throws InterruptedException {
	try {
	    Process p1 = new Process(0, conds[0]);
	    Process p2 = new Process(1, conds[1]);
	    p1.start();
	    p2.start();

	    Sched sc = new Sched();
	    sc.start();
	} catch (Exception e) {
	    e.printStackTrace();
	}
    }
}
