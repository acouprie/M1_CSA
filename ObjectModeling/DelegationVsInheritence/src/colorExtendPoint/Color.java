package colorExtendPoint;

public class Color {
	
	private int red;    
	private int green;    
	private int blue; 

	public Color(int red, int green, int blue) throws IllegalArgumentException {   
		this.setRed(red);   
		this.setGreen(green);   
		this.setBlue(blue);  
	} 

	public static final Color ROUGE = new Color (255, 0, 0); 
	public static final Color VERT = new Color (0, 255, 0); 
	public static final Color BLEU = new Color (0, 0, 255);    
	
	public int getRed() {      
		return (this.red);  
	} 

	public int getGreen() {      
		return (this.green);  
	} 

	public int getBlue() {      
		return (this.blue);  
	} 

	public int getRGB() {      
		return this.red * 256 * 256 + this.green * 256 + this.blue;  
	} 

	public void setRed(int red) throws IllegalArgumentException {      
		if (red < 0 || red > 255)           
			throw new IllegalArgumentException("bad shade of red");      
		this.red = red;  
	} 

	public void setGreen(int green) throws IllegalArgumentException {      
		if (green < 0 || green > 255)           
			throw new IllegalArgumentException("bad shade of green");      
		this.green = green;  
	} 

	public void setBlue(int blue) throws IllegalArgumentException {      
		if (blue < 0 || blue > 255)           
			throw new IllegalArgumentException("bad shade of blue");      
		this.blue = blue;  
	}

	@Override
	public String toString() {
		return "Color [red=" + red + ", green=" + green + ", blue=" + blue + "]";
	} 

}
