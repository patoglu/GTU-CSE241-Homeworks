import java.util.ArrayList;

public class Iterator<E> {
	int cursor;
	public E[] iterArr;
	/**
	 * 
	 * @param myIterArr Container Array
	 */
	public Iterator(E[] myIterArr)
	{
		iterArr = (E[]) new Object[myIterArr.length];
		iterArr = myIterArr;
		cursor = 0;

	}
	/**
	 * 
	 * @return if a container has next element.
	 */
	public boolean hasNext()
	{
		if(cursor < iterArr.length)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	/**
	 * Returns the next element in the iteration and advances the iterator.
	 * @return next element.
	 */
	public E next()
	{
		if(cursor < iterArr.length)
		{
			
			return iterArr[cursor++];
			
		}
		return iterArr[0];
	}
	/**
	 * Removes from the underlying collection the last element returned by this iterator
	 */
	public void remove()
	{
		ArrayList<E> a = new ArrayList<E>();
		for(int i = 0 ; i < iterArr.length ; ++i)
		{
			a.add(iterArr[i]);
		}
		a.remove(cursor);
		for(int i = 0 ; i < iterArr.length - 1 ;++i)
		{
			iterArr[i] = a.get(i);
		}
	}
	/**
	 * 
	 * @return the current element.
	 */
	public E at()
	{
		return iterArr[cursor];
	}
}
