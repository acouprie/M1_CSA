import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class ArrayTriableTest extends ConteneurTriableTest {
	
	@Before
	public void setUp() {
		this.test = new ArrayTriable(10);
		super.setUp();
	}

}
