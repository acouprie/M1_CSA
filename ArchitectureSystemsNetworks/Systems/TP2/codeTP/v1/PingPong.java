import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.Condition;

class PingPong extends Thread {
    final Lock lock;
    final Condition cond;
    final int objectif;
    
    public void run() {
	for(int i=0; i<4;i++) {
	    lock.lock();
	    if(Main.mode != objectif) {
		try {
		    cond.await();
		} catch (Exception e) {
		    e.printStackTrace();
		}
	    }
	    if (Main.mode == 0) System.out.println("Ping");
        else System.out.println("Pong");
	    Main.mode = 1-Main.mode;
        cond.signal();
	    lock.unlock();
	}
    }
    public PingPong(Lock l, Condition c, int o) {
	lock=l;
	cond=c;
	objectif=o;
    }
}


    
