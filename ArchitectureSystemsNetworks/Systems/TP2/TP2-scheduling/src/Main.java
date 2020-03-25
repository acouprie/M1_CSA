import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.Condition;

class Main {
	public static int nbProcess = 6;
	public static Process processes[] = new Process[nbProcess];
    public static Lock lock = new ReentrantLock();
    public static Condition conds[] = new Condition[nbProcess];

	public static Condition csched = lock.newCondition();

    public static int process = 0;
    public static boolean sched = true;
    
    public static void main(String[] args) throws InterruptedException {
	try {
		for (int i = 0; i < nbProcess; i++) {
			conds[i] = lock.newCondition();
			processes[i] = new Process(i, conds[i]);
			processes[i].start();
		}

		Sched sc = new Sched();
	    sc.start();

		} catch (Exception e) {
		    e.printStackTrace();
		}
    }
}
