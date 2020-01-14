public class BooleanVariable extends Satisfiable {
    String variable;
    String label;
    private boolean value;
    public BooleanVariable(String a, String label) {
        this.variable = a;
        this.label = label;
    }

    public void fixTruthValue(boolean val) {
        this.value = val;
    }

    public String interpretation() {
        if (value) {
            return this.label;
        } else {
            return "not " + this.label;
        }
    }

    @Override
    public boolean isSatisfiable() {
        return value;
    }

    @Override
    public String toString() {
        return this.variable;
    }
}
