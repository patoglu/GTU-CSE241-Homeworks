

public class LinkedList<E> implements Collection<E>{
	private E[] javaArray;
	private Iterator<E> myIter;
	public LinkedList()
	{
		javaArray = (E[]) new Object[0];
	}
	@Override
	public void add(E e) {
		
			E[] tempArray =(E[]) new Object[javaArray.length + 1];
			int i;
			for(i = 0 ; i < javaArray.length ; ++i)
			{
				tempArray[i] = javaArray[i];
			}
			tempArray[i] = e;
			javaArray = tempArray;
			
			myIter = new Iterator <E>(javaArray);
		
	}

	@Override
	public void addAll(Collection<E> c) {
		while(c.iterator().hasNext())
		{
			add(c.iterator().at());
			c.iterator().next();
		}
	}

	@Override
	public boolean contains(E e) {
		for(int i = 0 ; i < javaArray.length ; ++i)
		{
			if(javaArray[i] == e)
			{
				return true;
			}
		}
		return false;
	}

	@Override
	public boolean containsAll(Collection<E> c) {
		boolean flag = true;
		while(c.iterator().hasNext())
		{	
			if(this.contains(c.iterator().at()))
			{
				//cool
			}
			else
			{
				flag = false;
			}
		}
		return flag;
	}

	@Override
	public boolean isEmpty() {
		if(javaArray.length == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	@Override
	public void remove(E e) {
		int pos = 0;
		for(int i = 0 ; i < javaArray.length ; ++i)
		{
			if(javaArray[i] == e)
			{
				pos = i + 1;
				break;
			}
		}
			
			
			for (int c = pos - 1; c < javaArray.length - 1; c++)
			{
				 javaArray[c] = javaArray[c+1];
			}
			E [] tempArr =(E[]) new Object[javaArray.length - 1];
			for(int i = 0 ; i < javaArray.length - 1 ; ++i)
			{
				tempArr[i] = javaArray[i];
			}
			javaArray =(E[]) new Object[tempArr.length];
			for(int i = 0 ; i < tempArr.length ; ++i)
			{
				javaArray[i] = tempArr[i];
			}
		
	}


	@Override
	public void retainAll(Collection<E> c) {
		while(c.iterator().hasNext())
		{
			if(c.iterator().at() == c)
			{
				remove(c.iterator().at());
				c.iterator().next();
			}
		}
	}

	@Override
	public int size() {
		return javaArray.length;
	}
	@Override
	public Iterator<E> iterator() {

		return myIter;
	}
	public void printAll()
	{
		for(int i = 0 ; i < javaArray.length ; ++i)
		{
			System.out.println(javaArray[i]);
		}
	}
	@Override
	public void removeAll(Collection<E> c) {
		while(c.iterator().hasNext())
		{
			if(c.iterator().at() == c)
			{
				remove(c.iterator().at());
				c.iterator().next();
			}
		}
	}
	@Override
	public void clear() {
		javaArray = (E[]) new Object[0];
	}
}
