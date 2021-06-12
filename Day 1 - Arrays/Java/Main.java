import java.util.ArrayList;

class CustomArray{
	private ArrayList<Object> array;

	public CustomArray(){
		this.array = new ArrayList<>();
	}
	public int size(){
		return array.size();
	}
	public boolean isEmpty(){
		return array.isEmpty();
	}
	public void push(Object item){
		array.add(item);
	}
	public Object at(int index){
		if (!(index > array.size() && !(index < 0)))
			return array.get(index);
		else
			return null;
	}
	public void insert(int item, int index){
		array.add(index, item);
	}
	public void prepend(int item){
		array.add(0, item);
	}
	public Object pop(){
		return array.remove(array.size());
	}
	public void delete(int index){
		array.remove(index);
	} 
	public void remove(Object item){
		for(int i = 0; i < this.array.size(); i++){
			if(array.get(i).equals(item)){
				array.remove(i);
			}
		}
	}
	public int find(Object item){
		return array.indexOf(item);
	}
	public void print(){
		for(int i = 0; i < this.array.size(); i++){
			System.out.println(array.get(i));
		}
	}
}

class Main{
	public static void main(String[] args){
		CustomArray customArray = new CustomArray();
	}
}