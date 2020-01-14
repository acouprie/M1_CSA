import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import solution.ListTriable;

public class ListTriableTest extends ConteneurTriableTest{

	@Before
	public void setUp() {
		this.test = new ListTriable(10);
		super.setUp();
	}

}
