
public class Main {

	public static void main(String[] args) {
		
		System.out.println("HashSetTest Begins.");
		System.out.println("Creating two hashset objects with String type..");
		HashSet<String> mensTennis = new HashSet<String>();
		HashSet<String> womensTennis = new HashSet<String>();
		
		System.out.println("Filling mensTennis hashSet");
		try {
			mensTennis.add("Roger Federer");
			mensTennis.add("Novak Djokovic");
			mensTennis.add("Rafael Nadal");
			mensTennis.add("Grigor Dimitrov");
			mensTennis.add("Alexander Zverev");
			mensTennis.add("Juan Martin del Potro");
			mensTennis.add("Milos Raonic");
		}catch(IllegalArgumentException e) {
			System.out.println("Error!");
		}
		
		System.out.println("*****************************************");
		System.out.println("Printing all set tennis men");
		mensTennis.printAll();
		System.out.println("*****************************************");
		System.out.println("Filling womensTennis hashSet");
		try
		{
			womensTennis.add("Serena Williams");
			womensTennis.add("Caroline Wozniacki");
			womensTennis.add("Simona Halep");
			womensTennis.add("Maria Sharapova");
			womensTennis.add("Jelena Jankovic");
			womensTennis.add("Venus Williams");
			womensTennis.add("Lina");
		}catch(IllegalArgumentException e)
		{
			System.out.println("Error!");
		}
		
		System.out.println("Printing all set tennis women");
		womensTennis.printAll();
		System.out.println("*****************************************");
		
		System.out.println("Let's add womens tennis to mens tennis with addAll method.");
		
		mensTennis.addAll(womensTennis);
		System.out.println("and print them...");
		
		mensTennis.printAll();
		System.out.println("*****************************************");
		
		System.out.println("Testing remove method.");
		System.out.println("Maria Sharapova will be removed.");
		
		mensTennis.remove("Maria Sharapova");
		mensTennis.printAll();
		System.out.println("*****************************************");
		System.out.println("Testing if the container has Roger Federer or not");
		if(mensTennis.contains("Roger Federer"))
		{
			System.out.println("G.O.A.T exist for sure");
		}
		else
		{
			System.out.println("Not expecting this.");
		}
		System.out.println("*****************************************");
		System.out.println("Testing containsAllMethod");
		if(mensTennis.containsAll(womensTennis))
		{
			System.out.println("Mens tennis contain womens tennis as expected");
		}
		else
		{
			System.out.println("Not expected");
		}
		System.out.println("*****************************************");
		System.out.println("Checking if the container is empty or not.");
		if(mensTennis.isEmpty())
		{
			System.out.println("Container is empty.(Not expected)");
		}
		else
		{
			System.out.println("Container is not empty as expected.");
		}
		System.out.print("Container has ");
		System.out.print(mensTennis.size());
		System.out.print(" elements.\n");
		System.out.println("Lets clear the container so we can test isEmpty method again");
		mensTennis.clear();
		if(mensTennis.isEmpty())
		{
			System.out.println("Container is empty as expected");
		}
		else
		{
			System.out.println("Container is not empty.");
		}
		System.out.print("Container has ");
		System.out.print(mensTennis.size());
		System.out.print(" elements.\n");
		System.out.println("*****************************************");
		System.out.println("*****************************************");
		System.out.println("*****************************************");
		System.out.println("Testing same things for integers.");
		HashSet<Integer> even = new HashSet<Integer>();
		HashSet<Integer> odd = new HashSet<Integer>();
		
		System.out.println("Filling even hashSet");
		try
		{
			even.add(0);
			even.add(2);
			even.add(4);
			even.add(6);
			even.add(8);
		}catch(IllegalArgumentException e)
		{
			System.out.println("Error!");
		}
		
		System.out.println("*****************************************");
		System.out.println("Printing all even");
		even.printAll();
		System.out.println("*****************************************");
		System.out.println("Filling odd hashSet");
		try
		{
			odd.add(1);
			odd.add(3);
			odd.add(5);
			odd.add(7);
			odd.add(9);
		}catch(IllegalArgumentException e)
		{
			System.out.println("Error!");
		}
			
	
		System.out.println("Printing all odd women");
		odd.printAll();
		System.out.println("*****************************************");
		
		System.out.println("Let's add even  to odd addAll method.");
		
		even.addAll(odd);
		System.out.println("and print them...");
		
		even.printAll();
		System.out.println("*****************************************");
		
		System.out.println("Testing remove method.");
		System.out.println("1 will be removed.");
		
		even.remove(1);
		even.printAll();
		System.out.println("*****************************************");
		System.out.println("Testing if the container has 5 or not");
		if(even.contains(5))
		{
			System.out.println("5 exist for sure");
		}
		else
		{
			System.out.println("Not expecting this.");
		}
		System.out.println("*****************************************");
		System.out.println("Testing containsAllMethod");
		if(even.containsAll(odd))
		{
			System.out.println("even contain odd as expected");
		}
		else
		{
			System.out.println("Not expected");
		}
		System.out.println("*****************************************");
		System.out.println("Checking if the container is empty or not.");
		if(even.isEmpty())
		{
			System.out.println("Container is empty.(Not expected)");
		}
		else
		{
			System.out.println("Container is not empty as expected.");
		}
		System.out.print("Container has ");
		System.out.print(even.size());
		System.out.print(" elements.\n");
		System.out.println("Lets clear the container so we can test isEmpty method again");
		even.clear();
		if(even.isEmpty())
		{
			System.out.println("Container is empty as expected");
		}
		else
		{
			System.out.println("Container is not empty.");
		}
		System.out.println("*****************************************");
		System.out.println("*****************************************");
		System.out.println("*****************************************");
		System.out.println("*****************************************");
		System.out.println("*****************************************");
		System.out.println("*****************************************");
		
		System.out.println("ArrayList Begins.");
		System.out.println("Creating two ArrayList objects with String type..");
		ArrayList<String> mensTennis2 = new ArrayList<String>();
		ArrayList<String> womensTennis22 = new ArrayList<String>();
		
		System.out.println("Filling mensTennis2 arrayList");
		try
		{
			mensTennis2.add("Roger Federer");
			mensTennis2.add("Novak Djokovic");
			mensTennis2.add("Rafael Nadal");
			mensTennis2.add("Grigor Dimitrov");
			mensTennis2.add("Alexander Zverev");
			mensTennis2.add("Juan Martin del Potro");
			mensTennis2.add("Milos Raonic");
		}catch(IllegalArgumentException e)
		{
			System.out.println("Error!");
		}
	
		System.out.println("*****************************************");
		System.out.println("Printing all set tennis men");
		mensTennis2.printAll();
		System.out.println("*****************************************");
		System.out.println("Filling womensTennis22 arrayList");
		try
		{
			womensTennis22.add("Serena Williams");
			womensTennis22.add("Caroline Wozniacki");
			womensTennis22.add("Simona Halep");
			womensTennis22.add("Maria Sharapova");
			womensTennis22.add("Jelena Jankovic");
			womensTennis22.add("Venus Williams");
			womensTennis22.add("Lina");
		}catch(IllegalArgumentException e)
		{
			System.out.println("Error!");
		}
		
		System.out.println("Printing all set tennis women");
		womensTennis22.printAll();
		System.out.println("*****************************************");
		
		System.out.println("Let's add womens tennis to mens tennis with addAll method.");
		
		mensTennis2.addAll(womensTennis22);
		System.out.println("and print them...");
		
		mensTennis2.printAll();
		System.out.println("*****************************************");
		
		System.out.println("Testing remove method.");
		System.out.println("Maria Sharapova will be removed.");
		
		mensTennis2.remove("Maria Sharapova");
		mensTennis2.printAll();
		System.out.println("*****************************************");
		System.out.println("Testing if the container has Roger Federer or not");
		if(mensTennis2.contains("Roger Federer"))
		{
			System.out.println("G.O.A.T exist for sure");
		}
		else
		{
			System.out.println("Not expecting this.");
		}
		System.out.println("*****************************************");
		System.out.println("Testing containsAllMethod");
		if(mensTennis2.containsAll(womensTennis22))
		{
			System.out.println("Mens tennis contain womens tennis as expected");
		}
		else
		{
			System.out.println("Not expected");
		}
		System.out.println("*****************************************");
		System.out.println("Checking if the container is empty or not.");
		if(mensTennis2.isEmpty())
		{
			System.out.println("Container is empty.(Not expected)");
		}
		else
		{
			System.out.println("Container is not empty as expected.");
		}
		System.out.print("Container has ");
		System.out.print(mensTennis2.size());
		System.out.print(" elements.\n");
		System.out.println("Lets clear the container so we can test isEmpty method again");
		mensTennis2.clear();
		if(mensTennis2.isEmpty())
		{
			System.out.println("Container is empty as expected");
		}
		else
		{
			System.out.println("Container is not empty.");
		}
		System.out.print("Container has ");
		System.out.print(mensTennis2.size());
		System.out.print(" elements.\n");
		System.out.println("*****************************************");
		System.out.println("*****************************************");
		System.out.println("*****************************************");
		System.out.println("Testing same things for integers.");
		ArrayList<Integer> even2 = new ArrayList<Integer>();
		ArrayList<Integer> odd2 = new ArrayList<Integer>();
		
		System.out.println("Filling even2 ArrayList");
		even2.add(0);
		even2.add(2);
		even2.add(4);
		even2.add(6);
		even2.add(8);
		System.out.println("*****************************************");
		System.out.println("Printing all even2");
		even2.printAll();
		System.out.println("*****************************************");
		System.out.println("Filling odd2 ArrayList");
		odd2.add(1);
		odd2.add(3);
		odd2.add(5);
		odd2.add(7);
		odd2.add(9);
		System.out.println("Printing all odd2 women");
		odd2.printAll();
		System.out.println("*****************************************");
		
		System.out.println("Let's add even2  to odd2 addAll method.");
		
		even2.addAll(odd2);
		System.out.println("and print them...");
		
		even2.printAll();
		System.out.println("*****************************************");
		
		System.out.println("Testing remove method.");
		System.out.println("1 will be removed.");
		
		even2.remove(1);
		even2.printAll();
		System.out.println("*****************************************");
		System.out.println("Testing if the container has 5 or not");
		if(even2.contains(5))
		{
			System.out.println("5 exist for sure");
		}
		else
		{
			System.out.println("Not expecting this.");
		}
		System.out.println("*****************************************");
		System.out.println("Testing containsAllMethod");
		if(even2.containsAll(odd2))
		{
			System.out.println("even2 contain odd2 as expected");
		}
		else
		{
			System.out.println("Not expected");
		}
		System.out.println("*****************************************");
		System.out.println("Checking if the container is empty or not.");
		if(even2.isEmpty())
		{
			System.out.println("Container is empty.(Not expected)");
		}
		else
		{
			System.out.println("Container is not empty as expected.");
		}
		System.out.print("Container has ");
		System.out.print(even2.size());
		System.out.print(" elements.\n");
		System.out.println("Lets clear the container so we can test isEmpty method again");
		even2.clear();
		if(even2.isEmpty())
		{
			System.out.println("Container is empty as expected");
		}
		else
		{
			System.out.println("Container is not empty.");
		}
		
		System.out.println("*****************************************");
		System.out.println("*****************************************");
		System.out.println("*****************************************");
		System.out.println("*****************************************");
		System.out.println("HashSetTest Begins.");
		System.out.println("Creating two hashset objects with String type..");
		LinkedList<String> mensTennis3 = new LinkedList<String>();
		LinkedList<String> womensTennis33 = new LinkedList<String>();
		
		System.out.println("Filling mensTennis3 LinkedList");
		mensTennis3.add("Roger Federer");
		mensTennis3.add("Novak Djokovic");
		mensTennis3.add("Rafael Nadal");
		mensTennis3.add("Grigor Dimitrov");
		mensTennis3.add("Alexander Zverev");
		mensTennis3.add("Juan Martin del Potro");
		mensTennis3.add("Milos Raonic");
		System.out.println("*****************************************");
		System.out.println("Printing all set tennis men");
		mensTennis3.printAll();
		System.out.println("*****************************************");
		System.out.println("Filling womensTennis33 hashSet");
		womensTennis33.add("Serena Williams");
		womensTennis33.add("Caroline Wozniacki");
		womensTennis33.add("Simona Halep");
		womensTennis33.add("Maria Sharapova");
		womensTennis33.add("Jelena Jankovic");
		womensTennis33.add("Venus Williams");
		womensTennis33.add("Lina");
		System.out.println("Printing all set tennis women");
		womensTennis33.printAll();
		System.out.println("*****************************************");
		
		System.out.println("Let's add womens tennis to mens tennis with addAll method.");
		
		mensTennis3.addAll(womensTennis33);
		System.out.println("and print them...");
		
		mensTennis3.printAll();
		System.out.println("*****************************************");
		
		System.out.println("Testing remove method.");
		System.out.println("Maria Sharapova will be removed.");
		
		mensTennis3.remove("Maria Sharapova");
		mensTennis3.printAll();
		System.out.println("*****************************************");
		System.out.println("Testing if the container has Roger Federer or not");
		if(mensTennis3.contains("Roger Federer"))
		{
			System.out.println("G.O.A.T exist for sure");
		}
		else
		{
			System.out.println("Not expecting this.");
		}
		System.out.println("*****************************************");
		System.out.println("Testing containsAllMethod");
		if(mensTennis3.containsAll(womensTennis33))
		{
			System.out.println("Mens tennis contain womens tennis as expected");
		}
		else
		{
			System.out.println("Not expected");
		}
		System.out.println("*****************************************");
		System.out.println("Checking if the container is empty or not.");
		if(mensTennis3.isEmpty())
		{
			System.out.println("Container is empty.(Not expected)");
		}
		else
		{
			System.out.println("Container is not empty as expected.");
		}
		System.out.print("Container has ");
		System.out.print(mensTennis3.size());
		System.out.print(" elements.\n");
		System.out.println("Lets clear the container so we can test isEmpty method again");
		mensTennis3.clear();
		if(mensTennis3.isEmpty())
		{
			System.out.println("Container is empty as expected");
		}
		else
		{
			System.out.println("Container is not empty.");
		}
		System.out.print("Container has ");
		System.out.print(mensTennis3.size());
		System.out.print(" elements.\n");
		System.out.println("*****************************************");
		System.out.println("*****************************************");
		System.out.println("*****************************************");
		System.out.println("Testing same things for integers.");
		LinkedList<Integer> even3 = new LinkedList<Integer>();
		LinkedList<Integer> odd3 = new LinkedList<Integer>();
		
		System.out.println("Filling even3 LinkedList");
		even3.add(0);
		even3.add(2);
		even3.add(4);
		even3.add(6);
		even3.add(8);
		System.out.println("*****************************************");
		System.out.println("Printing all even3");
		even3.printAll();
		System.out.println("*****************************************");
		System.out.println("Filling odd3 hashSet");
		odd3.add(1);
		odd3.add(3);
		odd3.add(5);
		odd3.add(7);
		odd3.add(9);
		System.out.println("Printing all odd3 women");
		odd3.printAll();
		System.out.println("*****************************************");
		
		System.out.println("Let's add even3  to odd3 addAll method.");
		
		even3.addAll(odd3);
		System.out.println("and print them...");
		
		even3.printAll();
		System.out.println("*****************************************");
		
		System.out.println("Testing remove method.");
		System.out.println("1 will be removed.");
		
		even3.remove(1);
		even3.printAll();
		System.out.println("*****************************************");
		System.out.println("Testing if the container has 5 or not");
		if(even3.contains(5))
		{
			System.out.println("5 exist for sure");
		}
		else
		{
			System.out.println("Not expecting this.");
		}
		System.out.println("*****************************************");
		System.out.println("Testing containsAllMethod");
		if(even3.containsAll(odd3))
		{
			System.out.println("even3 contain odd3 as expected");
		}
		else
		{
			System.out.println("Not expected");
		}
		System.out.println("*****************************************");
		System.out.println("Checking if the container is empty or not.");
		if(even3.isEmpty())
		{
			System.out.println("Container is empty.(Not expected)");
		}
		else
		{
			System.out.println("Container is not empty as expected.");
		}
		System.out.print("Container has ");
		System.out.print(even3.size());
		System.out.print(" elements.\n");
		System.out.println("Lets clear the container so we can test isEmpty method again");
		even3.clear();
		if(even3.isEmpty())
		{
			System.out.println("Container is empty as expected");
		}
		else
		{
			System.out.println("Container is not empty.");
		}
		
	}
}
