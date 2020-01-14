public class Equivalence extends BinaryOperand {
    Satisfiable left;
    Satisfiable right;

    @Override
    public void setLeftOperand(Satisfiable left) {
        this.left = left;
    }

    @Override
    public void setRightOperand(Satisfiable right) {
        this.right = right;
    }

    @Override
    public boolean isSatisfiable() {
        return !this.left.isSatisfiable() && !this.right.isSatisfiable();
    }

    @Override
    public String toString() {
        return "(" + left.toString() + "<=>" + right.toString() + ")";
    }
}
