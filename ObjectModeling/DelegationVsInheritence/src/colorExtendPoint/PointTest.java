package colorExtendPoint;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.Test;

class PointTest {

	private Point p;    

	@BeforeEach  
	public void setUp() throws Exception {   
		this.p = new Point(1.0F, 2.0F);  
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
	public void testOrigin_Point() {   
		assertEquals(0.0F,Point.ORIGIN_POINT.getAbscisse());   
		assertEquals(0.0F,Point.ORIGIN_POINT.getOrdinate());  
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

}
