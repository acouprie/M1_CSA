package colorExtendPoint;

public class Point {
	
	private float abscisse;     
	private float ordinate; 
	 
	public Point(float abscisse, float ordinate) {   
		this.abscisse = abscisse;   
		this.ordinate = ordinate;  
	}     
	
	public static final Point ORIGIN_POINT = new Point(0.0F, 0.0F);     
	
	public float getAbscisse() {   
		return this.abscisse;  
	}     
	
	public float getOrdinate() {   
		return this.ordinate;  
	}     
	
	public void  translate(float tx, float ty) {   
		this.abscisse += tx;   
		this.ordinate += ty;  
	} 
	 
	public void toScale(float h) throws IllegalArgumentException {   
		if (h <= 0.0F)    
			throw new IllegalArgumentException("wrong factor");   
		this.abscisse *= h;   
		this.ordinate *= h;  
	}

	@Override
	public String toString() {
		return "Point [abscisse=" + abscisse + ", ordinate=" + ordinate + "]";
	}  

}
