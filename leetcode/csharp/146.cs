public class CachedNode
{
  public int Key { get; set; }
  public int Value { get; set; }
  public CachedNode? Prev { get; set; }
  public CachedNode? Next { get; set; }

  public CachedNode(int key, int value)
  {
    Key = key;
    Value = value;
  }
}

public class LRUCache
{
  private readonly int capacity;
  private readonly Dictionary<int, CachedNode> cacheStorage;
  public CachedNode? head;
  public CachedNode? tail;

  public LRUCache(int capacity)
  {
    this.capacity = capacity;
    cacheStorage = new Dictionary<int, CachedNode>(capacity);
  }

  public int Get(int key)
  {
    if (!HasKey(key))
    {
      return -1;
    }

    var cachedNode = GetByKey(key);
    MoveToHead(cachedNode);
    return cachedNode.Value;
  }

  private void MoveToHead(CachedNode node)
  {
    Remove(node);
    AddFirst(node);
  }

  public void Put(int key, int value)
  {
    if (HasKey(key))
    {
      var cachedNode = GetByKey(key);
      cachedNode.Value = value;
      MoveToHead(cachedNode);
    }
    else
    {
      var cachedNode = new CachedNode(key, value);

      if (cacheStorage.Count == capacity && tail != null)
      {
        Remove(tail);
      }

      AddFirst(cachedNode);
      cacheStorage[key] = cachedNode;
    }
  }

  private CachedNode GetByKey(int key) => cacheStorage[key];

  private bool HasKey(int key) => cacheStorage.ContainsKey(key);

  private void AddFirst(CachedNode node)
  {
    node.Next = head;
    node.Prev = null;

    if (head != null)
      head.Prev = node;

    head = node;

    if (tail == null)
      tail = node;

    cacheStorage[node.Key] = node;
  }

  private void Remove(CachedNode node)
  {
    cacheStorage.Remove(node.Key);

    if (node.Prev != null)
      node.Prev.Next = node.Next;
    else
      head = node.Next;

    if (node.Next != null)
      node.Next.Prev = node.Prev;
    else
      tail = node.Prev;

    node.Prev = null;
    node.Next = null;
  }
}
