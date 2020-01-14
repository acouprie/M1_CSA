import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import solution.ConteneurTriable;
import solution.MyString;

public abstract class ConteneurTriableTest {

	protected  ConteneurTriable test;
	
	@Before
	public void setUp() {
		this.test.addElement(new MyString("coucou"));
		this.test.addElement(new MyString("Hello"));
		this.test.addElement(new MyString("World"));
		this.test.addElement(new MyString("Monde"));
		this.test.addElement(new MyString("alphabet"));
		this.test.addElement(new MyString("alphabetisation"));
		this.test.addElement(new MyString("coucou"));
		this.test.addElement(new MyString("Zorro"));
		this.test.addElement(new MyString("Zoe"));
		this.test.addElement(new MyString("TouteBonneChoseAUneFin"));
	}
	
	@Test
	public void testTriArray() {
		this.test.trier();
		for (int i = 0; i < this.test.getSize()-1; i++) {
			assertTrue(this.test.getElement(i).lessThanOrEqualTo(this.test.getElement(i+1)));
		}
	}

}
