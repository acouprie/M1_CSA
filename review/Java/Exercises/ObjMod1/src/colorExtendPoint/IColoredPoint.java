package colorExtendPoint;

public interface IColoredPoint extends IPoint {
    int getRed();

    int getGreen();

    int getBlue();

    void setRed(int red) throws IllegalArgumentException;

    void setGreen(int green) throws IllegalArgumentException;

    void setBlue(int blue) throws IllegalArgumentException;

    String toString();
}
