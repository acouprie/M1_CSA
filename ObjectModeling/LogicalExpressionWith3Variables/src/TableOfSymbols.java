import java.util.AbstractList;
import java.util.ArrayList;
public class TableOfSymbols {
    private AbstractList<BooleanVariable> variables;
    public TableOfSymbols() {
        this.variables = new ArrayList<BooleanVariable>();
    }
    public void addVariable (BooleanVariable variable) {
        this.variables.add(variable);
    }
    public void fixTruthValue (boolean... values) {
        for (int i = 0; i < Math.min(values.length,variables.size()); i++)
            this.variables.get(i). fixTruthValue (values[i]);
    }
    public void fixTruthValue (int value, int nbVariables) {
        boolean[] listOfParametres = new boolean[nbVariables];
        int shift = 0;
        do {
            int remainder = value % 2;
            listOfParametres[nbVariables-1-shift++] = remainder == 1;
            value /= 2;
        } while (value != 0);
        this. fixTruthValue (listOfParametres);
    }
    public String interpretation(int numVariable) {
        return this.variables.get(numVariable).interpretation();
    }
}