package lab4.a.Zad8;

public class MathArrayTest {
    public static void main(String[] args) {
        MathArray mathArray = new MathArray();
        System.out.printf("""
                        %1$s
                        Multiplied matrix:\t%2$s
                        Square matrix:
                        %3$s
                        Scalar Product:\t%4$.2f
                        Transpose matrix:
                        %5$s
                        Trace: %6$.2f
                        """,
                mathArray.toString(),
                mathArray.toString(mathArray.multiplyMatrixByRow()),
                mathArray.toString(mathArray.squareMatrix()),
                mathArray.scalarProduct(),
                mathArray.toString(mathArray.transposeMatrix()),
                mathArray.matrixTrace());
    }
}
