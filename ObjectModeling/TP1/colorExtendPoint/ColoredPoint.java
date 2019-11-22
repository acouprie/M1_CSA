package colorExtendPoint;

public class ColoredPoint extends Point {

	private Color color; 

	public ColoredPoint(float abscisse, float ordinate, int red, int green, int blue)  throws IllegalArgumentException {   
		super(abscisse, ordinate);   
		this.color = new Color(red,green,blue);  
	} 

	public ColoredPoint(float abscisse, float ordinate, Color color) {   
		super(abscisse, ordinate);   
		this.color = color;
	} 

	public static final ColoredPoint ORIGIN_POINT   = new ColoredPoint(0.0F, 0.0F, 0 , 0, 0); 

	public int getRed() {   
		return this.color.getRed(); 
	} 

	public int getGreen() {   
		return this.color.getGreen();  
	} 

	public int getBlue() {   
		return this.color.getBlue();  
	} 

	public void setRed(int red) throws IllegalArgumentException {   
		this.color.setRed(red);  
	} 

	public void setGreen(int green) throws IllegalArgumentException {   
		this.color.setGreen(green);  
	} 

	public void setBlue(int blue) throws IllegalArgumentException  {   
		this.color.setBlue(blue);  
	}    

	public String toString () {   
		return super.toString() + this.color.toString();  
	}   
}
