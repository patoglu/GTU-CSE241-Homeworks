
public interface Set<E> extends Collection<E> {
	public void add(E e);
	public void addAll(Collection <E> c);
	public boolean contains(E e);
	public boolean containsAll(Collection <E> c);
	public boolean isEmpty();
	public void remove(E e);
	public void removeAll(Collection <E> c);
	public void retainAll(Collection <E> c);
	public int size();
	//Iterator yazilacak
}
