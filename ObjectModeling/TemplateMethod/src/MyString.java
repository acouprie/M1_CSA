import java.util.LinkedList;
import java.util.List;

public class MyString extends MyComparable {
	
	private List<Character> data;
	
	public MyString(String s) {
		this.data = new LinkedList<Character>();
		for (int i = 0; i < s.length(); i++)
			this.data.add(i, Character.toLowerCase(s.charAt(i)));
	}

	@Override
	public boolean equalTo(MyComparable other) {
		if (other instanceof MyString) {
			MyString otherString = (MyString) other;
			if (this.data.size() == otherString.data.size()) {
				for (int i = 0; i < this.data.size(); i++) {
					if (! this.data.get(i).equals(otherString.data.get(i)))
						return false;
				}
				return true;
			}
			else
				return false;
		}
		else
			throw new RuntimeException("The type of other must be MyString");
	}

	@Override
	public boolean lessThan(MyComparable other) {
		if (other instanceof MyString) {
			MyString otherString = (MyString) other;
			for (int i = 0; i < Math.min(this.data.size(),otherString.data.size()); i++) {
				if (! this.data.get(i).equals(otherString.data.get(i))) {
					return (this.data.get(i).compareTo(otherString.data.get(i)) < 0);
				}
			}
			return (this.data.size() < otherString.data.size());
		}
		else
			throw new RuntimeException("The type of other must be MyString");
	}

}
