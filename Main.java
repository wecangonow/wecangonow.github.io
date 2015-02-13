class Node{
	int data;
	Node next;
	public Node(int d){
		data = d;
	}
}

public class Main {
	public	static void main(String[] args){
		Node a = new Node(1);
		Node b = new Node(2);
		Node c = new Node(3);

		a.next = b;
		b.next = c;
		System.out.println(a.next.next.data);
	
	}
	
}
