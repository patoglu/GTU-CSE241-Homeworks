/**
 * 
 * @author Sushi
 *
 * @param <E> anyType
 */
public interface Collection <E> {
	/**
	 * 
	 * @param e generic type for add method.
	 */
	public void add(E e);
	/**
	 * 
	 * @param c generic type for collection
	 */
	public void addAll(Collection<E> c);
	/**
	 * 
	 * @param e generic type
	 * @return boolean
	 */
	public boolean contains(E e);
	/**
	 * 
	 * @param c generic type for collection
	 * @return boolean
	 */
	public boolean containsAll(Collection<E> c);
	/**
	 * 
	 * @return boolean, empty or not.
	 */
	public boolean isEmpty();
	/**
	 * 
	 * @param e Removes the generic type.
	 */
	public void remove(E e);
	/**
	 * 
	 * @param c Removes from the collection
	 */
	public void removeAll(Collection<E> c);
	/**
	 * Retains only the elements in this collection that are contained in the specified collection
	 * @param c collection generic.
	 */
	public void retainAll(Collection<E> c);
	/**
	 * 
	 * @return returns the size.
	 */
	public int size();
	/**
	 * 
	 * @return an Iterator over the collection.
	 */
	public Iterator<E> iterator();
	/**
	 * clear collection
	 */
	public void clear();
}
