package colorExtendPoint;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class ColoredPointTest {

	private ColoredPoint p;    

	@BeforeEach  
	public void setUp() throws Exception {   
		this.p = new ColoredPoint(1.0F, 2.0F,1,2,3);  
	} 

	@AfterEach 
	public void tearDown() throws Exception {   
		this.p = null;  
	} 

	@Test  
	public void testAbscisseConstructor() {   
		assertEquals(1.0F,this.p.getAbscisse());  
	}    

	@Test  
	public void testOrdinateConstructor() {   
		assertEquals(2.0F,this.p.getOrdinate());  
	}      

	@Test  
	public void testTranslate() {   
		float oldAbscisse = this.p.getAbscisse();   
		float oldOrdonnée = this.p.getOrdinate();   
		this.p.translate(1.1F, 2.2F);   
		assertEquals(oldAbscisse + 1.1F, this.p.getAbscisse());   
		assertEquals(oldOrdonnée + 2.2F, this.p.getOrdinate());  
	}    

	@Test  
	public void testToScale() {   
		float oldAbscisse = this.p.getAbscisse();   
		float oldOrdonnée = this.p.getOrdinate();   
		this.p.toScale(1.5F);   
		assertEquals(oldAbscisse * 1.5F, this.p.getAbscisse());   
		assertEquals(oldOrdonnée * 1.5F, this.p.getOrdinate());  
	}  

	@Test
	public void NullValueInputForToScaleMethod() {
		assertThrows(IllegalArgumentException.class,
				()->{this.p.toScale(0.0F);} );
	}

	@Test 
	public void NegativeValueInputForToScaleMethod() {  
		assertThrows(IllegalArgumentException.class,
				()->{this.p.toScale(-1.0F);} );
	}

	@Test  
	public void testRedComponentOfColor() {   
		assertEquals(1,this.p.getRed());  
	} 

	@Test  
	public void testGreenComponentOfColor() {   
		assertEquals(2,this.p.getGreen());  
	}    

	@Test  
	public void testBlueComponentOfColor() {   
		assertEquals(3,this.p.getBlue());  
	}   

	@Test  
	public void testRedComponentSetter() {   
		this.p.setRed(255);   
		assertEquals(255,this.p.getRed());  
	} 

	@Test  
	public void testGreenComponentSetter() {   
		this.p.setGreen(255);   
		assertEquals(255,this.p.getGreen());  
	}    

	@Test  
	public void testBlueComponentSetter() {   
		this.p.setBlue(255);   
		assertEquals(255,this.p.getBlue());  
	}    

	@Test  
	public void testOrigin_Point() {   
		assertEquals(0.0F,ColoredPoint.ORIGIN_POINT.getAbscisse());   
		assertEquals(0.0F,ColoredPoint.ORIGIN_POINT.getOrdinate());   
		assertEquals(0,ColoredPoint.ORIGIN_POINT.getRed());   
		assertEquals(0,ColoredPoint.ORIGIN_POINT.getGreen());   
		assertEquals(0,ColoredPoint.ORIGIN_POINT.getBlue());  
	} 
}
