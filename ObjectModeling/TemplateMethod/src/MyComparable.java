
public abstract class MyComparable {
	
	public abstract boolean equalTo(MyComparable other);
	public abstract boolean lessThan(MyComparable other);
	
	public boolean lessThanOrEqualTo(MyComparable other) {
		return this.lessThan(other) || this.equalTo(other);
	}
	
	public boolean greaterThan(MyComparable other) {
		return (!this.lessThan(other) && !this.equalTo(other));
	}
	
	public boolean greaterThanOrEqualTo(MyComparable other) {
		return !this.lessThan(other);
	}
	
}
