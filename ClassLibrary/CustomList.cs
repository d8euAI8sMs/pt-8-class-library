using System.Collections.Generic;

namespace ClassLibrary
{
    public interface ICustomList
    {
        void Add(int item);

        void Remove(int item);

        int Count { get; }

        int Sum { get; }

        int this[int pos] { get; set; }
    }

    public class CustomList : ICustomList
    {
        private IList<int> backingCollection = new List<int>();
        private int sum = 0;

        public void Add(int item)
        {
            backingCollection.Add(item);
            sum += item;
        }

        public void Remove(int item)
        {
            backingCollection.Remove(item);
            sum -= item;
        }

        public int Count
        {
            get {
                return backingCollection.Count;
            }
        }

        public int Sum
        {
            get
            {
                return sum;
            }
        }

        public int this[int pos]
        {
            get
            {
                return backingCollection[pos];
            }
            set
            {
                sum -= backingCollection[pos];
                sum += value;
                backingCollection[pos] = value;
            }
        }
    }
}
