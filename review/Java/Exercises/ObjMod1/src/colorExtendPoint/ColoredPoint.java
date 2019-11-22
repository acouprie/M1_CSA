package colorExtendPoint;

public class ColoredPoint implements IColoredPoint {

	private Color color;
	private Point p;

	public ColoredPoint(float abscisse, float ordinate, int red, int green, int blue)  throws IllegalArgumentException {   
		this.p = new Point(abscisse, ordinate);
		this.color = new Color(red,green,blue);  
	} 

	public ColoredPoint(float abscisse, float ordinate, Color color) {
		this.p = new Point(abscisse, ordinate);
		this.color = color;
	} 

	public static final ColoredPoint ORIGIN_POINT   = new ColoredPoint(0.0F, 0.0F, 0 , 0, 0); 

	@Override
	public int getRed() {
		return this.color.getRed(); 
	} 

	@Override
	public int getGreen() {
		return this.color.getGreen();  
	} 

	@Override
	public int getBlue() {
		return this.color.getBlue();  
	} 

	@Override
	public void setRed(int red) throws IllegalArgumentException {
		this.color.setRed(red);  
	} 

	@Override
	public void setGreen(int green) throws IllegalArgumentException {
		this.color.setGreen(green);  
	} 

	@Override
	public void setBlue(int blue) throws IllegalArgumentException  {
		this.color.setBlue(blue);  
	}    

	@Override
	public String toString() {
		return super.toString() + this.color.toString();  
	}

	@Override
	public float getAbscisse() {
		return this.p.getAbscisse();
	}

	@Override
	public float getOrdinate() {
		return this.p.getOrdinate();
	}

	@Override
	public void translate(float tx, float ty) {
		this.p.translate(tx, ty);
	}

	@Override
	public void toScale(float h) throws IllegalArgumentException {
		this.p.toScale(h);
	}
}
