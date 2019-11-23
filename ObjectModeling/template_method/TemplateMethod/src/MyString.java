import static java.lang.Integer.min;

public class MyString extends MyComparable {
    private String name;

    public MyString(String name) {
        this.name = name;
    }

    public boolean equalTo(MyComparable c1) {
        MyString s = (MyString) c1;
        return this.name.equals(s.name);
    }

    public boolean lessThan(MyComparable c2) {
        MyString str = (MyString) c2;
        for (int i = 0; i < min(this.name.length(), str.name.length()); i ++) {
            if (this.name.charAt(i) != str.name.charAt(i)) {
                return this.name.charAt(i) < str.name.charAt((i));
            }
        }
        return this.name.length() < str.name.length();
    }
}
