import static org.junit.Assert.*;

import java.awt.Color;

import org.junit.Test;

public class MyColorTest {

	@Test
	public void testCouleursEgales() {
		MyColor c1 = new MyColor(new Color(1,2,3));
		MyColor c2 = new MyColor(new Color(1,2,3));
		MyColor c3 = new MyColor(new Color(2,2,3));
		MyColor c4 = new MyColor(new Color(1,3,3));
		MyColor c5 = new MyColor(new Color(1,2,4));
		assertTrue(c1.equalTo(c2));
		assertFalse(c1.equalTo(c3));
		assertFalse(c1.equalTo(c4));
		assertFalse(c1.equalTo(c5));
	}

	@Test (expected=RuntimeException.class)
	public void testExceptionEgalPourCouleurNulle() {
		MyColor c1 = new MyColor(new Color(1,2,3));
		c1.equalTo(null);
	}
	
	@Test (expected=RuntimeException.class)
	public void testExceptionEgalPourNonComparable() {
		MyColor c1 = new MyColor(new Color(1,2,3));
		c1.equalTo(new MyString("test"));
	}
	
	@Test (expected=RuntimeException.class)
	public void testExceptionInferieurPourCouleurNulle() {
		MyColor c1 = new MyColor(new Color(1,2,3));
		c1.lessThan(null);
	}
	
	@Test (expected=RuntimeException.class)
	public void testExceptionInferieurPourNonComparable() {
		MyColor c1 = new MyColor(new Color(1,2,3));
		c1.lessThan(new MyString("test"));
	}
	
	@Test 
	public void testCouleursInferieures() {
		MyColor c1 = new MyColor(new Color(1,2,3));
		MyColor c2 = new MyColor(new Color(1,2,4));
		MyColor c3 = new MyColor(new Color(1,2,2));
		assertTrue(c1.lessThan(c2));
		assertFalse(c1.lessThan(c3));
		assertFalse(c1.lessThan(c1));
	}
	
	@Test 
	public void testCouleursInferieuresOuEgales() {
		MyColor c1 = new MyColor(new Color(1,2,3));
		MyColor c2 = new MyColor(new Color(1,2,4));
		MyColor c3 = new MyColor(new Color(1,2,2));
		assertTrue(c1.lessThanOrEqualTo(c2));
		assertFalse(c1.lessThanOrEqualTo(c3));
		assertTrue(c1.lessThanOrEqualTo(c1));
	}
	
	@Test
	public void testCouleursSuperieures() {
		MyColor c1 = new MyColor(new Color(1,2,3));
		MyColor c2 = new MyColor(new Color(1,2,4));
		MyColor c3 = new MyColor(new Color(1,2,2));
		assertFalse(c1.greaterThan(c2));
		assertTrue(c1.greaterThan(c3));
		assertFalse(c1.greaterThan(c1));
	}
	
	@Test
	public void testCouleursSuperieuresOuEgales() {
		MyColor c1 = new MyColor(new Color(1,2,3));
		MyColor c2 = new MyColor(new Color(1,2,4));
		MyColor c3 = new MyColor(new Color(1,2,2));
		assertFalse(c1.greaterThanOrEqualTo(c2));
		assertTrue(c1.greaterThanOrEqualTo(c3));
		assertTrue(c1.greaterThanOrEqualTo(c1));
	}
}
