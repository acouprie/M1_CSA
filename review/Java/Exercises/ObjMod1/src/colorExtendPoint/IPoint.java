package colorExtendPoint;

public interface IPoint {
    float getAbscisse();

    float getOrdinate();

    void  translate(float tx, float ty);

    void toScale(float h) throws IllegalArgumentException;
}
