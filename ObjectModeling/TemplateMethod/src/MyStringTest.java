import static org.junit.Assert.*;

import java.awt.Color;

import org.junit.Test;

public class MyStringTest {

	@Test
	public void testChainesEgales() {
		MyString s1 = new MyString("abcd");
		assertTrue(s1.equalTo(new MyString("Abcd")));
		assertFalse(s1.equalTo(new MyString("bbcd")));
		assertFalse(s1.equalTo(new MyString("accd")));
		assertFalse(s1.equalTo(new MyString("abdd")));
		assertFalse(s1.equalTo(new MyString("abce")));
		assertFalse(s1.equalTo(new MyString("abcde")));
		assertFalse(s1.equalTo(new MyString("abc")));
		assertTrue(s1.equalTo(s1));
	}
	
	
	@Test (expected=RuntimeException.class)
	public void testExceptionEgalPourChaineNulle() {
		MyString s1 = new MyString("abcd");
		s1.equalTo(null);
	}
	
	@Test (expected=RuntimeException.class)
	public void testExceptionEgalPourNonComparable() {
		MyString s1 = new MyString("abcd");
		s1.equalTo(new MyColor(new Color(1,2,3)));
	}
	
	@Test
	public void testChainesInferieures() {
		MyString s1 = new MyString("abcd");
		assertTrue(s1.lessThan(new MyString("bbcd")));
		assertTrue(s1.lessThan(new MyString("accd")));
		assertTrue(s1.lessThan(new MyString("abdd")));
		assertTrue(s1.lessThan(new MyString("abce")));
		assertTrue(s1.lessThan(new MyString("abcde")));
		assertFalse(s1.lessThan(new MyString("abc")));
		assertFalse(s1.lessThan(s1));
	}
	
	@Test (expected=RuntimeException.class)
	public void testExceptionInferieurPourChaineNulle() {
		MyString s1 = new MyString("abcd");
		s1.lessThan(null);
	}
	
	@Test (expected=RuntimeException.class)
	public void testExceptionInferieurPourNonComparable() {
		MyString s1 = new MyString("abcd");
		s1.equalTo(new MyColor(new Color(1,2,3)));
	}

}
