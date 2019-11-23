public abstract class MyComparable {
    public abstract boolean equalTo(MyComparable c2);

    public abstract boolean lessThan(MyComparable o);

    public boolean lessThanOrEqualTo(MyComparable c2) {
        if(equalTo(c2) || lessThan((c2))) {
            return true;
        } else {
            return false;
        }
    }

    public boolean greaterThan(MyComparable c3) {
        if(!lessThan(c3) && !equalTo(c3)) {
            return true;
        } else {
            return false;
        }
    }

    public boolean greaterThanOrEqualTo(MyComparable c2) {
        if(!lessThan(c2) || equalTo(c2)) {
            return true;
        } else {
            return false;
        }
    }
}
