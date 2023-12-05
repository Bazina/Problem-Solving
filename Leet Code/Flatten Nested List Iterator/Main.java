import java.util.*;

class NestedInteger {
    List<NestedInteger> list;
    Integer number;

    public NestedInteger(Integer number) {
        this.number = number;
    }

    public NestedInteger(List<NestedInteger> list) {
        this.list = list;
    }

    // @return true if this NestedInteger holds a single integer, rather than a nested list.
    public boolean isInteger() {
        return number != null;
    }

    // @return the single integer that this NestedInteger holds, if it holds a single integer
    // Return null if this NestedInteger holds a nested list
    public Integer getInteger() {
        return number;
    }

    // @return the nested list that this NestedInteger holds, if it holds a nested list
    // Return empty list if this NestedInteger holds a single integer
    public List<NestedInteger> getList() {
        return list;
    }
}


class NestedIterator implements Iterator<Integer> {
    Queue<Integer> queue = new LinkedList<>();

    public NestedIterator(List<NestedInteger> nestedList) {
        recur(nestedList);
    }

    public void recur (List<NestedInteger> nestedList) {
        if (!nestedList.isEmpty())
            for (NestedInteger integer : nestedList) {
                if (integer.isInteger()) {
                    queue.add(integer.getInteger());
                } else {
                    recur(integer.getList());
                }
            }
    }

    @Override
    public Integer next() {
        return queue.poll();
    }

    @Override
    public boolean hasNext() {
        return !queue.isEmpty();
    }
}

public class Main {
    public static void main(String[] args) {
        List<NestedInteger> nestedList = new ArrayList<>() {
            {
                add(new NestedInteger(new ArrayList<>() {{
                    add(new NestedInteger(1));
                    add(new NestedInteger(1));
                }}));
                add(new NestedInteger(2));
                add(new NestedInteger(new ArrayList<>() {{
                    add(new NestedInteger(1));
                    add(new NestedInteger(1));
                }}));
                add(new NestedInteger(new ArrayList<>() {{
                    add(new NestedInteger(1));
                    add(new NestedInteger(new ArrayList<>() {{
                        add(new NestedInteger(2));
                        add(new NestedInteger(3));
                        add(new NestedInteger(new ArrayList<>() {{
                            add(new NestedInteger(4));
                            add(new NestedInteger(5));
                        }}));
                    }}));
                }}));
            }
        };

        NestedIterator i = new NestedIterator(nestedList);
        while (i.hasNext())
            System.out.println(i.next());
    }
}