import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.Condition;

class Main {
    public static Lock lock = new ReentrantLock();
    public static Condition cping = lock.newCondition();

    public static int mode = 0;
    
    public static void main(String[] args) throws InterruptedException {
	try {
	    PingPong ping= new PingPong(lock, cping, 0);
	    PingPong pong= new PingPong(lock, cping, 1);

	    ping.start();
	    pong.start();
	} catch (Exception e) {
	    e.printStackTrace();
	}
    }
}
