import java.awt.*;

public class MyColor extends MyComparable {
    private Color color;

    public MyColor(Color color) {
        this.color = color;
    }

    public boolean equalTo(MyComparable c1) {
        MyColor s = (MyColor) c1;
        return this.color.equals(s.color);
    }

    public boolean lessThan(MyComparable c2) {
        MyColor c = (MyColor) c2;
        if(this.color.getRed() != c.color.getRed()) {
            return this.color.getRed() < c.color.getRed();
        }
        if(this.color.getGreen() != c.color.getGreen()) {
            return this.color.getGreen() < c.color.getGreen();
        }
        if(this.color.getBlue() != c.color.getBlue()) {
            return this.color.getBlue() < c.color.getBlue();
        }
        return false;
    }
}
