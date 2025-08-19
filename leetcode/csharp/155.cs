public class MinStack
{

  private Stack<int> storageStack;
  private Stack<int> minimumStack;

  public MinStack()
  {
    storageStack = new();
    minimumStack = new();
  }

  public void Push(int val)
  {
    storageStack.Push(val);

    bool canPush = minimumStack.Count == 0 || minimumStack.Peek() >= val;

    if (!canPush) return;
    minimumStack.Push(val);
  }

  public void Pop()
  {
    int topValue = storageStack.Peek();
    storageStack.Pop();

    if (topValue == minimumStack.Peek())
    {
      minimumStack.Pop();
    }

  }

  public int Top() => storageStack.Peek();

  public int GetMin() => minimumStack.Peek();
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.Push(val);
 * obj.Pop();
 * int param_3 = obj.Top();
 * int param_4 = obj.GetMin();
 */