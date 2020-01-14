import java.awt.Color;

public class MyColor extends MyComparable {
	
	private Color color;

	public MyColor(Color color) {
		this.color = color;
	}

	@Override
	public boolean equalTo(MyComparable other) {
		if (other instanceof MyColor) {
		MyColor otherColor = (MyColor) other;
		return 	(this.color.getBlue() == otherColor.color.getBlue()) &&
				(this.color.getGreen() == otherColor.color.getGreen()) &&
				(this.color.getRed() == otherColor.color.getRed());
		}
		else
			throw new RuntimeException("The type of other must be MyColor");
	}

	@Override
	public boolean lessThan(MyComparable other) {
		if (other instanceof MyColor) {
			MyColor otherColor = (MyColor) other;
			int sumOfComponentsOfThis = this.color.getBlue() + this.color.getGreen() + this.color.getRed();
			int sumoOfComponentsOfOther = otherColor.color.getBlue() + otherColor.color.getGreen() + otherColor.color.getRed();
			return (sumOfComponentsOfThis < sumoOfComponentsOfOther);
			}
			else
				throw new RuntimeException("The type of other must be MyColor");
		
	}

}
