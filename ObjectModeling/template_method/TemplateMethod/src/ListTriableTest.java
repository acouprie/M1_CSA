import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class ListTriableTest extends ConteneurTriableTest{

	@Before
	public void setUp() {
		this.test = new ListTriable(10);
		super.setUp();
	}

}
